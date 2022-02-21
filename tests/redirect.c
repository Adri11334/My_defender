/*
** EPITECH PROJECT, 2022
** my_project
** File description:
** redirect output
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

void redirect_all_stdout(void)
{
        cr_redirect_stdout();
        cr_redirect_stderr();
}
