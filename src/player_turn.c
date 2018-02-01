/*
** EPITECH PROJECT, 2018
** player_turn.c
** File description:
** player's action
*/

#include <stdlib.h>
#include "stick.h"

static int verif_line(char *line, int line_max, int *good)
{
	int line_nb = 0;
	int ind = 0;

	while (line[ind]) {
		if (line[ind] < '0' || line[ind] > '9')
			line_nb = -1;
		ind += 1;
	}
	if (line_nb >= 0)
		line_nb = my_getnbr(line);
	if (line_nb <= line_max && line_nb > 0)
		*good = 1;
	else if (line_nb == -1)
		my_putstr("Error: invalid input (positive number expected)\n");
	else
		my_putstr("Error: this line is out of range\n");
	return (line_nb);
}

static int verif_pipe(int line_nb, char *map, int *good)
{
	int cpt = 0;
	int i = 0;
	int pipe_nb = 0;

	while (cpt != line_nb) {
		if (map[i] == '\n')
			cpt += 1;
		i += 1;
	}
	while (map[i] != '\n') {
		if (map[i] == '|')
			pipe_nb += 1;
		i += 1;
	}
	if (pipe_nb == 0) {
		*good = 0;
		my_putstr("Error: no match(es) on this line\n");
	}
	return (pipe_nb);
}

static int line_nbr(char **av, char *map)
{
	char *line = NULL;
	int line_max = my_getnbr(av[1]);
	int line_nb = 0;
	int pipe_nb = 0;
	int good = 0;

	while (good == 0) {
		my_putstr("Line: ");
		line = get_next_line(0);
		if (line == NULL) {
			return (-1);
		}
		line_nb = verif_line(line, line_max, &good);
		if (line_nb <= line_max && good == 1)
			pipe_nb = verif_pipe(line_nb, map, &good);
		free(line);
	}
	return (line_nb);
}

static int go_to_goodline(char *map, int line_nb)
{
	int cpt = 0;
	int i = 0;

	while (cpt != line_nb) {
		if (map[i] == '\n')
			cpt += 1;
		i += 1;
	}
	return (i);
}

char *player_turn(char **av, char *map)
{
	int line_nb = 0;
	int match_nb = 0;
	int cpt = 0;
	int i = 0;
	int good = 0;

	my_putstr("Your turn:\n");
	while (good == 0) {
		line_nb = line_nbr(av, map);
		if (line_nb == -1)
			return (NULL);
		i = go_to_goodline(map, line_nb);
		match_nb = matches_nbr(av, i, map, &good);
		if (match_nb == -1)
			return (NULL);
	}
	player_action(match_nb, line_nb);
	map = change_map(line_nb, match_nb, map);
	return (map);
}
