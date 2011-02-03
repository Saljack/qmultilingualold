/** @file multilingual_cli.cpp*/
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


#include "multilingual_cli.h"
#include <limits>

using namespace std;

Multilingual_cli::Multilingual_cli()
{
    int cislo;
    while (true) {
        cout << "Zadejte cislo (0-999999999): ";
        cin >> cislo;
        if (cin.fail()) {
            cin.clear();
            cin.ignore ( std::numeric_limits<std::streamsize>::max(), '\n' );
            cout << "Nezadali jste číslo nebo je cislo větší!\n";
            continue;
        } else {
            if (cislo<0) {
                cout << "Číslo musí být kladné!" << endl;
                cin.clear();
                continue;
            }
            if (cislo>999999999) {
                cout << "Číslo musí být menší než 999999999!" << endl;
                continue;
            }
            break;
        }
    }
     cout << endl;

    Language * jazyky[3];
    jazyky[0] = new Czech();
    cout << "V "+jazyky[0]->getNameLanguage()+" je číslo zapsané slovy: ";
    jazyky[0]->printNum(cislo);
    jazyky[1] = new English();
    cout << "V "+jazyky[1]->getNameLanguage()+" je číslo zapsané slovy: ";
    jazyky[1]->printNum(cislo);
    jazyky[2] = new Deutsch();
    cout << "V "+jazyky[2]->getNameLanguage()+" je číslo zapsané slovy: ";
    jazyky[2] ->printNum(cislo);

    string number;
    cout << endl <<"Zadejte slovně zapsané číslo v libovolném z těchto jazyků - čeština, němčina, angličtina: ";
    getline(cin, number);
    getline(cin, number);
    if (cin.fail()) {
        cout << "Špatný vstup!\n";
        return;
    }
    int tmp;
    bool zapano = false;
    for (int i =0; i<3; ++i) {
        tmp = jazyky[i]->getNum(number);
        if (tmp>-1) {
            cout << endl <<"Hledané číslo je zapsané v: \"" << jazyky[i]->getNameLanguage() << "\" a zapsané číslicemi je: "<< tmp << endl;
	    zapano = true;
            break;
        }
    }
    
    if(!zapano){
      cout << "Hledané číslo není zapsané v některém z implementovaných jazycích"<< endl;
    }

    for (int i = 0 ; i<3; ++i) {
        delete jazyky[i];
    }
}

Multilingual_cli::~Multilingual_cli()
{

}

