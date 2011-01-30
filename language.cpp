/** @file language.cpp*/
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








