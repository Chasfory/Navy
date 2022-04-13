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

static int GLOBAL = 0;

void msg_hit(__attribute__((unused))int tmp, __attribute__((unused))siginfo_t *play, __attribute__((unused))void *data)
{
    GLOBAL = 1;
    my_putstr("hit\n\n");
}

void msg_missed(__attribute__((unused))int tmp, __attribute__((unused))siginfo_t *play, __attribute__((unused))void *data)
{
    GLOBAL = 2;
    my_putstr("missed\n\n");
}

void glob(__attribute__((unused))int tmp, __attribute__((unused))siginfo_t *game, __attribute__((unused))void *data)
{
    GLOBAL = 1;
}

void init_game_player_one(player_t *game)
{
    struct sigaction sign = {0};

    game->pid = getpid();
    display_connect(game);
    sign.sa_sigaction = &connect;
    sign.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sign, NULL);
    pause();
    game->pid_bis = GLOBAL;
    sign.sa_sigaction = &glob;
    sign.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sign, NULL);
    usleep(50000);
    display_maps(game);
    while (finish_game(game) != 1) {
        game_attack(game);
        game_waiting(game);
        my_putchar('\n');
        display_maps(game);
    }
}

void change_map(char *sms, player_t *game)
{
    char x = sms[0] - 16;
    char y = sms[1];
    int compt_x = (x - 48) * 2;
    int compt_y = y - 47;

    if (GLOBAL == 1) {
        game->map_enemy[compt_y][compt_x] = 'x';
    }
    else {
        if (game->map_enemy[compt_y][compt_x] == 'x')
            return;
        game->map_enemy[compt_y][compt_x] = 'o';
    }
}

void connect(int tmp, siginfo_t *player, __attribute__((unused))void *data)
{
    tmp = player->si_pid;

    GLOBAL = tmp;
    my_putstr("enemy connected\n\n");
    if (kill(player->si_pid, SIGUSR1) == -1)
        return;
}