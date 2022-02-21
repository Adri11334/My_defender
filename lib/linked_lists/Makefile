##
## EPITECH PROJECT, 2022
## Linked List lib
## File description:
## Makefile
##

SRC		=	create.c			\
			delete_node.c		\
			destroy.c			\
			length.c			\
			push.c				\
			restart.c			\

OBJ		=	$(SRC:.c=.o)

NAME 	=	liblinkedlist.a

CFLAGS	=	-w -Wall -Wextra -Werror -Wshadow -Wimplicit -pedantic

CPPFLAGS	+=	-I./

all:		$(NAME)
.PHONY:	all

$(NAME):	$(OBJ)
			ar rc -o $(NAME) $(OBJ)
			mv $@ ../
			mkdir -p ../../include
			cp linked_lists.h ../../include/

clean:
			rm -f $(OBJ)
.PHONY:	clean

fclean: 	clean
			rm -f ../$(NAME)
			rm -f ../../include/linked_lists.h
.PHONY:	fclean

re:			fclean all
.PHONY:	re
