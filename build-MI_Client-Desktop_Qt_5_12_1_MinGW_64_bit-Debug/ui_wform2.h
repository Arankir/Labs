/********************************************************************************
** Form generated from reading UI file 'wform2.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WFORM2_H
#define UI_WFORM2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Wform2
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *NumberInvoice;
    QPushButton *pushButton;
    QScrollArea *IngredientsInStock;
    QWidget *scrollAreaWidgetContents_2;
    QScrollArea *AllIngredients;
    QWidget *scrollAreaWidgetContents;
    QLabel *label_4;
    QDateEdit *DateInvoice;
    QComboBox *Stocks;

    void setupUi(QWidget *Wform2)
    {
        if (Wform2->objectName().isEmpty())
            Wform2->setObjectName(QString::fromUtf8("Wform2"));
        Wform2->resize(641, 511);
        label = new QLabel(Wform2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 47, 13));
        label_2 = new QLabel(Wform2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 40, 81, 16));
        label_3 = new QLabel(Wform2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 70, 61, 16));
        NumberInvoice = new QLineEdit(Wform2);
        NumberInvoice->setObjectName(QString::fromUtf8("NumberInvoice"));
        NumberInvoice->setGeometry(QRect(90, 40, 113, 20));
        pushButton = new QPushButton(Wform2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 460, 75, 23));
        IngredientsInStock = new QScrollArea(Wform2);
        IngredientsInStock->setObjectName(QString::fromUtf8("IngredientsInStock"));
        IngredientsInStock->setGeometry(QRect(300, 90, 291, 351));
        IngredientsInStock->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 289, 349));
        IngredientsInStock->setWidget(scrollAreaWidgetContents_2);
        AllIngredients = new QScrollArea(Wform2);
        AllIngredients->setObjectName(QString::fromUtf8("AllIngredients"));
        AllIngredients->setGeometry(QRect(10, 90, 261, 351));
        AllIngredients->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 259, 349));
        AllIngredients->setWidget(scrollAreaWidgetContents);
        label_4 = new QLabel(Wform2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(210, 40, 31, 16));
        DateInvoice = new QDateEdit(Wform2);
        DateInvoice->setObjectName(QString::fromUtf8("DateInvoice"));
        DateInvoice->setGeometry(QRect(240, 40, 110, 22));
        DateInvoice->setCalendarPopup(true);
        Stocks = new QComboBox(Wform2);
        Stocks->setObjectName(QString::fromUtf8("Stocks"));
        Stocks->setGeometry(QRect(50, 10, 151, 22));

        retranslateUi(Wform2);

        QMetaObject::connectSlotsByName(Wform2);
    } // setupUi

    void retranslateUi(QWidget *Wform2)
    {
        Wform2->setWindowTitle(QApplication::translate("Wform2", "Form", nullptr));
        label->setText(QApplication::translate("Wform2", "\320\241\320\272\320\273\320\260\320\264:", nullptr));
        label_2->setText(QApplication::translate("Wform2", "\342\204\226 \320\235\320\260\320\272\320\273\320\260\320\264\320\275\320\276\320\271:", nullptr));
        label_3->setText(QApplication::translate("Wform2", "\320\237\321\200\320\276\320\264\321\203\320\272\321\202\321\213:", nullptr));
        pushButton->setText(QApplication::translate("Wform2", "\320\237\321\200\320\276\320\262\320\265\321\201\321\202\320\270", nullptr));
        label_4->setText(QApplication::translate("Wform2", "\320\224\320\260\321\202\320\260:", nullptr));
        DateInvoice->setDisplayFormat(QApplication::translate("Wform2", "yyyy.MM.dd", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Wform2: public Ui_Wform2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WFORM2_H
