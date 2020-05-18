/*
** EPITECH PROJECT, 2018
** put_action.c
** File description:
** put what ia or you did
*/

#include "stick.h"

void player_action(int match_nb, int line_nb)
{
    my_putstr("Player removed ");
    my_put_nbr(match_nb);
    my_putstr(" match(es) from line ");
    my_put_nbr(line_nb);
    my_putstr("\n");
}

void ia_action(int result, int line)
{
    my_putstr("AI removed ");
    my_put_nbr(result);
    my_putstr(" match(es) from line ");
    my_put_nbr(line);
    my_putstr("\n");
}
