/*
** EPITECH PROJECT, 2021
** my lib
** File description:
** my librairy
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdarg.h>

    typedef struct printf_flag_s {
        char flag;
        void (*ptr_function) (va_list);
    } printf_flag_t;

    typedef struct str_words_array_s {
        char *sep;
        char **words;
        int current_word;
        int current_in_word;
        char *str;
        int str_length;
    } str_to_words_array_t;

    int my_swap(int *a, int *b);
    void my_putchar(char c);

    int my_isneg(int nb);
    int my_put_nbr(int nb);

    int my_putstr(char const *str);
    int my_strlen(char const *str);
    int my_getnbr(char const *str);

    int my_sort_int_array(int *tab, int size);

    int my_compute_power_rec(int nb, int power);
    int my_compute_square_root(int nb);

    int my_is_prime(int nb);
    int my_find_prime_sup(int nb);

    char *my_strcpy(char *dest, char const *src);
    char *my_strdup(char const *src);
    char *my_strncpy(char *dest, char const *src, int n);
    char *my_revstr(char *str);
    char *my_strstr(char *str, char const *to_find);
    char **my_str_to_words_array(const char *str, const char separators[]);

    int get_first_line_length(char *text);
    char *my_get_first_line(char *text);

    int my_strcmp(char const *s1, char const *s2);
    int my_strncmp(char const *s1, char const *s2, int n);

    char *my_strupcase(char *str);
    char *my_strlowcase(char *str);
    char *my_strcapitalize(char *str);

    int my_str_isalpha(char const *str);
    int my_str_isnum(char const *str);
    int my_str_islower(char const *str);
    int my_str_isupper(char const *str);
    int my_str_isprintable(char const *str);
    char *my_to_str(int nb);

    char *get_file_content(char const *filepath);
    int my_showstr(char const *str);
    int my_showmem(char const *str, int size);

    char *my_strcat(char *dest, char const *src);
    char *my_strncat(char *dest, char const *src, int nb);

    char check_letter(char letter);
    int is_letter(char *str, char letter);
    int check_string(char *str, int *mc, long *fn, int *i);
    void *my_malloc(int size, char *buf);

    void write_white(char *str);
    void write_blue(char *str);
    void write_green(char *str);
    void write_cyan(char *str);
    void write_red(char *str);
    void write_purple(char *str);

    void red_header(const char *str);
    void green_header(const char *str);
    void cyan_header(const char *str);
    void blue_header(const char *str);
    void white_header(const char *str);
    void purple_header(const char *str);

    int to_octal(int dec);
    void to_binary(unsigned int dec, char *binary, int len);
    void to_hex(unsigned int dec, char *hex, int len);
    void to_hex_long(long long nb, char *hex, int len);
    unsigned int to_unsigned_octal(unsigned int dec);
    char *convert_strlowcase(char *str);
    int print_unisgned_number(unsigned int nb);
    void print_unsigned_octal(va_list arg);
    void print_unsigned_dec(va_list arg);
    void print_integer(va_list arg);
    void print_ptr(va_list arg);
    void print_octal(int nb);
    void print_string(va_list arg);
    void print_spec_string(va_list arg);
    void print_binary(va_list arg);
    void print_hexadecimal(va_list arg);
    void print_hexadecimal_low(va_list arg);
    void check_printf_percent(va_list list, int *i, char pc, char c);
    void my_printf(char *str, ...);
    void mprintf(char *str, ...);
#endif/* !MY_H_ */
