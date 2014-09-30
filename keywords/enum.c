/*
 * keywords/enum.c
 * Enumerations provides a convenient way to associate constant values to names
 * - Memory foot print is the best way to realize enum (which is not ready now :-( )
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

/*
 * enum months { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };
 * FEB = 2, MAR = 3, etc.
 */

//typedef enum {RANDOM=3, IMMEDIATE, SEARCH} strategy_t;

enum strategy { RANDOM=3, IMMEDIATE, SEARCH };
enum strategy my_strategy = IMMEDIATE;

int main(void) {
//	strategy_t my_strategy = IMMEDIATE;
	printf("%d\n",my_strategy);
	return 0;
}

