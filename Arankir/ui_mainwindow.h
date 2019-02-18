/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLineEdit *LoginEdit;
    QLabel *LoginLable;
    QPushButton *Connect;
    QLineEdit *PaswordEdit;
    QLabel *PaswordLable;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(249, 163);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        LoginEdit = new QLineEdit(centralWidget);
        LoginEdit->setObjectName(QString::fromUtf8("LoginEdit"));
        LoginEdit->setGeometry(QRect(100, 10, 113, 20));
        LoginLable = new QLabel(centralWidget);
        LoginLable->setObjectName(QString::fromUtf8("LoginLable"));
        LoginLable->setGeometry(QRect(20, 10, 51, 16));
        QFont font;
        font.setPointSize(12);
        LoginLable->setFont(font);
        Connect = new QPushButton(centralWidget);
        Connect->setObjectName(QString::fromUtf8("Connect"));
        Connect->setGeometry(QRect(80, 80, 75, 23));
        PaswordEdit = new QLineEdit(centralWidget);
        PaswordEdit->setObjectName(QString::fromUtf8("PaswordEdit"));
        PaswordEdit->setGeometry(QRect(100, 40, 113, 20));
        PaswordLable = new QLabel(centralWidget);
        PaswordLable->setObjectName(QString::fromUtf8("PaswordLable"));
        PaswordLable->setGeometry(QRect(20, 40, 61, 21));
        PaswordLable->setFont(font);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 249, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        LoginLable->setText(QApplication::translate("MainWindow", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        Connect->setText(QApplication::translate("MainWindow", "\320\222\321\205\320\276\320\264", nullptr));
        PaswordLable->setText(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
