/*
** EPITECH PROJECT, 2021
** navy.h
** File description:
** navy
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

#include "navy.h"

void init_struct_maps(maps_t *map)
{
    map->x1 = 0;
    map->y1 = 0;
    map->x2 = 0;
    map->y2 = 0;
    map->boat = malloc(sizeof(char) * 33);
}

int init_game_player_two(player_t *game, char **av)
{
    game->pid = getpid();
    if ((game->pid_bis = my_get_nbr(av[1])) == 84)
        return (84);
    my_putstr("my_pid: ");
    my_put_nbr(game->pid);
    if (kill(game->pid_bis, SIGUSR1) == -1)
        return (84);
    lets_go(game);
    return (0);
}