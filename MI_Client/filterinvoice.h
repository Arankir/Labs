#ifndef FILTERINVOICE_H
#define FILTERINVOICE_H

#include <QString>
#include <QDate>

class FilterInvoice
{
public:
    FilterInvoice();
    bool DateAll(QString a, QString b);
    bool DateBefore(QString a, QString b);
    bool DateAfter(QString a, QString b);
    bool DateIn(QString a, QString b);
    bool IngredientAll(int);
    bool IngredientInc(int);
    bool IngredientDec(int);
    bool InvoiceTitle(QString a, QString b);
    bool InvoiceEmpty(QString a, QString b);
    bool IngredientTitle(QString a, QString b);
    bool IngredientEmpty(QString a, QString b);
    bool StockTitle(QString a, QString b);
    bool StockEmpty(QString a, QString b);
};

#endif // FILTERINVOICE_H
