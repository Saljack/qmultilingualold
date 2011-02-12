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
* about.cpp
*
* 11.2.2011
* saljack
* About
*/

#include "about.h"
#include "ui_about.h"

About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
    ui->lblIcon->setText("<img src=\":/logo\" />");
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(accept()));
    ui->label_2->setText("<b>Version</b>: 0.1");
}

About::~About()
{
    delete ui;
}

void About::changeEvent(QEvent *e)
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
