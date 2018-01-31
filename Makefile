##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Matchstick's makefile
##

SRC	=	src/matchstick_main.c	\
		src/my_getnbr.c	\
		src/create_map.c	\
		src/game.c	\
		src/my_putstr.c	\
		src/player_turn.c	\
		src/ia_turn.c	\
		src/test_end.c	\
		src/get_next_line.c	\
		src/my_put_nbr.c	\
		src/verif_match.c	\
		src/change_map.c	\
		src/put_action.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	matchstick

CFLAGS	=	-Iinclude -g

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ)

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
