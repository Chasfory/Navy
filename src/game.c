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

int won_compt(player_t *game)
{
    int won = 0;

    for (int i = 2; game->map_enemy[i] != NULL; i++) {
        for (int j = 2; game->map_enemy[i][j] != '\0'; j++) {
            if (game->map_enemy[i][j] == 'x')
                won++;
        }
    }
    return (won);
}

int lose_compt(player_t *game)
{
    int lose = 0;

    for (int i = 2; game->map[i] != NULL; i++) {
        for (int j = 2; game->map[i][j] != '\0'; j++) {
            if (game->map[i][j] == 'x')
                lose++;
        }
    }
    return (lose);
}

int finish_game(player_t *game)
{
    int won = won_compt(game);
    int lose = lose_compt(game);

    if (won == 14) {
        my_putstr("\nI won\n");
        return (1);
    }
    if (lose == 14) {
        my_putstr("\nEnemy won\n");
        return (1);
    }
    else 
        return (0);
}

void lets_go(player_t *game)
{
    struct sigaction sign2 = {0};

    sign2.sa_sigaction = &connect_play_two;
    sign2.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sign2, NULL);
    sigaction(SIGUSR2, &sign2, NULL);
    pause();
    display_maps(game);
    while ((finish_game(game)) != 1) {
        my_putchar('\n');
        game_waiting(game);
        game_attack(game);
        display_maps(game);
    }
}

void game_waiting(player_t *game)
{
    struct sigaction sign = {0};
    struct sigaction sign_2 = {0};

    my_putstr("waiting for enemy's attack...\n");
    sign.sa_sigaction = &signal_1;
    sign.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sign, NULL);
    sign_2.sa_sigaction = &signal_2;
    sign_2.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR2, &sign_2, NULL);
    for (int i = 0; i < 16; i++) {
        pause();
    }
    mess_1(game, tony(2));
    mess_2(game, tony(2));
    hit_or_missed(game->v, game->i, game);
}