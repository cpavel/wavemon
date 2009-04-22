/*
 * wavemon - a wireless network monitoring aplication
 *
 * Copyright (c) 2001-2002 Jan Morgenstern <jan@jm-music.de>
 *
 * wavemon is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free
 * Software Foundation; either version 2, or (at your option) any later
 * version.
 *
 * wavemon is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along
 * with wavemon; see the file COPYING.  If not, write to the Free Software
 * Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */
#include "wavemon.h"

int scr_help(void)
{
	WINDOW *w_help, *w_menu;
	int key = 0;

	w_help = newwin_title(LINES - 1, COLS, 0, 0, "Help", 0, 0);
	w_menu = wmenubar(SCR_HELP);

	waddstr_center(w_help, (LINES >> 1) - 1, "don't panic.");

	wrefresh(w_help);

	while (key < KEY_F(1) || key > KEY_F(10)) {
		while ((key = wgetch(w_menu)) <= 0)
			usleep(5000);

		/* Keyboard shortcuts */
		if (key == 'q')
			key = KEY_F(10);
		else if (key == 'i')
			key = KEY_F(1);
	}

	werase(w_help);
	wrefresh(w_help);
	delwin(w_help);

	werase(w_menu);
	wrefresh(w_menu);
	delwin(w_menu);

	return key - KEY_F(1);
}
