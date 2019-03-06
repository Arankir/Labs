/********************************************************************************
** Form generated from reading UI file 'wform1.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WFORM1_H
#define UI_WFORM1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Wform1
{
public:
    QTableView *StockChangeTable;
    QLabel *label_2;
    QLabel *label_3;
    QRadioButton *RBInc;
    QRadioButton *RBDec;
    QRadioButton *RBAll;
    QPushButton *ApplyStockChangeFilter;
    QGroupBox *groupBox;
    QDateEdit *DateChange;
    QRadioButton *RBAllDate;
    QRadioButton *RBBDate;
    QRadioButton *RBInDate;
    QRadioButton *RBADate;
    QComboBox *Stocks;
    QComboBox *Ingredients;

    void setupUi(QWidget *Wform1)
    {
        if (Wform1->objectName().isEmpty())
            Wform1->setObjectName(QString::fromUtf8("Wform1"));
        Wform1->resize(641, 511);
        StockChangeTable = new QTableView(Wform1);
        StockChangeTable->setObjectName(QString::fromUtf8("StockChangeTable"));
        StockChangeTable->setGeometry(QRect(0, 20, 491, 461));
        label_2 = new QLabel(Wform1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(500, 160, 47, 13));
        label_3 = new QLabel(Wform1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(500, 210, 47, 13));
        RBInc = new QRadioButton(Wform1);
        RBInc->setObjectName(QString::fromUtf8("RBInc"));
        RBInc->setGeometry(QRect(500, 280, 121, 17));
        RBDec = new QRadioButton(Wform1);
        RBDec->setObjectName(QString::fromUtf8("RBDec"));
        RBDec->setGeometry(QRect(500, 300, 131, 17));
        RBAll = new QRadioButton(Wform1);
        RBAll->setObjectName(QString::fromUtf8("RBAll"));
        RBAll->setGeometry(QRect(500, 260, 91, 17));
        RBAll->setChecked(true);
        ApplyStockChangeFilter = new QPushButton(Wform1);
        ApplyStockChangeFilter->setObjectName(QString::fromUtf8("ApplyStockChangeFilter"));
        ApplyStockChangeFilter->setGeometry(QRect(530, 320, 75, 23));
        groupBox = new QGroupBox(Wform1);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(500, 10, 120, 141));
        DateChange = new QDateEdit(groupBox);
        DateChange->setObjectName(QString::fromUtf8("DateChange"));
        DateChange->setGeometry(QRect(10, 20, 91, 22));
        DateChange->setCalendarPopup(true);
        RBAllDate = new QRadioButton(groupBox);
        RBAllDate->setObjectName(QString::fromUtf8("RBAllDate"));
        RBAllDate->setGeometry(QRect(10, 50, 91, 17));
        RBAllDate->setChecked(true);
        RBBDate = new QRadioButton(groupBox);
        RBBDate->setObjectName(QString::fromUtf8("RBBDate"));
        RBBDate->setGeometry(QRect(10, 70, 82, 17));
        RBInDate = new QRadioButton(groupBox);
        RBInDate->setObjectName(QString::fromUtf8("RBInDate"));
        RBInDate->setGeometry(QRect(10, 90, 82, 17));
        RBADate = new QRadioButton(groupBox);
        RBADate->setObjectName(QString::fromUtf8("RBADate"));
        RBADate->setGeometry(QRect(10, 110, 82, 17));
        Stocks = new QComboBox(Wform1);
        Stocks->setObjectName(QString::fromUtf8("Stocks"));
        Stocks->setGeometry(QRect(500, 180, 121, 22));
        Ingredients = new QComboBox(Wform1);
        Ingredients->setObjectName(QString::fromUtf8("Ingredients"));
        Ingredients->setGeometry(QRect(500, 230, 121, 22));

        retranslateUi(Wform1);

        QMetaObject::connectSlotsByName(Wform1);
    } // setupUi

    void retranslateUi(QWidget *Wform1)
    {
        Wform1->setWindowTitle(QApplication::translate("Wform1", "Form", nullptr));
        label_2->setText(QApplication::translate("Wform1", "\320\241\320\272\320\273\320\260\320\264:", nullptr));
        label_3->setText(QApplication::translate("Wform1", "\320\237\321\200\320\276\320\264\321\203\320\272\321\202:", nullptr));
        RBInc->setText(QApplication::translate("Wform1", "\320\237\321\200\320\276\320\264\321\203\320\272\321\202 \320\264\320\276\320\261\320\260\320\262\320\270\320\273\321\201\321\217", nullptr));
        RBDec->setText(QApplication::translate("Wform1", "\320\237\321\200\320\276\320\264\321\203\320\272\321\202 \320\277\320\276\321\202\321\200\320\260\321\202\320\270\320\273\321\201\321\217", nullptr));
        RBAll->setText(QApplication::translate("Wform1", "\320\222\321\201\320\265 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217", nullptr));
        ApplyStockChangeFilter->setText(QApplication::translate("Wform1", "\320\244\320\270\320\273\321\214\321\202\321\200", nullptr));
        groupBox->setTitle(QApplication::translate("Wform1", "\320\224\320\260\321\202\320\260", nullptr));
        DateChange->setDisplayFormat(QApplication::translate("Wform1", "yyyy.MM.dd", nullptr));
        RBAllDate->setText(QApplication::translate("Wform1", "\320\233\321\216\320\261\320\260\321\217 \320\264\320\260\321\202\320\260", nullptr));
        RBBDate->setText(QApplication::translate("Wform1", "\320\224\320\276 \320\264\320\260\321\202\321\213", nullptr));
        RBInDate->setText(QApplication::translate("Wform1", "\320\242\320\276\321\207\320\275\320\260\321\217 \320\264\320\260\321\202\320\260", nullptr));
        RBADate->setText(QApplication::translate("Wform1", "\320\237\320\276\321\201\320\273\320\265 \320\264\320\260\321\202\321\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Wform1: public Ui_Wform1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WFORM1_H
