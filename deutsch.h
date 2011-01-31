/** @file deutsch.h*/
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
