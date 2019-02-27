/********************************************************************************
** Form generated from reading UI file 'cform4.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CFORM4_H
#define UI_CFORM4_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CForm4
{
public:
    QCalendarWidget *calendar;
    QRadioButton *breakfast;
    QRadioButton *lunch;
    QRadioButton *dinner;
    QRadioButton *other;
    QScrollArea *menu;
    QWidget *scrollAreaWidgetContents;
    QPushButton *search;
    QLabel *selectDateText;
    QLabel *date;

    void setupUi(QWidget *CForm4)
    {
        if (CForm4->objectName().isEmpty())
            CForm4->setObjectName(QString::fromUtf8("CForm4"));
        CForm4->resize(641, 511);
        calendar = new QCalendarWidget(CForm4);
        calendar->setObjectName(QString::fromUtf8("calendar"));
        calendar->setGeometry(QRect(20, 20, 248, 183));
        QFont font;
        font.setKerning(true);
        font.setStyleStrategy(QFont::PreferDefault);
        calendar->setFont(font);
        calendar->setSelectionMode(QCalendarWidget::SingleSelection);
        breakfast = new QRadioButton(CForm4);
        breakfast->setObjectName(QString::fromUtf8("breakfast"));
        breakfast->setGeometry(QRect(30, 240, 82, 17));
        lunch = new QRadioButton(CForm4);
        lunch->setObjectName(QString::fromUtf8("lunch"));
        lunch->setGeometry(QRect(30, 270, 82, 17));
        dinner = new QRadioButton(CForm4);
        dinner->setObjectName(QString::fromUtf8("dinner"));
        dinner->setGeometry(QRect(30, 300, 82, 17));
        other = new QRadioButton(CForm4);
        other->setObjectName(QString::fromUtf8("other"));
        other->setGeometry(QRect(30, 330, 82, 17));
        menu = new QScrollArea(CForm4);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu->setGeometry(QRect(370, 20, 201, 451));
        menu->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 199, 449));
        menu->setWidget(scrollAreaWidgetContents);
        search = new QPushButton(CForm4);
        search->setObjectName(QString::fromUtf8("search"));
        search->setGeometry(QRect(30, 360, 75, 23));
        selectDateText = new QLabel(CForm4);
        selectDateText->setObjectName(QString::fromUtf8("selectDateText"));
        selectDateText->setGeometry(QRect(30, 210, 91, 21));
        date = new QLabel(CForm4);
        date->setObjectName(QString::fromUtf8("date"));
        date->setGeometry(QRect(120, 210, 81, 21));

        retranslateUi(CForm4);

        QMetaObject::connectSlotsByName(CForm4);
    } // setupUi

    void retranslateUi(QWidget *CForm4)
    {
        CForm4->setWindowTitle(QApplication::translate("CForm4", "Form", nullptr));
        breakfast->setText(QApplication::translate("CForm4", "\320\267\320\260\320\262\321\202\321\200\320\260\320\272", nullptr));
        lunch->setText(QApplication::translate("CForm4", "\320\276\320\261\320\265\320\264", nullptr));
        dinner->setText(QApplication::translate("CForm4", "\321\203\320\266\320\270\320\275", nullptr));
        other->setText(QApplication::translate("CForm4", "\320\264\321\200\321\203\320\263\320\276\320\265", nullptr));
        search->setText(QApplication::translate("CForm4", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        selectDateText->setText(QApplication::translate("CForm4", "\320\222\321\213\320\261\321\200\320\260\320\275\320\275\320\260\321\217 \320\264\320\260\321\202\320\260:", nullptr));
        date->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CForm4: public Ui_CForm4 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CFORM4_H
