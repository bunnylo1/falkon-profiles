#ifndef TMULTI_H
#define TMULTI_H

#include <QList>
#include <QString>

class TMulti {
private:
    bool isBadName(QString name);
    QString getTdesktopPath();
public:
    QString PATH;
    QList<QString> getSessions();
    bool editSession(QString old_name, QString new_name);
    bool deleteSession(QString name);
    bool addSession(QString name);
    bool launchSession(QString name);
    TMulti();
};

#endif // TMULTI_H
