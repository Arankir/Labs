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
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Warehousekeeper
{
public:
    QFrame *line;
    QWidget *widget;
    QPushButton *whatchStockChanges;
    QFrame *line_2;
    QPushButton *AddIngredients;
    QFrame *line_4;
    QPushButton *watchStock;
    QPushButton *LogOut;
    QPushButton *Hide;
    QFrame *line_3;
    QWidget *widget_3;
    QWidget *widget_2;

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
        whatchStockChanges = new QPushButton(Warehousekeeper);
        whatchStockChanges->setObjectName(QString::fromUtf8("whatchStockChanges"));
        whatchStockChanges->setGeometry(QRect(10, 80, 151, 23));
        line_2 = new QFrame(Warehousekeeper);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(170, 550, 641, 21));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        AddIngredients = new QPushButton(Warehousekeeper);
        AddIngredients->setObjectName(QString::fromUtf8("AddIngredients"));
        AddIngredients->setGeometry(QRect(10, 300, 151, 23));
        line_4 = new QFrame(Warehousekeeper);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(800, 50, 21, 511));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        watchStock = new QPushButton(Warehousekeeper);
        watchStock->setObjectName(QString::fromUtf8("watchStock"));
        watchStock->setGeometry(QRect(10, 50, 151, 23));
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

        retranslateUi(Warehousekeeper);

        QMetaObject::connectSlotsByName(Warehousekeeper);
    } // setupUi

    void retranslateUi(QWidget *Warehousekeeper)
    {
        Warehousekeeper->setWindowTitle(QApplication::translate("Warehousekeeper", "Form", nullptr));
        whatchStockChanges->setText(QApplication::translate("Warehousekeeper", "\320\230\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217 \320\275\320\260 \321\201\320\272\320\273\320\260\320\264\320\260\321\205", nullptr));
        AddIngredients->setText(QApplication::translate("Warehousekeeper", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\270\320\275\320\263\321\200\320\265\320\264\320\270\320\265\320\275\321\202\321\213", nullptr));
        watchStock->setText(QApplication::translate("Warehousekeeper", "\320\237\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \321\201\320\272\320\273\320\260\320\264\321\213", nullptr));
        LogOut->setText(QApplication::translate("Warehousekeeper", "\320\237\320\265\321\200\320\265\320\267\320\260\320\271\321\202\320\270", nullptr));
        Hide->setText(QApplication::translate("Warehousekeeper", "\320\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Warehousekeeper: public Ui_Warehousekeeper {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAREHOUSEKEEPER_H
