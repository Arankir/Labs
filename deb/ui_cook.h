/********************************************************************************
** Form generated from reading UI file 'cook.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COOK_H
#define UI_COOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Cook
{
public:
    QPushButton *LogOut;
    QPushButton *Hide;
    QGroupBox *GBC1;
    QScrollArea *C1SA1;
    QWidget *scrollAreaWidgetContents;
    QScrollArea *C1SA2;
    QWidget *scrollAreaWidgetContents_2;
    QGroupBox *GBC3;
    QRadioButton *other;
    QScrollArea *DishMenu;
    QWidget *scrollAreaWidgetContents_3;
    QLabel *labelCount;
    QRadioButton *breakfast;
    QCheckBox *CountBox;
    QPushButton *Cancel;
    QDateEdit *dateEdit;
    QLineEdit *CountEdit;
    QScrollArea *AllDish;
    QWidget *scrollAreaWidgetContents_4;
    QRadioButton *dinner;
    QRadioButton *lunch;
    QPushButton *Applay;
    QGroupBox *GBC4;
    QScrollArea *C4SA1;
    QWidget *scrollAreaWidgetContents_5;
    QRadioButton *C4RB1;
    QCalendarWidget *C4Calendar;
    QRadioButton *C4RB4;
    QRadioButton *C4RB3;
    QRadioButton *C4RB2;
    QPushButton *C4BSearch;
    QLabel *C4LAmount;
    QGroupBox *GBC2;
    QLabel *label_2;
    QLabel *label;
    QPushButton *C2BSearch;
    QTableView *C2T1;
    QComboBox *C2CB1;
    QComboBox *C2CB2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *whatchDish;
    QPushButton *whatchIngredients;
    QPushButton *createMenu;
    QPushButton *prevMenu;

    void setupUi(QWidget *Cook)
    {
        if (Cook->objectName().isEmpty())
            Cook->setObjectName(QString::fromUtf8("Cook"));
        Cook->resize(829, 577);
        LogOut = new QPushButton(Cook);
        LogOut->setObjectName(QString::fromUtf8("LogOut"));
        LogOut->setGeometry(QRect(750, 10, 71, 23));
        Hide = new QPushButton(Cook);
        Hide->setObjectName(QString::fromUtf8("Hide"));
        Hide->setEnabled(true);
        Hide->setGeometry(QRect(780, 60, 21, 23));
        Hide->setLayoutDirection(Qt::LeftToRight);
        GBC1 = new QGroupBox(Cook);
        GBC1->setObjectName(QString::fromUtf8("GBC1"));
        GBC1->setGeometry(QRect(170, 510, 641, 511));
        C1SA1 = new QScrollArea(GBC1);
        C1SA1->setObjectName(QString::fromUtf8("C1SA1"));
        C1SA1->setGeometry(QRect(30, 40, 261, 441));
        C1SA1->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 259, 439));
        C1SA1->setWidget(scrollAreaWidgetContents);
        C1SA2 = new QScrollArea(GBC1);
        C1SA2->setObjectName(QString::fromUtf8("C1SA2"));
        C1SA2->setGeometry(QRect(310, 40, 291, 441));
        C1SA2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 289, 439));
        C1SA2->setWidget(scrollAreaWidgetContents_2);
        GBC3 = new QGroupBox(Cook);
        GBC3->setObjectName(QString::fromUtf8("GBC3"));
        GBC3->setGeometry(QRect(480, 220, 641, 511));
        other = new QRadioButton(GBC3);
        other->setObjectName(QString::fromUtf8("other"));
        other->setGeometry(QRect(30, 470, 82, 17));
        DishMenu = new QScrollArea(GBC3);
        DishMenu->setObjectName(QString::fromUtf8("DishMenu"));
        DishMenu->setGeometry(QRect(340, 30, 201, 331));
        DishMenu->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 199, 329));
        DishMenu->setWidget(scrollAreaWidgetContents_3);
        labelCount = new QLabel(GBC3);
        labelCount->setObjectName(QString::fromUtf8("labelCount"));
        labelCount->setGeometry(QRect(150, 390, 71, 16));
        breakfast = new QRadioButton(GBC3);
        breakfast->setObjectName(QString::fromUtf8("breakfast"));
        breakfast->setGeometry(QRect(30, 380, 82, 17));
        CountBox = new QCheckBox(GBC3);
        CountBox->setObjectName(QString::fromUtf8("CountBox"));
        CountBox->setGeometry(QRect(150, 420, 171, 31));
        CountBox->setAutoExclusive(false);
        Cancel = new QPushButton(GBC3);
        Cancel->setObjectName(QString::fromUtf8("Cancel"));
        Cancel->setGeometry(QRect(350, 370, 75, 23));
        dateEdit = new QDateEdit(GBC3);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(150, 460, 110, 22));
        dateEdit->setCalendarPopup(true);
        CountEdit = new QLineEdit(GBC3);
        CountEdit->setObjectName(QString::fromUtf8("CountEdit"));
        CountEdit->setGeometry(QRect(220, 390, 71, 20));
        AllDish = new QScrollArea(GBC3);
        AllDish->setObjectName(QString::fromUtf8("AllDish"));
        AllDish->setGeometry(QRect(30, 30, 221, 331));
        AllDish->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_4"));
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 219, 329));
        AllDish->setWidget(scrollAreaWidgetContents_4);
        dinner = new QRadioButton(GBC3);
        dinner->setObjectName(QString::fromUtf8("dinner"));
        dinner->setGeometry(QRect(30, 440, 82, 17));
        lunch = new QRadioButton(GBC3);
        lunch->setObjectName(QString::fromUtf8("lunch"));
        lunch->setGeometry(QRect(30, 410, 82, 17));
        Applay = new QPushButton(GBC3);
        Applay->setObjectName(QString::fromUtf8("Applay"));
        Applay->setGeometry(QRect(450, 370, 75, 23));
        GBC4 = new QGroupBox(Cook);
        GBC4->setObjectName(QString::fromUtf8("GBC4"));
        GBC4->setGeometry(QRect(200, 480, 641, 511));
        C4SA1 = new QScrollArea(GBC4);
        C4SA1->setObjectName(QString::fromUtf8("C4SA1"));
        C4SA1->setGeometry(QRect(380, 40, 201, 391));
        C4SA1->setWidgetResizable(true);
        scrollAreaWidgetContents_5 = new QWidget();
        scrollAreaWidgetContents_5->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_5"));
        scrollAreaWidgetContents_5->setGeometry(QRect(0, 0, 199, 389));
        C4SA1->setWidget(scrollAreaWidgetContents_5);
        C4RB1 = new QRadioButton(GBC4);
        C4RB1->setObjectName(QString::fromUtf8("C4RB1"));
        C4RB1->setGeometry(QRect(40, 260, 82, 17));
        C4RB1->setChecked(true);
        C4Calendar = new QCalendarWidget(GBC4);
        C4Calendar->setObjectName(QString::fromUtf8("C4Calendar"));
        C4Calendar->setGeometry(QRect(30, 40, 248, 183));
        QFont font;
        font.setKerning(true);
        font.setStyleStrategy(QFont::PreferDefault);
        C4Calendar->setFont(font);
        C4Calendar->setSelectionMode(QCalendarWidget::SingleSelection);
        C4RB4 = new QRadioButton(GBC4);
        C4RB4->setObjectName(QString::fromUtf8("C4RB4"));
        C4RB4->setGeometry(QRect(40, 320, 82, 17));
        C4RB3 = new QRadioButton(GBC4);
        C4RB3->setObjectName(QString::fromUtf8("C4RB3"));
        C4RB3->setGeometry(QRect(40, 300, 82, 17));
        C4RB2 = new QRadioButton(GBC4);
        C4RB2->setObjectName(QString::fromUtf8("C4RB2"));
        C4RB2->setGeometry(QRect(40, 280, 82, 17));
        C4BSearch = new QPushButton(GBC4);
        C4BSearch->setObjectName(QString::fromUtf8("C4BSearch"));
        C4BSearch->setGeometry(QRect(40, 350, 75, 23));
        C4LAmount = new QLabel(GBC4);
        C4LAmount->setObjectName(QString::fromUtf8("C4LAmount"));
        C4LAmount->setGeometry(QRect(380, 440, 171, 16));
        GBC2 = new QGroupBox(Cook);
        GBC2->setObjectName(QString::fromUtf8("GBC2"));
        GBC2->setGeometry(QRect(230, 450, 641, 511));
        label_2 = new QLabel(GBC2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(410, 100, 71, 16));
        label = new QLabel(GBC2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(410, 70, 71, 16));
        C2BSearch = new QPushButton(GBC2);
        C2BSearch->setObjectName(QString::fromUtf8("C2BSearch"));
        C2BSearch->setGeometry(QRect(480, 160, 75, 23));
        C2T1 = new QTableView(GBC2);
        C2T1->setObjectName(QString::fromUtf8("C2T1"));
        C2T1->setGeometry(QRect(20, 30, 381, 481));
        C2CB1 = new QComboBox(GBC2);
        C2CB1->setObjectName(QString::fromUtf8("C2CB1"));
        C2CB1->setGeometry(QRect(490, 70, 141, 22));
        C2CB2 = new QComboBox(GBC2);
        C2CB2->setObjectName(QString::fromUtf8("C2CB2"));
        C2CB2->setGeometry(QRect(490, 100, 141, 22));
        verticalLayoutWidget = new QWidget(Cook);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 0, 151, 581));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        whatchDish = new QPushButton(verticalLayoutWidget);
        whatchDish->setObjectName(QString::fromUtf8("whatchDish"));

        verticalLayout->addWidget(whatchDish);

        whatchIngredients = new QPushButton(verticalLayoutWidget);
        whatchIngredients->setObjectName(QString::fromUtf8("whatchIngredients"));

        verticalLayout->addWidget(whatchIngredients);

        createMenu = new QPushButton(verticalLayoutWidget);
        createMenu->setObjectName(QString::fromUtf8("createMenu"));

        verticalLayout->addWidget(createMenu);

        prevMenu = new QPushButton(verticalLayoutWidget);
        prevMenu->setObjectName(QString::fromUtf8("prevMenu"));

        verticalLayout->addWidget(prevMenu);

        LogOut->raise();
        GBC1->raise();
        GBC3->raise();
        GBC4->raise();
        GBC2->raise();
        Hide->raise();
        verticalLayoutWidget->raise();

        retranslateUi(Cook);

        QMetaObject::connectSlotsByName(Cook);
    } // setupUi

    void retranslateUi(QWidget *Cook)
    {
        Cook->setWindowTitle(QApplication::translate("Cook", "Form", nullptr));
        LogOut->setText(QApplication::translate("Cook", "\320\237\320\265\321\200\320\265\320\267\320\260\320\271\321\202\320\270", nullptr));
        Hide->setText(QApplication::translate("Cook", "\320\245", nullptr));
        GBC1->setTitle(QApplication::translate("Cook", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \320\261\320\273\321\216\320\264", nullptr));
        GBC3->setTitle(QApplication::translate("Cook", "\320\241\320\276\320\267\320\264\320\260\320\275\320\270\320\265 \320\274\320\265\320\275\321\216", nullptr));
        other->setText(QApplication::translate("Cook", "\320\264\321\200\321\203\320\263\320\276\320\265", nullptr));
        labelCount->setText(QApplication::translate("Cook", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        breakfast->setText(QApplication::translate("Cook", "\320\267\320\260\320\262\321\202\321\200\320\260\320\272", nullptr));
        CountBox->setText(QApplication::translate("Cook", "\320\275\320\260 \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\276\321\202\320\264\321\213\321\205\320\260\321\216\321\211\320\270\321\205", nullptr));
        Cancel->setText(QApplication::translate("Cook", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        dinner->setText(QApplication::translate("Cook", "\321\203\320\266\320\270\320\275", nullptr));
        lunch->setText(QApplication::translate("Cook", "\320\276\320\261\320\265\320\264", nullptr));
        Applay->setText(QApplication::translate("Cook", "\320\237\321\200\320\270\320\275\321\217\321\202\321\214", nullptr));
        GBC4->setTitle(QApplication::translate("Cook", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \320\277\321\200\320\276\321\210\320\273\321\213\321\205 \320\274\320\265\320\275\321\216", nullptr));
        C4RB1->setText(QApplication::translate("Cook", "\320\267\320\260\320\262\321\202\321\200\320\260\320\272", nullptr));
        C4RB4->setText(QApplication::translate("Cook", "\320\264\321\200\321\203\320\263\320\276\320\265", nullptr));
        C4RB3->setText(QApplication::translate("Cook", "\321\203\320\266\320\270\320\275", nullptr));
        C4RB2->setText(QApplication::translate("Cook", "\320\276\320\261\320\265\320\264", nullptr));
        C4BSearch->setText(QApplication::translate("Cook", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        C4LAmount->setText(QApplication::translate("Cook", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276:", nullptr));
        GBC2->setTitle(QApplication::translate("Cook", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \320\270\320\275\320\263\321\200\320\265\320\264\320\270\320\265\320\275\321\202\320\276\320\262", nullptr));
        label_2->setText(QApplication::translate("Cook", "\321\201\320\272\320\273\320\260\320\264", nullptr));
        label->setText(QApplication::translate("Cook", "\320\270\320\275\320\263\321\200\320\270\320\264\320\270\320\265\320\275\321\202", nullptr));
        C2BSearch->setText(QApplication::translate("Cook", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        whatchDish->setText(QApplication::translate("Cook", "\320\237\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \320\261\320\273\321\216\320\264\320\260", nullptr));
        whatchIngredients->setText(QApplication::translate("Cook", "\320\237\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \320\270\320\275\320\263\321\200\320\270\320\264\320\270\320\265\320\275\321\202\321\213", nullptr));
        createMenu->setText(QApplication::translate("Cook", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\274\320\265\320\275\321\216", nullptr));
        prevMenu->setText(QApplication::translate("Cook", "\320\237\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \320\277\321\200\320\276\321\210\320\273\321\213\320\265 \320\274\320\265\320\275\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Cook: public Ui_Cook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COOK_H
