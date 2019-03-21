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
#include <QtWidgets/QRadioButton>
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
    QTableView *tableView;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton;
    QPushButton *Hide;
    QPushButton *LogOut;
    QGroupBox *GBA4;
    QTableView *A4TVStocks;
    QPushButton *A4BApply;
    QLineEdit *A4LETitle;
    QLabel *A4LTitle;
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
    QGroupBox *A6GBTables;
    QRadioButton *A6RBauth;
    QRadioButton *A6RBdish;
    QRadioButton *A6RBguests;
    QRadioButton *A6RBingredients_stock;
    QRadioButton *A6RBingredients;
    QRadioButton *A6RBingredients_dish;
    QRadioButton *A6RBmenu;
    QRadioButton *A6RBinvoice;
    QRadioButton *A6RBinvoice_stock;
    QRadioButton *A6RBstock;
    QRadioButton *A6RBmenu_dish;
    QRadioButton *A6RBrole;
    QRadioButton *A6RBtype_menu;
    QPushButton *A6BI1;
    QPushButton *A6BI2;
    QPushButton *A6BI3;
    QPushButton *A6BI4;
    QPushButton *A6BI5;
    QPushButton *A6BI6;
    QPushButton *A6BI7;
    QPushButton *A6BI8;
    QPushButton *A6BI9;
    QLineEdit *A6LE4;
    QLabel *A6L4;
    QLineEdit *A6LE7;
    QLabel *A6L7;
    QLineEdit *A6LE8;
    QLabel *A6L8;
    QLineEdit *A6LE6;
    QLineEdit *A6LE5;
    QLabel *A6L5;
    QLabel *A6L6;
    QTableView *A6TV;
    QLabel *A6L1;
    QLineEdit *A6LE3;
    QLabel *A6L3;
    QLineEdit *A6LE2;
    QLineEdit *A6LE1;
    QLabel *A6L2;
    QWidget *Cook;
    QWidget *Whk;
    QWidget *Stocker;

    void setupUi(QWidget *Admin)
    {
        if (Admin->objectName().isEmpty())
            Admin->setObjectName(QString::fromUtf8("Admin"));
        Admin->resize(900, 639);
        tabWidget = new QTabWidget(Admin);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 881, 621));
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
        GBA1->setGeometry(QRect(180, 590, 641, 511));
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
        GBA2->setGeometry(QRect(190, 580, 641, 511));
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
        GBA5->setGeometry(QRect(220, 550, 641, 511));
        tableView = new QTableView(GBA5);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 20, 591, 411));
        lineEdit = new QLineEdit(GBA5);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(140, 440, 113, 20));
        lineEdit_2 = new QLineEdit(GBA5);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(20, 440, 113, 20));
        lineEdit_3 = new QLineEdit(GBA5);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(260, 440, 113, 20));
        lineEdit_4 = new QLineEdit(GBA5);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(380, 440, 113, 20));
        pushButton = new QPushButton(GBA5);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(240, 470, 75, 23));
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
        GBA4->setGeometry(QRect(210, 560, 641, 511));
        A4TVStocks = new QTableView(GBA4);
        A4TVStocks->setObjectName(QString::fromUtf8("A4TVStocks"));
        A4TVStocks->setGeometry(QRect(10, 20, 291, 471));
        A4BApply = new QPushButton(GBA4);
        A4BApply->setObjectName(QString::fromUtf8("A4BApply"));
        A4BApply->setGeometry(QRect(400, 280, 75, 23));
        A4LETitle = new QLineEdit(GBA4);
        A4LETitle->setObjectName(QString::fromUtf8("A4LETitle"));
        A4LETitle->setGeometry(QRect(440, 210, 113, 20));
        A4LTitle = new QLabel(GBA4);
        A4LTitle->setObjectName(QString::fromUtf8("A4LTitle"));
        A4LTitle->setGeometry(QRect(330, 210, 101, 16));
        GBA3 = new QGroupBox(Admin1);
        GBA3->setObjectName(QString::fromUtf8("GBA3"));
        GBA3->setGeometry(QRect(200, 570, 641, 511));
        A3LETitle = new QLineEdit(GBA3);
        A3LETitle->setObjectName(QString::fromUtf8("A3LETitle"));
        A3LETitle->setGeometry(QRect(190, 440, 111, 21));
        A3BApply = new QPushButton(GBA3);
        A3BApply->setObjectName(QString::fromUtf8("A3BApply"));
        A3BApply->setGeometry(QRect(190, 470, 141, 31));
        A3TVDish = new QTableView(GBA3);
        A3TVDish->setObjectName(QString::fromUtf8("A3TVDish"));
        A3TVDish->setGeometry(QRect(10, 30, 161, 381));
        A3LTitle = new QLabel(GBA3);
        A3LTitle->setObjectName(QString::fromUtf8("A3LTitle"));
        A3LTitle->setGeometry(QRect(190, 420, 81, 16));
        A3SAAllIngredients = new QScrollArea(GBA3);
        A3SAAllIngredients->setObjectName(QString::fromUtf8("A3SAAllIngredients"));
        A3SAAllIngredients->setGeometry(QRect(180, 30, 161, 381));
        A3SAAllIngredients->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 159, 379));
        A3SAAllIngredients->setWidget(scrollAreaWidgetContents);
        A3SASelectedIngredients = new QScrollArea(GBA3);
        A3SASelectedIngredients->setObjectName(QString::fromUtf8("A3SASelectedIngredients"));
        A3SASelectedIngredients->setGeometry(QRect(350, 30, 251, 381));
        A3SASelectedIngredients->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 249, 379));
        A3SASelectedIngredients->setWidget(scrollAreaWidgetContents_2);
        GBA6 = new QGroupBox(Admin1);
        GBA6->setObjectName(QString::fromUtf8("GBA6"));
        GBA6->setGeometry(QRect(220, 50, 641, 511));
        A6GBTables = new QGroupBox(GBA6);
        A6GBTables->setObjectName(QString::fromUtf8("A6GBTables"));
        A6GBTables->setGeometry(QRect(510, 30, 121, 281));
        A6RBauth = new QRadioButton(A6GBTables);
        A6RBauth->setObjectName(QString::fromUtf8("A6RBauth"));
        A6RBauth->setGeometry(QRect(10, 20, 82, 17));
        A6RBauth->setChecked(true);
        A6RBdish = new QRadioButton(A6GBTables);
        A6RBdish->setObjectName(QString::fromUtf8("A6RBdish"));
        A6RBdish->setGeometry(QRect(10, 40, 82, 17));
        A6RBguests = new QRadioButton(A6GBTables);
        A6RBguests->setObjectName(QString::fromUtf8("A6RBguests"));
        A6RBguests->setGeometry(QRect(10, 60, 82, 17));
        A6RBingredients_stock = new QRadioButton(A6GBTables);
        A6RBingredients_stock->setObjectName(QString::fromUtf8("A6RBingredients_stock"));
        A6RBingredients_stock->setGeometry(QRect(10, 120, 101, 17));
        A6RBingredients = new QRadioButton(A6GBTables);
        A6RBingredients->setObjectName(QString::fromUtf8("A6RBingredients"));
        A6RBingredients->setGeometry(QRect(10, 80, 82, 17));
        A6RBingredients_dish = new QRadioButton(A6GBTables);
        A6RBingredients_dish->setObjectName(QString::fromUtf8("A6RBingredients_dish"));
        A6RBingredients_dish->setGeometry(QRect(10, 100, 101, 17));
        A6RBmenu = new QRadioButton(A6GBTables);
        A6RBmenu->setObjectName(QString::fromUtf8("A6RBmenu"));
        A6RBmenu->setGeometry(QRect(10, 180, 82, 17));
        A6RBinvoice = new QRadioButton(A6GBTables);
        A6RBinvoice->setObjectName(QString::fromUtf8("A6RBinvoice"));
        A6RBinvoice->setGeometry(QRect(10, 140, 82, 17));
        A6RBinvoice_stock = new QRadioButton(A6GBTables);
        A6RBinvoice_stock->setObjectName(QString::fromUtf8("A6RBinvoice_stock"));
        A6RBinvoice_stock->setGeometry(QRect(10, 160, 81, 17));
        A6RBstock = new QRadioButton(A6GBTables);
        A6RBstock->setObjectName(QString::fromUtf8("A6RBstock"));
        A6RBstock->setGeometry(QRect(10, 240, 82, 17));
        A6RBmenu_dish = new QRadioButton(A6GBTables);
        A6RBmenu_dish->setObjectName(QString::fromUtf8("A6RBmenu_dish"));
        A6RBmenu_dish->setGeometry(QRect(10, 200, 82, 17));
        A6RBrole = new QRadioButton(A6GBTables);
        A6RBrole->setObjectName(QString::fromUtf8("A6RBrole"));
        A6RBrole->setGeometry(QRect(10, 220, 82, 17));
        A6RBtype_menu = new QRadioButton(A6GBTables);
        A6RBtype_menu->setObjectName(QString::fromUtf8("A6RBtype_menu"));
        A6RBtype_menu->setGeometry(QRect(10, 260, 82, 17));
        A6BI1 = new QPushButton(GBA6);
        A6BI1->setObjectName(QString::fromUtf8("A6BI1"));
        A6BI1->setGeometry(QRect(520, 320, 21, 23));
        QFont font;
        font.setFamily(QString::fromUtf8("Webdings"));
        font.setPointSize(12);
        A6BI1->setFont(font);
        A6BI2 = new QPushButton(GBA6);
        A6BI2->setObjectName(QString::fromUtf8("A6BI2"));
        A6BI2->setGeometry(QRect(540, 320, 21, 23));
        A6BI2->setFont(font);
        A6BI3 = new QPushButton(GBA6);
        A6BI3->setObjectName(QString::fromUtf8("A6BI3"));
        A6BI3->setGeometry(QRect(560, 320, 21, 23));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Wingdings 2"));
        font1.setPointSize(10);
        A6BI3->setFont(font1);
        A6BI4 = new QPushButton(GBA6);
        A6BI4->setObjectName(QString::fromUtf8("A6BI4"));
        A6BI4->setGeometry(QRect(580, 320, 21, 23));
        A6BI4->setFont(font);
        A6BI5 = new QPushButton(GBA6);
        A6BI5->setObjectName(QString::fromUtf8("A6BI5"));
        A6BI5->setGeometry(QRect(600, 320, 21, 23));
        A6BI5->setFont(font);
        A6BI6 = new QPushButton(GBA6);
        A6BI6->setObjectName(QString::fromUtf8("A6BI6"));
        A6BI6->setGeometry(QRect(520, 340, 21, 23));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Wingdings 2"));
        font2.setPointSize(12);
        A6BI6->setFont(font2);
        A6BI7 = new QPushButton(GBA6);
        A6BI7->setObjectName(QString::fromUtf8("A6BI7"));
        A6BI7->setGeometry(QRect(540, 340, 21, 23));
        A6BI7->setFont(font2);
        A6BI8 = new QPushButton(GBA6);
        A6BI8->setObjectName(QString::fromUtf8("A6BI8"));
        A6BI8->setGeometry(QRect(580, 340, 21, 23));
        A6BI8->setFont(font2);
        A6BI9 = new QPushButton(GBA6);
        A6BI9->setObjectName(QString::fromUtf8("A6BI9"));
        A6BI9->setGeometry(QRect(600, 340, 21, 23));
        A6BI9->setFont(font2);
        A6LE4 = new QLineEdit(GBA6);
        A6LE4->setObjectName(QString::fromUtf8("A6LE4"));
        A6LE4->setGeometry(QRect(190, 480, 51, 20));
        A6L4 = new QLabel(GBA6);
        A6L4->setObjectName(QString::fromUtf8("A6L4"));
        A6L4->setGeometry(QRect(190, 460, 47, 13));
        A6LE7 = new QLineEdit(GBA6);
        A6LE7->setObjectName(QString::fromUtf8("A6LE7"));
        A6LE7->setGeometry(QRect(370, 480, 51, 20));
        A6L7 = new QLabel(GBA6);
        A6L7->setObjectName(QString::fromUtf8("A6L7"));
        A6L7->setGeometry(QRect(370, 460, 47, 13));
        A6LE8 = new QLineEdit(GBA6);
        A6LE8->setObjectName(QString::fromUtf8("A6LE8"));
        A6LE8->setGeometry(QRect(430, 480, 51, 20));
        A6L8 = new QLabel(GBA6);
        A6L8->setObjectName(QString::fromUtf8("A6L8"));
        A6L8->setGeometry(QRect(430, 460, 47, 13));
        A6LE6 = new QLineEdit(GBA6);
        A6LE6->setObjectName(QString::fromUtf8("A6LE6"));
        A6LE6->setGeometry(QRect(310, 480, 51, 20));
        A6LE5 = new QLineEdit(GBA6);
        A6LE5->setObjectName(QString::fromUtf8("A6LE5"));
        A6LE5->setGeometry(QRect(250, 480, 51, 20));
        A6L5 = new QLabel(GBA6);
        A6L5->setObjectName(QString::fromUtf8("A6L5"));
        A6L5->setGeometry(QRect(250, 460, 47, 13));
        A6L6 = new QLabel(GBA6);
        A6L6->setObjectName(QString::fromUtf8("A6L6"));
        A6L6->setGeometry(QRect(310, 460, 47, 13));
        A6TV = new QTableView(GBA6);
        A6TV->setObjectName(QString::fromUtf8("A6TV"));
        A6TV->setGeometry(QRect(10, 20, 491, 431));
        A6L1 = new QLabel(GBA6);
        A6L1->setObjectName(QString::fromUtf8("A6L1"));
        A6L1->setGeometry(QRect(10, 460, 47, 13));
        A6LE3 = new QLineEdit(GBA6);
        A6LE3->setObjectName(QString::fromUtf8("A6LE3"));
        A6LE3->setGeometry(QRect(130, 480, 51, 20));
        A6L3 = new QLabel(GBA6);
        A6L3->setObjectName(QString::fromUtf8("A6L3"));
        A6L3->setGeometry(QRect(130, 460, 47, 13));
        A6LE2 = new QLineEdit(GBA6);
        A6LE2->setObjectName(QString::fromUtf8("A6LE2"));
        A6LE2->setGeometry(QRect(70, 480, 51, 20));
        A6LE1 = new QLineEdit(GBA6);
        A6LE1->setObjectName(QString::fromUtf8("A6LE1"));
        A6LE1->setGeometry(QRect(10, 480, 51, 20));
        A6L2 = new QLabel(GBA6);
        A6L2->setObjectName(QString::fromUtf8("A6L2"));
        A6L2->setGeometry(QRect(70, 460, 47, 13));
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
        GBA5->setTitle(QApplication::translate("Admin", "\320\230\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\265 \321\202\321\200\320\265\320\261\320\276\320\262\320\260\320\275\320\270\320\271 \320\264\320\273\321\217 \320\270\320\275\320\263\321\200\320\265\320\264\320\270\320\265\320\275\321\202\320\276\320\262", nullptr));
        pushButton->setText(QApplication::translate("Admin", "PushButton", nullptr));
        Hide->setText(QApplication::translate("Admin", "\320\245", nullptr));
        LogOut->setText(QApplication::translate("Admin", "\320\237\320\265\321\200\320\265\320\267\320\260\320\271\321\202\320\270", nullptr));
        GBA4->setTitle(QApplication::translate("Admin", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\275\320\276\320\262\320\276\320\263\320\276 \321\201\320\272\320\273\320\260\320\264\320\260", nullptr));
        A4BApply->setText(QApplication::translate("Admin", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        A4LETitle->setPlaceholderText(QApplication::translate("Admin", "\320\235\320\265 \320\262\320\262\320\265\320\264\320\265\320\275\320\276", nullptr));
        A4LTitle->setText(QApplication::translate("Admin", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\201\320\272\320\273\320\260\320\264\320\260", nullptr));
        GBA3->setTitle(QApplication::translate("Admin", "\320\224\320\276\320\261\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\275\320\276\320\262\320\276\320\263\320\276 \320\261\320\273\321\216\320\264\320\260", nullptr));
        A3LETitle->setPlaceholderText(QApplication::translate("Admin", "\320\235\320\265 \320\262\321\213\320\261\321\200\320\260\320\275\320\276", nullptr));
        A3BApply->setText(QApplication::translate("Admin", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
        A3LTitle->setText(QApplication::translate("Admin", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        GBA6->setTitle(QApplication::translate("Admin", "\320\243\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\320\265 \320\261\320\260\320\267\320\276\320\271 \320\264\320\260\320\275\320\275\321\213\321\205", nullptr));
        A6GBTables->setTitle(QApplication::translate("Admin", "\320\242\320\260\320\261\320\273\320\270\321\206\320\260", nullptr));
        A6RBauth->setText(QApplication::translate("Admin", "auth", nullptr));
        A6RBdish->setText(QApplication::translate("Admin", "dish", nullptr));
        A6RBguests->setText(QApplication::translate("Admin", "guests", nullptr));
        A6RBingredients_stock->setText(QApplication::translate("Admin", "ingredients-stock", nullptr));
        A6RBingredients->setText(QApplication::translate("Admin", "ingredients", nullptr));
        A6RBingredients_dish->setText(QApplication::translate("Admin", "ingredients-dish", nullptr));
        A6RBmenu->setText(QApplication::translate("Admin", "menu", nullptr));
        A6RBinvoice->setText(QApplication::translate("Admin", "invoice", nullptr));
        A6RBinvoice_stock->setText(QApplication::translate("Admin", "invoice-stock", nullptr));
        A6RBstock->setText(QApplication::translate("Admin", "stock", nullptr));
        A6RBmenu_dish->setText(QApplication::translate("Admin", "menu-dish", nullptr));
        A6RBrole->setText(QApplication::translate("Admin", "role", nullptr));
        A6RBtype_menu->setText(QApplication::translate("Admin", "type-menu", nullptr));
        A6BI1->setText(QApplication::translate("Admin", "\357\200\271", nullptr));
        A6BI2->setText(QApplication::translate("Admin", "\357\200\263", nullptr));
        A6BI3->setText(QApplication::translate("Admin", "\357\200\241", nullptr));
        A6BI4->setText(QApplication::translate("Admin", "\357\200\264", nullptr));
        A6BI5->setText(QApplication::translate("Admin", "\357\200\272", nullptr));
        A6BI6->setText(QApplication::translate("Admin", "\357\200\262", nullptr));
        A6BI7->setText(QApplication::translate("Admin", "\357\200\263", nullptr));
        A6BI8->setText(QApplication::translate("Admin", "\357\201\220", nullptr));
        A6BI9->setText(QApplication::translate("Admin", "\357\201\217", nullptr));
        A6L4->setText(QApplication::translate("Admin", "Text4", nullptr));
        A6L7->setText(QApplication::translate("Admin", "Text7", nullptr));
        A6L8->setText(QApplication::translate("Admin", "Text8", nullptr));
        A6L5->setText(QApplication::translate("Admin", "Text5", nullptr));
        A6L6->setText(QApplication::translate("Admin", "Text6", nullptr));
        A6L1->setText(QApplication::translate("Admin", "Text1", nullptr));
        A6L3->setText(QApplication::translate("Admin", "Text3", nullptr));
        A6L2->setText(QApplication::translate("Admin", "Text2", nullptr));
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
