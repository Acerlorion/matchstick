/*
** EPITECH PROJECT, 2018
** get_next_line.c
** File description:
** get lines
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

static int check_file(int *fd, int *inc, char *red, char *out)
{
    int c_red = 0;

    if (out == NULL)
        return (84);
    if (red[*inc] == '\0') {
        c_red = read(*fd, red, READ_SIZE);
        if (c_red <= 0)
            return (84);
        red[c_red] = '\0';
        *inc = 0;
    }
    return (0);
}

static char *realloc_out(int *limit, char *out)
{
    int i = 0;
    int j = 0;
    char *save = malloc(sizeof(char) * (*limit + 1));

    if (save == NULL)
        return (NULL);
    while (i != *limit) {
        save[i] = out[i];
        i = i + 1;
    }
    free(out);
    *limit = *limit + READ_SIZE;
    out = malloc(sizeof(char) * (*limit + 1));
    while (j != i) {
        out[j] = save[j];
        j = j + 1;
    }
    free(save);
    return (out);
}

static void str_cpy(char *red, char *out, int *aba, int *inc)
{
    out[*aba] = red[*inc];
    *aba = *aba + 1;
    *inc = *inc + 1;
}

static char *next_line(int fd)
{
    static char red[READ_SIZE + 1];
    static int inc = 0;
    int limit = READ_SIZE;
    int aba = 0;
    char *out = malloc(sizeof(char) * (limit + 1));

    if (check_file(&fd, &inc, red, out) == 84)
        return (NULL);
    while (red[inc] != '\n') {
        if (aba == limit)
            out = realloc_out(&limit, out);
        if (out == NULL)
            return (NULL);
        str_cpy(red, out, &aba, &inc);
        if (check_file(&fd, &inc, red, out) == 84)
            return (NULL);
    }
    out[aba] = '\0';
    inc = inc + 1;
    return (out);
}

char *get_next_line(int fd)
{
    char *out = NULL;

    if (READ_SIZE <= 0 || READ_SIZE >= 2147483645)
        return (NULL);
    out = next_line(fd);
    return (out);
}
