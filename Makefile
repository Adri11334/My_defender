##
## EPITECH PROJECT, 2022
## my_project
## File description:
## Makefile
##

SRC			=	src/button/button_destroy.c			\
				src/button/button_clic_detection.c	\
				src/button/button_init.c			\
				src/button/button_interactions.c	\
				src/callbacks/callbacks.c			\
				src/callbacks/cb_print_hello.c		\
				src/display/display_button.c		\
				src/display/display_map.c			\
				src/events/event_quit_game.c		\
				src/events/events.c					\
				src/maps/maps_block_click.c			\
				src/maps/maps_load_blocks.c			\
				src/maps/maps_objects.c				\
				src/maps/maps_road_type.c			\
				src/maps/maps_validity.c			\
				src/menu/menu_create_buttons.c		\
				src/menu/menu_display_button.c		\
				src/scene/scene_game.c				\
				src/scene/scene_menu.c				\
				src/text/text_destroy.c				\
				src/text/text_init.c				\
				src/utils/dimension.c				\
				src/window.c						\

CRITERION	=	$(wildcard tests/*.c)

OBJ			=	$(SRC:.c=.o)

NAME		=	my_defender
#-Werror
CFLAGS		+=	-W -Wall -Wextra  -Wshadow -Wimplicit -pedantic

LDFLAGS		+=	-L./lib -lutils
LDFLAGS		+=	-L./lib -llinkedlist
LDFLAGS		+=	-lcsfml-graphics -lcsfml-system  -lcsfml-audio

CPPFLAGS	+=	-I./include/
CPPFLAGS	+=	-g

all:			lib	$(NAME)
PHONY		+=	all

lib:
				make -C ./lib/
PHONY		+=	lib

$(NAME):		$(OBJ)
				gcc src/main.c $^ -o $@ -ggdb3 $(CPPFLAGS) $(LDFLAGS)

debug:			CPPFLAGS += -ggdb3
debug:			CPPFLAGS += -g
debug:			lib	$(OBJ)
				gcc src/main.c $(OBJ) -o $@ $(CPPFLAGS) $(LDFLAGS)
				valgrind ./$@
PHONY		+=	debug

tests_run:		CPPFLAGS += --coverage
tests_run:		CPPFLAGS += -lcriterion
tests_run:		lib
				gcc -o uts $(SRC) $(CRITERION) $(CPPFLAGS) $(LDFLAGS)
				-./uts
				rm -f uts
PHONY		+=	tests_run

cover:
				mkdir -p covr
				gcovr --exclude tests/ --html --html-details -o covr/cover.html
				gcovr --branches --exclude tests/
				make -C ./ clean
PHONY		+=	cover

clean:
				make -s -C ./lib/ clean
				@find . -type f | xargs touch
				@rm -f $(OBJ)
				@rm -f *.o
				@rm -f *~
				@rm -f vgcore*
				@rm -f #*
				@rm -f *.gcda
				@rm -f *.identifier
				@rm -f *.gcno
PHONY		+=	clean

fclean:			clean
				make -s -C ./lib/ fclean
				rm -f $(NAME)
				@rm -f covr/*.html
				@rm -f covr/*.css
				@rm -rf covr/
				@rm -f *Zone.Identifier
				@rm -f projet
				@rm -f *.gcno
PHONY		+=	fclean

my_tests: 		tests_run cover
PHONY		+=	my_tests

re:				fclean all
PHONY		+=	re

run:			all
				-./$(NAME)
PHONY		+=	run

.PHONY:			$(PHONY)
