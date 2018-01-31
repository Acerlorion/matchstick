/*
** EPITECH PROJECT, 2018
** stick.h
** File description:
** matchstick's header
*/

#ifndef STICK_H_
#define STICK_H_

int my_getnbr(char const *);
char *create_map(char **, char *);
void my_putstr( char const *);
int my_strlen(char const *);
int game_begin(char **, char *);
char *ia_turn(char *, char **);
char *player_turn(char **av, char *map);
int test_end(char *);
char *get_next_line(int);
void my_putchar(char);
int my_put_nbr(int);
int verif_match(char *, int, int *, int);
char *change_map(int, int, char *);
void ia_action(int, int);
void player_action(int, int);

#endif /* STICK_H_ */
