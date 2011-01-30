/** @file multilingual_cli.h*/
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


#ifndef MULTILINGUAL_CLI_H
#define MULTILINGUAL_CLI_H

#include "language.h"
#include "czech.h"
#include "english.h"
#include "deutsch.h"
#include <iostream>

/**
 * Trida pro praci s prevadenim cisel za pomoci prikazove radky (cli)
 */
class Multilingual_cli
{

public:
    Multilingual_cli();
    Multilingual_cli(const Multilingual_cli& other);
    virtual ~Multilingual_cli();
    void start();
};

#endif // MULTILINGUAL_CLI_H
