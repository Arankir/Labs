/********************************************************************************
** Form generated from reading UI file 'q123.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_Q123_H
#define UI_Q123_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_q123
{
public:
    QToolButton *toolButton;
    QRadioButton *radioButton;
    QCheckBox *checkBox;

    void setupUi(QWidget *q123)
    {
        if (q123->objectName().isEmpty())
            q123->setObjectName(QString::fromUtf8("q123"));
        q123->resize(400, 300);
        toolButton = new QToolButton(q123);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(170, 120, 25, 19));
        radioButton = new QRadioButton(q123);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(120, 70, 82, 17));
        checkBox = new QCheckBox(q123);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(130, 210, 70, 17));

        retranslateUi(q123);

        QMetaObject::connectSlotsByName(q123);
    } // setupUi

    void retranslateUi(QWidget *q123)
    {
        q123->setWindowTitle(QApplication::translate("q123", "Form", nullptr));
        toolButton->setText(QApplication::translate("q123", "...", nullptr));
        radioButton->setText(QApplication::translate("q123", "RadioButton", nullptr));
        checkBox->setText(QApplication::translate("q123", "CheckBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class q123: public Ui_q123 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_Q123_H
