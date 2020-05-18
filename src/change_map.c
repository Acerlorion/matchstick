/*
** EPITECH PROJECT, 2018
** change_map.c
** File description:
** modify the map
*/

char *change_map(int line_nb, int match_nb, char *map)
{
    int cpt = 0;
    int i = 0;

    while (cpt != line_nb + 1) {
        if (map[i] == '\n')
            cpt += 1;
        i += 1;
    }
    while (match_nb != 0) {
        if (map[i] == '|') {
            map[i] = ' ';
            match_nb -= 1;
        }
        i -= 1;
    }
    return (map);
}
