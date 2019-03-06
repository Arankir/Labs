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
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
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
    QFrame *line;
    QWidget *widget;
    QFrame *line_2;
    QFrame *line_4;
    QPushButton *LogOut;
    QPushButton *Hide;
    QFrame *line_3;
    QWidget *widget_3;
    QWidget *widget_2;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *watchStock;
    QPushButton *whatchStockChanges;
    QPushButton *AddIngredients;
    QGroupBox *GBC1;
    QScrollArea *C1SA1;
    QWidget *scrollAreaWidgetContents;
    QScrollArea *C1SA2;
    QWidget *scrollAreaWidgetContents_2;
    QGroupBox *GBC4;
    QScrollArea *C4SA1;
    QWidget *scrollAreaWidgetContents_5;
    QRadioButton *C4RB1;
    QCalendarWidget *C4Calendar;
    QRadioButton *C4RB4;
    QRadioButton *C4RB3;
    QRadioButton *C4RB2;
    QPushButton *C4BSearch;
    QLabel *C4LAmount;
    QGroupBox *GBC2;
    QLabel *label_2;
    QLabel *label;
    QPushButton *C2BSearch;
    QTableView *C2T1;
    QComboBox *C2CB1;
    QComboBox *C2CB2;

    void setupUi(QWidget *Warehousekeeper)
    {
        if (Warehousekeeper->objectName().isEmpty())
            Warehousekeeper->setObjectName(QString::fromUtf8("Warehousekeeper"));
        Warehousekeeper->resize(829, 577);
        line = new QFrame(Warehousekeeper);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(170, 36, 641, 31));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        widget = new QWidget(Warehousekeeper);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(170, 50, 641, 511));
        line_2 = new QFrame(Warehousekeeper);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(170, 550, 641, 21));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(Warehousekeeper);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(800, 50, 21, 511));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        LogOut = new QPushButton(Warehousekeeper);
        LogOut->setObjectName(QString::fromUtf8("LogOut"));
        LogOut->setGeometry(QRect(750, 10, 71, 23));
        Hide = new QPushButton(Warehousekeeper);
        Hide->setObjectName(QString::fromUtf8("Hide"));
        Hide->setEnabled(true);
        Hide->setGeometry(QRect(780, 60, 21, 23));
        Hide->setLayoutDirection(Qt::LeftToRight);
        line_3 = new QFrame(Warehousekeeper);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(160, 50, 20, 511));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        widget_3 = new QWidget(Warehousekeeper);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(170, 50, 641, 511));
        widget_2 = new QWidget(Warehousekeeper);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(170, 50, 641, 511));
        verticalLayoutWidget = new QWidget(Warehousekeeper);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 2, 151, 571));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        watchStock = new QPushButton(verticalLayoutWidget);
        watchStock->setObjectName(QString::fromUtf8("watchStock"));

        verticalLayout->addWidget(watchStock);

        whatchStockChanges = new QPushButton(verticalLayoutWidget);
        whatchStockChanges->setObjectName(QString::fromUtf8("whatchStockChanges"));

        verticalLayout->addWidget(whatchStockChanges);

        AddIngredients = new QPushButton(verticalLayoutWidget);
        AddIngredients->setObjectName(QString::fromUtf8("AddIngredients"));

        verticalLayout->addWidget(AddIngredients);

        GBC1 = new QGroupBox(Warehousekeeper);
        GBC1->setObjectName(QString::fromUtf8("GBC1"));
        GBC1->setGeometry(QRect(170, 30, 641, 511));
        C1SA1 = new QScrollArea(GBC1);
        C1SA1->setObjectName(QString::fromUtf8("C1SA1"));
        C1SA1->setGeometry(QRect(30, 40, 261, 441));
        C1SA1->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 259, 439));
        C1SA1->setWidget(scrollAreaWidgetContents);
        C1SA2 = new QScrollArea(GBC1);
        C1SA2->setObjectName(QString::fromUtf8("C1SA2"));
        C1SA2->setGeometry(QRect(310, 40, 291, 441));
        C1SA2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 289, 439));
        C1SA2->setWidget(scrollAreaWidgetContents_2);
        GBC4 = new QGroupBox(Warehousekeeper);
        GBC4->setObjectName(QString::fromUtf8("GBC4"));
        GBC4->setGeometry(QRect(200, 10, 641, 511));
        C4SA1 = new QScrollArea(GBC4);
        C4SA1->setObjectName(QString::fromUtf8("C4SA1"));
        C4SA1->setGeometry(QRect(380, 40, 201, 391));
        C4SA1->setWidgetResizable(true);
        scrollAreaWidgetContents_5 = new QWidget();
        scrollAreaWidgetContents_5->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_5"));
        scrollAreaWidgetContents_5->setGeometry(QRect(0, 0, 199, 389));
        C4SA1->setWidget(scrollAreaWidgetContents_5);
        C4RB1 = new QRadioButton(GBC4);
        C4RB1->setObjectName(QString::fromUtf8("C4RB1"));
        C4RB1->setGeometry(QRect(40, 260, 82, 17));
        C4RB1->setChecked(true);
        C4Calendar = new QCalendarWidget(GBC4);
        C4Calendar->setObjectName(QString::fromUtf8("C4Calendar"));
        C4Calendar->setGeometry(QRect(30, 40, 248, 183));
        QFont font;
        font.setKerning(true);
        font.setStyleStrategy(QFont::PreferDefault);
        C4Calendar->setFont(font);
        C4Calendar->setSelectionMode(QCalendarWidget::SingleSelection);
        C4RB4 = new QRadioButton(GBC4);
        C4RB4->setObjectName(QString::fromUtf8("C4RB4"));
        C4RB4->setGeometry(QRect(40, 320, 82, 17));
        C4RB3 = new QRadioButton(GBC4);
        C4RB3->setObjectName(QString::fromUtf8("C4RB3"));
        C4RB3->setGeometry(QRect(40, 300, 82, 17));
        C4RB2 = new QRadioButton(GBC4);
        C4RB2->setObjectName(QString::fromUtf8("C4RB2"));
        C4RB2->setGeometry(QRect(40, 280, 82, 17));
        C4BSearch = new QPushButton(GBC4);
        C4BSearch->setObjectName(QString::fromUtf8("C4BSearch"));
        C4BSearch->setGeometry(QRect(40, 350, 75, 23));
        C4LAmount = new QLabel(GBC4);
        C4LAmount->setObjectName(QString::fromUtf8("C4LAmount"));
        C4LAmount->setGeometry(QRect(380, 440, 171, 16));
        GBC2 = new QGroupBox(Warehousekeeper);
        GBC2->setObjectName(QString::fromUtf8("GBC2"));
        GBC2->setGeometry(QRect(230, 0, 641, 511));
        label_2 = new QLabel(GBC2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(410, 100, 71, 16));
        label = new QLabel(GBC2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(410, 70, 71, 16));
        C2BSearch = new QPushButton(GBC2);
        C2BSearch->setObjectName(QString::fromUtf8("C2BSearch"));
        C2BSearch->setGeometry(QRect(480, 160, 75, 23));
        C2T1 = new QTableView(GBC2);
        C2T1->setObjectName(QString::fromUtf8("C2T1"));
        C2T1->setGeometry(QRect(20, 30, 381, 481));
        C2CB1 = new QComboBox(GBC2);
        C2CB1->setObjectName(QString::fromUtf8("C2CB1"));
        C2CB1->setGeometry(QRect(490, 70, 141, 22));
        C2CB2 = new QComboBox(GBC2);
        C2CB2->setObjectName(QString::fromUtf8("C2CB2"));
        C2CB2->setGeometry(QRect(490, 100, 141, 22));
        line->raise();
        widget->raise();
        line_2->raise();
        line_4->raise();
        LogOut->raise();
        line_3->raise();
        widget_3->raise();
        widget_2->raise();
        Hide->raise();
        verticalLayoutWidget->raise();
        GBC1->raise();
        GBC4->raise();
        GBC2->raise();

        retranslateUi(Warehousekeeper);

        QMetaObject::connectSlotsByName(Warehousekeeper);
    } // setupUi

    void retranslateUi(QWidget *Warehousekeeper)
    {
        Warehousekeeper->setWindowTitle(QApplication::translate("Warehousekeeper", "Form", nullptr));
        LogOut->setText(QApplication::translate("Warehousekeeper", "\320\237\320\265\321\200\320\265\320\267\320\260\320\271\321\202\320\270", nullptr));
        Hide->setText(QApplication::translate("Warehousekeeper", "\320\245", nullptr));
        watchStock->setText(QApplication::translate("Warehousekeeper", "\320\237\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \321\201\320\272\320\273\320\260\320\264\321\213", nullptr));
        whatchStockChanges->setText(QApplication::translate("Warehousekeeper", "\320\230\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217 \320\275\320\260 \321\201\320\272\320\273\320\260\320\264\320\260\321\205", nullptr));
        AddIngredients->setText(QApplication::translate("Warehousekeeper", "\320\237\321\200\320\276\320\262\320\265\321\201\321\202\320\270 \320\275\320\260\320\272\320\273\320\260\320\264\320\275\321\203\321\216", nullptr));
        GBC1->setTitle(QApplication::translate("Warehousekeeper", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \320\261\320\273\321\216\320\264", nullptr));
        GBC4->setTitle(QApplication::translate("Warehousekeeper", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \320\277\321\200\320\276\321\210\320\273\321\213\321\205 \320\274\320\265\320\275\321\216", nullptr));
        C4RB1->setText(QApplication::translate("Warehousekeeper", "\320\267\320\260\320\262\321\202\321\200\320\260\320\272", nullptr));
        C4RB4->setText(QApplication::translate("Warehousekeeper", "\320\264\321\200\321\203\320\263\320\276\320\265", nullptr));
        C4RB3->setText(QApplication::translate("Warehousekeeper", "\321\203\320\266\320\270\320\275", nullptr));
        C4RB2->setText(QApplication::translate("Warehousekeeper", "\320\276\320\261\320\265\320\264", nullptr));
        C4BSearch->setText(QApplication::translate("Warehousekeeper", "\320\237\320\276\320\270\321\201\320\272", nullptr));
        C4LAmount->setText(QApplication::translate("Warehousekeeper", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276:", nullptr));
        GBC2->setTitle(QApplication::translate("Warehousekeeper", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \320\270\320\275\320\263\321\200\320\265\320\264\320\270\320\265\320\275\321\202\320\276\320\262", nullptr));
        label_2->setText(QApplication::translate("Warehousekeeper", "\321\201\320\272\320\273\320\260\320\264", nullptr));
        label->setText(QApplication::translate("Warehousekeeper", "\320\270\320\275\320\263\321\200\320\270\320\264\320\270\320\265\320\275\321\202", nullptr));
        C2BSearch->setText(QApplication::translate("Warehousekeeper", "\320\237\320\276\320\270\321\201\320\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Warehousekeeper: public Ui_Warehousekeeper {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAREHOUSEKEEPER_H
