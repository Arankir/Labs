/********************************************************************************
** Form generated from reading UI file 'warehousekeeper.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAREHOUSEKEEPER_H
#define UI_WAREHOUSEKEEPER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
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

class Ui_Warehousekeeper
{
public:
    QPushButton *LogOut;
    QPushButton *Hide;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *WhkButtonShowW1;
    QPushButton *WhkButtonShowW2;
    QPushButton *WhkButtonShowW3;
    QGroupBox *GBW3;
    QDateEdit *W3DEDate;
    QScrollArea *W3SAAllIngredients;
    QWidget *scrollAreaWidgetContents;
    QComboBox *W3CBStocks;
    QLabel *W3L2;
    QPushButton *W3BApply;
    QLabel *W3L3;
    QLineEdit *W3LEInvoice;
    QLabel *W3L4;
    QScrollArea *W3SACheckedIngredients;
    QWidget *scrollAreaWidgetContents_2;
    QLabel *W3L1;
    QGroupBox *GBW2;
    QPushButton *W2ButtonApply;
    QGroupBox *W2GBDate;
    QDateEdit *W2DEDateChange;
    QRadioButton *W2RBAllDate;
    QRadioButton *W2RBBeforeDate;
    QRadioButton *W2RBInDate;
    QRadioButton *W2RBAfterDate;
    QLabel *W2L1;
    QComboBox *W2CBIngredients;
    QLabel *W2L2;
    QComboBox *W2CBStocks;
    QTableView *W2Table;
    QLabel *label_3;
    QLineEdit *W2LEInvoice;
    QGroupBox *groupBox;
    QRadioButton *W2RBAllChanges;
    QRadioButton *W2RBIncChanges;
    QRadioButton *W2RBDecChanges;
    QGroupBox *GBW1;
    QLabel *label_2;
    QLabel *label;
    QPushButton *W1BSearch;
    QTableView *W1T1;
    QComboBox *W1CB1;
    QComboBox *W1CB2;

    void setupUi(QWidget *Warehousekeeper)
    {
        if (Warehousekeeper->objectName().isEmpty())
            Warehousekeeper->setObjectName(QString::fromUtf8("Warehousekeeper"));
        Warehousekeeper->resize(829, 577);
        LogOut = new QPushButton(Warehousekeeper);
        LogOut->setObjectName(QString::fromUtf8("LogOut"));
        LogOut->setGeometry(QRect(750, 10, 71, 23));
        Hide = new QPushButton(Warehousekeeper);
        Hide->setObjectName(QString::fromUtf8("Hide"));
        Hide->setEnabled(true);
        Hide->setGeometry(QRect(780, 60, 21, 23));
        Hide->setLayoutDirection(Qt::LeftToRight);
        verticalLayoutWidget = new QWidget(Warehousekeeper);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 2, 151, 571));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        WhkButtonShowW1 = new QPushButton(verticalLayoutWidget);
        WhkButtonShowW1->setObjectName(QString::fromUtf8("WhkButtonShowW1"));

        verticalLayout->addWidget(WhkButtonShowW1);

        WhkButtonShowW2 = new QPushButton(verticalLayoutWidget);
        WhkButtonShowW2->setObjectName(QString::fromUtf8("WhkButtonShowW2"));

        verticalLayout->addWidget(WhkButtonShowW2);

        WhkButtonShowW3 = new QPushButton(verticalLayoutWidget);
        WhkButtonShowW3->setObjectName(QString::fromUtf8("WhkButtonShowW3"));

        verticalLayout->addWidget(WhkButtonShowW3);

        GBW3 = new QGroupBox(Warehousekeeper);
        GBW3->setObjectName(QString::fromUtf8("GBW3"));
        GBW3->setGeometry(QRect(170, 550, 641, 511));
        W3DEDate = new QDateEdit(GBW3);
        W3DEDate->setObjectName(QString::fromUtf8("W3DEDate"));
        W3DEDate->setGeometry(QRect(250, 50, 110, 22));
        W3DEDate->setCalendarPopup(true);
        W3SAAllIngredients = new QScrollArea(GBW3);
        W3SAAllIngredients->setObjectName(QString::fromUtf8("W3SAAllIngredients"));
        W3SAAllIngredients->setGeometry(QRect(20, 100, 221, 351));
        W3SAAllIngredients->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 219, 349));
        W3SAAllIngredients->setWidget(scrollAreaWidgetContents);
        W3CBStocks = new QComboBox(GBW3);
        W3CBStocks->setObjectName(QString::fromUtf8("W3CBStocks"));
        W3CBStocks->setGeometry(QRect(60, 20, 151, 22));
        W3L2 = new QLabel(GBW3);
        W3L2->setObjectName(QString::fromUtf8("W3L2"));
        W3L2->setGeometry(QRect(20, 50, 81, 16));
        W3BApply = new QPushButton(GBW3);
        W3BApply->setObjectName(QString::fromUtf8("W3BApply"));
        W3BApply->setGeometry(QRect(20, 470, 75, 23));
        W3L3 = new QLabel(GBW3);
        W3L3->setObjectName(QString::fromUtf8("W3L3"));
        W3L3->setGeometry(QRect(20, 80, 61, 16));
        W3LEInvoice = new QLineEdit(GBW3);
        W3LEInvoice->setObjectName(QString::fromUtf8("W3LEInvoice"));
        W3LEInvoice->setGeometry(QRect(100, 50, 113, 20));
        W3L4 = new QLabel(GBW3);
        W3L4->setObjectName(QString::fromUtf8("W3L4"));
        W3L4->setGeometry(QRect(220, 50, 31, 16));
        W3SACheckedIngredients = new QScrollArea(GBW3);
        W3SACheckedIngredients->setObjectName(QString::fromUtf8("W3SACheckedIngredients"));
        W3SACheckedIngredients->setGeometry(QRect(270, 100, 331, 351));
        W3SACheckedIngredients->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 329, 349));
        W3SACheckedIngredients->setWidget(scrollAreaWidgetContents_2);
        W3L1 = new QLabel(GBW3);
        W3L1->setObjectName(QString::fromUtf8("W3L1"));
        W3L1->setGeometry(QRect(20, 20, 47, 13));
        GBW2 = new QGroupBox(Warehousekeeper);
        GBW2->setObjectName(QString::fromUtf8("GBW2"));
        GBW2->setGeometry(QRect(180, 60, 641, 511));
        W2ButtonApply = new QPushButton(GBW2);
        W2ButtonApply->setObjectName(QString::fromUtf8("W2ButtonApply"));
        W2ButtonApply->setGeometry(QRect(520, 450, 75, 23));
        W2GBDate = new QGroupBox(GBW2);
        W2GBDate->setObjectName(QString::fromUtf8("W2GBDate"));
        W2GBDate->setGeometry(QRect(500, 100, 120, 141));
        W2DEDateChange = new QDateEdit(W2GBDate);
        W2DEDateChange->setObjectName(QString::fromUtf8("W2DEDateChange"));
        W2DEDateChange->setGeometry(QRect(10, 20, 91, 22));
        W2DEDateChange->setCalendarPopup(true);
        W2RBAllDate = new QRadioButton(W2GBDate);
        W2RBAllDate->setObjectName(QString::fromUtf8("W2RBAllDate"));
        W2RBAllDate->setGeometry(QRect(10, 50, 91, 17));
        W2RBAllDate->setChecked(true);
        W2RBBeforeDate = new QRadioButton(W2GBDate);
        W2RBBeforeDate->setObjectName(QString::fromUtf8("W2RBBeforeDate"));
        W2RBBeforeDate->setGeometry(QRect(10, 70, 82, 17));
        W2RBInDate = new QRadioButton(W2GBDate);
        W2RBInDate->setObjectName(QString::fromUtf8("W2RBInDate"));
        W2RBInDate->setGeometry(QRect(10, 90, 82, 17));
        W2RBAfterDate = new QRadioButton(W2GBDate);
        W2RBAfterDate->setObjectName(QString::fromUtf8("W2RBAfterDate"));
        W2RBAfterDate->setGeometry(QRect(10, 110, 82, 17));
        W2L1 = new QLabel(GBW2);
        W2L1->setObjectName(QString::fromUtf8("W2L1"));
        W2L1->setGeometry(QRect(500, 300, 47, 13));
        W2CBIngredients = new QComboBox(GBW2);
        W2CBIngredients->setObjectName(QString::fromUtf8("W2CBIngredients"));
        W2CBIngredients->setGeometry(QRect(500, 320, 121, 22));
        W2L2 = new QLabel(GBW2);
        W2L2->setObjectName(QString::fromUtf8("W2L2"));
        W2L2->setGeometry(QRect(500, 250, 47, 13));
        W2CBStocks = new QComboBox(GBW2);
        W2CBStocks->setObjectName(QString::fromUtf8("W2CBStocks"));
        W2CBStocks->setGeometry(QRect(500, 270, 121, 22));
        W2Table = new QTableView(GBW2);
        W2Table->setObjectName(QString::fromUtf8("W2Table"));
        W2Table->setGeometry(QRect(10, 20, 481, 461));
        label_3 = new QLabel(GBW2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(500, 50, 81, 16));
        W2LEInvoice = new QLineEdit(GBW2);
        W2LEInvoice->setObjectName(QString::fromUtf8("W2LEInvoice"));
        W2LEInvoice->setGeometry(QRect(500, 70, 113, 20));
        groupBox = new QGroupBox(GBW2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(500, 350, 121, 80));
        W2RBAllChanges = new QRadioButton(groupBox);
        W2RBAllChanges->setObjectName(QString::fromUtf8("W2RBAllChanges"));
        W2RBAllChanges->setGeometry(QRect(10, 20, 111, 17));
        W2RBAllChanges->setChecked(true);
        W2RBIncChanges = new QRadioButton(groupBox);
        W2RBIncChanges->setObjectName(QString::fromUtf8("W2RBIncChanges"));
        W2RBIncChanges->setGeometry(QRect(10, 40, 111, 17));
        W2RBDecChanges = new QRadioButton(groupBox);
        W2RBDecChanges->setObjectName(QString::fromUtf8("W2RBDecChanges"));
        W2RBDecChanges->setGeometry(QRect(10, 60, 111, 17));
        GBW1 = new QGroupBox(Warehousekeeper);
        GBW1->setObjectName(QString::fromUtf8("GBW1"));
        GBW1->setGeometry(QRect(800, 90, 641, 511));
        label_2 = new QLabel(GBW1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(410, 100, 71, 16));
        label = new QLabel(GBW1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(410, 70, 71, 16));
        W1BSearch = new QPushButton(GBW1);
        W1BSearch->setObjectName(QString::fromUtf8("W1BSearch"));
        W1BSearch->setGeometry(QRect(480, 160, 75, 23));
        W1T1 = new QTableView(GBW1);
        W1T1->setObjectName(QString::fromUtf8("W1T1"));
        W1T1->setGeometry(QRect(20, 30, 381, 481));
        W1CB1 = new QComboBox(GBW1);
        W1CB1->setObjectName(QString::fromUtf8("W1CB1"));
        W1CB1->setGeometry(QRect(490, 70, 141, 22));
        W1CB2 = new QComboBox(GBW1);
        W1CB2->setObjectName(QString::fromUtf8("W1CB2"));
        W1CB2->setGeometry(QRect(490, 100, 141, 22));
        LogOut->raise();
        verticalLayoutWidget->raise();
        GBW3->raise();
        GBW2->raise();
        GBW1->raise();
        Hide->raise();

        retranslateUi(Warehousekeeper);

        QMetaObject::connectSlotsByName(Warehousekeeper);
    } // setupUi

    void retranslateUi(QWidget *Warehousekeeper)
    {
        Warehousekeeper->setWindowTitle(QApplication::translate("Warehousekeeper", "Form", nullptr));
        LogOut->setText(QApplication::translate("Warehousekeeper", "\320\237\320\265\321\200\320\265\320\267\320\260\320\271\321\202\320\270", nullptr));
        Hide->setText(QApplication::translate("Warehousekeeper", "\320\245", nullptr));
        WhkButtonShowW1->setText(QApplication::translate("Warehousekeeper", "\320\237\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \321\201\320\272\320\273\320\260\320\264\321\213", nullptr));
        WhkButtonShowW2->setText(QApplication::translate("Warehousekeeper", "\320\230\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217 \320\275\320\260 \321\201\320\272\320\273\320\260\320\264\320\260\321\205", nullptr));
        WhkButtonShowW3->setText(QApplication::translate("Warehousekeeper", "\320\237\321\200\320\276\320\262\320\265\321\201\321\202\320\270 \320\275\320\260\320\272\320\273\320\260\320\264\320\275\321\203\321\216", nullptr));
        GBW3->setTitle(QApplication::translate("Warehousekeeper", "\320\241\320\276\320\267\320\264\320\260\320\275\320\270\320\265 \320\275\320\260\320\272\320\273\320\260\320\264\320\275\320\276\320\271", nullptr));
        W3DEDate->setDisplayFormat(QApplication::translate("Warehousekeeper", "yyyy-MM-dd", nullptr));
        W3L2->setText(QApplication::translate("Warehousekeeper", "\342\204\226 \320\235\320\260\320\272\320\273\320\260\320\264\320\275\320\276\320\271:", nullptr));
        W3BApply->setText(QApplication::translate("Warehousekeeper", "\320\237\321\200\320\276\320\262\320\265\321\201\321\202\320\270", nullptr));
        W3L3->setText(QApplication::translate("Warehousekeeper", "\320\237\321\200\320\276\320\264\321\203\320\272\321\202\321\213:", nullptr));
        W3L4->setText(QApplication::translate("Warehousekeeper", "\320\224\320\260\321\202\320\260:", nullptr));
        W3L1->setText(QApplication::translate("Warehousekeeper", "\320\241\320\272\320\273\320\260\320\264:", nullptr));
        GBW2->setTitle(QApplication::translate("Warehousekeeper", "\320\230\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217 \320\275\320\260 \321\201\320\272\320\273\320\260\320\264\320\260\321\205", nullptr));
        W2ButtonApply->setText(QApplication::translate("Warehousekeeper", "\320\244\320\270\320\273\321\214\321\202\321\200", nullptr));
        W2GBDate->setTitle(QApplication::translate("Warehousekeeper", "\320\224\320\260\321\202\320\260", nullptr));
        W2DEDateChange->setDisplayFormat(QApplication::translate("Warehousekeeper", "yyyy-MM-dd", nullptr));
        W2RBAllDate->setText(QApplication::translate("Warehousekeeper", "\320\233\321\216\320\261\320\260\321\217 \320\264\320\260\321\202\320\260", nullptr));
        W2RBBeforeDate->setText(QApplication::translate("Warehousekeeper", "\320\224\320\276 \320\264\320\260\321\202\321\213", nullptr));
        W2RBInDate->setText(QApplication::translate("Warehousekeeper", "\320\242\320\276\321\207\320\275\320\260\321\217 \320\264\320\260\321\202\320\260", nullptr));
        W2RBAfterDate->setText(QApplication::translate("Warehousekeeper", "\320\237\320\276\321\201\320\273\320\265 \320\264\320\260\321\202\321\213", nullptr));
        W2L1->setText(QApplication::translate("Warehousekeeper", "\320\237\321\200\320\276\320\264\321\203\320\272\321\202:", nullptr));
        W2L2->setText(QApplication::translate("Warehousekeeper", "\320\241\320\272\320\273\320\260\320\264:", nullptr));
        label_3->setText(QApplication::translate("Warehousekeeper", "\320\235\320\260\320\272\320\273\320\260\320\264\320\275\320\260\321\217 \342\204\226:", nullptr));
        groupBox->setTitle(QApplication::translate("Warehousekeeper", "\320\237\321\200\320\276\320\264\321\203\320\272\321\202\321\213", nullptr));
        W2RBAllChanges->setText(QApplication::translate("Warehousekeeper", "\320\222\321\201\320\265 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217", nullptr));
        W2RBIncChanges->setText(QApplication::translate("Warehousekeeper", "\320\224\320\276\320\261\320\260\320\262\320\270\320\273\320\270\321\201\321\214", nullptr));
        W2RBDecChanges->setText(QApplication::translate("Warehousekeeper", "\320\237\320\276\321\202\321\200\320\260\321\202\320\270\320\273\320\270\321\201\321\214", nullptr));
        GBW1->setTitle(QApplication::translate("Warehousekeeper", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \321\201\320\272\320\273\320\260\320\264\320\276\320\262", nullptr));
        label_2->setText(QApplication::translate("Warehousekeeper", "\321\201\320\272\320\273\320\260\320\264", nullptr));
        label->setText(QApplication::translate("Warehousekeeper", "\320\270\320\275\320\263\321\200\320\270\320\264\320\270\320\265\320\275\321\202", nullptr));
        W1BSearch->setText(QApplication::translate("Warehousekeeper", "\320\237\320\276\320\270\321\201\320\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Warehousekeeper: public Ui_Warehousekeeper {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAREHOUSEKEEPER_H
