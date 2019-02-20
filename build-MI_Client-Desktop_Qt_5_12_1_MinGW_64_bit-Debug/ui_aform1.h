/********************************************************************************
** Form generated from reading UI file 'aform1.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AFORM1_H
#define UI_AFORM1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AForm1
{
public:
    QPushButton *Reg;
    QLineEdit *PasswordEdit;
    QLineEdit *LoginEdit;
    QComboBox *Role;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *AForm1)
    {
        if (AForm1->objectName().isEmpty())
            AForm1->setObjectName(QString::fromUtf8("AForm1"));
        AForm1->resize(400, 300);
        Reg = new QPushButton(AForm1);
        Reg->setObjectName(QString::fromUtf8("Reg"));
        Reg->setGeometry(QRect(130, 210, 111, 23));
        PasswordEdit = new QLineEdit(AForm1);
        PasswordEdit->setObjectName(QString::fromUtf8("PasswordEdit"));
        PasswordEdit->setGeometry(QRect(130, 110, 113, 20));
        LoginEdit = new QLineEdit(AForm1);
        LoginEdit->setObjectName(QString::fromUtf8("LoginEdit"));
        LoginEdit->setGeometry(QRect(130, 70, 113, 20));
        Role = new QComboBox(AForm1);
        Role->addItem(QString());
        Role->addItem(QString());
        Role->addItem(QString());
        Role->addItem(QString());
        Role->setObjectName(QString::fromUtf8("Role"));
        Role->setGeometry(QRect(130, 160, 111, 22));
        label = new QLabel(AForm1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 70, 47, 13));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);
        label_2 = new QLabel(AForm1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(50, 110, 61, 16));
        label_2->setFont(font);

        retranslateUi(AForm1);

        QMetaObject::connectSlotsByName(AForm1);
    } // setupUi

    void retranslateUi(QWidget *AForm1)
    {
        AForm1->setWindowTitle(QApplication::translate("AForm1", "Form", nullptr));
        Reg->setText(QApplication::translate("AForm1", "\320\227\320\260\321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        Role->setItemText(0, QApplication::translate("AForm1", "\320\220\320\264\320\274\320\270\320\275", nullptr));
        Role->setItemText(1, QApplication::translate("AForm1", "\320\237\320\276\320\262\320\260\321\200", nullptr));
        Role->setItemText(2, QApplication::translate("AForm1", "\320\237\320\276\321\200\321\202\321\214\320\265", nullptr));
        Role->setItemText(3, QApplication::translate("AForm1", "\320\241\320\272\320\273\320\260\320\264\320\276\320\262\321\211\320\270\320\272", nullptr));

        label->setText(QApplication::translate("AForm1", "\320\233\320\276\320\263\320\270\320\275", nullptr));
        label_2->setText(QApplication::translate("AForm1", "\320\237\320\260\321\200\320\276\320\273\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AForm1: public Ui_AForm1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AFORM1_H
