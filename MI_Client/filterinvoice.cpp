#include "filterinvoice.h"

FilterInvoice::FilterInvoice()
{

}


bool FilterInvoice::DateAll(QString, QString){
    return true;
}
bool FilterInvoice::DateBefore(QString Json, QString Form){
    QDate DateJson;
    QDate DateForm;
    if(DateJson.fromString(Json,"yyyy-MM-dd")<DateForm.fromString(Form,"yyyy-MM-dd"))
        return true;
    else
        return false;
}
bool FilterInvoice::DateAfter(QString Json, QString Form){
    QDate DateJson;
    QDate DateForm;
    if(DateJson.fromString(Json,"yyyy-MM-dd")>DateForm.fromString(Form,"yyyy-MM-dd"))
        return true;
    else
        return false;
}
bool FilterInvoice::DateIn(QString Json, QString Form){
    QDate DateJson;
    QDate DateForm;
    if(DateJson.fromString(Json,"yyyy-MM-dd")==DateForm.fromString(Form,"yyyy-MM-dd"))
        return true;
    else
        return false;
}

bool FilterInvoice::IngredientAll(int){
return true;
}
bool FilterInvoice::IngredientInc(int a){
if(a>0)
    return true;
else
    return false;
}
bool FilterInvoice::IngredientDec(int a){
if(a<0)
    return true;
else
    return false;
}

bool FilterInvoice::InvoiceTitle(QString a, QString b){
if(a==b)
    return true;
else
    return false;
}
bool FilterInvoice::InvoiceEmpty(QString, QString){
return true;
}


bool FilterInvoice::IngredientTitle(QString a, QString b){
    if(a==b)
        return true;
    else
        return false;
}
bool FilterInvoice::IngredientEmpty(QString, QString){
    return true;
}

bool FilterInvoice::StockTitle(QString a, QString b){
if(a==b)
    return true;
else
    return false;
}
bool FilterInvoice::StockEmpty(QString, QString){
return true;
}
