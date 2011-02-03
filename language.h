/** @file language.h*/
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


#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <string>
#include <iostream>

using namespace std;

/**
 * Predstavuje rozhrani pro jazyky a pro prevadeni cisel 
 */
class Language {

public:
    Language();
    Language ( const Language& other );
    virtual void printNum(int num);
    virtual string getNumber(int num) = 0;
    virtual ~Language();
    void setGramerCisla(string gram[]);
    void setGramerRady(string gram[]);
    virtual int getNum(string cislo) = 0;
    string withOutSpace(string cislo);
    virtual string getNameLanguage() = 0;
    string getId();
    //Staticke konstanty
    static const int MILION = 1000000;
    static const int TISIC = 1000;
    static const int STO = 100;
    static const int DESET = 10;
protected:
    string cisla[10];
    string rady[4];
};

#endif // LANGUAGE_H
