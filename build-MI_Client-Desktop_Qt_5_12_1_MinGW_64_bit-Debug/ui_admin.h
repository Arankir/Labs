/********************************************************************************
** Form generated from reading UI file 'admin.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_H
#define UI_ADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Admin
{
public:
    QTabWidget *tabWidget;
    QWidget *Admin1;
    QPushButton *LogOut;
    QWidget *RegWid;
    QPushButton *Reg;
    QPushButton *AddIng;
    QPushButton *AddDish;
    QPushButton *AddStock;
    QPushButton *ChangeReq;
    QPushButton *Bd;
    QWidget *AddDishWid;
    QWidget *AddIngWid;
    QWidget *AddStockWid;
    QWidget *ChangeReqWid;
    QWidget *BdWid;
    QPushButton *hide;
    QFrame *line_3;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_4;
    QWidget *Cook;
    QWidget *Whk;
    QWidget *Stocker;

    void setupUi(QWidget *Admin)
    {
        if (Admin->objectName().isEmpty())
            Admin->setObjectName(QString::fromUtf8("Admin"));
        Admin->resize(908, 692);
        tabWidget = new QTabWidget(Admin);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 20, 881, 621));
        tabWidget->setTabShape(QTabWidget::Triangular);
        Admin1 = new QWidget();
        Admin1->setObjectName(QString::fromUtf8("Admin1"));
        LogOut = new QPushButton(Admin1);
        LogOut->setObjectName(QString::fromUtf8("LogOut"));
        LogOut->setGeometry(QRect(760, 20, 71, 23));
        RegWid = new QWidget(Admin1);
        RegWid->setObjectName(QString::fromUtf8("RegWid"));
        RegWid->setGeometry(QRect(220, 60, 641, 511));
        Reg = new QPushButton(Admin1);
        Reg->setObjectName(QString::fromUtf8("Reg"));
        Reg->setGeometry(QRect(20, 70, 141, 31));
        AddIng = new QPushButton(Admin1);
        AddIng->setObjectName(QString::fromUtf8("AddIng"));
        AddIng->setGeometry(QRect(20, 110, 141, 31));
        AddDish = new QPushButton(Admin1);
        AddDish->setObjectName(QString::fromUtf8("AddDish"));
        AddDish->setGeometry(QRect(20, 150, 141, 31));
        AddStock = new QPushButton(Admin1);
        AddStock->setObjectName(QString::fromUtf8("AddStock"));
        AddStock->setGeometry(QRect(20, 190, 141, 31));
        ChangeReq = new QPushButton(Admin1);
        ChangeReq->setObjectName(QString::fromUtf8("ChangeReq"));
        ChangeReq->setGeometry(QRect(20, 230, 141, 31));
        Bd = new QPushButton(Admin1);
        Bd->setObjectName(QString::fromUtf8("Bd"));
        Bd->setGeometry(QRect(20, 270, 141, 31));
        AddDishWid = new QWidget(Admin1);
        AddDishWid->setObjectName(QString::fromUtf8("AddDishWid"));
        AddDishWid->setGeometry(QRect(220, 60, 641, 511));
        AddIngWid = new QWidget(Admin1);
        AddIngWid->setObjectName(QString::fromUtf8("AddIngWid"));
        AddIngWid->setGeometry(QRect(220, 60, 641, 511));
        AddStockWid = new QWidget(Admin1);
        AddStockWid->setObjectName(QString::fromUtf8("AddStockWid"));
        AddStockWid->setGeometry(QRect(220, 60, 641, 511));
        ChangeReqWid = new QWidget(Admin1);
        ChangeReqWid->setObjectName(QString::fromUtf8("ChangeReqWid"));
        ChangeReqWid->setGeometry(QRect(220, 60, 641, 511));
        BdWid = new QWidget(Admin1);
        BdWid->setObjectName(QString::fromUtf8("BdWid"));
        BdWid->setGeometry(QRect(220, 60, 641, 511));
        hide = new QPushButton(Admin1);
        hide->setObjectName(QString::fromUtf8("hide"));
        hide->setGeometry(QRect(790, 80, 31, 23));
        line_3 = new QFrame(Admin1);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(210, 60, 20, 511));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line = new QFrame(Admin1);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(220, 46, 641, 31));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(Admin1);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(220, 560, 641, 21));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(Admin1);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(850, 60, 21, 511));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        tabWidget->addTab(Admin1, QString());
        BdWid->raise();
        ChangeReqWid->raise();
        AddStockWid->raise();
        AddDishWid->raise();
        AddIngWid->raise();
        RegWid->raise();
        LogOut->raise();
        Reg->raise();
        AddIng->raise();
        AddDish->raise();
        AddStock->raise();
        ChangeReq->raise();
        Bd->raise();
        hide->raise();
        line_3->raise();
        line->raise();
        line_2->raise();
        line_4->raise();
        Cook = new QWidget();
        Cook->setObjectName(QString::fromUtf8("Cook"));
        tabWidget->addTab(Cook, QString());
        Whk = new QWidget();
        Whk->setObjectName(QString::fromUtf8("Whk"));
        tabWidget->addTab(Whk, QString());
        Stocker = new QWidget();
        Stocker->setObjectName(QString::fromUtf8("Stocker"));
        tabWidget->addTab(Stocker, QString());

        retranslateUi(Admin);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Admin);
    } // setupUi

    void retranslateUi(QWidget *Admin)
    {
        Admin->setWindowTitle(QApplication::translate("Admin", "Form", nullptr));
        LogOut->setText(QApplication::translate("Admin", "\320\237\320\265\321\200\320\265\320\267\320\260\320\271\321\202\320\270", nullptr));
        Reg->setText(QApplication::translate("Admin", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        AddIng->setText(QApplication::translate("Admin", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\270\320\275\320\263\321\200\320\265\320\264\320\270\320\265\320\275\321\202", nullptr));
        AddDish->setText(QApplication::translate("Admin", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\261\320\273\321\216\320\264\320\276", nullptr));
        AddStock->setText(QApplication::translate("Admin", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\320\272\320\273\320\260\320\264", nullptr));
        ChangeReq->setText(QApplication::translate("Admin", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \321\202\321\200\320\265\320\261\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        Bd->setText(QApplication::translate("Admin", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\221\320\224", nullptr));
        hide->setText(QApplication::translate("Admin", "X", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Admin1), QApplication::translate("Admin", "\320\220\320\264\320\274\320\270\320\275", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Cook), QApplication::translate("Admin", "\320\237\320\276\320\262\320\260\321\200", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Whk), QApplication::translate("Admin", "\320\237\320\276\321\200\321\202\321\214\320\265", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Stocker), QApplication::translate("Admin", "\320\241\320\272\320\273\320\260\320\264\320\276\320\262\321\211\320\270\320\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Admin: public Ui_Admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H