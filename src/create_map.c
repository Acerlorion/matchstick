/*
** EPITECH PROJECT, 2018
** create_map.c
** File description:
** create the map
*/

#include <stdlib.h>
#include "stick.h"

static char *star_line(char *map, int nb_col)
{
	int aba = 0;
	int star_nb = 0;

	while (map[aba] != '\0') {
		aba += 1;
	}
	while (star_nb != nb_col) {
		map[aba] = '*';
		aba += 1;
		star_nb += 1;
	}
	map[aba] = '\n';
	aba += 1;
	map[aba] = '\0';
	return (map);
}

static char *add_star(int *inc, char *map)
{
	map[*inc] = '*';
	*inc += 1;
	return (map);
}

static char *add_game(int *inc, int space_nb, int pipe, char *map)
{
	int i_space = 0;
	int i_pipe = 0;

	while (i_space != space_nb) {
		map[*inc] = ' ';
		i_space += 1;
		*inc += 1;
	}
	i_space = 0;
	while (i_pipe != pipe) {
		map[*inc] = '|';
		i_pipe += 1;
		*inc += 1;
	}
	while (i_space != space_nb) {
		map[*inc] = ' ';
		i_space += 1;
		*inc += 1;
	}
	return (map);
}

static char *fill_map(char *map, int nb_line, int nb_col)
{
	int line = 0;
	int pipe = 1 + 2 * line;
	int inc = 0;
	int space_nb = (nb_col - 2 - pipe) / 2;

	while (map[inc] != '\0') {
		inc += 1;
	}
	while (line != nb_line) {
		pipe = 1 + 2 * line;
		space_nb = (nb_col - 2 - pipe) / 2;
		map = add_star(&inc, map);
		map = add_game(&inc, space_nb, pipe, map);
		map = add_star(&inc, map);
		map[inc] = '\n';
		inc += 1;
		line += 1;
	}
	map[inc] = '\0';
	return (map);
}

char *create_map(char **av, char *map)
{
	int nb_line = my_getnbr(av[1]);
	int nb_col = 1 + 2 * (nb_line - 1) + 2;
	int map_size = ((nb_line + 2) * (nb_col + 1)) + 1;

	if (nb_line <= 1 || nb_line >= 100)
		return (NULL);
	map = malloc(sizeof(char) * map_size);
	map[0] = '\0';
	map = star_line(map, nb_col);
	map = fill_map(map, nb_line, nb_col);
	map = star_line(map, nb_col);
	return (map);
}
