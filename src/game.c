/*
** EPITECH PROJECT, 2018
** game.c
** File description:
** matchstick's game
*/

#include <unistd.h>
#include <stdlib.h>
#include "stick.h"

static int put_end(char *map, int turn)
{
    my_putstr(map);
    if (turn % 2 == 0) {
        my_putstr("OH YES, you're retarded!\n");
        return (2);
    } else {
        my_putstr("OH NO, i'm retarded!\n");
        return (1);
    }
}

int game_begin(char **av, char *map)
{
    int end = 0;
    char *in = NULL;
    int turn = 1;

    while (end == 0) {
        my_putstr(map);
        write(1, "\n", 1);
        if (turn % 2 == 1) {
            map = player_turn(av, map);
            if (map == NULL)
                return (-1);
	} else {
            map = ia_turn(map, av);
            if (map == NULL)
                return (-1);
        }
        turn += 1;
        end = test_end(map);
    }
    return (put_end(map, turn));
}
