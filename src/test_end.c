/*
** EPITECH PROJECT, 2018
** test_end.c
** File description:
** if victory or loose
*/

int test_end(char *map)
{
	int aba = 0;

	while (map[aba]) {
		if (map[aba] == '|')
			return (0);
		aba += 1;
	}
	return (1);
}
