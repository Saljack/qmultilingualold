/** @file deutsch*/
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


#include "deutsch.h"

Deutsch::Deutsch() {
    string numera[10] = {"null", "eins", "zwei", "drei", "vier", "funf", "sechs", "sieben", "acht", "neun"};
    string rad[4]= {"zig", "hundert", "tausend", "Million"};
    setGramerCisla ( numera );
    setGramerRady ( rad );

}

Deutsch::Deutsch ( const Deutsch& other ) {
    //TODO
}

Deutsch::~Deutsch() {

}


/**
 * Prevede zadane cislo na slovni zapis
 * @param num - cislo, ktere se ma prevest na slovni zapis
 * @return - navraci cislo ve slovnim zapisu
 */
string Deutsch::getNumber(int num)
{
    string cislo;
    if ( num >= MILION ) {
        cislo += getMil ( num/MILION );
        bool mez = false;
        if (num%MILION) {
            if((num%MILION) / TISIC != 0){// Kvuli mezere
                cislo +=" " + getTis ( ( num%MILION ) /TISIC );
            } else {
                mez = true;
            }
        }
        if ( num%TISIC ) {
            if(mez){
                cislo += " ";
            }
            cislo += getSto ( num%1000 );
        }

    } else if ( num >= TISIC ) {
        cislo += getTis ( num/TISIC ) ;
        if ( num%TISIC != 0 ) {
            cislo += getSto ( num%1000 );
        }
    } else if ( num>=10 ) {
        cislo += getSto ( num );
    } else {
        cislo += getJed ( num );
    }
    return cislo;
}


string Deutsch::getDes ( int num ) {
    if ( num < 10 ) {
        if ( num>0 ) {
            return getJed ( num );
        }
    }
    string des;
    switch ( num/10 ) {
    case 1:
        return getDesitku ( num );
        break;
    case 2:
        des = "zwan"+rady[0];
        break;
    case 3:
        des = "dreissig";
        break;
    case 6:
        des = "sech"+rady[0];
        break;
    case 7:
        des = "sieb"+rady[0];
        break;
    default:
        des = cisla[num/10]+rady[0];
    }

    if ( num%10 == 0 ) {
        return des;
    }

    return getJed ( num%10 ) +"und"+des;

}

string Deutsch::getJed ( int num ) {
    return cisla[num];
}
string Deutsch::getSto ( int num ) {
    if ( num < 100 ) {
        return getDes ( num );
    }

    if ( num%100 == 0 ) {
        return getJed ( num/100 ) +rady[1];
    } else {
        return getJed ( num/100 ) +rady[1]+ getDes(num%100);
    }
}
string Deutsch::getTis ( int num ) {
    if (num == 1) {
        return "ein"+rady[2];
    }
    return getSto(num)+rady[2];
}

string Deutsch::getMil ( int num ) {
    if (num == 1) {
        return "eine "+rady[3];
    }
    return getSto(num)+" "+rady[3]+"en";
}

string Deutsch::getDesitku ( int num ) {
    if ( num == 11 ) {
        return "elf";
    } else if ( num == 12 ) {
        return "zwölf";
    }
    string des= "zehn";
    switch ( num%10 ) {
    case 0:
        return des;
    case 6:
        return "sech"+des;
    case 7:
        return "sieb"+des;
    default:
        return cisla[num%10]+des;
    }
}

//PSANA CISLA


/**
 * Prevede zadane cislo slovy na cisla
 * @param cislo - retezec, ktery se ma prevest cisla
 * @return - navraci cislo
 */
int Deutsch::getNum(string cislo)
{
    size_t mil = cislo.find(rady[3]);
    if (mil == string::npos) { //Neni milion
        return getNumPre(cislo);
    }
    int premil = getNumPre(cislo.substr(0, mil-1));
    if (premil == -1) {
        if(cislo.substr(0, mil-1) == "eine"){
            premil = 1;
        }else{
            return -1;
        }
    }
    int aftermil = 0;
    if(cislo.length() > mil+9){
        aftermil = getNumPre(cislo.substr(mil+10));
        if (aftermil == -1) {
            return -1;
        }
    }

    return premil*MILION+aftermil;

}

/**
 * Cisla pred milionem nebo za milionem
 */
int Deutsch::getNumPre(string cislo)
{
    //hledam tisic
    size_t tmp = cislo.find(rady[2]);
    if (tmp == string::npos) {
        return getNumSto(cislo);
    }

    int pretis = getNumSto(cislo.substr(0, tmp));
    if (pretis == -1) {
        return -1;
    }
    int aftis = 0;
    if(cislo.length() != cislo.substr(0, tmp+7).length()){
        aftis = getNumSto(cislo.substr(tmp+rady[2].length()));
        if (aftis == -1) {
            return -1;
        }
    }

    return pretis*TISIC+aftis;
}

/**
 * Cisla pred tisicem nebo za tisicem proste stovky
 */
int Deutsch::getNumSto(string cislo)
{
    size_t tmp = cislo.find(rady[1]);
    if (tmp == string::npos) {
        return getNumDes(cislo);
    }
    int sto = getNumJed(cislo.substr(0, tmp));
    if (sto==-1) {
        return -1;
    } else {
        sto *= STO;
        if(cislo.length() == cislo.substr(0, tmp+rady[1].length()).length()){
            return sto;
        }
    }
    int des = getNumDes(cislo.substr(tmp+rady[1].length()));
    if (des == -1) {
        return -1;
    }
    return sto+des;


}

int Deutsch::getNumDes(string cislo)
{
    size_t und = cislo.find("und");
    if (und == string::npos) {// cislo je bez und takze to muze byt desitka nebo jednotka
        int tmp = getNumJed(cislo);
        if(tmp == -1){
            tmp = getNumDesitky(cislo);
            if (tmp == -1) {
                tmp = getNumOnlyDes(cislo);
            }
        }
        return tmp;
    }

    int jed = getNumJed(cislo.substr(0, und));
    if (jed == -1) {
        return -1;
    }

    int des = getNumOnlyDes(cislo.substr(und+3));
    if (des == -1) {
        return -1;
    }

    return des+jed;
}

int Deutsch::getNumJed(string cislo)
{
    for (int i=0; i<10; ++i) {
        if (cislo == cisla[i]) {
            return i;
        }
    }
    if(cislo == "ein"){
        return 1;
    }
    return -1;
}

//10, 20, ... ,90
int Deutsch::getNumOnlyDes(string cislo)
{
    for (int i = 1; i<10; ++i) {
        if (cislo == getDes(i*10)) {
            return i*10;
        }
    }
    return -1;
}

//11, 12, ... , 19
int Deutsch::getNumDesitky(string cislo){
    for(int i =11; i < 20; ++i){
        if(cislo == getDes(i)){
            return i;
        }
    }
    return -1;
}

/**
 * vraci nazev jazyku
 * @return - nazev jazyku
 */
string Deutsch::getNameLanguage()
{
    return "deutch";
}









