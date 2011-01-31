/** @file czech.cpp*/
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


#include "czech.h"

Czech::Czech()
{
    string numera[10] = {"nula", "jedna", "dva", "tři", "čtyři", "pět", "šest", "sedm", "osm", "devět" };
    string ra[4] = {"cet", "set", "tisíc", "milion"};
    setGramerCisla(numera);
    setGramerRady(ra);
}

Czech::Czech(const Czech& other)
{

}

Czech::~Czech()
{

}

/**
 * Prevede zadane cislo na slovni zapis
 * @param num - cislo, ktere se ma prevest na slovni zapis
 * @return - navraci cislo ve slovnim zapisu
 */
string Czech::getNumber(int num)
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

string Czech::getDes(int num)
{
    if (num < 10 && (num>0)) {
        return getJed(num);
    }
    string deset;
    int des=num/10;
    if (des==1) {
        //logika pro desitky
        switch (num%10) {
        case 0:
            return "deset";
            break;
        case 1:
            return "jedenáct";
            break;
        case 4:
            return "čtrnáct";
        case 5:
            return "patnáct";
        case 9:
            return "devatenáct";
        default:
            return cisla[num%10]+"náct";
        }


    } else if ((des>1)&&(des<5)) {
        deset = cisla[des]+rady[0];
    } else {
        if (des==5) {
            deset = "pa";
        } else if (des==6) {
            deset = "še";
        } else if (des == 9) {
            deset = "deva";
        } else {
            deset = cisla[des];
        }
        deset += "desát";
    }
    if ((num%10)==0) {
        return deset;
    }
    return deset+" "+getJed(num%10);
}

string Czech::getJed(int num)
{
    return cisla[num];
}
string Czech::getMil(int num)
{
    if (num == 1) {
        return "milion";
    } else if (num < 5) {
        return getJed(num)+" miliony";
    }
    return getSto(num)+ " milionů";
}
string Czech::getSto(int num)
{
    if (num < 100) {
        return getDes(num);
    }
    string sto;
    int st= num / 100;
    if (st==1) {
        // do nothing
        sto = "sto";
    } else if (st == 2) {
        sto = "dvě stě";
    } else if (st>2 && st<5) {
        sto = cisla[st]+" sta";
    } else {
        sto = cisla[st]+" "+rady[1];
    }
    if (num%100 == 0) {
        return sto;
    }
    return sto+" "+getDes(num%100);
}
string Czech::getTis(int num)
{
    if (num > 1 && num <5) {
        return getJed(num)+" "+rady[2]+"e ";
    } else if (num == 1) {
        return rady[2]+" ";
    }
    return getSto(num)+" "+rady[2]+" ";

}

//CISLA ZAPSANA SLOVY

/**
 * Prevede zadane cislo slovy na cisla
 * @param cislo - retezec, ktery se ma prevest cisla
 * @return - navraci cislo
 */
int Czech::getNum(string cislo)
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
            tmp = getNumTis(cislo.substr(fst+1, scd-fst-1));//mozny problem s mezerou
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
    if (scd != string::npos) {
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
int Czech::getNumJed(string cislo)
{
    for (int i = 0; i<10 ; ++i) {
        if (cislo == cisla[i]) {
            return i;
        }
    }
    return -1;//Nenalezeno cislo 0..9
}

/**
 * Hleda jednoslovna cisla od 0 do 90
 *
 * @param cislo - cislo slovy
 * @return - vraci -1 pokud neni cislo zapsane slovy nalezeno jinak vraci cislo
 */
int Czech::getNumJedMist(string cislo)
{

    int num = getNumJed(cislo); // 0-10
    if (num == -1) {

        // 10-20
        for (int i= 10; i<20; ++i) {
            if (cislo == getDes(i)) {
                return i;
            }
        }
        num = getNumDes(cislo);
    }

    if (num == -1) {//Kdy by to byla stovka
        if (cislo == "sto") {
            return 100;
        }
    }


    return num;
}


/**
 * Dvoumistne cislo desitek a jednotek
 * @param cislo - dvou mistne cislo zapsane slovy
 * @return - vraci cislo
 */
int Czech::getNumDvoumistne(string cislo, const size_t mezera)
{
    string prvni = cislo.substr(0, mezera); //Mozna problem s mezerou takze se bude muset dat -1 ale myslim ze je to dobre
    string druhe = cislo.substr(mezera+1);
    int num = getNumDes(prvni);
    //Kontrola zda je prvni cislo nalezeno
    if (num == -1) {//jsou to stovky
        // muze byt i sto dvanact
        num = getNumSto(cislo);
        if(num == -1){
            if(cislo.substr(0,mezera) == "sto"){
                // Jednotky 10-19 a desitky
                string lst = cislo.substr(mezera+1);
                int jed = getNumJed(lst);
                if(jed == -1){
                    jed = getNumDes(lst);
                    if(jed == -1){
                        return -1;
                    }
                }
                return 100+jed;
            }
            return -1;
        }
    }
    int jed = 0;
    if(num < 100){
        jed = getNumJed(druhe);
        //Kontrola zda je druhe cislo nalezeno
        if (jed == -1) {
            return -1;
        }
    }
    return num+jed;
}


/**
 * Hleda cisla pouze desitky !
 * @param cislo - desitka zapsana slovy
 */
int Czech::getNumDes(string cislo)
{
    //20-90
    for (int i =20; i<91; i +=10) {
        if (cislo == getDes(i)) {
            return i;
        }
    }
    //10-19
    for(int i = 10; i<20; ++i){
        if(cislo == getDes(i)){
            return i;
        }
    }
    return -1;
}

int Czech::getNumSto(string cislo)
{

    for (int i =1; i<10; ++i) {
        if (cislo == getSto(i*100)) {
            return i*100;
        }
    }
    return -1;
}

int Czech::getNumTriMistne(string cislo, const size_t mezsto)
{
    int sto = getNumSto(cislo.substr(0, mezsto));
    if (sto == -1) {
        //JESTE TO MUZE BYT napr. 125
        size_t posto = cislo.find(" ");
        if(cislo.substr(0, posto) == "sto"){
            string poss = cislo.substr(posto+1);
            int tmp = getNumDvoumistne(poss, poss.find(" "));
            if(tmp == -1){
                return -1;
            }else{
                return STO+tmp;
            }
        }
        return -1;
    }
    string str = cislo.substr(mezsto+1);
    int des = getNumJed(str);
    if (des == -1) {
        des = getNumDes(str);
        if (des == -1) {
            return -1;
        }
    }
    return sto+des;
}

//s tisicem
int Czech::getNumTis(string cislo)
{
    size_t lastmez = cislo.find_last_of(" ");
    string tisi = cislo.substr(0, lastmez);
    int tis = getPre(tisi);
    if (tis == -1) {
        if(cislo == "tisíc"){
            return 1000;
        }else{
            return -1;
        }
    }
    string pom= getTis(tis);
    if (pom.substr(0, pom.length()-1) == cislo) {
        return tis*1000;
    }
    return -1;
}
int Czech::getNumMil(string cislo)
{
    size_t lastmez = cislo.find_last_of(" ");
    string tisi = cislo.substr(0, lastmez);
    int tis = getPre(tisi);
    if (tis == -1) {
        if(cislo == rady[3]){
            return MILION;
        }else{
            return -1;
        }
    }

    if (getMil(tis) == cislo) {
        return tis*1000000;
    }
    return -1;
}

int Czech::getNumCtyrMistne(string cislo, const size_t mezsto, const size_t mezdes )
{

    int sto = getNumSto(cislo.substr(0, mezsto));
    if (sto == -1) {
        return -1;
    }

    int des = getNumDes(cislo.substr(mezsto+1, mezdes-(mezsto+1)));
    if (des == -1) {
        return -1;
    }

    int jed = getNumJed(cislo.substr(mezdes+1));
    if (jed == -1) {
        return -1;
    }
    
    return sto+des+jed;
}


int Czech::getPre(string cislo)
{

    size_t mez = cislo.find(" ");
    //Bez mezery
    if (mez == string::npos) {
        return getNumJedMist(cislo);
    }

    size_t mez2 = cislo.find(" ", mez+1);
    //S jednou mezerou
    if (mez2 == string::npos) {
        return getNumDvoumistne(cislo, mez);
    }

    size_t mez3 = cislo.find(" ", mez2+1);
    if (mez3 == string::npos) {
        return getNumTriMistne(cislo, mez2);
    }

    return getNumCtyrMistne(cislo, mez2, mez3);
}


/**
 * vraci nazev jazyku
 * @return - nazev jazyku
 */
string Czech::getNameLanguage()
{
    return "češtině";
}






