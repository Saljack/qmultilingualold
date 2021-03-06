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
* settingsdialog.h
*
* 11.2.2011
* saljack
* SettingsDialog
*/

#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include <QDialog>
#include <QSettings>

namespace Ui {
    class SettingsDialog;
}

class SettingsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDialog(QWidget *parent = 0, QSettings *qset = 0);
    ~SettingsDialog();
    bool isTray();
    bool isRemembered();


protected:
    void changeEvent(QEvent *e);

private:
    Ui::SettingsDialog *ui;
    bool useTray;
    bool remember;
private slots:
    void pressed_btnLanguage();
    void setTray(bool tr);
    void setRemember(bool rem);
};

#endif // SETTINGSDIALOG_H
