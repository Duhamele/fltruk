#ifndef FLTRUK_INCLUDED
/****************************************************************
 * file fltruk/fltruk.hh
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Description:
 *      This file is the included header file of fltruk
 *      © Copyright (C) 2026, Basile Starynkevitch, France
 *       <basile@starynkevitch.net>
 * It is GPLv3+ licensed (or CeCILL in France)
 *
 * License: GPLv3+ (file COPYING-GPLv3)
 *    This software is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 ***/

#ifndef FLTRUK_SHORTGIT
#error FLTRUK_SHORTGIT should be defined in compilation command
#endif

#include <cassert>
#include <dlfcn.h>
#include <unistd.h>
#include <time.h>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <ostream>
#include <iostream>
#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Box.H>

extern "C" void* fltruk_proghdl; // for dlopen
extern "C" int fltruk_prog_arg_cnt(void);
extern "C" const char*fltruk_fetch_prog_arg(int rk);
#endif /*FLTRUK_INCLUDED*/
