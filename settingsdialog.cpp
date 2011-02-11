/*
    QMultilingual
    http://gitorious.org/qmultilingual
    
    Copyright (C) 2010-2011 Saljack <saljacky a gmail dot com>
    
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

/**
* settingsdialog.cpp
*
* 11.2.2011
* saljack
* SettingsDialog
*/

#include "settingsdialog.h"
#include "ui_settingsdialog.h"
#include <iostream>
#include <QDebug>
#include <QSettings>

SettingsDialog::SettingsDialog(QWidget *parent, QSettings* qset) :
    QDialog(parent),
    ui(new Ui::SettingsDialog)
{
    ui->setupUi(this);
    connect(ui->btnCancel, SIGNAL(pressed()), SLOT(reject()));
    connect(ui->btnOk, SIGNAL(pressed()), SLOT(accept()));
    connect(ui->btnLanguage, SIGNAL(pressed()), this, SLOT(pressed_btnLanguage()));
    connect(ui->chbTray, SIGNAL(toggled(bool)), this, SLOT(setTray(bool)));
    connect(ui->chbRem, SIGNAL(toggled(bool)), this, SLOT(setRemember(bool)));
    ui->chbRem->setChecked(qset->value("Remember").toBool());
    remember = ui->chbRem->isChecked();
    ui->chbTray->setChecked(qset->value("SystemTray").toBool());
    useTray = ui->chbTray->isChecked();

}

SettingsDialog::~SettingsDialog()
{
    delete ui;
}

void SettingsDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void SettingsDialog::pressed_btnLanguage(){
    //TODO
    //Show language dialog for load new language
}

bool SettingsDialog::isTray(){
    return useTray;
}

bool SettingsDialog::isRemembered(){
    return remember;
}

void SettingsDialog::setRemember(bool rem){
    remember = rem;
}

void SettingsDialog::setTray(bool tr){
    useTray = tr;
}

