/** @file language.cpp*/
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


#include "language.h"
using namespace std;

Language::Language() {

}

Language::Language ( const Language& other ) {

}

Language::~Language() {

}
/**
 * Nastavi gramatiku, cisla od 0-9
 * @param gram - pole s cisly
 */
void Language::setGramerCisla ( string gram[] ) {
    for ( int i=0; i<10; i++ ) {
        cisla[i] = gram[i];
    }
}

/**
 * Nastavi gramatiku, rady tj. stovky tisice
 * @param gram - pole s rady
 */
void Language::setGramerRady ( string gram[] ) {
    for ( int i=0; i<4; i++ ) {
        rady[i] = gram[i];
    }
}

/**
 * Vytiskne stdout zadane cislo
 * @param num - pole s cisly
 */
void Language::printNum ( int num ) {
    cout << getNumber(num) << endl;
}

/**
 * Ze zadaneho stringu odstrani mezery
 * @param cislo - retezec, z ktereho se budou mezery odstranovat
 */
string Language::withOutSpace(string cislo)
{
  for(unsigned i = 0; i<cislo.length(); ++i){
    if(cislo[i] == ' '){
      cislo.erase(i, 1);
    }
  }
  
  return cislo;
}

string Language::getId(){
    return getNameLanguage().substr(0,2);
}








