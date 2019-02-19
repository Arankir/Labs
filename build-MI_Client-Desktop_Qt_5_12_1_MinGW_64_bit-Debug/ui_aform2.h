/********************************************************************************
** Form generated from reading UI file 'aform2.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AFORM2_H
#define UI_AFORM2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AForm2
{
public:
    QLineEdit *IngrEdit;
    QLabel *label;
    QPushButton *Apply;
    QTableView *Ingr;
    QLabel *Unit;
    QLineEdit *UnitEdit;

    void setupUi(QWidget *AForm2)
    {
        if (AForm2->objectName().isEmpty())
            AForm2->setObjectName(QString::fromUtf8("AForm2"));
        AForm2->resize(471, 300);
        IngrEdit = new QLineEdit(AForm2);
        IngrEdit->setObjectName(QString::fromUtf8("IngrEdit"));
        IngrEdit->setGeometry(QRect(320, 50, 110, 20));
        label = new QLabel(AForm2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(260, 50, 60, 20));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        Apply = new QPushButton(AForm2);
        Apply->setObjectName(QString::fromUtf8("Apply"));
        Apply->setGeometry(QRect(290, 130, 75, 23));
        Ingr = new QTableView(AForm2);
        Ingr->setObjectName(QString::fromUtf8("Ingr"));
        Ingr->setGeometry(QRect(10, 10, 230, 250));
        Unit = new QLabel(AForm2);
        Unit->setObjectName(QString::fromUtf8("Unit"));
        Unit->setGeometry(QRect(250, 90, 81, 21));
        Unit->setFont(font);
        UnitEdit = new QLineEdit(AForm2);
        UnitEdit->setObjectName(QString::fromUtf8("UnitEdit"));
        UnitEdit->setGeometry(QRect(350, 90, 81, 21));

        retranslateUi(AForm2);

        QMetaObject::connectSlotsByName(AForm2);
    } // setupUi

    void retranslateUi(QWidget *AForm2)
    {
        AForm2->setWindowTitle(QApplication::translate("AForm2", "Form", nullptr));
        label->setText(QApplication::translate("AForm2", "\320\235\320\276\320\262\321\213\320\271", nullptr));
        Apply->setText(QApplication::translate("AForm2", "\320\237\321\200\320\276\320\262\320\265\321\201\321\202\320\270", nullptr));
        Unit->setText(QApplication::translate("AForm2", "\320\230\320\267\320\274\320\265\321\200\320\265\320\275\320\270\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AForm2: public Ui_AForm2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AFORM2_H
