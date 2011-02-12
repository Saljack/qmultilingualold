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
* about.h
*
* 11.2.2011
* saljack
* About
*/

#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>

namespace Ui {
    class About;
}

class About : public QDialog
{
    Q_OBJECT

public:
    explicit About(QWidget *parent = 0);
    ~About();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::About *ui;
};

#endif // ABOUT_H
