/*
** EPITECH PROJECT, 2021
** putchar function
** File description:
** display a char in console
*/

#include <unistd.h>

////////////////////////////////////////////////////////////
//
// display a character in the terminal
//
// @param c the character to display
////////////////////////////////////////////////////////////
void my_putchar(char c)
{
    write (1, &c, 1);
}
