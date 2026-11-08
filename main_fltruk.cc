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

static int fltruk_prog_argc;
static const char**fltruk_prog_argv;

static void
usage_fltruk(void)
{
    std::clog << fltruk_prog_argv[0] << " usage:" << std::endl
              << "\t --help                        # give this help" << std::endl
              << "\t --version                     # give version" << std::endl;
} // end usage_fltruk

static void
version_fltruk(void)
{
    std::clog << fltruk_prog_argv[0] << " version:" << std::endl
              << "\t git " << FLTRUK_SHORTGIT << std::endl
              << "\t FLTK ABI: " << Fl::abi_version() << std::endl
              << "\t FLTK API: " << Fl::api_version() << std::endl;
} // end version_fltruk

static int
arghandle_fltruk(int argc, char**argv, int &i)
{
    assert (argc>0);
    assert(argv);
    assert(i>=0);
    asm volatile ("nop");
    return i;
} // end arghandle_fltruk

int
main(int argc, char**argv)
{
    int iarg= 0;
    fltruk_prog_argc = argc;
    fltruk_prog_argv = (const char**)argv;
    fltruk_proghdl = dlopen (NULL, RTLD_NOW);
    assert (fltruk_proghdl);
    assert (main_fltruk_base);
    assert (main_fltruk_git);
    if (argc>1) {
        if (!strcmp(argv[1], "--help")) {
            usage_fltruk();
            return 0;
        } else if (!strcmp(argv[1], "--version")) {
            version_fltruk();
            return 0;
        };
    };
    int r = Fl::args(argc, argv, iarg, arghandle_fltruk);
    assert(r>=0);
    return 0;
} // end main
// end of file main-fltruk.c
