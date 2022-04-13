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
#include "struct_binary.h"

void msg_hit_or_missed(int compt, player_t *game)
{
    struct sigaction sign = {0};

    if (compt == 1)
        kill(game->pid_bis, SIGUSR1);
    else if (compt == -1)
        kill(game->pid_bis, SIGUSR2);
    sign.sa_sigaction = &hole;
    sign.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sign, NULL);
    usleep(50000);
}

void print_mess(char *x, char *y)
{
    char *mess = malloc(sizeof(char) * 3);

    for (int tmp = 0; tmp < 2; tmp++) {
        mess[tmp] = y[0] + 16;
        tmp++;
        mess[tmp] = x[0];
    }
    mess[3] = '\0';
    my_putstr(mess);
}

int touch_missed(int compt_x, int compt_y, player_t *game)
{
    my_putstr(": missed\n");
    if (game->map[compt_y][compt_x] == 'x')
        return (-1);
    if ((game->map[compt_y][compt_x] == 'o') ||
        (game->map[compt_y][compt_x] == '.'))
        game->map[compt_y][compt_x] = 'o';
    return (-1);
}

void hit_or_missed(int compt_x, int compt_y, player_t *game)
{
    int tmp_x = compt_x;
    int result = 0;

    compt_x = 2;
    compt_y += 1;
    for (int tmp = 1; tmp < tmp_x; tmp++)  {
        compt_x += 2;
    }
    if ((game->map[compt_y][compt_x] == 'o') ||
        (game->map[compt_y][compt_x] == 'x') ||
        (game->map[compt_y][compt_x] == '.')) {
        result = touch_missed(compt_x, compt_y, game);
    } else {
        result = 1;
        game->map[compt_y][compt_x] = 'x';
        my_putstr(": hit\n");
    }
    msg_hit_or_missed(result, game);
}

void mess_1(player_t *game, char *y)
{
    int compt = 0;
    char mess_2[10];

    game->v = 0;
    for (int c = 0; c < 9; c++) {
        if (c == 4)
            mess_2[c] = ' ';
        else {
            mess_2[c] = y[compt];
            compt++;
        }
    }
    mess_2[9] = '\0';
    while (game->v < ((sizeof(binary)) / (sizeof(binary[0]))) &&
    (my_strcmp(mess_2, binary[game->v]) != 0)) {
        game->v = game->v + 1;
    }
    my_putchar(letter[game->v][0] + 16);
    game->v = game->v + 1;
}

void mess_2(player_t *game, char *y)
{
    int compt = 8;
    char mess_1[10];

    game->i = 0;
    for (int b = 0; b < 9; b++) {
        if (b == 4)
            mess_1[b] = ' ';
        else {
            mess_1[b] = y[compt];
            compt++;
        }
    }
    mess_1[9] = '\0';
    while (game->i < ((sizeof(binary)) / (sizeof(binary[0]))) &&
    (my_strcmp(mess_1, binary[game->i]) != 0)) {
        game->i = game->i + 1;
    }
    my_putchar((letter[game->i][0]));
    game->i += 1;
}