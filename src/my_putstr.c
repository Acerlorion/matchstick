/*
** EPITECH PROJECT, 2017
** my_putstr.c
** File description:
** ui
*/

#include <unistd.h>

int my_strlen(char const *str)
{
	int len = 0;

	while (str[len]) {
		len++;
	}
	return (len);
}

void my_putstr( char const *str)
{
	int len = my_strlen(str);

	write(1, str, len);
}
