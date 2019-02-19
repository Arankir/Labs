/********************************************************************************
** Form generated from reading UI file 'aform3.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AFORM3_H
#define UI_AFORM3_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AForm3
{
public:
    QPushButton *Apply;
    QLineEdit *DishEdit;
    QLabel *label;
    QTableView *dishs;
    QComboBox *IngrBox;
    QLineEdit *CountEdit;
    QLabel *label_2;
    QLabel *label_3;
    QScrollArea *Ingredients;
    QWidget *scrollAreaWidgetContents;
    QPushButton *Add;

    void setupUi(QWidget *AForm3)
    {
        if (AForm3->objectName().isEmpty())
            AForm3->setObjectName(QString::fromUtf8("AForm3"));
        AForm3->resize(832, 390);
        Apply = new QPushButton(AForm3);
        Apply->setObjectName(QString::fromUtf8("Apply"));
        Apply->setGeometry(QRect(230, 250, 75, 23));
        DishEdit = new QLineEdit(AForm3);
        DishEdit->setObjectName(QString::fromUtf8("DishEdit"));
        DishEdit->setGeometry(QRect(260, 50, 110, 20));
        label = new QLabel(AForm3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(180, 50, 71, 20));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        dishs = new QTableView(AForm3);
        dishs->setObjectName(QString::fromUtf8("dishs"));
        dishs->setGeometry(QRect(10, 10, 151, 250));
        IngrBox = new QComboBox(AForm3);
        IngrBox->setObjectName(QString::fromUtf8("IngrBox"));
        IngrBox->setGeometry(QRect(278, 100, 91, 22));
        CountEdit = new QLineEdit(AForm3);
        CountEdit->setObjectName(QString::fromUtf8("CountEdit"));
        CountEdit->setGeometry(QRect(270, 140, 101, 20));
        label_2 = new QLabel(AForm3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(180, 100, 91, 20));
        label_2->setFont(font);
        label_3 = new QLabel(AForm3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(180, 140, 91, 20));
        label_3->setFont(font);
        Ingredients = new QScrollArea(AForm3);
        Ingredients->setObjectName(QString::fromUtf8("Ingredients"));
        Ingredients->setGeometry(QRect(400, 10, 151, 251));
        Ingredients->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 149, 249));
        Ingredients->setWidget(scrollAreaWidgetContents);
        Add = new QPushButton(AForm3);
        Add->setObjectName(QString::fromUtf8("Add"));
        Add->setGeometry(QRect(220, 180, 75, 23));

        retranslateUi(AForm3);

        QMetaObject::connectSlotsByName(AForm3);
    } // setupUi

    void retranslateUi(QWidget *AForm3)
    {
        AForm3->setWindowTitle(QApplication::translate("AForm3", "Form", nullptr));
        Apply->setText(QApplication::translate("AForm3", "\320\237\321\200\320\276\320\262\320\265\321\201\321\202\320\270", nullptr));
        label->setText(QApplication::translate("AForm3", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265", nullptr));
        label_2->setText(QApplication::translate("AForm3", "\320\230\320\275\320\263\321\200\320\265\320\264\320\270\320\265\320\275\321\202", nullptr));
        label_3->setText(QApplication::translate("AForm3", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        Add->setText(QApplication::translate("AForm3", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AForm3: public Ui_AForm3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AFORM3_H
