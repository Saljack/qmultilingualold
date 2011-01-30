#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "english.h"
#include "czech.h"
#include "deutsch.h"
#include <QTextEdit>
#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->actionSettings->setEnabled(false); //Zatim neni co nastavovat
    lan[0] = new English();
    lan[1] = new Czech();
    lan[2] = new Deutsch();
    ui->lblNotNum->setVisible(false);
    ui->label_0->setText(QString::fromUtf8(lan[0]->getNameLanguage().c_str()).toUpper());
    ui->label_1->setText(QString::fromUtf8(lan[1]->getNameLanguage().c_str()).toUpper());
    ui->label_2->setText(QString::fromUtf8(lan[2]->getNameLanguage().c_str()).toUpper());
    connect(ui->spbNum,SIGNAL(valueChanged(int)), this, SLOT(spbNum_changed()));
    connect(ui->chbEn,SIGNAL(clicked()), this, SLOT(spbNum_changed()));
    connect(ui->chbCz,SIGNAL(clicked()), this, SLOT(spbNum_changed()));
    connect(ui->chbDe,SIGNAL(clicked()), this, SLOT(spbNum_changed()));
}

MainWindow::~MainWindow()
{
    for(int i=0; i<3; ++i){
        delete lan[i];
    }
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainWindow::on_pushButton_clicked()
{
    //TODO
    std::string str = ui->lneText->text().toUtf8().data();
    std::cout << str;
    std::cout << lan[0]->getNum(str);
    if(lan[0]->getNum(str) != -1){
        ui->le0->setText(QString::number(lan[0]->getNum(str)));
    }else{
        ui->le0->setText("");
    }
    if(lan[1]->getNum(str) != -1){
        ui->le1->setText(QString::number(lan[1]->getNum(str)));
    }else{
        ui->le1->setText("");
    }
    if(lan[2]->getNum(str) != -1){
        ui->le2->setText(QString::number(lan[2]->getNum(str)));
    }else{
        ui->le2->setText("");
    }
}

void MainWindow::spbNum_changed(){
    int numero = ui->spbNum->value();

    if(ui->chbEn->isChecked()){
        ui->le0->setText(QString::fromUtf8(lan[0]->getNumber(numero).c_str()));
    }
    if(ui->chbCz->isChecked()){
        ui->le1->setText(QString::fromUtf8(lan[1]->getNumber(numero).c_str()));
    }
    if(ui->chbDe->isChecked()){
        ui->le2->setText(QString::fromUtf8(lan[2]->getNumber(numero).c_str()));
    }
}

void MainWindow::on_actionAbout_Qt_triggered()
{
    qApp->aboutQt();
}

void MainWindow::on_actionSettings_triggered()
{
 //TODO
}

void MainWindow::on_actionExit_triggered()
{
    qApp->quit();
}

void MainWindow::on_actionAbout_QMultilingual_triggered()
{
    //Predelat na samotnou tridu
       QTextEdit* about = new QTextEdit();
       about->setWindowFlags(Qt::Tool);
       about->setWindowModality(Qt::ApplicationModal);
       about->setText("<h1>About QMultilingual</h1> By Saljack (saljacky@gmail.com)<br/> <b>Version:</b> 0.1-pre-alpha");
       about->setReadOnly(true);
       about->show();
}
