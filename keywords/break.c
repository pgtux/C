/*
 * keywords/break.c
 * break can used to come out of the looping i.e from 'for , do..while , while , switch' 
 * - Breaking is needed or conditional break is needed to end the program [normal terminations]
 *
 * 
 * Author: Parthiban Nallathambi <parthiban@penguintux.co.in>
 *
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 *
 */

#include <stdio.h>

int main(void) {
	int i=0;

/* Use case with while loop */
	while(++i) {
		printf("Looping at %d\n",i);
		if (i == 5)
			break;
	}

/* Use case with switch */

	switch (2) {		/* Hard coded to switch into '2' to explain break */
		case 1:
			printf("Will not hit into this case\n");
			break;
		case 2:
			printf("Will be breaking here\n");
			break;
		case 3:
			printf("We won't hit here\n");
			break;
		default:
			break;
	}
	return 0;
}
