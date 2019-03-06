/********************************************************************************
** Form generated from reading UI file 'cform2.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CFORM2_H
#define UI_CFORM2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CForm2
{
public:
    QTableView *IngredientsTable;
    QLineEdit *IngredientEdit;
    QLineEdit *stockEdit;
    QLineEdit *countEdit;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *Search;

    void setupUi(QWidget *CForm2)
    {
        if (CForm2->objectName().isEmpty())
            CForm2->setObjectName(QString::fromUtf8("CForm2"));
        CForm2->resize(641, 511);
        IngredientsTable = new QTableView(CForm2);
        IngredientsTable->setObjectName(QString::fromUtf8("IngredientsTable"));
        IngredientsTable->setGeometry(QRect(10, 10, 321, 481));
        IngredientEdit = new QLineEdit(CForm2);
        IngredientEdit->setObjectName(QString::fromUtf8("IngredientEdit"));
        IngredientEdit->setGeometry(QRect(430, 30, 113, 20));
        stockEdit = new QLineEdit(CForm2);
        stockEdit->setObjectName(QString::fromUtf8("stockEdit"));
        stockEdit->setGeometry(QRect(430, 70, 113, 20));
        countEdit = new QLineEdit(CForm2);
        countEdit->setObjectName(QString::fromUtf8("countEdit"));
        countEdit->setGeometry(QRect(430, 110, 113, 20));
        label = new QLabel(CForm2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(350, 30, 71, 16));
        label_2 = new QLabel(CForm2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(350, 70, 71, 16));
        label_3 = new QLabel(CForm2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(350, 110, 71, 16));
        Search = new QPushButton(CForm2);
        Search->setObjectName(QString::fromUtf8("Search"));
        Search->setGeometry(QRect(440, 160, 75, 23));

        retranslateUi(CForm2);

        QMetaObject::connectSlotsByName(CForm2);
    } // setupUi

    void retranslateUi(QWidget *CForm2)
    {
        CForm2->setWindowTitle(QApplication::translate("CForm2", "Form", nullptr));
        label->setText(QApplication::translate("CForm2", "\320\270\320\275\320\263\321\200\320\270\320\264\320\270\320\265\320\275\321\202", nullptr));
        label_2->setText(QApplication::translate("CForm2", "\321\201\320\272\320\273\320\260\320\264", nullptr));
        label_3->setText(QApplication::translate("CForm2", "\320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        Search->setText(QApplication::translate("CForm2", "\320\237\320\276\320\270\321\201\320\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CForm2: public Ui_CForm2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CFORM2_H
