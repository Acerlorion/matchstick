/*
** EPITECH PROJECT, 2018
** verif_match.c
** File description:
** check match
*/

#include <stdlib.h>
#include "stick.h"

static int joke_fonction(int match_nb, int pipe_nb, char *match)
{
    if (match_nb >= 0)
        match_nb = my_getnbr(match);
    if (match_nb == 0) {
        my_putstr("Error: you have to remove at least one match\n");
        return (-2);
    } else if (match_nb > pipe_nb) {
        my_putstr("Error: not enough matches on this line\n");
        return (-2);
    }
    return (match_nb);
}

static int is_number(char *match)
{
    int ind = 0;

    while (match[ind]) {
        if (match[ind] < '0' || match[ind] > '9')
            return (-1);
        ind += 1;
    }
    return (0);
}

static int verif_match(char *match, int match_max, int *good, int pipe_nb)
{
    int match_nb = 0;

    match_nb = is_number(match);
    if (match_nb == -1)
        my_putstr("Error: invalid input (positive number expected)\n");
    match_nb = joke_fonction(match_nb, pipe_nb, match);
    if (match_nb < 0)
        return (0);
    if (match_nb <= match_max && match_nb > 0)
        *good = 1;
    else {
        my_putstr("Error: you cannot remove more than ");
        my_put_nbr(match_max);
        my_putstr(" matches per turn\n");
    }
    return (match_nb);
}

int matches_nbr(char **av, int i, char *map, int *good)
{
    int match_max = my_getnbr(av[2]);
    char *match = NULL;
    int match_nb = 0;
    int pipe_nb = 0;

    while (map[i] != '\n') {
        if (map[i] == '|')
            pipe_nb += 1;
        i += 1;
    }
    my_putstr("Matches: ");
    match = get_next_line(0);
    if (match == NULL) {
        return (-1);
    }
    match_nb = verif_match(match, match_max, good, pipe_nb);
    free(match);
    return (match_nb);
}
