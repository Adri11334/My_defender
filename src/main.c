/*
** EPITECH PROJECT, 2022
** my_project
** File description:
** main file
*/

#include <stddef.h>
#include "my_defender.h"

int display_help(void)
{
    char *text = NULL;

    text = get_file_content("../assets/help.txt");
    if (text != NULL)
        write(1, text, my_strlen(text));
    else
        return 84;
    return 0;
}

int main(int argc, char **argv, char **env)
{
    if (*env == NULL)
        return 84;
    if (my_strcmp(argv[1], "-h") == 0)
        return display_help();
    return main_window(argv);
}
