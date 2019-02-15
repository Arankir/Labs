/********************************************************************************
** Form generated from reading UI file 'cooform1.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COOFORM1_H
#define UI_COOFORM1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CooForm1
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QWidget *CooForm1)
    {
        if (CooForm1->objectName().isEmpty())
            CooForm1->setObjectName(QString::fromUtf8("CooForm1"));
        CooForm1->resize(567, 371);
        scrollArea = new QScrollArea(CooForm1);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(10, 20, 231, 331));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 229, 329));
        scrollArea->setWidget(scrollAreaWidgetContents);

        retranslateUi(CooForm1);

        QMetaObject::connectSlotsByName(CooForm1);
    } // setupUi

    void retranslateUi(QWidget *CooForm1)
    {
        CooForm1->setWindowTitle(QApplication::translate("CooForm1", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CooForm1: public Ui_CooForm1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COOFORM1_H
