#include <QList>
#include <QDir>
#include <QDirIterator>
#include <QString>
#include <QProcessEnvironment>
#include <QStandardPaths>
#include <QApplication>

#include "tmulti.h"
#include "mainwindow.h"

TMulti::TMulti(){
    QCoreApplication::setApplicationName("falkon");
    PATH = QDir::cleanPath(
    QStandardPaths::writableLocation(
    QStandardPaths::AppConfigLocation) + 
    QDir::separator() + "profiles");
}

QList<QString> TMulti::getSessions() {
    QList<QString> sessions = QDir(PATH)
            .entryList(QDir::Filter::Dirs);

    foreach(QString name, sessions) {
        if (isBadName(name)) {
            sessions.removeAll(name);
        }
    }
    /*
    QString defaultSession = QStandardPaths::locate(QStandardPaths::GenericDataLocation, "TelegramDesktop", QStandardPaths::LocateDirectory);
    
    if (!defaultSession.isEmpty() && QDir(defaultSession).exists()) {
        sessions.append("Default Falkon session");
    }*/

    return sessions;
}

bool TMulti::editSession(QString old_name, QString new_name) {
    if (isBadName(new_name) || isBadName(old_name)) return false;

    return QDir(PATH).rename(old_name, new_name);
}

bool TMulti::deleteSession(QString name) {
    if (isBadName(name)) return false;
    QDir dataDir = QDir(PATH);
    
    return QDir(dataDir.absoluteFilePath(name)).removeRecursively();
}

bool TMulti::addSession(QString name) {
    if (isBadName(name)) return false;

    return QDir(PATH).mkpath(name);
}

bool TMulti::launchSession(QString name) {
    if (!QFile(getTdesktopPath()).exists()) {
        return false;
    }

    QProcess *process = new QProcess();
    
//    if (name != "Default Falkon session") {
        QStringList args = {"-r", "-p", name};
        process->setArguments(args);
//    }
    
    process->setProgram(getTdesktopPath());

    process->startDetached();
    return true;
}

bool TMulti::isBadName(QString name) {
    return name.contains(".");//|| name.contains("Default Telegram session");
}

QString TMulti::getTdesktopPath() {
    QFile defaultPath(TDESKTOP_PATH);
    
    if (defaultPath.exists()) {
        return defaultPath.fileName();
    }
    
#if defined(Q_OS_WIN)
#else
    QProcessEnvironment env(QProcessEnvironment::systemEnvironment());
    QString envPath = env.value("PATH");
    
    foreach (QString path, envPath.split(":")) {
        QDir pathDir(path);
        QFile file(pathDir.filePath("falkon"));
        
        if (file.exists()) {
            return file.fileName();
        }
    }
#endif

    return defaultPath.fileName();
}
