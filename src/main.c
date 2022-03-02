/*
** EPITECH PROJECT, 2022
** my_project
** File description:
** main file
*/

#include <stddef.h>
#include "my_project.h"

int main(int argc, char **argv, char **env)
{
    if (*env == NULL)
        return 84;
    return main_window(argv);
}
