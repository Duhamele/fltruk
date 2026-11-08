/****************************************************************
 * file fltruk/plugins-fltruk.cc
 * SPDX-License-Identifier: GPL-3.0-or-later
 *
 * Description:
 *      This file manage plugins of fltruk
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

extern "C" const char plugins_fltruk_git[] = FLTRUK_SHORTGIT;
extern "C" const char plugins_fltruk_base[] = FLTRUK_BASE;

extern "C" const char source_directory_fltruk[];

extern "C" const char make_fltruk[];

void
compile_plugins_fltruk(void)
{
    struct dirent* ent = nullptr;
    char genpath[384];
    memset (genpath, 0, sizeof(genpath));
    snprintf(genpath, sizeof(genpath)-1, "%s/generated/", source_directory_fltruk);
    DIR* gendir= opendir(genpath);
    if (!gendir) {
        FLTRUK_WARNING("fail to opendir %s", genpath);
        return;
    };
    do {
        const int srclen=80;
        char srcpath[sizeof(genpath) + srclen + 4];
        memset(srcpath, 0, sizeof(srcpath));
        char pluginpath[sizeof(srcpath)];
        memset(pluginpath, 0, sizeof(pluginpath));
	char cmdbuf[sizeof(genpath) + 2*srclen + 4];
	memset (cmdbuf, 0, sizeof(cmdbuf));
        ent = readdir(gendir);
        if (!ent)
            return;
        if (ent->d_type != DT_REG && ent->d_type != DT_LNK)
            continue;
        if (ent->d_name[0] == '.' || ent->d_name[0] == '!')
            continue;
        if (ent->d_reclen < 4 || ent->d_reclen>srclen+sizeof(genpath))
            continue;
        if (ent->d_name[ent->d_reclen-2] != '.'
                && ent->d_name[ent->d_reclen-1] != 'c')
            continue;
        int slen = snprintf (srcpath, sizeof(srcpath), "%s/%s",
			     source_directory_fltruk, ent->d_name);
        if (slen<0) {
            FLTRUK_WARNING("snprintf failed for %s in source dir %s",
			   ent->d_name, source_directory_fltruk);
            continue;
        }
        strcpy (pluginpath, srcpath);
        int pluglen = (int)strlen(pluginpath);
        assert (pluglen>4);
        assert (pluglen<(int)sizeof(pluginpath)-4);
	assert (pluginpath[pluglen-2] == '.' && pluginpath[pluglen-1] == 'c');
	pluginpath[pluglen-1] = 's';
	pluginpath[pluglen] = 'o';
	pluginpath[pluglen+1] = (char)0;
    } while (ent);
    closedir(gendir);
} // end compile_plugins_fltruk


// end of file fltruk/plugins_fltruk.cc
