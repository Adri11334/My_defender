/*
** EPITECH PROJECT, 2022
** lib
** File description:
** str_word_array from stumper 01
*/

#include <stdlib.h>
#include "my.h"

int strwa_array_size(const char *str, const char *sep)
{
    int words = 1;

    if (str == NULL || sep == NULL)
        return 0;
    for (int i = 0; str[i] != '\0'; i++)
        for (int j = 0; j < my_strlen(sep); j++)
            if (str[i] == sep[j])
                words++;
    return words;
}

int strwa_check_this_char(str_to_words_array_t *w_a)
{
    int new_word = 0;
    int skip_char = 0;
    int sep_l = 0;

    if (w_a->sep == NULL)
        return 84;
    sep_l = my_strlen(w_a->sep);
    for (int i = 0; i < sep_l; i++) {
        if (w_a->str[0] == w_a->sep[i]
        && w_a->words[w_a->current_word] != NULL
        && w_a->words[w_a->current_word][i] != '\0')
            new_word++;
        if (w_a->str[0] == w_a->sep[i])
            skip_char++;
    }
    if (new_word != 0 && w_a->str[1] != '\0' && skip_char != 0)
        return 1;
    if (skip_char != 0)
        return 2;
    return 0;
}

int strwa_my_while(str_to_words_array_t *w_a)
{
    switch (strwa_check_this_char(w_a)) {
        case 84: return 84; break;
        case 0: w_a->words[w_a->current_word][w_a->current_in_word] =
                w_a->str[0];
                w_a->current_in_word++;
                break;
        case 1: w_a->current_in_word = 0;
                w_a->current_word++;
                w_a->words[w_a->current_word] =
                my_malloc(my_strlen(w_a->str) + 1, NULL);
                if (w_a->words[w_a->current_word] == NULL)
                    return 84;
                break;
        case 2: w_a->current_in_word = 0;
                break;
    }
    return 0;
}

str_to_words_array_t *strwa_init(const char *str, const char separators[])
{
    str_to_words_array_t *words_arr = malloc(sizeof(str_to_words_array_t));

    if (str == NULL || separators == NULL || words_arr == NULL)
        return NULL;
    words_arr->str_length = strlen(str);
    words_arr->str = str;
    words_arr->sep = separators;
    words_arr->current_word = 0;
    words_arr->current_in_word = 0;
    words_arr->words = my_malloc(sizeof(char*) *
    strwa_array_size(str, separators) + 1, NULL);
    if (words_arr->words == NULL)
        return NULL;
    words_arr->words[0] = my_malloc(words_arr->str_length + 1, NULL);
    if (words_arr->words[0] == NULL)
        return NULL;
    return words_arr;
}

char **my_str_to_words_array(const char *str, const char separators[])
{
    str_to_words_array_t *words_arr = strwa_init(str, separators);
    char **words = NULL;
    int words_size_allocated = strwa_array_size(str, separators) + 1;

    if (words_arr == NULL)
        return NULL;
    for (; words_arr->str[0] != '\0'; words_arr->str++)
        if (strwa_my_while(words_arr) == 84)
            return NULL;
    for (int i = 0; i <= words_size_allocated; i++)
        if (words_arr->words[words_arr->current_word] == '\0') {
            free(words_arr->words[words_arr->current_word]);
            words_arr->words[words_arr->current_word] == NULL;
        }
    for (int i = 0; i <  words_arr->str_length; i++)
        str--;
    words = words_arr->words;
    free(words_arr);
    return words;
}
