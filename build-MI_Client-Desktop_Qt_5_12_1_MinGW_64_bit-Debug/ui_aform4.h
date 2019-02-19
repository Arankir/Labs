/********************************************************************************
** Form generated from reading UI file 'aform4.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AFORM4_H
#define UI_AFORM4_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AForm4
{
public:
    QLineEdit *StockEdit;
    QPushButton *Apply;
    QLabel *label;
    QTableView *stock;

    void setupUi(QWidget *AForm4)
    {
        if (AForm4->objectName().isEmpty())
            AForm4->setObjectName(QString::fromUtf8("AForm4"));
        AForm4->resize(459, 300);
        StockEdit = new QLineEdit(AForm4);
        StockEdit->setObjectName(QString::fromUtf8("StockEdit"));
        StockEdit->setGeometry(QRect(320, 50, 110, 20));
        Apply = new QPushButton(AForm4);
        Apply->setObjectName(QString::fromUtf8("Apply"));
        Apply->setGeometry(QRect(290, 120, 75, 23));
        label = new QLabel(AForm4);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(260, 50, 60, 20));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        stock = new QTableView(AForm4);
        stock->setObjectName(QString::fromUtf8("stock"));
        stock->setGeometry(QRect(10, 10, 230, 250));

        retranslateUi(AForm4);

        QMetaObject::connectSlotsByName(AForm4);
    } // setupUi

    void retranslateUi(QWidget *AForm4)
    {
        AForm4->setWindowTitle(QApplication::translate("AForm4", "Form", nullptr));
        Apply->setText(QApplication::translate("AForm4", "\320\237\321\200\320\276\320\262\320\265\321\201\321\202\320\270", nullptr));
        label->setText(QApplication::translate("AForm4", "\320\235\320\276\320\262\321\213\320\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AForm4: public Ui_AForm4 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AFORM4_H
