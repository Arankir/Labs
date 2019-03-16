#include "warehousekeeper.h"
#include "ui_warehousekeeper.h"

Warehousekeeper::Warehousekeeper(QString ips, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Warehousekeeper){
    IP=ips;
    ui->setupUi(this);
    ui->W2DEDateChange->setDate(QDate::currentDate());
    ui->W3DEDate->setDate(QDate::currentDate());
    ui->GBW1->move(170,50);
    ui->GBW2->move(170,50);
    ui->GBW3->move(170,50);
    ui->W1T1->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->W2Table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    Warehousekeeper::on_Hide_clicked();
}

Warehousekeeper::~Warehousekeeper(){
    delete ui;
}

void Warehousekeeper::on_LogOut_clicked(){
    emit loginOpen();
    this->hide();
}

void Warehousekeeper::on_Hide_clicked(){
    ui->GBW1->setVisible(false);
    ui->GBW2->setVisible(false);
    ui->GBW3->setVisible(false);
    ui->Hide->setVisible(false);
}

void Warehousekeeper::on_W1BSearch_clicked(){
    QStandardItemModel *W1T1M = new QStandardItemModel;
    QStringList hh;
    QJsonArray JsonA=whk1.object().value("ingredient_stock").toArray();
    hh.append("Склад");
    hh.append("Ингредиент");
    hh.append("Кол-во");
    W1T1M->setHorizontalHeaderLabels(hh);
    QString Ing=ui->W1CB1->currentText();
    QString Stock=ui->W1CB2->currentText();
    int k=0;
    for(int i=0;i<JsonA.size();i++){
        if((Ing!="Не выбрано" ? JsonA[i].toObject().value("ingredient_title").toString()==Ing : JsonA[i].toObject().value("ingredient_title").toString()!="")&&(Stock!="Не выбрано" ? JsonA[i].toObject().value("stock_title").toString()==Stock : JsonA[i].toObject().value("stock_title").toString()!="")){
            QStandardItem *Item1;
            Item1 = new QStandardItem(QString(JsonA[i].toObject().value("stock_title").toString()));
            W1T1M->setItem(k,0,Item1);
            QStandardItem *Item2;
            Item2 = new QStandardItem(QString(JsonA[i].toObject().value("ingredient_title").toString()));
            W1T1M->setItem(k,1,Item2);
            QStandardItem *Item3;
            Item3 = new QStandardItem(QString(JsonA[i].toObject().value("amount").toString()+" "+JsonA[i].toObject().value("unit").toString()));
            W1T1M->setItem(k,2,Item3);
            k++;
        }
    }
    ui->W1T1->setModel(W1T1M);
    ui->W1T1->resizeRowsToContents();
}

void Warehousekeeper::on_WhkButtonShowW1_clicked(){
    Network *whks1 = new Network;
    connect(whks1,SIGNAL(onReady(Network *)),this,SLOT(OnResultWhk1(Network *)));
    whks1->Get("http://"+IP+":5555/stock_ingredients.json");
    QStandardItemModel *W1T1M = new QStandardItemModel;
    QStringList hh;
    hh.append("Склад");
    hh.append("Ингредиент");
    hh.append("Кол-во");
    W1T1M->setHorizontalHeaderLabels(hh);
    ui->W1T1->setModel(W1T1M);
    Warehousekeeper::on_Hide_clicked();
    ui->GBW1->setVisible(true);
    ui->Hide->setVisible(true);
}

void Warehousekeeper::on_WhkButtonShowW2_clicked(){
    Network *whks2 = new Network;
    connect(whks2,SIGNAL(onReady(Network *)),this,SLOT(OnResultWhk2(Network *)));
    whks2->Get("http://"+IP+":5555/invoice.json");
    Warehousekeeper::on_Hide_clicked();
    ui->GBW2->setVisible(true);
    ui->Hide->setVisible(true);
}

void Warehousekeeper::on_WhkButtonShowW3_clicked(){
    Network *whks3 = new Network;
    connect(whks3,SIGNAL(onReady(Network *)),this,SLOT(OnResultWhk3(Network *)));
    whks3->Get("http://"+IP+":5555/wkinfo.json");
    Warehousekeeper::on_Hide_clicked();
    ui->GBW3->setVisible(true);
    ui->Hide->setVisible(true);
}

void Warehousekeeper::OnResultWhk1(Network *whk){
    qDebug() << whk->GetAnswer();
    if(whk->GetAnswer()==""){
        qDebug() <<"Error";
        qDebug() << whk->GetError();
        } else {
        whk1=QJsonDocument::fromJson(whk->GetAnswer().toUtf8());
        QJsonArray JsonA=whk1.object().value("ingredient_stock").toArray();
        QStandardItemModel *C2T1M = new QStandardItemModel;
        QStringList hh;
        hh.append("Склад");
        hh.append("Ингредиент");
        hh.append("Кол-во");
        C2T1M->setHorizontalHeaderLabels(hh);
        for(int i=0;i<JsonA.size();i++){
            QStandardItem *Item1;
            Item1 = new QStandardItem(QString(JsonA[i].toObject().value("stock_title").toString()));
            C2T1M->setItem(i,0,Item1);
            QStandardItem *Item2;
            Item2 = new QStandardItem(QString(JsonA[i].toObject().value("ingredient_title").toString()));
            C2T1M->setItem(i,1,Item2);
            QStandardItem *Item3;
            Item3 = new QStandardItem(QString(JsonA[i].toObject().value("amount").toString()+" "+JsonA[i].toObject().value("unit").toString()));
            C2T1M->setItem(i,2,Item3);
        }
        JsonA=whk1.object().value("Ingredients").toArray();
        ui->W1CB1->clear();
        ui->W1CB1->addItem("Не выбрано");
        for(int i=0;i<JsonA.size();i++){
            ui->W1CB1->addItem(JsonA[i].toString());
        }
        JsonA=whk1.object().value("Stocks").toArray();
        ui->W1CB2->clear();
        ui->W1CB2->addItem("Не выбрано");
        for(int i=0;i<JsonA.size();i++){
            ui->W1CB2->addItem(JsonA[i].toString());
        }
        ui->W1T1->setModel(C2T1M);
        ui->W1T1->resizeRowsToContents();
        ui->W1T1->resizeColumnsToContents();
        }
}

void Warehousekeeper::OnResultWhk2(Network *whk){
    qDebug() << whk->GetAnswer();
    if(whk->GetAnswer()==""){
        qDebug() <<"Error";
        qDebug() << whk->GetError();
        } else {
        whk2=QJsonDocument::fromJson(whk->GetAnswer().toUtf8());
        QJsonArray JsonA=whk2.object().value("Invoice").toArray();
        QStandardItemModel *W2T1M = new QStandardItemModel;
        QStringList hh;
        hh.append("Накладная №");
        hh.append("Дата");
        hh.append("Склад");
        hh.append("Продукт");
        hh.append("Кол-во");
        W2T1M->setHorizontalHeaderLabels(hh);
        for(int i=0;i<JsonA.size();i++){
            QStandardItem *Item1;
            Item1 = new QStandardItem(QString(JsonA[i].toObject().value("id").toString()));
            W2T1M->setItem(i,0,Item1);
            QStandardItem *Item2;
            Item2 = new QStandardItem(QString(JsonA[i].toObject().value("date").toString()));
            W2T1M->setItem(i,1,Item2);
            QStandardItem *Item3;
            Item3 = new QStandardItem(QString(JsonA[i].toObject().value("title-stock").toString()));
            W2T1M->setItem(i,2,Item3);
            QStandardItem *Item4;
            Item4 = new QStandardItem(QString(JsonA[i].toObject().value("title-ingredient").toString()));
            W2T1M->setItem(i,3,Item4);
            QStandardItem *Item5;
            Item5 = new QStandardItem(QString(JsonA[i].toObject().value("amount").toString()+" "+JsonA[i].toObject().value("unit").toString()));
            W2T1M->setItem(i,4,Item5);
        }
        JsonA=whk2.object().value("Ingredients").toArray();
        ui->W2CBIngredients->clear();
        ui->W2CBIngredients->addItem("Не выбрано");
        for(int i=0;i<JsonA.size();i++){
            ui->W2CBIngredients->addItem(JsonA[i].toString());
        }
        JsonA=whk2.object().value("Stocks").toArray();
        ui->W2CBStocks->clear();
        ui->W2CBStocks->addItem("Не выбрано");
        for(int i=0;i<JsonA.size();i++){
            ui->W2CBStocks->addItem(JsonA[i].toString());
        }
        ui->W2Table->setModel(W2T1M);
        ui->W2Table->resizeRowsToContents();
        ui->W2Table->resizeColumnsToContents();
        }
}

void Warehousekeeper::OnResultWhk3(Network *whk){
    qDebug() << whk->GetAnswer();
    if(whk->GetAnswer()==""){
        qDebug() <<"Error";
        qDebug() << whk->GetError();
        } else {
        whk3=QJsonDocument::fromJson(whk->GetAnswer().toUtf8());
        QJsonArray JAIng=whk3.object().value("Ingredients").toArray();
        QJsonArray JASto=whk3.object().value("Stocks").toArray();
        QWidget* widget = new QWidget;
        QFormLayout *layout = new QFormLayout;
        for(int i=0;i<JAIng.size();i++){
            QCheckBox *chb = new QCheckBox(this);
            chb->setObjectName("W3chb"+JAIng[i].toObject().value("title").toString());
            chb->setText(JAIng[i].toObject().value("title").toString()+" ("+JAIng[i].toObject().value("unit").toString()+")");
            layout->addWidget(chb);
            connect(chb,SIGNAL(stateChanged(int)),this,SLOT(on_W3chbPressed(int)));
            }
        widget->setLayout(layout);
        ui->W3SAAllIngredients->setWidget(widget);
        LIngredients.clear();
        QWidget* widget2 = new QWidget;
        QFormLayout *layout2 = new QFormLayout;
        widget2->setLayout(layout2);
        ui->W3SACheckedIngredients->setWidget(widget2);
        for(int i=0;i<JASto.size();i++){
            ui->W3CBStocks->addItem(JASto[i].toString());
            }
        }
}


void Warehousekeeper::on_W2ButtonApply_clicked(){
    QStandardItemModel *W2T1M = new QStandardItemModel;
    QStringList hh;
    QJsonArray JsonA=whk2.object().value("Invoice").toArray();
    hh.append("Накладная №");
    hh.append("Дата");
    hh.append("Склад");
    hh.append("Продукт");
    hh.append("Кол-во");
    W2T1M->setHorizontalHeaderLabels(hh);
    FilterInvoice FI;
    if(ui->W2CBStocks->currentText()!="Не выбрано")
        sto=&FilterInvoice::StockTitle;
    else
        sto=&FilterInvoice::StockEmpty;
    if(ui->W2LEInvoice->text()!="")
        inv=&FilterInvoice::InvoiceTitle;
    else
        inv=&FilterInvoice::InvoiceEmpty;
    if(ui->W2CBIngredients->currentText()!="Не выбрано")
        tin=&FilterInvoice::IngredientTitle;
    else
        tin=&FilterInvoice::IngredientEmpty;
    int k=0;
    for(int i=0;i<JsonA.size();i++){
//        if((FI.*dat)(JsonA[i].toObject().value("date").toString(),ui->W2DEDateChange->text()))
//            if((FI.*sto)(JsonA[i].toObject().value("title-stock").toString(),ui->W2CBStocks->currentText()))
//                if((FI.*ing)(JsonA[i].toObject().value("amount").toString().toInt()))
//                    if((FI.*inv)(JsonA[i].toObject().value("id").toString(),ui->W2LEInvoice->text()))
//                        if((FI.*tin)(JsonA[i].toObject().value("title-ingredient").toString(),ui->W2CBIngredients->currentText())){
        if((FI.*dat)(JsonA[i].toObject().value("date").toString(),ui->W2DEDateChange->text())&&(FI.*sto)(JsonA[i].toObject().value("title-stock").toString(),ui->W2CBStocks->currentText())&&(FI.*ing)(JsonA[i].toObject().value("amount").toString().toInt())&&(FI.*inv)(JsonA[i].toObject().value("id").toString(),ui->W2LEInvoice->text())&&(FI.*tin)(JsonA[i].toObject().value("title-ingredient").toString(),ui->W2CBIngredients->currentText())){
            QStandardItem *Item1;
            Item1 = new QStandardItem(QString(JsonA[i].toObject().value("id").toString()));
            W2T1M->setItem(k,0,Item1);
            QStandardItem *Item2;
            Item2 = new QStandardItem(QString(JsonA[i].toObject().value("date").toString()));
            W2T1M->setItem(k,1,Item2);
            QStandardItem *Item3;
            Item3 = new QStandardItem(QString(JsonA[i].toObject().value("title-stock").toString()));
            W2T1M->setItem(k,2,Item3);
            QStandardItem *Item4;
            Item4 = new QStandardItem(QString(JsonA[i].toObject().value("title-ingredient").toString()));
            W2T1M->setItem(k,3,Item4);
            QStandardItem *Item5;
            Item5 = new QStandardItem(QString(JsonA[i].toObject().value("amount").toString()+" "+JsonA[i].toObject().value("unit").toString()));
            W2T1M->setItem(k,4,Item5);
            k++;
        }
    }
    ui->W2Table->setModel(W2T1M);
    ui->W2Table->resizeRowsToContents();
}

void Warehousekeeper::on_W2RBAllDate_clicked()
{
    dat =&FilterInvoice::DateAll;
}

void Warehousekeeper::on_W2RBBeforeDate_clicked()
{
    dat =&FilterInvoice::DateBefore;
}

void Warehousekeeper::on_W2RBInDate_clicked()
{
    dat =&FilterInvoice::DateIn;
}

void Warehousekeeper::on_W2RBAfterDate_clicked()
{
    dat =&FilterInvoice::DateAfter;
}

void Warehousekeeper::on_W2RBAllChanges_clicked()
{
    ing =&FilterInvoice::IngredientAll;
}

void Warehousekeeper::on_W2RBIncChanges_clicked()
{
    ing =&FilterInvoice::IngredientInc;
}

void Warehousekeeper::on_W2RBDecChanges_clicked()
{
    ing =&FilterInvoice::IngredientDec;
}

void Warehousekeeper::on_W3chbPressed(int state){
    QCheckBox* chb = (QCheckBox*) sender();
    QRegExp exp("[1-9]{1}[0-9]{0,10}");
    if(state == 2){
        LIngredients.push_back(chb);
        } else {
        for(int i=0; i<LIngredients.size();i++){
            if (LIngredients[i] == chb)
                LIngredients.takeAt(i);
            }
        }
    QFormLayout* layout = new QFormLayout;
    QWidget* widget = new QWidget;
    for(int i=0; i<LIngredients.size();i++){
        QLineEdit* LiEd = new QLineEdit();
        LiEd->setObjectName(LIngredients[i]->objectName().mid(5,LIngredients[i]->objectName().length()-5));
        LiEd->setValidator(new QRegExpValidator(exp,this));
        layout->addRow(new QLabel(LIngredients[i]->text()),LiEd);
        }
    widget->setLayout(layout);
    ui->W3SACheckedIngredients->setWidget(widget);
}

void Warehousekeeper::on_W3BApply_clicked(){
    //{"date":"2019-02-13","stock":"Подвал","id":"982", "ingredients": [{"title":"Морковь","amount":20},...]}
    QJsonArray JAInv=whk3.object().value("Invoices").toArray();
    if(ui->W3LEInvoice->text()!=""){
        bool accept=true;
        for (int i=0;i<JAInv.size();i++) {
            if(JAInv[i].toObject().value("id").toString()==ui->W3LEInvoice->text()){
                accept=false;
                break;
                }
            }
        if(accept){
            if(LIngredients.size()!=0){
                for (int i=0;i<LIngredients.size();i++) {
                    if(findChild<QLineEdit*>(LIngredients[i]->objectName().mid(5,LIngredients[i]->objectName().length()-5))->text()=="")
                        accept=false;
                    }
                if(accept){
                    QJsonObject post;
                    post["date"]=ui->W3DEDate->text();
                    post["stock"]=ui->W3CBStocks->currentText();
                    post["id"]=ui->W3LEInvoice->text();
                    QJsonArray ingredients;
                    for (int i=0;i<LIngredients.size();i++) {
                        QJsonObject ingredient;
                        ingredient["title"]=LIngredients[i]->objectName().mid(5,LIngredients[i]->objectName().length()-5);
                        ingredient["amount"]=findChild<QLineEdit*>(LIngredients[i]->objectName().mid(5,LIngredients[i]->objectName().length()-5))->text().toInt();
                        ingredients.append(ingredient);
                    }
                    post["ingredients"]=ingredients;
                    QJsonDocument doc;
                    doc.setObject(post);
                    qDebug() << doc;
                    Network *net = new Network;
                    connect(net,SIGNAL(onReady(Network *)),this,SLOT(on_ResultAddInvoice(Network *)));
                    net->Post("http://"+IP+":5555/addinvoice.json", doc);
                } else
                    QMessageBox::warning(this,"Ошибка!","Поля с количеством ингредиентов не могут быть пустыми!");
            } else
                QMessageBox::warning(this,"Ошибка!","Выберите продукты!");
        } else
            QMessageBox::warning(this,"Ошибка!","Накладная с таким номером уже существует!");
    } else
        QMessageBox::warning(this,"Ошибка!","Введите номер накладной!");
}

void Warehousekeeper::on_ResultAddInvoice(Network *a){
    qDebug() << a->GetAnswer();
    qDebug() << a->GetError();
    if(a->GetAnswer()=="YES"){
        Network *whks3 = new Network;
        connect(whks3,SIGNAL(onReady(Network *)),this,SLOT(OnResultWhk3(Network *)));
        whks3->Get("http://"+IP+":5555/wkinfo.json");
        QMessageBox::information(this,"Успешно!","Новая накладная добавлена!");
        } else {
        if(a->GetAnswer()=="NO"){
            QMessageBox::warning(this,"Ошибка!","Не удалось добавить накладную!");
            } else {
                QMessageBox::warning(this,"Ошибка!","Не удалось добавить накладную! ("+a->GetAnswer()+")");
            }
        }
}
