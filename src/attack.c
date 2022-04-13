/*
** EPITECH PROJECT, 2021
** attack.c
** File description:
** navy
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

#include "navy.h"
#include "struct_binary.h"

__attribute__((unused)) static const char *letter[];

void kill_sms(char *coord_tmp, player_t *game)
{
    for (int tmp = 0; coord_tmp[tmp] != '\0'; tmp++) {
        if (coord_tmp[tmp] == '0')
            kill(game->pid_bis, SIGUSR1);
        else if (coord_tmp[tmp] == '1')
            kill(game->pid_bis, SIGUSR2);
        usleep(5000);
    }
}

void coordination_of_the_attack(char *sms, player_t *game)
{
    char x = sms[0] - 16;
    char y = sms[1];
    char coord_x[10];
    char coord_y[10];
    int compt_x = x - 48;
    int compt_y = y - 48;

    my_strcpy(coord_x, binary[compt_x - 1]);
    my_strcpy(coord_y, binary[compt_y - 1]);
    kill_sms(coord_x, game);
    kill_sms(coord_y, game);
}

void play_attack(player_t *game, char *sms)
{
    struct sigaction sign = {0};
    struct sigaction sign_2 = {0};

    sign.sa_sigaction = &msg_hit;
    sign.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sign, NULL);
    sign_2.sa_sigaction = &msg_missed;
    sign_2.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR2, &sign_2, NULL);
    coordination_of_the_attack(sms, game);
    usleep(9000);
    change_map(sms, game);
}

void game_attack_bis(char *sms, player_t *game)
{
    if (check_error(sms) == 0) {
        my_putstr(sms);
        my_putstr(": ");
        play_attack(game, sms);
        continu_game(game);
        }
    else if (check_error(sms) == 84) {
        my_putstr("wrong position");
        game_attack(game);
    }
}

void game_attack(player_t *game)
{
    char *sms = NULL;
    size_t buffsize = 0;
    int message = 0;
    int tmp = 0;

    my_putstr("\nattack: ");
    message = getline(&sms, &buffsize, stdin);
    if (message == -1)
        return;
    else {
        for (; sms[tmp] != '\n'; tmp++);
        sms[tmp] = '\0';
    }
    game_attack_bis(sms, game);
}