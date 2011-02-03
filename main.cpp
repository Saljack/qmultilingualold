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

const int LANGUAGE = 3; // Number of language

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    bool cli = false;
    int lanI = 0;
    int num = -1;
    //SET Language
    Language* lan[LANGUAGE];
    lan[0] = new English();
    lan[1] = new Czech();
    lan[2] = new Deutsch();

    QList<QString>::iterator i = a.arguments().begin();
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

        if(*i == "-l"){
            ++i;
            if(i == a.arguments().end()){
                std::cout << "Wrong syntax. After -l must be language id." << std::endl <<" Now it is implemented: " << std::endl;
                for(int z=0; z< LANGUAGE; ++z){
                    std::cout << lan[z]->getId() << " - " << lan[z]->getNameLanguage() << endl;
                }
                return 0;
            }

            QString l = i->toLower();

            //Language
            for(int z=0; z< LANGUAGE; ++z){
                if(l == QString(lan[z]->getId().c_str())){
                    lanI = z;
                    break;
                }
            }

            if(lanI == -1){
                std::cout << "Wrong syntax. After -l must be language id." << std::endl <<"Now it is implemented: " << std::endl;
                for(int z=0; z< LANGUAGE; ++z){
                    std::cout << "\t" <<lan[z]->getId() << " - " << lan[z]->getNameLanguage() << endl;
                }
                return 0;
            }
        }

        if(*i == "-n"){
            ++i;
            if(i == a.arguments().end()){
                std::cout << "Wrong syntax. After -n must be integer." << std::endl;
                return 0;
            }
            bool ok;
            int n = i->toInt(&ok);
            if(ok){
                num = n;
            }else{
                std::cout << "Wrong syntax. After -n must be integer." << std::endl;
                return 0;
            }
        }

        ++i;
    }

    if(cli){
        if(num != -1){
            cout << lan[lanI]->getNumber(num) << endl;
        }else{
            Multilingual_cli cl;
        }
        return 0;
    }

    MainWindow w;
    w.show();

    return a.exec();
}
