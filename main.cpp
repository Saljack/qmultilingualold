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


/**
  UTF 8
  */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    bool cli = false;
    int lanI = 0;
    int num = -1;
    QString text;
    //SET Language
    Language* lan[LANGUAGE];
    lan[0] = new English();
    lan[1] = new Czech();
    lan[2] = new Deutsch();
    QList<QString> argumenty = a.arguments();

    QList<QString>::iterator i = argumenty.begin();


    while(i != argumenty.end()){
        if(*i == "-c" || *i == "--cli"){
            cli = true;
        }
        if(*i == "-h" || *i == "--help"){
            std::cout << "QMultilingual help" << std::endl;
            std::cout << "Created by Saljack" << std::endl;
            std::cout << "  --help, -h \tthis help page" << std::endl;
            std::cout << "  --cli, -c \trun without gui" << std::endl;
            std::cout << "  -l [EN|DE|CZ]\tlanguage default is English. If it is run without next arguemt, it will write list of language." << std::endl;
            std::cout << "  -n NUMBER \tNUMBER must be integer and >= 0. Return string of number in chosen language." << std::endl;
            std::cout << "  -t STRING \tSTRING must be string and >= 0. Return integer number of string in chosen language." << std::endl;
            return 0;
        }

        //Language
        if(*i == "-l"){
            ++i;
            if(i == argumenty.end()){
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

        //Number
        if(*i == "-n"){
            ++i;
            if(i == argumenty.end()){
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

        //Text
        if(*i == "-t"){

            cli = true;
            ++i;
            if( i == argumenty.end()){
                cout << "Wrong syntax. After -t must be string." << endl;
                return 0;
            }
            if((*i).at(0) == '"'){
                cout << "Wrong syntax. To help run qmultilingual --help." << endl;
                return 0;
            }
            text = *i;
            ++i;
            while( i != argumenty.end()){
                if((*i).at(0) == '-'){
                    break;
                }
                text += " " + *i;
                ++i;
            }
            --i;


        }

        ++i;
    }

    if(cli){
        if(num != -1){
            cout << lan[lanI]->getNumber(num) << endl;
        }else if(!text.isEmpty()){
            int nbr = lan[lanI]->getNum(text.toUtf8().data());
            if(nbr >= 0){
                cout <<  nbr << endl;
            } else {
                cout << text.toUtf8().data() << " is not number in " << lan[lanI]->getNameLanguage() << endl;
            }
        }else{
            Multilingual_cli cl;
        }
        return 0;
    }

    MainWindow w;
    w.show();

    return a.exec();
}
