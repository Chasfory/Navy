/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** navy
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <fcntl.h>

#include "navy.h"

char **map_create(char **map)
{
    map[0] = my_strcpy(map[0], " |A B C D E F G H");
    map[1] = my_strcpy(map[1], "-+---------------");
    map[2] = my_strcpy(map[2], "1|. . . . . . . .");
    map[3] = my_strcpy(map[3], "2|. . . . . . . .");
    map[4] = my_strcpy(map[4], "3|. . . . . . . .");
    map[5] = my_strcpy(map[5], "4|. . . . . . . .");
    map[6] = my_strcpy(map[6], "5|. . . . . . . .");
    map[7] = my_strcpy(map[7], "6|. . . . . . . .");
    map[8] = my_strcpy(map[8], "7|. . . . . . . .");
    map[9] = my_strcpy(map[9], "8|. . . . . . . .");
    map[10] = NULL;
    return(map);
}

char **maps_enemy()
{
    char **map = malloc(sizeof(char *) * 11);

    if (map == NULL)
        return NULL;
    for (int tmp = 0; tmp < 10; tmp++) {
        map[tmp] = malloc(sizeof(char) * 18);
        if (map[tmp] == NULL)
            return NULL;
    }
    map = map_create(map);
    return (map);
}

char **maps(char *av)
{
    char **map = malloc(sizeof(char *) * 11);

    if (map == NULL)
        return NULL;
    for (int tmp = 0; tmp < 10; tmp++) {
        map[tmp] = malloc(sizeof(char) * 18);
        if (map[tmp] == NULL)
            return NULL;
    }
    map = map_create(map);
    map = draw_boat_first(av, map);
    return (map);
}