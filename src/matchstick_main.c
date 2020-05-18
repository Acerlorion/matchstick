/*
** EPITECH PROJECT, 2018
** matchstick_main.c
** File description:
** matchstick's main
*/

#include <stdlib.h>
#include "stick.h"

static int error(int ac, char **av)
{
    int i1d = 1;
    int i2d = 0;

    if (ac != 3)
        return (1);
    while (av[i1d]) {
        i2d = 0;
        while (av[i1d][i2d]) {
            if (av[i1d][i2d] < '0' || av[i1d][i2d] > '9')
                return (1);
            i2d += 1;
        }
        i1d += 1;
    }
    return (0);
}

int main(int ac, char **av)
{
    int return_val = 0;
    char *map = NULL;

    if (error(ac, av) == 1) {
        return (84);
    }
    map = create_map(av, map);
    if (map == NULL) {
        return (84);
    }
    return_val = game_begin(av, map);
    if (return_val == -1) {
        free(map);
        return (0);
    }
    free(map);
    return (return_val);
}
