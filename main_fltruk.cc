/****************************************************************
 * file fltruk/main-fltruk.cc
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Description:
 *      This file is the main file of fltruk
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
#include "fltruk.hh"

extern "C" const char main_fltruk_git[] = FLTRUK_SHORTGIT;
extern "C" const char main_fltruk_base[] = FLTRUK_BASE;

void* fltruk_proghdl;

int
main(int argc, char**argv)
{
  fltruk_proghdl = dlopen (NULL, RTLD_NOW);
  assert (fltruk_proghdl);
  assert (main_fltruk_base);
  assert (main_fltruk_git);
  return 0;
} // end main
// end of file main-fltruk.c
