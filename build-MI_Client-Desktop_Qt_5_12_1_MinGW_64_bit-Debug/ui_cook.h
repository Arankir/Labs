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
#include <QtWidgets/QFrame>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Cook
{
public:
    QPushButton *whatchDish;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QWidget *widget;
    QPushButton *pushButton_6;
    QFrame *line;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_2;

    void setupUi(QWidget *Cook)
    {
        if (Cook->objectName().isEmpty())
            Cook->setObjectName(QString::fromUtf8("Cook"));
        Cook->resize(829, 577);
        whatchDish = new QPushButton(Cook);
        whatchDish->setObjectName(QString::fromUtf8("whatchDish"));
        whatchDish->setGeometry(QRect(10, 50, 151, 23));
        pushButton_2 = new QPushButton(Cook);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 80, 151, 23));
        pushButton_3 = new QPushButton(Cook);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 300, 151, 23));
        pushButton_4 = new QPushButton(Cook);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 330, 151, 23));
        pushButton_5 = new QPushButton(Cook);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(750, 10, 71, 23));
        widget = new QWidget(Cook);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(170, 50, 641, 511));
        pushButton_6 = new QPushButton(Cook);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setEnabled(true);
        pushButton_6->setGeometry(QRect(780, 60, 21, 23));
        pushButton_6->setLayoutDirection(Qt::LeftToRight);
        line = new QFrame(Cook);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(170, 36, 641, 31));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(Cook);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(160, 50, 20, 511));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(Cook);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(800, 50, 21, 511));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(Cook);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(170, 550, 641, 21));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        retranslateUi(Cook);

        QMetaObject::connectSlotsByName(Cook);
    } // setupUi

    void retranslateUi(QWidget *Cook)
    {
        Cook->setWindowTitle(QApplication::translate("Cook", "Form", nullptr));
        whatchDish->setText(QApplication::translate("Cook", "\320\237\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \320\261\320\273\321\216\320\264\320\260", nullptr));
        pushButton_2->setText(QApplication::translate("Cook", "\320\237\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \320\270\320\275\320\263\321\200\320\270\320\264\320\270\320\265\320\275\321\202\321\213", nullptr));
        pushButton_3->setText(QApplication::translate("Cook", "\320\241\320\276\320\267\320\264\320\260\321\202\321\214 \320\274\320\265\320\275\321\216", nullptr));
        pushButton_4->setText(QApplication::translate("Cook", "\320\237\320\276\321\201\320\274\320\276\321\202\321\200\320\265\321\202\321\214 \320\277\321\200\320\276\321\210\320\273\321\213\320\265 \320\274\320\265\320\275\321\216", nullptr));
        pushButton_5->setText(QApplication::translate("Cook", "\320\237\320\265\321\200\320\265\320\267\320\260\320\271\321\202\320\270", nullptr));
        pushButton_6->setText(QApplication::translate("Cook", "\320\245", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Cook: public Ui_Cook {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COOK_H
