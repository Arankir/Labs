/********************************************************************************
** Form generated from reading UI file 'cform2.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CFORM2_H
#define UI_CFORM2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CForm2
{
public:
    QTableView *tableView;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QWidget *CForm2)
    {
        if (CForm2->objectName().isEmpty())
            CForm2->setObjectName(QString::fromUtf8("CForm2"));
        CForm2->resize(579, 464);
        tableView = new QTableView(CForm2);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 10, 321, 401));
        lineEdit = new QLineEdit(CForm2);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(430, 30, 113, 20));
        lineEdit_2 = new QLineEdit(CForm2);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(430, 70, 113, 20));
        lineEdit_3 = new QLineEdit(CForm2);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(430, 110, 113, 20));
        lineEdit_4 = new QLineEdit(CForm2);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(430, 150, 113, 20));
        label = new QLabel(CForm2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(350, 30, 71, 16));
        label_2 = new QLabel(CForm2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(350, 70, 71, 16));
        label_3 = new QLabel(CForm2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(350, 110, 71, 16));
        label_4 = new QLabel(CForm2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(350, 150, 71, 16));

        retranslateUi(CForm2);

        QMetaObject::connectSlotsByName(CForm2);
    } // setupUi

    void retranslateUi(QWidget *CForm2)
    {
        CForm2->setWindowTitle(QApplication::translate("CForm2", "Form", nullptr));
        label->setText(QApplication::translate("CForm2", "\320\270\320\275\320\263\321\200\320\270\320\264\320\270\320\265\320\275\321\202", nullptr));
        label_2->setText(QApplication::translate("CForm2", "\321\201\320\272\320\273\320\260\320\264", nullptr));
        label_3->setText(QApplication::translate("CForm2", "\320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        label_4->setText(QApplication::translate("CForm2", "\320\264\320\260\321\202\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CForm2: public Ui_CForm2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CFORM2_H
