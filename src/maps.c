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

char  **draw_boat(maps_t *map, char **maps, int tmp)
{
    while(map->x1 <= map->x2 && map->y1 <= map->y2) {
        maps[map->x1][map->y1] = map->boat[tmp];
        if (map->boat[tmp + 2] < map->boat[tmp + 5])
            map->y1 = map->y1 + 2;
        else
            map->x1 = map->x1 + 1;
    }
    return (maps);
}

char **draw_boat_first(char const *av, char **maps)
{
    maps_t map;

    map.fd = open(av, O_RDONLY);
    init_struct_maps(&map);
    if (map.boat == NULL || map.fd == -1)
        return NULL;
    read(map.fd, map.boat, 31);
    map.boat[31] = '\0';
    if (check_boat(map.boat) == 84)
        return (NULL);
    for (int tmp = 0; tmp < 32; tmp += 8) {
        map.x1 = map.boat[tmp + 3] - 47;
        map.y1 = (map.boat[tmp + 2] - 64) * 2;
        maps[map.x1][map.y1] = map.boat[tmp];
        map.x2 = map.boat[tmp + 6] - 47;
        map.y2 = (map.boat[tmp + 5] - 64) * 2;
        maps[map.x2][map.y2] = map.boat[tmp];
        maps = draw_boat(&map, maps, tmp);
    }
    return (maps);
}

void display_maps(player_t *game)
{
    my_putstr("my positions:\n");
    for (int tmp = 0; tmp < 10; tmp++) {
        my_putstr(game->map[tmp]);
        my_putchar('\n');
    }
    my_putstr("\nenemy's positions:\n");
    for (int tmp = 0; tmp < 10; tmp++) {
        my_putstr(game->map_enemy[tmp]);
        my_putchar('\n');
    }
}

int init_struct_player(player_t *game, int ac, char **av)
{
    game->pid = getpid();
    game->v = 0;
    game->i = 0;
    game->mess_1 = NULL;
    game->mess_2 = NULL;
    game->pid_bis = 0;
    if (ac == 2) {
        if ((game->map = maps(av[1])) == NULL)
            return (84);
        game->map_enemy = maps_enemy();
    }
    if (ac == 3) {
        if ((game->map = maps(av[2])) == NULL)
            return (84);
        game->map_enemy = maps_enemy();
    }
    return (0);
}