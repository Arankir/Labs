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
    QLabel *label_3;
    QLineEdit *C1LE;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QTableView *C1TVIngredients;
    QGroupBox *GBC3;
    QScrollArea *C3SA2;
    QWidget *scrollAreaWidgetContents_3;
    QLabel *labelCount;
    QCheckBox *C3CBGuests;
    QPushButton *C3BCancel;
    QLineEdit *C3LEGuests;
    QScrollArea *C3SA1;
    QWidget *scrollAreaWidgetContents_4;
    QPushButton *C3BApply;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *breakfast;
    QRadioButton *lunch;
    QRadioButton *dinner;
    QRadioButton *other;
    QDateEdit *C3Date;
    QLabel *label_8;
    QLabel *label_9;
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
    QLabel *label_7;
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
        GBC1->setGeometry(QRect(680, 540, 641, 511));
        C1SA1 = new QScrollArea(GBC1);
        C1SA1->setObjectName(QString::fromUtf8("C1SA1"));
        C1SA1->setGeometry(QRect(30, 40, 151, 431));
        C1SA1->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 149, 429));
        C1SA1->setWidget(scrollAreaWidgetContents);
        label_3 = new QLabel(GBC1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(30, 480, 47, 13));
        C1LE = new QLineEdit(GBC1);
        C1LE->setObjectName(QString::fromUtf8("C1LE"));
        C1LE->setGeometry(QRect(70, 475, 113, 20));
        label_4 = new QLabel(GBC1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 20, 47, 16));
        label_5 = new QLabel(GBC1);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(190, 20, 81, 16));
        label_6 = new QLabel(GBC1);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(180, 260, 47, 13));
        C1TVIngredients = new QTableView(GBC1);
        C1TVIngredients->setObjectName(QString::fromUtf8("C1TVIngredients"));
        C1TVIngredients->setGeometry(QRect(190, 40, 411, 431));
        GBC3 = new QGroupBox(Cook);
        GBC3->setObjectName(QString::fromUtf8("GBC3"));
        GBC3->setGeometry(QRect(170, 50, 641, 511));
        C3SA2 = new QScrollArea(GBC3);
        C3SA2->setObjectName(QString::fromUtf8("C3SA2"));
        C3SA2->setGeometry(QRect(360, 60, 221, 331));
        C3SA2->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_3"));
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 219, 329));
        C3SA2->setWidget(scrollAreaWidgetContents_3);
        labelCount = new QLabel(GBC3);
        labelCount->setObjectName(QString::fromUtf8("labelCount"));
        labelCount->setGeometry(QRect(230, 400, 71, 16));
        C3CBGuests = new QCheckBox(GBC3);
        C3CBGuests->setObjectName(QString::fromUtf8("C3CBGuests"));
        C3CBGuests->setGeometry(QRect(230, 420, 331, 21));
        C3CBGuests->setAutoExclusive(false);
        C3BCancel = new QPushButton(GBC3);
        C3BCancel->setObjectName(QString::fromUtf8("C3BCancel"));
        C3BCancel->setGeometry(QRect(100, 400, 71, 21));
        C3LEGuests = new QLineEdit(GBC3);
        C3LEGuests->setObjectName(QString::fromUtf8("C3LEGuests"));
        C3LEGuests->setGeometry(QRect(300, 400, 71, 20));
        C3SA1 = new QScrollArea(GBC3);
        C3SA1->setObjectName(QString::fromUtf8("C3SA1"));
        C3SA1->setGeometry(QRect(30, 60, 221, 331));
        C3SA1->setWidgetResizable(true);
        scrollAreaWidgetContents_4 = new QWidget();
        scrollAreaWidgetContents_4->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_4"));
        scrollAreaWidgetContents_4->setGeometry(QRect(0, 0, 219, 329));
        C3SA1->setWidget(scrollAreaWidgetContents_4);
        C3BApply = new QPushButton(GBC3);
        C3BApply->setObjectName(QString::fromUtf8("C3BApply"));
        C3BApply->setGeometry(QRect(260, 440, 91, 31));
        verticalLayoutWidget_2 = new QWidget(GBC3);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(260, 60, 91, 331));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        breakfast = new QRadioButton(verticalLayoutWidget_2);
        breakfast->setObjectName(QString::fromUtf8("breakfast"));
        breakfast->setChecked(true);

        verticalLayout_2->addWidget(breakfast);

        lunch = new QRadioButton(verticalLayoutWidget_2);
        lunch->setObjectName(QString::fromUtf8("lunch"));

        verticalLayout_2->addWidget(lunch);

        dinner = new QRadioButton(verticalLayoutWidget_2);
        dinner->setObjectName(QString::fromUtf8("dinner"));

        verticalLayout_2->addWidget(dinner);

        other = new QRadioButton(verticalLayoutWidget_2);
        other->setObjectName(QString::fromUtf8("other"));

        verticalLayout_2->addWidget(other);

        C3Date = new QDateEdit(verticalLayoutWidget_2);
        C3Date->setObjectName(QString::fromUtf8("C3Date"));
        C3Date->setCalendarPopup(true);

        verticalLayout_2->addWidget(C3Date);

        label_8 = new QLabel(GBC3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(30, 40, 61, 16));
        label_9 = new QLabel(GBC3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(360, 40, 111, 16));
        GBC4 = new QGroupBox(Cook);
        GBC4->setObjectName(QString::fromUtf8("GBC4"));
        GBC4->setGeometry(QRect(730, 520, 641, 511));
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
        label_7 = new QLabel(GBC4);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(380, 20, 47, 13));
        GBC2 = new QGroupBox(Cook);
        GBC2->setObjectName(QString::fromUtf8("GBC2"));
        GBC2->setGeometry(QRect(200, 560, 641, 511));
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
        label_3->setText(QApplication::translate("Cook", "\320\237\320\276\321\200\321\206\320\270\320\271", nullptr));
        C1LE->setInputMask(QApplication::translate("Cook", "00000000000", nullptr));
        C1LE->setText(QApplication::translate("Cook", "1", nullptr));
        label_4->setText(QApplication::translate("Cook", "\320\221\320\273\321\216\320\264\320\276:", nullptr));
        label_5->setText(QApplication::translate("Cook", "\320\230\320\275\320\263\321\200\320\265\320\264\320\270\320\265\320\275\321\202\321\213:", nullptr));
        label_6->setText(QApplication::translate("Cook", "->", nullptr));
        GBC3->setTitle(QApplication::translate("Cook", "\320\241\320\276\320\267\320\264\320\260\320\275\320\270\320\265 \320\274\320\265\320\275\321\216", nullptr));
        labelCount->setText(QApplication::translate("Cook", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276:", nullptr));
        C3CBGuests->setText(QApplication::translate("Cook", "\320\275\320\260 \320\272\320\276\320\273-\320\262\320\276 \320\276\321\202\320\264\321\213\321\205\320\260\321\216\321\211\320\270\321\205", nullptr));
        C3BCancel->setText(QApplication::translate("Cook", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", nullptr));
        C3LEGuests->setInputMask(QApplication::translate("Cook", "00000000000", nullptr));
        C3LEGuests->setText(QApplication::translate("Cook", "0", nullptr));
        C3BApply->setText(QApplication::translate("Cook", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\274\320\265\320\275\321\216", nullptr));
        breakfast->setText(QApplication::translate("Cook", "\320\227\320\260\320\262\321\202\321\200\320\260\320\272", nullptr));
        lunch->setText(QApplication::translate("Cook", "\320\236\320\261\320\265\320\264", nullptr));
        dinner->setText(QApplication::translate("Cook", "\320\243\320\266\320\270\320\275", nullptr));
        other->setText(QApplication::translate("Cook", "\320\224\321\200\321\203\320\263\320\276\320\265", nullptr));
        C3Date->setDisplayFormat(QApplication::translate("Cook", "yyyy-MM-dd", nullptr));
        label_8->setText(QApplication::translate("Cook", "\320\222\321\201\320\265 \320\261\320\273\321\216\320\264\320\260:", nullptr));
        label_9->setText(QApplication::translate("Cook", "\320\222\321\213\320\261\321\200\320\260\320\275\320\275\321\213\320\265 \320\261\320\273\321\216\320\264\320\260:", nullptr));
        GBC4->setTitle(QApplication::translate("Cook", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \320\277\321\200\320\276\321\210\320\273\321\213\321\205 \320\274\320\265\320\275\321\216", nullptr));
        C4RB1->setText(QApplication::translate("Cook", "\320\267\320\260\320\262\321\202\321\200\320\260\320\272", nullptr));
        C4RB4->setText(QApplication::translate("Cook", "\320\264\321\200\321\203\320\263\320\276\320\265", nullptr));
        C4RB3->setText(QApplication::translate("Cook", "\321\203\320\266\320\270\320\275", nullptr));
        C4RB2->setText(QApplication::translate("Cook", "\320\276\320\261\320\265\320\264", nullptr));
        C4BSearch->setText(QApplication::translate("Cook", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        C4LAmount->setText(QApplication::translate("Cook", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276:", nullptr));
        label_7->setText(QApplication::translate("Cook", "\320\221\320\273\321\216\320\264\320\260:", nullptr));
        GBC2->setTitle(QApplication::translate("Cook", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \320\270\320\275\320\263\321\200\320\265\320\264\320\270\320\265\320\275\321\202\320\276\320\262", nullptr));
        label_2->setText(QApplication::translate("Cook", "\321\201\320\272\320\273\320\260\320\264", nullptr));
        label->setText(QApplication::translate("Cook", "\320\270\320\275\320\263\321\200\320\270\320\264\320\270\320\265\320\275\321\202", nullptr));
        C2BSearch->setText(QApplication::translate("Cook", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        C2CB2->setCurrentText(QString());
        whatchDish->setText(QApplication::translate("Cook", "\320\237\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \320\261\320\273\321\216\320\264\320\260", nullptr));
        whatchIngredients->setText(QApplication::translate("Cook", "\320\237\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \320\270\320\275\320\263\321\200\320\265\320\264\320\270\320\265\320\275\321\202\321\213", nullptr));
        createMenu->setText(QApplication::translate("Cook", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\274\320\265\320\275\321\216", nullptr));
        prevMenu->setText(QApplication::translate("Cook", "\320\237\321\200\320\276\321\210\320\273\321\213\320\265 \320\274\320\265\320\275\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Cook: public Ui_Cook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COOK_H
