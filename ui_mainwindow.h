/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QListWidget *sessions;
    QVBoxLayout *verticalLayout_2;
    QPushButton *start;
    QPushButton *edit;
    QPushButton *remove;
    QPushButton *add;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(365, 191);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        sessions = new QListWidget(centralWidget);
        sessions->setObjectName(QString::fromUtf8("sessions"));

        verticalLayout->addWidget(sessions);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        start = new QPushButton(centralWidget);
        start->setObjectName(QString::fromUtf8("start"));

        verticalLayout_2->addWidget(start);

        edit = new QPushButton(centralWidget);
        edit->setObjectName(QString::fromUtf8("edit"));

        verticalLayout_2->addWidget(edit);

        remove = new QPushButton(centralWidget);
        remove->setObjectName(QString::fromUtf8("remove"));

        verticalLayout_2->addWidget(remove);

        add = new QPushButton(centralWidget);
        add->setObjectName(QString::fromUtf8("add"));

        verticalLayout_2->addWidget(add);


        horizontalLayout->addLayout(verticalLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Falkon Profiles Manager", nullptr));
        start->setText(QCoreApplication::translate("MainWindow", "start", nullptr));
        edit->setText(QCoreApplication::translate("MainWindow", "edit", nullptr));
        remove->setText(QCoreApplication::translate("MainWindow", "remove", nullptr));
        add->setText(QCoreApplication::translate("MainWindow", "add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
