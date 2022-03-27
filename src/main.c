/*
** EPITECH PROJECT, 2022
** my_project
** File description:
** main file
*/

#include <unistd.h>
#include <stddef.h>
#include "my_defender.h"

int display_help(void)
{
    char *text = NULL;

    cyan_header("Our Defender: help command (how to play/use)");
    text = get_file_content("assets/help.txt");
    if (text != NULL)
        write(1, text, my_strlen(text));
    else {
        write_red("Error reading the help file.\n");
        return 84;
    }
    return 0;
}

static int check_display(char **env)
{
    int index = 0;

    if (*env == NULL || env == NULL)
        return 0;
    while (env[index] != NULL) {
        if (my_strncmp(env[index], "DISPLAY=", 8) == 0)
            return 1;
        index++;
    }
    return 0;
}

int main(int argc, char **argv, char **env)
{
    if (*env == NULL && check_display(env) == 0) {
        red_header("Our Defender: crash preventing");
        write_red("No env founded.\n");
        return 84;
    }
    if (my_strcmp(argv[1], "-h") == 0)
        return display_help();
    return main_window(argv);
}
