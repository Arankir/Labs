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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Admin
{
public:
    QTabWidget *tabWidget;
    QWidget *Admin1;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *ABShow1;
    QPushButton *ABShow2;
    QPushButton *ABShow3;
    QPushButton *ABShow4;
    QPushButton *ABShow5;
    QPushButton *ABShow6;
    QGroupBox *GBA1;
    QLabel *A1LLogin;
    QLabel *A1LPassword;
    QComboBox *A1CBRole;
    QLineEdit *A1LELogin;
    QLineEdit *A1LEPassword;
    QPushButton *A1BApply;
    QLabel *A1LRole;
    QTableView *A1TVUsers;
    QGroupBox *GBA2;
    QLineEdit *A2LEtitle;
    QTableView *A2TVIngredients;
    QPushButton *A2BApply;
    QLabel *A2Ltitle;
    QLineEdit *A2LEunit;
    QLabel *A2Lneedonstock;
    QLabel *A2Lunit;
    QLineEdit *A2LEneedonstock;
    QGroupBox *GBA5;
    QPushButton *Hide;
    QPushButton *LogOut;
    QGroupBox *GBA4;
    QGroupBox *GBA3;
    QLineEdit *A3LETitle;
    QPushButton *A3BApply;
    QTableView *A3TVDish;
    QLabel *A3LTitle;
    QScrollArea *A3SAAllIngredients;
    QWidget *scrollAreaWidgetContents;
    QScrollArea *A3SASelectedIngredients;
    QWidget *scrollAreaWidgetContents_2;
    QGroupBox *GBA6;
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
        verticalLayoutWidget = new QWidget(Admin1);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 0, 161, 601));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        ABShow1 = new QPushButton(verticalLayoutWidget);
        ABShow1->setObjectName(QString::fromUtf8("ABShow1"));

        verticalLayout->addWidget(ABShow1);

        ABShow2 = new QPushButton(verticalLayoutWidget);
        ABShow2->setObjectName(QString::fromUtf8("ABShow2"));

        verticalLayout->addWidget(ABShow2);

        ABShow3 = new QPushButton(verticalLayoutWidget);
        ABShow3->setObjectName(QString::fromUtf8("ABShow3"));

        verticalLayout->addWidget(ABShow3);

        ABShow4 = new QPushButton(verticalLayoutWidget);
        ABShow4->setObjectName(QString::fromUtf8("ABShow4"));

        verticalLayout->addWidget(ABShow4);

        ABShow5 = new QPushButton(verticalLayoutWidget);
        ABShow5->setObjectName(QString::fromUtf8("ABShow5"));

        verticalLayout->addWidget(ABShow5);

        ABShow6 = new QPushButton(verticalLayoutWidget);
        ABShow6->setObjectName(QString::fromUtf8("ABShow6"));

        verticalLayout->addWidget(ABShow6);

        GBA1 = new QGroupBox(Admin1);
        GBA1->setObjectName(QString::fromUtf8("GBA1"));
        GBA1->setGeometry(QRect(180, 570, 641, 511));
        A1LLogin = new QLabel(GBA1);
        A1LLogin->setObjectName(QString::fromUtf8("A1LLogin"));
        A1LLogin->setGeometry(QRect(350, 180, 41, 21));
        A1LPassword = new QLabel(GBA1);
        A1LPassword->setObjectName(QString::fromUtf8("A1LPassword"));
        A1LPassword->setGeometry(QRect(350, 220, 51, 16));
        A1CBRole = new QComboBox(GBA1);
        A1CBRole->addItem(QString());
        A1CBRole->addItem(QString());
        A1CBRole->addItem(QString());
        A1CBRole->addItem(QString());
        A1CBRole->setObjectName(QString::fromUtf8("A1CBRole"));
        A1CBRole->setGeometry(QRect(460, 260, 111, 21));
        A1LELogin = new QLineEdit(GBA1);
        A1LELogin->setObjectName(QString::fromUtf8("A1LELogin"));
        A1LELogin->setGeometry(QRect(460, 180, 111, 21));
        A1LEPassword = new QLineEdit(GBA1);
        A1LEPassword->setObjectName(QString::fromUtf8("A1LEPassword"));
        A1LEPassword->setGeometry(QRect(460, 220, 111, 21));
        A1BApply = new QPushButton(GBA1);
        A1BApply->setObjectName(QString::fromUtf8("A1BApply"));
        A1BApply->setGeometry(QRect(380, 310, 141, 31));
        A1LRole = new QLabel(GBA1);
        A1LRole->setObjectName(QString::fromUtf8("A1LRole"));
        A1LRole->setGeometry(QRect(350, 260, 81, 16));
        A1TVUsers = new QTableView(GBA1);
        A1TVUsers->setObjectName(QString::fromUtf8("A1TVUsers"));
        A1TVUsers->setGeometry(QRect(10, 30, 291, 471));
        GBA2 = new QGroupBox(Admin1);
        GBA2->setObjectName(QString::fromUtf8("GBA2"));
        GBA2->setGeometry(QRect(230, 550, 641, 511));
        A2LEtitle = new QLineEdit(GBA2);
        A2LEtitle->setObjectName(QString::fromUtf8("A2LEtitle"));
        A2LEtitle->setGeometry(QRect(100, 440, 111, 21));
        A2TVIngredients = new QTableView(GBA2);
        A2TVIngredients->setObjectName(QString::fromUtf8("A2TVIngredients"));
        A2TVIngredients->setGeometry(QRect(10, 30, 601, 381));
        A2BApply = new QPushButton(GBA2);
        A2BApply->setObjectName(QString::fromUtf8("A2BApply"));
        A2BApply->setGeometry(QRect(230, 470, 141, 31));
        A2Ltitle = new QLabel(GBA2);
        A2Ltitle->setObjectName(QString::fromUtf8("A2Ltitle"));
        A2Ltitle->setGeometry(QRect(100, 420, 81, 16));
        A2LEunit = new QLineEdit(GBA2);
        A2LEunit->setObjectName(QString::fromUtf8("A2LEunit"));
        A2LEunit->setGeometry(QRect(400, 440, 111, 21));
        A2Lneedonstock = new QLabel(GBA2);
        A2Lneedonstock->setObjectName(QString::fromUtf8("A2Lneedonstock"));
        A2Lneedonstock->setGeometry(QRect(220, 420, 171, 21));
        A2Lunit = new QLabel(GBA2);
        A2Lunit->setObjectName(QString::fromUtf8("A2Lunit"));
        A2Lunit->setGeometry(QRect(400, 420, 150, 16));
        A2LEneedonstock = new QLineEdit(GBA2);
        A2LEneedonstock->setObjectName(QString::fromUtf8("A2LEneedonstock"));
        A2LEneedonstock->setGeometry(QRect(220, 440, 111, 21));
        GBA5 = new QGroupBox(Admin1);
        GBA5->setObjectName(QString::fromUtf8("GBA5"));
        GBA5->setGeometry(QRect(840, 110, 641, 511));
        Hide = new QPushButton(Admin1);
        Hide->setObjectName(QString::fromUtf8("Hide"));
        Hide->setEnabled(true);
        Hide->setGeometry(QRect(830, 60, 21, 23));
        Hide->setLayoutDirection(Qt::LeftToRight);
        LogOut = new QPushButton(Admin1);
        LogOut->setObjectName(QString::fromUtf8("LogOut"));
        LogOut->setGeometry(QRect(800, 10, 71, 23));
        GBA4 = new QGroupBox(Admin1);
        GBA4->setObjectName(QString::fromUtf8("GBA4"));
        GBA4->setGeometry(QRect(830, 130, 641, 511));
        GBA3 = new QGroupBox(Admin1);
        GBA3->setObjectName(QString::fromUtf8("GBA3"));
        GBA3->setGeometry(QRect(220, 40, 641, 511));
        A3LETitle = new QLineEdit(GBA3);
        A3LETitle->setObjectName(QString::fromUtf8("A3LETitle"));
        A3LETitle->setGeometry(QRect(190, 440, 111, 21));
        A3BApply = new QPushButton(GBA3);
        A3BApply->setObjectName(QString::fromUtf8("A3BApply"));
        A3BApply->setGeometry(QRect(190, 470, 141, 31));
        A3TVDish = new QTableView(GBA3);
        A3TVDish->setObjectName(QString::fromUtf8("A3TVDish"));
        A3TVDish->setGeometry(QRect(10, 30, 171, 381));
        A3LTitle = new QLabel(GBA3);
        A3LTitle->setObjectName(QString::fromUtf8("A3LTitle"));
        A3LTitle->setGeometry(QRect(190, 420, 81, 16));
        A3SAAllIngredients = new QScrollArea(GBA3);
        A3SAAllIngredients->setObjectName(QString::fromUtf8("A3SAAllIngredients"));
        A3SAAllIngredients->setGeometry(QRect(190, 30, 201, 381));
        A3SAAllIngredients->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 199, 379));
        A3SAAllIngredients->setWidget(scrollAreaWidgetContents);
        A3SASelectedIngredients = new QScrollArea(GBA3);
        A3SASelectedIngredients->setObjectName(QString::fromUtf8("A3SASelectedIngredients"));
        A3SASelectedIngredients->setGeometry(QRect(400, 30, 201, 381));
        A3SASelectedIngredients->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 199, 379));
        A3SASelectedIngredients->setWidget(scrollAreaWidgetContents_2);
        GBA6 = new QGroupBox(Admin1);
        GBA6->setObjectName(QString::fromUtf8("GBA6"));
        GBA6->setGeometry(QRect(850, 90, 641, 511));
        tabWidget->addTab(Admin1, QString());
        verticalLayoutWidget->raise();
        LogOut->raise();
        Hide->raise();
        GBA1->raise();
        GBA2->raise();
        GBA3->raise();
        GBA4->raise();
        GBA5->raise();
        GBA6->raise();
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
        ABShow1->setText(QApplication::translate("Admin", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        ABShow2->setText(QApplication::translate("Admin", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\270\320\275\320\263\321\200\320\265\320\264\320\270\320\265\320\275\321\202", nullptr));
        ABShow3->setText(QApplication::translate("Admin", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\261\320\273\321\216\320\264\320\276", nullptr));
        ABShow4->setText(QApplication::translate("Admin", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\320\272\320\273\320\260\320\264", nullptr));
        ABShow5->setText(QApplication::translate("Admin", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \321\202\321\200\320\265\320\261\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        ABShow6->setText(QApplication::translate("Admin", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\221\320\224", nullptr));
        GBA1->setTitle(QApplication::translate("Admin", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\320\260\321\206\320\270\321\217 \320\275\320\276\320\262\320\276\320\263\320\276 \320\277\320\276\320\273\321\214\320\267\320\276\320\262\320\260\321\202\320\265\320\273\321\217", nullptr));
        A1LLogin->setText(QApplication::translate("Admin", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        A1LPassword->setText(QApplication::translate("Admin", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
        A1CBRole->setItemText(0, QApplication::translate("Admin", "\320\237\320\276\320\262\320\260\321\200", nullptr));
        A1CBRole->setItemText(1, QApplication::translate("Admin", "\320\241\320\272\320\273\320\260\320\264\320\276\320\262\321\211\320\270\320\272", nullptr));
        A1CBRole->setItemText(2, QApplication::translate("Admin", "\320\237\320\276\321\200\321\202\321\214\320\265", nullptr));
        A1CBRole->setItemText(3, QApplication::translate("Admin", "\320\220\320\264\320\274\320\270\320\275\320\270\321\201\321\202\321\200\320\260\321\202\320\276\321\200", nullptr));

        A1LELogin->setPlaceholderText(QApplication::translate("Admin", "\320\235\320\265 \320\262\321\213\320\261\321\200\320\260\320\275\320\276", nullptr));
        A1LEPassword->setPlaceholderText(QApplication::translate("Admin", "\320\235\320\265 \320\262\321\213\320\261\321\200\320\260\320\275\320\276", nullptr));
        A1BApply->setText(QApplication::translate("Admin", "\320\227\320\260\321\200\320\265\320\263\320\265\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        A1LRole->setText(QApplication::translate("Admin", "\320\237\321\200\320\260\320\262\320\260 \320\264\320\276\321\201\321\202\321\203\320\277\320\260", nullptr));
        GBA2->setTitle(QApplication::translate("Admin", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\275\320\276\320\262\320\276\320\263\320\276 \320\270\320\275\320\263\321\200\320\265\320\264\320\270\320\265\320\275\321\202\320\260", nullptr));
        A2LEtitle->setPlaceholderText(QApplication::translate("Admin", "\320\235\320\265 \320\262\321\213\320\261\321\200\320\260\320\275\320\276", nullptr));
        A2BApply->setText(QApplication::translate("Admin", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        A2Ltitle->setText(QApplication::translate("Admin", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        A2LEunit->setPlaceholderText(QApplication::translate("Admin", "\320\235\320\265 \320\262\321\213\320\261\321\200\320\260\320\275\320\276", nullptr));
        A2Lneedonstock->setText(QApplication::translate("Admin", "\320\235\320\265\320\276\320\261\321\205\320\276\320\264\320\270\320\274\320\276\320\265 \320\272\320\276\320\273-\320\262\320\276 \320\275\320\260 \321\201\320\272\320\273\320\260\320\264\320\260\321\205", nullptr));
        A2Lunit->setText(QApplication::translate("Admin", "\320\221\321\203\320\264\320\265\321\202 \320\270\320\267\320\274\320\265\321\200\321\217\321\202\321\214\321\201\321\217 \320\262", nullptr));
        A2LEneedonstock->setPlaceholderText(QApplication::translate("Admin", "\320\235\320\265 \320\262\321\213\320\261\321\200\320\260\320\275\320\276", nullptr));
        GBA5->setTitle(QApplication::translate("Admin", "\320\230\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\265 \321\202\321\200\320\265\320\264\320\276\320\262\320\260\320\275\320\270\320\271 \320\264\320\273\321\217 \320\270\320\275\320\263\321\200\320\265\320\264\320\270\320\265\320\275\321\202\320\276\320\262", nullptr));
        Hide->setText(QApplication::translate("Admin", "\320\245", nullptr));
        LogOut->setText(QApplication::translate("Admin", "\320\237\320\265\321\200\320\265\320\267\320\260\320\271\321\202\320\270", nullptr));
        GBA4->setTitle(QApplication::translate("Admin", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\275\320\276\320\262\320\276\320\263\320\276 \321\201\320\272\320\273\320\260\320\264\320\260", nullptr));
        GBA3->setTitle(QApplication::translate("Admin", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\275\320\276\320\262\320\276\320\263\320\276 \320\261\320\273\321\216\320\264\320\260", nullptr));
        A3LETitle->setPlaceholderText(QApplication::translate("Admin", "\320\235\320\265 \320\262\321\213\320\261\321\200\320\260\320\275\320\276", nullptr));
        A3BApply->setText(QApplication::translate("Admin", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        A3LTitle->setText(QApplication::translate("Admin", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        GBA6->setTitle(QApplication::translate("Admin", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\261\320\260\320\267\320\276\320\271 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Admin1), QApplication::translate("Admin", "\320\220\320\264\320\274\320\270\320\275", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Cook), QApplication::translate("Admin", "\320\237\320\276\320\262\320\260\321\200", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Whk), QApplication::translate("Admin", "\320\241\320\272\320\273\320\260\320\264\320\276\320\262\321\211\320\270\320\272", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(Stocker), QApplication::translate("Admin", "\320\237\320\276\321\200\321\202\321\214\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Admin: public Ui_Admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H
