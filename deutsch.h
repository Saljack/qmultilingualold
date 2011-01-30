/** @file deutsch.h*/
/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) <year>  <name of author>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef DEUTSCH_H
#define DEUTSCH_H
#include "language.h"

/**
 * Predstavuje veskere operace s prevadenymi cisly v nemcine
 */
class Deutsch: public Language {

public:
    Deutsch();
    Deutsch ( const Deutsch& other );
    virtual ~Deutsch();
    int getNum(string cislo);
    string getNumber(int num);
    string getNameLanguage();

private:
    string getJed (int num );
    string getDes (int num );
    string getSto (int num );
    string getTis (int num );
    string getMil (int num );
    string getDesitku (int num);
    int getNumPre (string cislo);
    int getNumSto (string cislo);
    int getNumDes (string cislo);
    int getNumJed (string cislo);
    int getNumOnlyDes (string cislo);
    int getNumDesitky(string cislo);
};

#endif // DEUTSCH_H
