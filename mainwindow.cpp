/*
QMultilingual
http://gitorious.org/qmultilingual

Copyright (C) 2011 Saljack <saljacky a gmail dot com>

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
version 2 as published by the Free Software Foundation.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "english.h"
#include "czech.h"
#include "deutsch.h"
#include <QTextEdit>
#include <iostream>
#include "settingsdialog.h"
#include <QDebug>
#include "about.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qApp->setWindowIcon(QIcon(":/logo"));
    //    ui->actionSettings->setEnabled(false); //Zatim neni co nastavovat
//    qDebug() << settings.value("SystemTray").toBool();    //DBG
//    qDebug() << settings.value("Remember").toBool();      //DBG
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
    ui->chbEn->setChecked(settings.value("EN").toBool());
    ui->chbDe->setChecked(settings.value("DE").toBool());
    ui->chbCz->setChecked(settings.value("CZ").toBool());
//    qDebug() << "EN" << settings.value("EN").toBool();  //DBG
//    qDebug() << "DE" << settings.value("DE").toBool();  //DBG
//    qDebug() << "CZ" << settings.value("CZ").toBool();  //DBG
    ui->spbNum->setValue(settings.value("number").toInt());
    spbNum_changed();
}

MainWindow::~MainWindow()
{
    if(settings.value("Remember").toBool() == true){
        settings.setValue("EN", ui->chbEn->isChecked());
        settings.setValue("DE", ui->chbDe->isChecked());
        settings.setValue("CZ", ui->chbCz->isChecked());
        settings.setValue("number", ui->spbNum->value());
    }
//    qDebug() << "EN" << settings.value("EN").toBool();
//    qDebug() << "DE" << settings.value("DE").toBool();
//    qDebug() << "CZ" << settings.value("CZ").toBool();
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
    SettingsDialog stg(this, &settings);
    int res = stg.exec();
    if(res == QDialog::Accepted){
        settings.setValue("SystemTray", stg.isTray());
        settings.setValue("Remember", stg.isRemembered());
    }

}

void MainWindow::on_actionExit_triggered()
{
    qApp->quit();
}

void MainWindow::on_actionAbout_QMultilingual_triggered()
{
    About ab;
    ab.exec();
}
QSettings* MainWindow::getSettings(){
    return &settings;
}
