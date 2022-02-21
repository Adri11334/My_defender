/*
** EPITECH PROJECT, 2021
** lib
** File description:
** occurrence of a letter in a sting
*/

////////////////////////////////////////////////////////////
//
// Get the occurrence of a letter in a string
//
// @param str the string you want to analyse
// @param letter the letter you want to search
////////////////////////////////////////////////////////////
int is_letter(char *str, char letter)
{
    int letter_count = 0;

    if (!str || !letter)
        return 84;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == letter) {
            ++letter_count;
        }
    }
    return letter_count;
}
