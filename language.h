/** @file language.h*/
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
