/********************************************************************************
** Form generated from reading UI file 'cook.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COOK_H
#define UI_COOK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Cook
{
public:
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *Cook)
    {
        if (Cook->objectName().isEmpty())
            Cook->setObjectName(QString::fromUtf8("Cook"));
        Cook->resize(400, 300);
        label = new QLabel(Cook);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 60, 181, 81));
        pushButton = new QPushButton(Cook);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(10, 10, 75, 23));

        retranslateUi(Cook);

        QMetaObject::connectSlotsByName(Cook);
    } // setupUi

    void retranslateUi(QWidget *Cook)
    {
        Cook->setWindowTitle(QApplication::translate("Cook", "Form", nullptr));
        label->setText(QApplication::translate("Cook", "TextLabel", nullptr));
        pushButton->setText(QApplication::translate("Cook", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Cook: public Ui_Cook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COOK_H
