/*
 * gcc_example/hello.c
 * Sample code to compile with GCC at various stages for better understanding
 * - This code doesn't include anything other then main() function
 * - Find the complete details on compilation in 'End of this Document'
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

int main(void) {
	return 0;
}

/*
 * # Preprocessed stage
 * gcc -Wall -Wextra -g3 -E ./hello.c
 *
 * - Stopping at preprocessed stage
 * - This throws the output in stdout
 *
 * gcc -Wall -Wextra -g3 -E ./hello.c >./hello.i
 *
 * # Compiler stage
 * gcc -Wall -Wextra -g3 -S ./hello.c
 *
 * - Stopping at compilation stage
 * - This saves assembler code in 'hello.s'
 *
 * # Assembly stage
 * gcc -Wall -Wextra -g3 -c ./hello.c
 *
 * - Stopping at assembly stage
 * - This saves the object code in 'hello.o'
 * - Link stage is not at this step
 *
 * # Linking stage
 * gcc -Wall -Wextra -g3 -o ./hello ./hello.c
 *
 * - Executable binary file in ELF format is generated
 * - To run this program simply run "./hello"
 * - Notice the file permission : set with executable bit on
 *
 *
 * # All staging at one place
 * - To save all the intermediate files at one step '-save-temps' switch can be used
 *
 * gcc -Wall -Wextra -g3 -save-temps -o ./hello ./hello.c
 */
