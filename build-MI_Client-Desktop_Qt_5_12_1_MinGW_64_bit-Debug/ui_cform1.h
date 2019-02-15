/********************************************************************************
** Form generated from reading UI file 'cform1.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CFORM1_H
#define UI_CFORM1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CForm1
{
public:
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;

    void setupUi(QWidget *CForm1)
    {
        if (CForm1->objectName().isEmpty())
            CForm1->setObjectName(QString::fromUtf8("CForm1"));
        CForm1->resize(555, 363);
        scrollArea = new QScrollArea(CForm1);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(30, 20, 181, 311));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 179, 309));
        scrollArea->setWidget(scrollAreaWidgetContents);
        scrollArea_2 = new QScrollArea(CForm1);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(260, 20, 211, 311));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QString::fromUtf8("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 209, 309));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        retranslateUi(CForm1);

        QMetaObject::connectSlotsByName(CForm1);
    } // setupUi

    void retranslateUi(QWidget *CForm1)
    {
        CForm1->setWindowTitle(QApplication::translate("CForm1", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CForm1: public Ui_CForm1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CFORM1_H
