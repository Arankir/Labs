/********************************************************************************
** Form generated from reading UI file 'cform3.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CFORM3_H
#define UI_CFORM3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cForm3
{
public:
    QScrollArea *AllDish;
    QWidget *scrollAreaWidgetContents;
    QScrollArea *DishMenu;
    QWidget *scrollAreaWidgetContents_2;
    QRadioButton *breakfast;
    QRadioButton *lunch;
    QRadioButton *dinner;
    QRadioButton *other;
    QLineEdit *CountEdit;
    QLabel *labelCount;
    QCheckBox *CountBox;
    QPushButton *Cancel;
    QPushButton *Applay;
    QDateEdit *dateEdit;

    void setupUi(QWidget *cForm3)
    {
        if (cForm3->objectName().isEmpty())
            cForm3->setObjectName(QString::fromUtf8("cForm3"));
        cForm3->resize(641, 511);
        AllDish = new QScrollArea(cForm3);
        AllDish->setObjectName(QString::fromUtf8("AllDish"));
        AllDish->setGeometry(QRect(20, 10, 221, 331));
        AllDish->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 219, 329));
        AllDish->setWidget(scrollAreaWidgetContents);
        DishMenu = new QScrollArea(cForm3);
        DishMenu->setObjectName(QString::fromUtf8("DishMenu"));
        DishMenu->setGeometry(QRect(330, 10, 201, 331));
        DishMenu->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 199, 329));
        DishMenu->setWidget(scrollAreaWidgetContents_2);
        breakfast = new QRadioButton(cForm3);
        breakfast->setObjectName(QString::fromUtf8("breakfast"));
        breakfast->setGeometry(QRect(20, 360, 82, 17));
        lunch = new QRadioButton(cForm3);
        lunch->setObjectName(QString::fromUtf8("lunch"));
        lunch->setGeometry(QRect(20, 390, 82, 17));
        dinner = new QRadioButton(cForm3);
        dinner->setObjectName(QString::fromUtf8("dinner"));
        dinner->setGeometry(QRect(20, 420, 82, 17));
        other = new QRadioButton(cForm3);
        other->setObjectName(QString::fromUtf8("other"));
        other->setGeometry(QRect(20, 450, 82, 17));
        CountEdit = new QLineEdit(cForm3);
        CountEdit->setObjectName(QString::fromUtf8("CountEdit"));
        CountEdit->setGeometry(QRect(210, 370, 71, 20));
        labelCount = new QLabel(cForm3);
        labelCount->setObjectName(QString::fromUtf8("labelCount"));
        labelCount->setGeometry(QRect(140, 370, 71, 16));
        CountBox = new QCheckBox(cForm3);
        CountBox->setObjectName(QString::fromUtf8("CountBox"));
        CountBox->setGeometry(QRect(140, 400, 171, 31));
        Cancel = new QPushButton(cForm3);
        Cancel->setObjectName(QString::fromUtf8("Cancel"));
        Cancel->setGeometry(QRect(340, 350, 75, 23));
        Applay = new QPushButton(cForm3);
        Applay->setObjectName(QString::fromUtf8("Applay"));
        Applay->setGeometry(QRect(440, 350, 75, 23));
        dateEdit = new QDateEdit(cForm3);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(140, 440, 110, 22));
        dateEdit->setCalendarPopup(true);

        retranslateUi(cForm3);

        QMetaObject::connectSlotsByName(cForm3);
    } // setupUi

    void retranslateUi(QWidget *cForm3)
    {
        cForm3->setWindowTitle(QApplication::translate("cForm3", "Form", nullptr));
        breakfast->setText(QApplication::translate("cForm3", "\320\267\320\260\320\262\321\202\321\200\320\260\320\272", nullptr));
        lunch->setText(QApplication::translate("cForm3", "\320\276\320\261\320\265\320\264", nullptr));
        dinner->setText(QApplication::translate("cForm3", "\321\203\320\266\320\270\320\275", nullptr));
        other->setText(QApplication::translate("cForm3", "\320\264\321\200\321\203\320\263\320\276\320\265", nullptr));
        labelCount->setText(QApplication::translate("cForm3", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        CountBox->setText(QApplication::translate("cForm3", "\320\275\320\260 \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\276\321\202\320\264\321\213\321\205\320\260\321\216\321\211\320\270\321\205", nullptr));
        Cancel->setText(QApplication::translate("cForm3", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        Applay->setText(QApplication::translate("cForm3", "\320\237\321\200\320\270\320\275\321\217\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class cForm3: public Ui_cForm3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CFORM3_H
