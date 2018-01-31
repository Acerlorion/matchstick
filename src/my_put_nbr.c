/*
** EPITECH PROJECT, 2017
** my_putnbr.c
** File description:
** put nbr
*/

#include <unistd.h>

void my_putchar(char c)
{
	write(1, &c, 1);
}

static int display_nbr(int nb, int n, int b)
{
	int a = 0;

	while (nb >= 10) {
		nb = nb / 10;
		n = n * 10;
	}
	while (n != 0) {
		a = (b / n) % 10;
		my_putchar(a + 48);
		n = n / 10;
	}
	return (0);
}

int my_put_nbr(int nb)
{
	int b;
	int n = 1;

	if (nb < 0) {
		nb = -nb;
		my_putchar('-');
	}
	b = nb;
	display_nbr(nb, n, b);
	return (0);
}
