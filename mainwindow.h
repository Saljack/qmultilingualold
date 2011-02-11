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
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "language.h"
#include <QSystemTrayIcon>
#include <QSettings>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QSettings* getSettings();

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_pushButton_clicked();
    void spbNum_changed();

    void on_actionAbout_Qt_triggered();

    void on_actionSettings_triggered();

    void on_actionExit_triggered();

    void on_actionAbout_QMultilingual_triggered();

private:
    Ui::MainWindow *ui;
    Language* lan[3];
    QSystemTrayIcon* tray;
    QSettings settings;

};

#endif // MAINWINDOW_H
