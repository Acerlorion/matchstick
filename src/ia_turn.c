/*
** EPITECH PROJECT, 2018
** ia_turn.c
** File description:
** ia's action
*/

#include <stdlib.h>
#include "stick.h"

static int *create_matches(char *map, int *matches, int match_max)
{
	int line = 0;
	int match = 0;
	int aba = 0;

	while (map[aba]) {
		if (map[aba] == '|')
			match += 1;
		if (map[aba] == '\n') {
			matches[line] = match;
			line += 1;
			match = 0;
		}
		aba += 1;
	}
	return (matches);
}

static int calcul_res(int *matches, int match_max)
{
	int i = 0;
	int result = 0;

	while (matches[i] == 0) {
		i += 1;
	}
	while (matches[i] != 0) {
		result = result ^ matches[i];
		i += 1;
	}
	return (result);
}

static void adapt_output(int *line, int *result, int *matches, int match_max)
{
	int i = 0;

	while (matches[i] == 0) {
		i += 1;
	}
	*line = i;
	while (matches[i] != 0) {
		if (matches[i] >= *result)
			*line = i;
		i += 1;
	}
	if (matches[*line] < *result) {
		*result = *result % (matches[*line] + 1);
	} else if (matches[*line] - *result <= 0) {
		*result -= 1;
	}
	if (*result > match_max) {
		*result = *result % (match_max + 1);
	}
}

char *ia_turn(char *map, char **av)
{
	int match_max = my_getnbr(av[2]);
	int line_max = my_getnbr(av[1]);
	int result = 0;
	int line = 0;
	int *matches = malloc(sizeof(int) * (line_max + 2));

	my_putstr("AI's turn...\n");
	matches = create_matches(map, matches, match_max);
	result = calcul_res(matches, match_max);
	adapt_output(&line, &result, matches, match_max);
	if (result == 0)
		result = 1;
	ia_action(result, line);
	map = change_map(line, result, map);
	free(matches);
	return (map);
}
