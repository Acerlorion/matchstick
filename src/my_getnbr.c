/*
** EPITECH PROJECT, 2017
** my_getnbr.c
** File description:
** get nbr
*/

static int strnbr_to_nbr(int i, int start_nbr, char const *str)
{
	long time_nbr = 1;
	int calcul = 0;

	while ((str[i] >= '0' && str[i] <= '9') && str[i]) {
		time_nbr = time_nbr * 10;
		i = i + 1;
	}
	time_nbr = time_nbr / 10;
	while (start_nbr < i) {
		calcul = calcul + (str[start_nbr] - 48) * time_nbr;
		start_nbr = start_nbr + 1;
		time_nbr = time_nbr / 10;
	}
	return (calcul);
}

int my_getnbr(char const *str)
{
	int i = 0;
	int negative = 0;
	long start_nbr = 0;
	long result = 0;

	while ((str[i] < '0' || str[i] > '9') && str[i] != '\0') {
		i = i + 1;
		start_nbr = start_nbr + 1;
	}
	result = strnbr_to_nbr(i, start_nbr, str);
	return (result);
}
