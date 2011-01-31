/** @file english.h*/
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


#ifndef ENGLISH_H
#define ENGLISH_H
#include "language.h"


/**
 * Predstavuje veskere operace s prevadenymi cisly v anglictine
 */
class English: public Language
{
public:
    English();
    English ( const English& other );
    virtual ~English();
    int getNum(string cislo);
    string getNumber(int num);
    string getNameLanguage();
    
private:
    string getJed(int num);
    string getDes(int num);
    string getSto(int num);
    string getTis(int num);
    string getMil(int num);
    int getNumSto(string cislo);
    int getNumDes(string cislo);
    int getNumTis(string cislo);
    int getNumJed(string cislo);
    int getNumMil(string cislo);
    int getNumJedMist(string cislo);
    int getNumDvoumistne(string cislo);
    int getNumTriMistne(string cislo);
    int getPre(string cislo);
};

#endif // ENGLISH_H
