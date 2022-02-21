/*
** EPITECH PROJECT, 2022
** my_lib
** File description:
** get_file
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

#include "my.h"

char *fs_open_read_file(int fd, int size)
{
    char *buffer = my_malloc(sizeof(char) * size + 1, NULL);
    int read_status;

    if (fd == -1 || buffer == NULL)
        return NULL;
    read_status = read(fd, buffer, size);
    close(fd);
    if (read_status == -1)
        return NULL;
    if (read_status == 0)
        return NULL;
    if (read_status < size)
        return NULL;
    return buffer;
}

////////////////////////////////////////////////////////////
//
// get the content of a file
//
// @param filepath the path to the file
////////////////////////////////////////////////////////////
char *get_file_content(char const *filepath)
{
    struct stat file_stat = {0};
    char *content = NULL;
    int file_descriptor = 0;
    int file_size = 0;

    if (filepath == NULL)
        return NULL;
    stat(filepath, &file_stat);
    file_size = file_stat.st_size;
    file_descriptor = open(filepath, O_RDONLY);
    content = fs_open_read_file(file_descriptor, file_size);
    if (content == NULL)
        return NULL;
    return content;
}
