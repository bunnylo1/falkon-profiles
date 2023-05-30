#include <QDir>
#include <QListWidget>
#include <QString>
#include <QProcess>
#include <QInputDialog>
#include <QMessageBox>
#include <QDesktopWidget>
#include <QWidget>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "tmulti.h"


/*
 * Startup
 */

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setGeometry(
        QStyle::alignedRect(
            Qt::LeftToRight,
            Qt::AlignCenter,
            this->size(),
            QDesktopWidget()
               .screenGeometry(this)
        )
    );

    QDir curr = QDir();
    
    if (!curr.exists(tmulti.PATH)) {
        curr.mkdir(tmulti.PATH);
    }

    foreach(QString session, tmulti.getSessions()) {
        addItem(session);
    }

    if (ui->sessions->count() > 0) {
        ui->sessions->setFocus();
        ui->sessions->item(0)->setSelected(true);
    }
}


/*
 * Qt Wrap
*/

QString MainWindow::getSelectedItem() {
     QListWidgetItem *widget = ui->sessions->currentItem();
     return widget == nullptr ? nullptr : widget->text();
}

void MainWindow::showError(QString text) {
    QMessageBox msg;
    msg.setText(text);
    msg.setIcon(QMessageBox::Critical);
    msg.exec();
}

QString MainWindow::inputTextDialog(QString text) {
    return QInputDialog::getText(this, "", text,  QLineEdit::Normal);
}

void MainWindow::deleteSelectedItem() {
    qDeleteAll(ui->sessions->selectedItems());
}

void MainWindow::addItem(QString item) {
    ui->sessions->addItem(item);
    ui->sessions->sortItems();
    ui->sessions->setFocus();
}

/*
 * onClick listener
 */

void MainWindow::on_start_clicked()
{
    QString name = getSelectedItem();
    if (name == nullptr) return;

    if (!tmulti.launchSession(name)) {
        showError(tr("no_tdesktop"));
    }
}

void MainWindow::on_add_clicked()
{
    QString name = inputTextDialog(tr("sess_name"));
    if (name == "") return;

    bool res = tmulti.addSession(name);
    
    if (!res) {
        showError(tr("creation_err"));
        return;
    }
    
    res = tmulti.launchSession(name);
    
    if (!res) {
        showError(tr("no_tdesktop"));
        return;
    }
    
   addItem(name);
}

void MainWindow::on_remove_clicked()
{
    QString name = getSelectedItem();
    if (name == nullptr) return;

    bool res = tmulti.deleteSession(name);

    if (res) {
       deleteSelectedItem();
    } else {
       showError(tr("delete_err"));
    }
}

void MainWindow::on_edit_clicked()
{
    QString name = getSelectedItem();
    if (name == nullptr) return;

    QString new_name = inputTextDialog(tr("new_name"));
    if (new_name == "") return;

    bool res = tmulti.editSession(name, new_name);

    if (res) {
        deleteSelectedItem();
        addItem(new_name);
    } else {
        showError(tr("edit_err"));
    }
}

void MainWindow::on_sessions_itemDoubleClicked(QListWidgetItem *item)
{
    if (!tmulti.launchSession(item->text())) {
        showError(tr("no_tdesktop"));
    }
}
