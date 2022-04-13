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

#include "navy.h"

void display()
{
    my_putstr("USAGE\n");
    my_putstr("     ./navy [first_player_pid] navy_positions\
    \n");
    my_putstr("DESCRIPTION\n");
    my_putstr("      first_player_pid: only for the 2nd play\
    er. pid of the first player.\n");
    my_putstr("      navy_positions: file representing the p\
    ositions of the ships.\n");
}

int main(int ac, char **av)
{
    player_t game;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
        display();
    if (ac != 2 && ac != 3)
        return (84);
    if (ac == 2) {
        if (init_struct_player(&game, ac, av) != 84)
            init_game_player_one(&game);
        else
            return (84);
    }
    else if (ac == 3) {
        if (init_struct_player(&game, ac, av) != 84)
            init_game_player_two(&game, av);
        else
            return (84);
    }
    return (0);
}