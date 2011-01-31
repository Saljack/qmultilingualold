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
#include <QtGui/QApplication>
#include "mainwindow.h"
#include "multilingual_cli.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    bool cli = false;
    QList<QString>::iterator i = a.arguments().begin();
/*    ++i;*///test
    while(i != a.arguments().end()){
        if(*i == "-c" || *i == "--cli"){
            cli = true;
        }
        if(*i == "-h" || *i == "--help"){
            std::cout << "QMultilingual help" << std::endl;
            std::cout << "Created by Saljack" << std::endl;
            std::cout << "  --help, -h \tthis help page" << std::endl;
            std::cout << "  --cli, -c \trun without gui" << std::endl;
            return 0;
        }
        ++i;
    }
    if(cli){
        Multilingual_cli cl;
//        delete cl;
        return 0;
    }
    MainWindow w;
    w.show();

    return a.exec();

}
