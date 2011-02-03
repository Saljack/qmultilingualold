/** @file english.cpp*/
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


#include "english.h"
#include <cstring>

English::English()
{
    string numera[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    string ra[4] = {"ty", "hundred", "thousand", "million"};
    setGramerCisla(numera);
    setGramerRady(ra);
}
English::English(const English& other): Language(other)
{

}

English::~English()
{

}

/**
 * Prevede zadane cislo na slovni zapis
 * @param num - cislo, ktere se ma prevest na slovni zapis
 * @return - navraci cislo ve slovnim zapisu
 */
string English::getNumber(int num)
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

string English::getJed(int num) {
    return cisla[num];
}

string English::getDes(int num)
{
    if (num<10 && num>0) {
        return getJed(num);
    }

    string des;
    if ((num/10) == 1) {
        switch (num%10) {
        case 0:
            return "ten";
        case 1:
            return "eleven";
        case 2:
            return "twelve";
        case 3:
            des = "thir";
            break;
        case 5:
            des = "fif";
            break;
        default:
            des = cisla[num%10];
        }
        return des += "teen";
    }

    switch (num/10) {
    case 2:
        des = "twen";
        break;
    case 3:
        des = "thir";
        break;
    case 4:
        des = "for";
        break;
    case 5:
        des = "fif";
        break;
    case 8:
        des = "eigh";
        break;
    default:
        des = cisla[num/10];
    }
    des += rady[0];
    if ((num%10) == 0) {
        return des;
    }
    return des+"-"+getJed(num%10);
}
string English::getSto(int num)
{
    if (num<100) {
        return getDes(num);
    }

    string sto = getJed(num/100)+" "+rady[1];
    if ((num%100) == 0) {
        return sto;
    }
    return sto+" and "+getDes(num%100);


}
string English::getTis(int num)
{
    return getSto(num)+" "+rady[2]+" ";
}
string English::getMil(int num)
{
    return getSto(num)+" "+rady[3];
}

//CISLA ZAPSANA SLOVY

/**
 * Prevede zadane cislo slovy na cisla
 * @param cislo - retezec, ktery se ma prevest cisla
 * @return - navraci cislo
 */
int English::getNum(string cislo)
{
    int num = 0;
    int tmp;
    //MILIONY
    size_t fst = cislo.find(rady[3]);
    if (fst != string::npos) {
        fst = cislo.find(" ", fst+1);//ulozi mezeru za milionem
        if ( fst == string::npos) {
            return getNumMil(cislo);
        }
        tmp = getNumMil(cislo.substr(0, fst));
        if (tmp == -1) {
            return -1;
        }
        num = tmp;
    }


    //TISICE
    size_t scd = cislo.find(rady[2]);
    if (scd !=string::npos) {
        scd = cislo.find(" ", scd); //prvni mezera po tisici

        //mezera po cislu uz neni
        if (scd == string::npos) {
            if (fst == string::npos) { //jestli byl nalezen milion
                return getNumTis(cislo);
            }
            //Tisicem to konci
            tmp = getNumTis(cislo.substr(fst+1, scd-fst-1));
            if (tmp == -1) {
                return -1;
            }
            num +=tmp;
        } else {
            if (fst != string::npos) {
                tmp = getNumTis(cislo.substr(fst+1, scd-fst-1));
            } else {
                tmp = getNumTis(cislo.substr(0, scd));
            }
            if (tmp == -1) {
                return -1;
            }
            num+=tmp;
        }

    }

    //STOVKY
    if (scd != string::npos) { //Zda jsou pritomny tisice
        tmp = getPre(cislo.substr(scd+1));
    } else if (fst != string::npos) {
        tmp = getPre(cislo.substr(fst+1));
    } else {
        tmp = getPre(cislo);
    }
    if (tmp == -1) {
        return -1;
    }
    num += tmp;
    return num;
}


/**
 * Hleda cisla od 0 do 10
 *
 * @param cislo - cislo slovy
 */
int English::getNumJed(string cislo)
{
    for (int i = 0; i<10 ; ++i) {
        if (cislo == cisla[i]) {
            return i;
        }
    }
    return -1;//Nenalezeno cislo 0..9
}


// Upravit na cisla s pomlckou a bez
/**
 * Hleda jednoslovna cisla od 0 do 90
 *
 * @param cislo - cislo slovy
 * @return - vraci -1 pokud neni cislo zapsane slovy nalezeno, jinak vraci cislo
 *
 * HOTOVO
*/
int English::getNumJedMist(string cislo)
{
    int num = -1;
    size_t pom = cislo.find("-");
    //Kdyz neni pomlcka
    if (pom == string::npos) {
        num = getNumJed(cislo); // 0-10
        if (num == -1) {
            num = getNumDes(cislo);
        }
    } else { //Pokud je nalezena pomlcka
        num = getNumDes(cislo.substr(0, pom));
        if (num != -1) {
            int tmp = getNumJed(cislo.substr(pom+1));
            if (tmp!= -1) {
                num += tmp;
            }
        }
    }

    if (num == -1) {
        num = getNumSto(cislo);
    }

    return num;
}


/**
 * Dvoumistne cislo desitek a jednotek
 * @param cislo - dvou mistne cislo zapsane slovy
 * @return - vraci cislo
 */
int English::getNumDvoumistne(string cislo)
{
    return getNumSto(cislo);
}

/**
 * Hleda cisla pouze desitky !
 * @param cislo - desitka zapsana slovy
 *
 */
int English::getNumDes(string cislo)
{
//    int num = -1;
    for(int i =10; i<20; ++i){
        if(cislo == getDes(i)){
            return i;
        }
    }
    for (int i =20; i<91; i +=10) {
        if (cislo == getDes(i)) {
            return i;
        }
    }
    return -1;
}

int English::getNumSto(string cislo)
{
    for (int i =1; i<10; ++i) {
        if (cislo == getSto(i*100)) {
            return i*100;
        }
    }
    return -1;
}

int English::getNumTriMistne(string cislo)
{
    size_t lastmez = cislo.find(" and ");
    if (lastmez == string::npos) {
        return -1;
    }
    int desitky = getNumJedMist(cislo.substr(lastmez+5));
    if (desitky == -1) {
        return -1;
    }
    int stovky = getNumSto(cislo.substr(0, lastmez));
    if (stovky == -1) {
        return -1;
    }
    return stovky+desitky;
}

//s tisicem
int English::getNumTis(string cislo)
{
    size_t lastmez = cislo.find_last_of(" ");
    string tisi = cislo.substr(0, lastmez);
    int tis = getPre(tisi);
    if (tis == -1) {
        return -1;
    }
    string pom= getTis(tis);
    if (pom.substr(0, pom.length()-1) == cislo) {
        return tis*1000;
    }
    return -1;
}
int English::getNumMil(string cislo)
{
    size_t lastmez = cislo.find_last_of(" ");
    string tisi = cislo.substr(0, lastmez);
    int tis = getPre(tisi);
    if (tis == -1) {
        return -1;
    }

    if (getMil(tis) == cislo) {
        return tis*1000000;
    }
    return -1;
}

int English::getPre(string cislo)
{
    size_t mez = cislo.find(" ");
    //Bez mezery
    if (mez == string::npos) {
        return getNumJedMist(cislo);
    }

    size_t mez2 = cislo.find(" ", mez+1);
    //S jednou mezerou
    if (mez2 == string::npos) {
        return getNumDvoumistne(cislo);
    }

    return getNumTriMistne(cislo);
}
/**
 * vraci nazev jazyku
 * @return - nazev jazyku
 */
string English::getNameLanguage()
{
    return "english";
}

