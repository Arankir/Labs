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
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFormLayout>
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
    QTableView *P3TVGuests;
    QLineEdit *P3LEPasport;
    QLineEdit *P3LESecondName;
    QLineEdit *P3LEFirstName;
    QLineEdit *P3LEPatronymic;
    QDateEdit *P3DESettlementDate;
    QDateEdit *P3DEEvictionDate;
    QLineEdit *P3LETelephone;
    QLabel *P3LPasport;
    QLabel *P3LSecondName;
    QLabel *P3LFirstName;
    QLabel *P3LPatronymic;
    QLabel *P3LTelephone;
    QLabel *P3LSettlementDate;
    QLabel *P3LEvictionDate;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLineEdit *P3LEid;
    QLabel *P3Lid;
    QPushButton *LogOut;
    QGroupBox *GBP2;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *P2LSecondName;
    QLineEdit *P2LESecondName;
    QLabel *P2LFirstName;
    QLineEdit *P2LEFirstName;
    QLabel *P2LPatronymic;
    QLineEdit *P2LEPatronymic;
    QLabel *P2LTelephone;
    QLineEdit *P2LETelephone;
    QLabel *P2LPasport;
    QLineEdit *P2LEPasport;
    QCalendarWidget *P2CWSettlementDate;
    QCalendarWidget *P2CWEvictionDate;
    QLabel *P2LSettlementDate;
    QLabel *P2LEvictionDate;
    QPushButton *P2ButtonApply;
    QPushButton *Hide;
    QGroupBox *GBP1;
    QTableView *P1TVGuests;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QGroupBox *P1GBSettlementDate;
    QDateEdit *P1DESettlementDate;
    QRadioButton *P1RBSettlementDateAll;
    QRadioButton *P1RBSettlementDateBefore;
    QRadioButton *P1RBSettlementDateIn;
    QRadioButton *P1RBSettlementDateAfter;
    QGroupBox *P1GBEvictionDate;
    QDateEdit *P1DEEvictionDate;
    QRadioButton *P1RBEvictionDateAll;
    QRadioButton *P1RBEvictionDateBefore;
    QRadioButton *P1RBEvictionDateIn;
    QRadioButton *P1RBEvictionDateAfter;
    QLineEdit *P1LEPasport;
    QLineEdit *P1LESecondName;
    QLineEdit *P1LEFirstName;
    QLineEdit *P1LEPatronymic;
    QLineEdit *P1LETelephone;
    QPushButton *P1ButtonAccept;

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
        GBP3->setGeometry(QRect(170, 40, 641, 511));
        P3TVGuests = new QTableView(GBP3);
        P3TVGuests->setObjectName(QString::fromUtf8("P3TVGuests"));
        P3TVGuests->setEnabled(true);
        P3TVGuests->setGeometry(QRect(10, 20, 591, 391));
        P3LEPasport = new QLineEdit(GBP3);
        P3LEPasport->setObjectName(QString::fromUtf8("P3LEPasport"));
        P3LEPasport->setGeometry(QRect(50, 430, 71, 20));
        P3LESecondName = new QLineEdit(GBP3);
        P3LESecondName->setObjectName(QString::fromUtf8("P3LESecondName"));
        P3LESecondName->setGeometry(QRect(120, 430, 71, 20));
        P3LEFirstName = new QLineEdit(GBP3);
        P3LEFirstName->setObjectName(QString::fromUtf8("P3LEFirstName"));
        P3LEFirstName->setGeometry(QRect(190, 430, 91, 20));
        P3LEPatronymic = new QLineEdit(GBP3);
        P3LEPatronymic->setObjectName(QString::fromUtf8("P3LEPatronymic"));
        P3LEPatronymic->setGeometry(QRect(280, 430, 71, 20));
        P3DESettlementDate = new QDateEdit(GBP3);
        P3DESettlementDate->setObjectName(QString::fromUtf8("P3DESettlementDate"));
        P3DESettlementDate->setGeometry(QRect(430, 430, 81, 22));
        P3DEEvictionDate = new QDateEdit(GBP3);
        P3DEEvictionDate->setObjectName(QString::fromUtf8("P3DEEvictionDate"));
        P3DEEvictionDate->setGeometry(QRect(510, 430, 81, 22));
        P3LETelephone = new QLineEdit(GBP3);
        P3LETelephone->setObjectName(QString::fromUtf8("P3LETelephone"));
        P3LETelephone->setGeometry(QRect(350, 430, 81, 20));
        P3LPasport = new QLabel(GBP3);
        P3LPasport->setObjectName(QString::fromUtf8("P3LPasport"));
        P3LPasport->setGeometry(QRect(50, 415, 71, 16));
        P3LSecondName = new QLabel(GBP3);
        P3LSecondName->setObjectName(QString::fromUtf8("P3LSecondName"));
        P3LSecondName->setGeometry(QRect(120, 415, 71, 16));
        P3LFirstName = new QLabel(GBP3);
        P3LFirstName->setObjectName(QString::fromUtf8("P3LFirstName"));
        P3LFirstName->setGeometry(QRect(190, 415, 91, 16));
        P3LPatronymic = new QLabel(GBP3);
        P3LPatronymic->setObjectName(QString::fromUtf8("P3LPatronymic"));
        P3LPatronymic->setGeometry(QRect(280, 415, 71, 16));
        P3LTelephone = new QLabel(GBP3);
        P3LTelephone->setObjectName(QString::fromUtf8("P3LTelephone"));
        P3LTelephone->setGeometry(QRect(350, 415, 81, 16));
        P3LSettlementDate = new QLabel(GBP3);
        P3LSettlementDate->setObjectName(QString::fromUtf8("P3LSettlementDate"));
        P3LSettlementDate->setGeometry(QRect(430, 415, 81, 16));
        P3LEvictionDate = new QLabel(GBP3);
        P3LEvictionDate->setObjectName(QString::fromUtf8("P3LEvictionDate"));
        P3LEvictionDate->setGeometry(QRect(510, 415, 81, 16));
        pushButton_4 = new QPushButton(GBP3);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(30, 460, 80, 21));
        pushButton_5 = new QPushButton(GBP3);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(480, 460, 121, 21));
        P3LEid = new QLineEdit(GBP3);
        P3LEid->setObjectName(QString::fromUtf8("P3LEid"));
        P3LEid->setEnabled(false);
        P3LEid->setGeometry(QRect(30, 430, 21, 21));
        P3Lid = new QLabel(GBP3);
        P3Lid->setObjectName(QString::fromUtf8("P3Lid"));
        P3Lid->setGeometry(QRect(30, 413, 21, 20));
        LogOut = new QPushButton(Portie);
        LogOut->setObjectName(QString::fromUtf8("LogOut"));
        LogOut->setGeometry(QRect(750, 10, 71, 23));
        GBP2 = new QGroupBox(Portie);
        GBP2->setObjectName(QString::fromUtf8("GBP2"));
        GBP2->setGeometry(QRect(180, 550, 641, 511));
        formLayoutWidget = new QWidget(GBP2);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(40, 60, 271, 387));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setVerticalSpacing(55);
        formLayout->setContentsMargins(0, 0, 0, 0);
        P2LSecondName = new QLabel(formLayoutWidget);
        P2LSecondName->setObjectName(QString::fromUtf8("P2LSecondName"));

        formLayout->setWidget(2, QFormLayout::LabelRole, P2LSecondName);

        P2LESecondName = new QLineEdit(formLayoutWidget);
        P2LESecondName->setObjectName(QString::fromUtf8("P2LESecondName"));

        formLayout->setWidget(2, QFormLayout::FieldRole, P2LESecondName);

        P2LFirstName = new QLabel(formLayoutWidget);
        P2LFirstName->setObjectName(QString::fromUtf8("P2LFirstName"));

        formLayout->setWidget(3, QFormLayout::LabelRole, P2LFirstName);

        P2LEFirstName = new QLineEdit(formLayoutWidget);
        P2LEFirstName->setObjectName(QString::fromUtf8("P2LEFirstName"));

        formLayout->setWidget(3, QFormLayout::FieldRole, P2LEFirstName);

        P2LPatronymic = new QLabel(formLayoutWidget);
        P2LPatronymic->setObjectName(QString::fromUtf8("P2LPatronymic"));

        formLayout->setWidget(4, QFormLayout::LabelRole, P2LPatronymic);

        P2LEPatronymic = new QLineEdit(formLayoutWidget);
        P2LEPatronymic->setObjectName(QString::fromUtf8("P2LEPatronymic"));

        formLayout->setWidget(4, QFormLayout::FieldRole, P2LEPatronymic);

        P2LTelephone = new QLabel(formLayoutWidget);
        P2LTelephone->setObjectName(QString::fromUtf8("P2LTelephone"));

        formLayout->setWidget(5, QFormLayout::LabelRole, P2LTelephone);

        P2LETelephone = new QLineEdit(formLayoutWidget);
        P2LETelephone->setObjectName(QString::fromUtf8("P2LETelephone"));

        formLayout->setWidget(5, QFormLayout::FieldRole, P2LETelephone);

        P2LPasport = new QLabel(formLayoutWidget);
        P2LPasport->setObjectName(QString::fromUtf8("P2LPasport"));

        formLayout->setWidget(1, QFormLayout::LabelRole, P2LPasport);

        P2LEPasport = new QLineEdit(formLayoutWidget);
        P2LEPasport->setObjectName(QString::fromUtf8("P2LEPasport"));

        formLayout->setWidget(1, QFormLayout::FieldRole, P2LEPasport);

        P2CWSettlementDate = new QCalendarWidget(GBP2);
        P2CWSettlementDate->setObjectName(QString::fromUtf8("P2CWSettlementDate"));
        P2CWSettlementDate->setGeometry(QRect(340, 40, 248, 183));
        P2CWEvictionDate = new QCalendarWidget(GBP2);
        P2CWEvictionDate->setObjectName(QString::fromUtf8("P2CWEvictionDate"));
        P2CWEvictionDate->setGeometry(QRect(340, 250, 248, 183));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(P2CWEvictionDate->sizePolicy().hasHeightForWidth());
        P2CWEvictionDate->setSizePolicy(sizePolicy);
        P2LSettlementDate = new QLabel(GBP2);
        P2LSettlementDate->setObjectName(QString::fromUtf8("P2LSettlementDate"));
        P2LSettlementDate->setGeometry(QRect(340, 20, 131, 16));
        P2LEvictionDate = new QLabel(GBP2);
        P2LEvictionDate->setObjectName(QString::fromUtf8("P2LEvictionDate"));
        P2LEvictionDate->setGeometry(QRect(340, 230, 241, 16));
        P2ButtonApply = new QPushButton(GBP2);
        P2ButtonApply->setObjectName(QString::fromUtf8("P2ButtonApply"));
        P2ButtonApply->setGeometry(QRect(260, 450, 121, 31));
        Hide = new QPushButton(Portie);
        Hide->setObjectName(QString::fromUtf8("Hide"));
        Hide->setEnabled(true);
        Hide->setGeometry(QRect(780, 60, 21, 23));
        Hide->setLayoutDirection(Qt::LeftToRight);
        GBP1 = new QGroupBox(Portie);
        GBP1->setObjectName(QString::fromUtf8("GBP1"));
        GBP1->setGeometry(QRect(790, 110, 641, 511));
        P1TVGuests = new QTableView(GBP1);
        P1TVGuests->setObjectName(QString::fromUtf8("P1TVGuests"));
        P1TVGuests->setGeometry(QRect(10, 20, 441, 481));
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
        P1GBSettlementDate = new QGroupBox(GBP1);
        P1GBSettlementDate->setObjectName(QString::fromUtf8("P1GBSettlementDate"));
        P1GBSettlementDate->setGeometry(QRect(470, 190, 131, 131));
        P1DESettlementDate = new QDateEdit(P1GBSettlementDate);
        P1DESettlementDate->setObjectName(QString::fromUtf8("P1DESettlementDate"));
        P1DESettlementDate->setGeometry(QRect(10, 20, 110, 22));
        P1RBSettlementDateAll = new QRadioButton(P1GBSettlementDate);
        P1RBSettlementDateAll->setObjectName(QString::fromUtf8("P1RBSettlementDateAll"));
        P1RBSettlementDateAll->setGeometry(QRect(10, 50, 82, 17));
        P1RBSettlementDateAll->setChecked(true);
        P1RBSettlementDateBefore = new QRadioButton(P1GBSettlementDate);
        P1RBSettlementDateBefore->setObjectName(QString::fromUtf8("P1RBSettlementDateBefore"));
        P1RBSettlementDateBefore->setGeometry(QRect(10, 70, 82, 17));
        P1RBSettlementDateIn = new QRadioButton(P1GBSettlementDate);
        P1RBSettlementDateIn->setObjectName(QString::fromUtf8("P1RBSettlementDateIn"));
        P1RBSettlementDateIn->setGeometry(QRect(10, 90, 82, 17));
        P1RBSettlementDateAfter = new QRadioButton(P1GBSettlementDate);
        P1RBSettlementDateAfter->setObjectName(QString::fromUtf8("P1RBSettlementDateAfter"));
        P1RBSettlementDateAfter->setGeometry(QRect(10, 110, 82, 17));
        P1GBEvictionDate = new QGroupBox(GBP1);
        P1GBEvictionDate->setObjectName(QString::fromUtf8("P1GBEvictionDate"));
        P1GBEvictionDate->setGeometry(QRect(470, 320, 131, 131));
        P1DEEvictionDate = new QDateEdit(P1GBEvictionDate);
        P1DEEvictionDate->setObjectName(QString::fromUtf8("P1DEEvictionDate"));
        P1DEEvictionDate->setGeometry(QRect(10, 20, 110, 22));
        P1RBEvictionDateAll = new QRadioButton(P1GBEvictionDate);
        P1RBEvictionDateAll->setObjectName(QString::fromUtf8("P1RBEvictionDateAll"));
        P1RBEvictionDateAll->setGeometry(QRect(10, 50, 82, 17));
        P1RBEvictionDateAll->setChecked(true);
        P1RBEvictionDateBefore = new QRadioButton(P1GBEvictionDate);
        P1RBEvictionDateBefore->setObjectName(QString::fromUtf8("P1RBEvictionDateBefore"));
        P1RBEvictionDateBefore->setGeometry(QRect(10, 70, 82, 17));
        P1RBEvictionDateIn = new QRadioButton(P1GBEvictionDate);
        P1RBEvictionDateIn->setObjectName(QString::fromUtf8("P1RBEvictionDateIn"));
        P1RBEvictionDateIn->setGeometry(QRect(10, 90, 82, 17));
        P1RBEvictionDateAfter = new QRadioButton(P1GBEvictionDate);
        P1RBEvictionDateAfter->setObjectName(QString::fromUtf8("P1RBEvictionDateAfter"));
        P1RBEvictionDateAfter->setGeometry(QRect(10, 110, 82, 17));
        P1LEPasport = new QLineEdit(GBP1);
        P1LEPasport->setObjectName(QString::fromUtf8("P1LEPasport"));
        P1LEPasport->setGeometry(QRect(510, 40, 113, 20));
        P1LESecondName = new QLineEdit(GBP1);
        P1LESecondName->setObjectName(QString::fromUtf8("P1LESecondName"));
        P1LESecondName->setGeometry(QRect(510, 70, 113, 20));
        P1LEFirstName = new QLineEdit(GBP1);
        P1LEFirstName->setObjectName(QString::fromUtf8("P1LEFirstName"));
        P1LEFirstName->setGeometry(QRect(510, 100, 113, 20));
        P1LEPatronymic = new QLineEdit(GBP1);
        P1LEPatronymic->setObjectName(QString::fromUtf8("P1LEPatronymic"));
        P1LEPatronymic->setGeometry(QRect(510, 130, 113, 20));
        P1LETelephone = new QLineEdit(GBP1);
        P1LETelephone->setObjectName(QString::fromUtf8("P1LETelephone"));
        P1LETelephone->setGeometry(QRect(510, 160, 113, 20));
        P1ButtonAccept = new QPushButton(GBP1);
        P1ButtonAccept->setObjectName(QString::fromUtf8("P1ButtonAccept"));
        P1ButtonAccept->setGeometry(QRect(510, 460, 75, 23));
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
        P3LEPasport->setInputMask(QApplication::translate("Portie", "00000000000", nullptr));
        P3DESettlementDate->setDisplayFormat(QApplication::translate("Portie", "yyyy-MM-dd", nullptr));
        P3DEEvictionDate->setDisplayFormat(QApplication::translate("Portie", "yyyy-MM-dd", nullptr));
        P3LETelephone->setInputMask(QApplication::translate("Portie", "00000000000", nullptr));
        P3LPasport->setText(QApplication::translate("Portie", "\320\237\320\260\321\201\320\277\320\276\321\200\321\202", nullptr));
        P3LSecondName->setText(QApplication::translate("Portie", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        P3LFirstName->setText(QApplication::translate("Portie", "\320\230\320\274\321\217", nullptr));
        P3LPatronymic->setText(QApplication::translate("Portie", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        P3LTelephone->setText(QApplication::translate("Portie", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
        P3LSettlementDate->setText(QApplication::translate("Portie", "\320\227\320\260\321\201\320\265\320\273\320\265\320\275\320\270\320\265", nullptr));
        P3LEvictionDate->setText(QApplication::translate("Portie", "\320\236\321\202\321\212\320\265\320\267\320\264", nullptr));
        pushButton_4->setText(QApplication::translate("Portie", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
        pushButton_5->setText(QApplication::translate("Portie", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217", nullptr));
        P3Lid->setText(QApplication::translate("Portie", "id", nullptr));
        LogOut->setText(QApplication::translate("Portie", "\320\237\320\265\321\200\320\265\320\267\320\260\320\271\321\202\320\270", nullptr));
        GBP2->setTitle(QApplication::translate("Portie", "\320\240\320\265\320\267\320\265\321\200\320\262\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \320\274\320\265\321\201\321\202", nullptr));
        P2LSecondName->setText(QApplication::translate("Portie", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        P2LESecondName->setPlaceholderText(QApplication::translate("Portie", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\204\320\260\320\274\320\270\320\273\320\270\321\216............................", nullptr));
        P2LFirstName->setText(QApplication::translate("Portie", "\320\230\320\274\321\217", nullptr));
        P2LEFirstName->setPlaceholderText(QApplication::translate("Portie", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\270\320\274\321\217....................................", nullptr));
        P2LPatronymic->setText(QApplication::translate("Portie", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        P2LEPatronymic->setPlaceholderText(QApplication::translate("Portie", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\276\321\202\321\207\320\265\321\201\321\202\320\262\320\276............................", nullptr));
        P2LTelephone->setText(QApplication::translate("Portie", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
        P2LETelephone->setPlaceholderText(QApplication::translate("Portie", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \321\202\320\265\320\273\320\265\321\204\320\276\320\275 (\320\275\320\265 \320\276\320\261\321\217\320\267\320\260\321\202\320\265\320\273\321\214\320\275\320\276)......", nullptr));
        P2LPasport->setText(QApplication::translate("Portie", "\320\237\320\260\321\201\320\277\320\276\321\200\321\202", nullptr));
        P2LEPasport->setPlaceholderText(QApplication::translate("Portie", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\260\321\201\320\277\320\276\321\200\321\202..............................", nullptr));
        P2LSettlementDate->setText(QApplication::translate("Portie", "\320\224\320\260\321\202\320\260 \320\277\321\200\320\270\320\261\321\213\321\202\320\270\321\217:", nullptr));
        P2LEvictionDate->setText(QApplication::translate("Portie", "\320\224\320\260\321\202\320\260 \320\262\321\213\320\265\320\267\320\264\320\260:", nullptr));
        P2ButtonApply->setText(QApplication::translate("Portie", "\320\227\320\260\321\200\320\265\320\267\320\265\321\200\320\262\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        Hide->setText(QApplication::translate("Portie", "\320\245", nullptr));
        GBP1->setTitle(QApplication::translate("Portie", "\320\237\321\200\320\276\321\201\320\274\320\276\321\202\321\200 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\271", nullptr));
        label->setText(QApplication::translate("Portie", "\320\237\320\260\321\201\320\277\320\276\321\200\321\202", nullptr));
        label_2->setText(QApplication::translate("Portie", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", nullptr));
        label_3->setText(QApplication::translate("Portie", "\320\230\320\274\321\217", nullptr));
        label_4->setText(QApplication::translate("Portie", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", nullptr));
        label_5->setText(QApplication::translate("Portie", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", nullptr));
        P1GBSettlementDate->setTitle(QApplication::translate("Portie", "\320\224\320\260\321\202\320\260 \320\267\320\260\320\265\320\267\320\264\320\260", nullptr));
        P1DESettlementDate->setDisplayFormat(QApplication::translate("Portie", "yyyy-MM-dd", nullptr));
        P1RBSettlementDateAll->setText(QApplication::translate("Portie", "\320\233\321\216\320\261\320\260\321\217 \320\264\320\260\321\202\320\260", nullptr));
        P1RBSettlementDateBefore->setText(QApplication::translate("Portie", "\320\224\320\276 \320\264\320\260\321\202\321\213", nullptr));
        P1RBSettlementDateIn->setText(QApplication::translate("Portie", "\320\242\320\276\321\207\320\275\320\260\321\217 \320\264\320\260\321\202\320\260", nullptr));
        P1RBSettlementDateAfter->setText(QApplication::translate("Portie", "\320\237\320\276\321\201\320\273\320\265 \320\264\320\260\321\202\321\213", nullptr));
        P1GBEvictionDate->setTitle(QApplication::translate("Portie", "\320\224\320\260\321\202\320\260 \320\276\321\202\321\212\320\265\320\267\320\264\320\260", nullptr));
        P1DEEvictionDate->setDisplayFormat(QApplication::translate("Portie", "yyyy-MM-dd", nullptr));
        P1RBEvictionDateAll->setText(QApplication::translate("Portie", "\320\233\321\216\320\261\320\260\321\217 \320\264\320\260\321\202\320\260", nullptr));
        P1RBEvictionDateBefore->setText(QApplication::translate("Portie", "\320\224\320\276 \320\264\320\260\321\202\321\213", nullptr));
        P1RBEvictionDateIn->setText(QApplication::translate("Portie", "\320\242\320\276\321\207\320\275\320\260\321\217 \320\264\320\260\321\202\320\260", nullptr));
        P1RBEvictionDateAfter->setText(QApplication::translate("Portie", "\320\237\320\276\321\201\320\273\320\265 \320\264\320\260\321\202\321\213", nullptr));
        P1LEPasport->setPlaceholderText(QApplication::translate("Portie", "\320\235\320\265 \320\262\321\213\320\261\321\200\320\260\320\275\320\276", nullptr));
        P1LESecondName->setPlaceholderText(QApplication::translate("Portie", "\320\235\320\265 \320\262\321\213\320\261\321\200\320\260\320\275\320\276", nullptr));
        P1LEFirstName->setPlaceholderText(QApplication::translate("Portie", "\320\235\320\265 \320\262\321\213\320\261\321\200\320\260\320\275\320\276", nullptr));
        P1LEPatronymic->setPlaceholderText(QApplication::translate("Portie", "\320\235\320\265 \320\262\321\213\320\261\321\200\320\260\320\275\320\276", nullptr));
        P1LETelephone->setPlaceholderText(QApplication::translate("Portie", "\320\235\320\265 \320\262\321\213\320\261\321\200\320\260\320\275\320\276", nullptr));
        P1ButtonAccept->setText(QApplication::translate("Portie", "\320\237\320\276\320\270\321\201\320\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Portie: public Ui_Portie {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PORTIE_H
