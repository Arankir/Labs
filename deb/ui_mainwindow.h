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
    QPushButton *Connect;
    QLineEdit *PaswordEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *IPEdit;
    QLabel *label_4;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(264, 211);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        LoginEdit = new QLineEdit(centralWidget);
        LoginEdit->setObjectName(QString::fromUtf8("LoginEdit"));
        LoginEdit->setGeometry(QRect(80, 50, 113, 20));
        Connect = new QPushButton(centralWidget);
        Connect->setObjectName(QString::fromUtf8("Connect"));
        Connect->setGeometry(QRect(90, 140, 75, 23));
        PaswordEdit = new QLineEdit(centralWidget);
        PaswordEdit->setObjectName(QString::fromUtf8("PaswordEdit"));
        PaswordEdit->setGeometry(QRect(80, 80, 113, 20));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(60, 0, 141, 51));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(27, 55, 47, 13));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 84, 47, 13));
        IPEdit = new QLineEdit(centralWidget);
        IPEdit->setObjectName(QString::fromUtf8("IPEdit"));
        IPEdit->setGeometry(QRect(80, 110, 113, 20));
        IPEdit->setDragEnabled(false);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(14, 108, 51, 20));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(LoginEdit, PaswordEdit);
        QWidget::setTabOrder(PaswordEdit, Connect);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        LoginEdit->setPlaceholderText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\273\320\276\320\263\320\270\320\275", nullptr));
        Connect->setText(QApplication::translate("MainWindow", "\320\222\321\205\320\276\320\264", nullptr));
        PaswordEdit->setPlaceholderText(QApplication::translate("MainWindow", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\260\321\200\320\276\320\273\321\214", nullptr));
        label->setText(QApplication::translate("MainWindow", "\320\241\320\220\320\235\320\220\320\242\320\236\320\240\320\230\320\231", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\320\233\320\276\320\263\320\270\320\275:", nullptr));
        label_3->setText(QApplication::translate("MainWindow", "\320\237\320\260\321\200\320\276\320\273\321\214:", nullptr));
        IPEdit->setInputMask(QApplication::translate("MainWindow", "000.000.000.000", nullptr));
        IPEdit->setText(QApplication::translate("MainWindow", "127.0.0.1", nullptr));
        label_4->setText(QApplication::translate("MainWindow", "IP-\320\260\320\264\321\200\320\265\321\201:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
