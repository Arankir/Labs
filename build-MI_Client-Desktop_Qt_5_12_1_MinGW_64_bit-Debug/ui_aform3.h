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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
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

    void setupUi(QWidget *AForm3)
    {
        if (AForm3->objectName().isEmpty())
            AForm3->setObjectName(QString::fromUtf8("AForm3"));
        AForm3->resize(457, 300);
        Apply = new QPushButton(AForm3);
        Apply->setObjectName(QString::fromUtf8("Apply"));
        Apply->setGeometry(QRect(290, 120, 75, 23));
        DishEdit = new QLineEdit(AForm3);
        DishEdit->setObjectName(QString::fromUtf8("DishEdit"));
        DishEdit->setGeometry(QRect(320, 50, 110, 20));
        label = new QLabel(AForm3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(260, 50, 60, 20));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        dishs = new QTableView(AForm3);
        dishs->setObjectName(QString::fromUtf8("dishs"));
        dishs->setGeometry(QRect(10, 10, 230, 250));

        retranslateUi(AForm3);

        QMetaObject::connectSlotsByName(AForm3);
    } // setupUi

    void retranslateUi(QWidget *AForm3)
    {
        AForm3->setWindowTitle(QApplication::translate("AForm3", "Form", nullptr));
        Apply->setText(QApplication::translate("AForm3", "\320\237\321\200\320\276\320\262\320\265\321\201\321\202\320\270", nullptr));
        label->setText(QApplication::translate("AForm3", "\320\235\320\276\320\262\321\213\320\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AForm3: public Ui_AForm3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AFORM3_H
