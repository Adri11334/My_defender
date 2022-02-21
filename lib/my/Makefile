##
## EPITECH PROJECT, 2021
## lib
## File description:
## my lib
##

SRC		=	utils/my_compute_power_rec.c	\
			utils/my_compute_square_root.c	\
			utils/my_get_file.c				\
			utils/my_find_prime_sup.c		\
			utils/my_first_line.c			\
			utils/my_getnbr.c				\
			utils/my_isneg.c				\
			utils/my_is_prime.c				\
			utils/my_putchar.c				\
			utils/my_put_nbr.c				\
			utils/my_putstr.c				\
			utils/my_revstr.c				\
			utils/my_showmem.c				\
			utils/my_showstr.c				\
			utils/my_sort_int_array.c		\
			utils/my_strcapitalize.c		\
			utils/my_strcat.c				\
			utils/my_strcmp.c				\
			utils/my_strcpy.c				\
			utils/my_strdup.c				\
			utils/my_str_isalpha.c			\
			utils/my_str_islower.c			\
			utils/my_str_isnum.c			\
			utils/my_str_isprintable.c		\
			utils/my_str_isupper.c			\
			utils/my_str_to_words_array.c	\
			utils/my_strlen.c				\
			utils/my_strlowcase.c			\
			utils/my_strncat.c				\
			utils/my_strncmp.c				\
			utils/my_strncpy.c				\
			utils/my_strstr.c				\
			utils/my_strupcase.c			\
			utils/my_swap.c					\
			utils/my_to_string.c			\
			utils/letter_occurence.c		\
			utils/my_malloc.c				\
			utils/print_color_2.c			\
			utils/print_color.c				\
			utils/print_header_2.c			\
			utils/print_header.c			\
			printf/convert.c				\
			printf/my_printf.c				\
			printf/print_base.c				\
			printf/print_pointeur.c			\
			printf/print_standard.c			\
			printf/unsigned_o_u.c			\
			printf/utils.c					\

OBJ		=	$(SRC:.c=.o)

NAME 	=	libutils.a

CFLAGS	=	-w -Wall -Wextra -Werror -Wshadow -Wimplicit -pedantic

CPPFLAGS	+=	-I./

all:		$(NAME)
.PHONY:	all

$(NAME):	$(OBJ)
			ar rc -o $(NAME) $(OBJ)
			mv $@ ../
			mkdir -p ../../include
			cp my.h ../../include/

clean:
			rm -f $(OBJ)
.PHONY:	clean

fclean: 	clean
			rm -f ../$(NAME)
			rm -f ../../include/my.h
.PHONY:	fclean

re:			fclean all
.PHONY:	re
