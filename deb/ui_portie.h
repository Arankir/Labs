/********************************************************************************
** Form generated from reading UI file 'portie.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PORTIE_H
#define UI_PORTIE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Portie
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QGroupBox *GBP3;
    QPushButton *LogOut;
    QGroupBox *GBP2;
    QPushButton *Hide;
    QGroupBox *GBP1;
    QTableView *tableView;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QGroupBox *groupBox;
    QDateEdit *dateEdit;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QGroupBox *groupBox_2;
    QDateEdit *dateEdit_2;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_6;
    QRadioButton *radioButton_7;
    QRadioButton *radioButton_8;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton_4;

    void setupUi(QWidget *Portie)
    {
        if (Portie->objectName().isEmpty())
            Portie->setObjectName(QString::fromUtf8("Portie"));
        Portie->resize(829, 577);
        verticalLayoutWidget = new QWidget(Portie);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 0, 151, 581));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(verticalLayoutWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(verticalLayoutWidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        pushButton = new QPushButton(verticalLayoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        GBP3 = new QGroupBox(Portie);
        GBP3->setObjectName(QString::fromUtf8("GBP3"));
        GBP3->setGeometry(QRect(800, 130, 641, 511));
        LogOut = new QPushButton(Portie);
        LogOut->setObjectName(QString::fromUtf8("LogOut"));
        LogOut->setGeometry(QRect(750, 10, 71, 23));
        GBP2 = new QGroupBox(Portie);
        GBP2->setObjectName(QString::fromUtf8("GBP2"));
        GBP2->setGeometry(QRect(180, 550, 641, 511));
        Hide = new QPushButton(Portie);
        Hide->setObjectName(QString::fromUtf8("Hide"));
        Hide->setEnabled(true);
        Hide->setGeometry(QRect(780, 60, 21, 23));
        Hide->setLayoutDirection(Qt::LeftToRight);
        GBP1 = new QGroupBox(Portie);
        GBP1->setObjectName(QString::fromUtf8("GBP1"));
        GBP1->setGeometry(QRect(170, 50, 641, 511));
        tableView = new QTableView(GBP1);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 20, 441, 481));
        label = new QLabel(GBP1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(460, 43, 47, 16));
        label_2 = new QLabel(GBP1);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(460, 73, 47, 16));
        label_3 = new QLabel(GBP1);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(460, 103, 47, 16));
        label_4 = new QLabel(GBP1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(460, 131, 51, 20));
        label_5 = new QLabel(GBP1);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(460, 163, 47, 16));
        groupBox = new QGroupBox(GBP1);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(470, 190, 131, 131));
        dateEdit = new QDateEdit(groupBox);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setGeometry(QRect(10, 20, 110, 22));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(10, 50, 82, 17));
        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(10, 70, 82, 17));
        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(10, 90, 82, 17));
        radioButton_4 = new QRadioButton(groupBox);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));
        radioButton_4->setGeometry(QRect(10, 110, 82, 17));
        groupBox_2 = new QGroupBox(GBP1);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(470, 320, 131, 131));
        dateEdit_2 = new QDateEdit(groupBox_2);
        dateEdit_2->setObjectName(QString::fromUtf8("dateEdit_2"));
        dateEdit_2->setGeometry(QRect(10, 20, 110, 22));
        radioButton_5 = new QRadioButton(groupBox_2);
        radioButton_5->setObjectName(QString::fromUtf8("radioButton_5"));
        radioButton_5->setGeometry(QRect(10, 50, 82, 17));
        radioButton_6 = new QRadioButton(groupBox_2);
        radioButton_6->setObjectName(QString::fromUtf8("radioButton_6"));
        radioButton_6->setGeometry(QRect(10, 70, 82, 17));
        radioButton_7 = new QRadioButton(groupBox_2);
        radioButton_7->setObjectName(QString::fromUtf8("radioButton_7"));
        radioButton_7->setGeometry(QRect(10, 90, 82, 17));
        radioButton_8 = new QRadioButton(groupBox_2);
        radioButton_8->setObjectName(QString::fromUtf8("radioButton_8"));
        radioButton_8->setGeometry(QRect(10, 110, 82, 17));
        lineEdit = new QLineEdit(GBP1);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(510, 40, 113, 20));
        lineEdit_2 = new QLineEdit(GBP1);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(510, 70, 113, 20));
        lineEdit_3 = new QLineEdit(GBP1);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(510, 100, 113, 20));
        lineEdit_4 = new QLineEdit(GBP1);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(510, 130, 113, 20));
        lineEdit_5 = new QLineEdit(GBP1);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(510, 160, 113, 20));
        pushButton_4 = new QPushButton(GBP1);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(510, 460, 75, 23));
        verticalLayoutWidget->raise();
        GBP3->raise();
        LogOut->raise();
        GBP2->raise();
        GBP1->raise();
        Hide->raise();

        retranslateUi(Portie);

        QMetaObject::connectSlotsByName(Portie);
    } // setupUi

    void retranslateUi(QWidget *Portie)
    {
        Portie->setWindowTitle(QApplication::translate("Portie", "Form", nullptr));
        pushButton_2->setText(QApplication::translate("Portie", "\320\237\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217", nullptr));
        pushButton_3->setText(QApplication::translate("Portie", "\320\227\320\260\321\200\320\265\320\267\320\265\321\200\320\262\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        pushButton->setText(QApplication::translate("Portie", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\216", nullptr));
        GBP3->setTitle(QApplication::translate("Portie", "\320\230\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\265 \320\270\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\320\270 \320\276 \320\277\320\276\321\201\321\202\320\276\321\217\320\273\321\214\321\206\320\260\321\205", nullptr));
        LogOut->setText(QApplication::translate("Portie", "\320\237\320\265\321\200\320\265\320\267\320\260\320\271\321\202\320\270", nullptr));
        GBP2->setTitle(QApplication::translate("Portie", "\320\240\320\265\320\267\320\265\321\200\320\262\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \320\274\320\265\321\201\321\202", nullptr));
        Hide->setText(QApplication::translate("Portie", "\320\245", nullptr));
        GBP1->setTitle(QApplication::translate("Portie", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\271", nullptr));
        label->setText(QApplication::translate("Portie", "\320\237\320\260\321\201\320\277\320\276\321\200\321\202", nullptr));
        label_2->setText(QApplication::translate("Portie", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        label_3->setText(QApplication::translate("Portie", "\320\230\320\274\321\217", nullptr));
        label_4->setText(QApplication::translate("Portie", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        label_5->setText(QApplication::translate("Portie", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
        groupBox->setTitle(QApplication::translate("Portie", "\320\224\320\260\321\202\320\260 \320\267\320\260\320\265\320\267\320\264\320\260", nullptr));
        dateEdit->setDisplayFormat(QApplication::translate("Portie", "yyyy-MM-dd", nullptr));
        radioButton->setText(QApplication::translate("Portie", "\320\233\321\216\320\261\320\260\321\217 \320\264\320\260\321\202\320\260", nullptr));
        radioButton_2->setText(QApplication::translate("Portie", "\320\224\320\276 \320\264\320\260\321\202\321\213", nullptr));
        radioButton_3->setText(QApplication::translate("Portie", "\320\242\320\276\321\207\320\275\320\260\321\217 \320\264\320\260\321\202\320\260", nullptr));
        radioButton_4->setText(QApplication::translate("Portie", "\320\237\320\276\321\201\320\273\320\265 \320\264\320\260\321\202\321\213", nullptr));
        groupBox_2->setTitle(QApplication::translate("Portie", "\320\224\320\260\321\202\320\260 \320\276\321\202\321\212\320\265\320\267\320\264\320\260", nullptr));
        dateEdit_2->setDisplayFormat(QApplication::translate("Portie", "yyyy-MM-dd", nullptr));
        radioButton_5->setText(QApplication::translate("Portie", "\320\233\321\216\320\261\320\260\321\217 \320\264\320\260\321\202\320\260", nullptr));
        radioButton_6->setText(QApplication::translate("Portie", "\320\224\320\276 \320\264\320\260\321\202\321\213", nullptr));
        radioButton_7->setText(QApplication::translate("Portie", "\320\242\320\276\321\207\320\275\320\260\321\217 \320\264\320\260\321\202\320\260", nullptr));
        radioButton_8->setText(QApplication::translate("Portie", "\320\237\320\276\321\201\320\273\320\265 \320\264\320\260\321\202\321\213", nullptr));
        pushButton_4->setText(QApplication::translate("Portie", "\320\237\320\276\320\270\321\201\320\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Portie: public Ui_Portie {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PORTIE_H
