/*
** EPITECH PROJECT, 2021
** fonction.c
** File description:
** navy
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

#include "navy.h"

void display_connect(player_t *game)
{
    my_putstr("my_pid: ");
    my_put_nbr(game->pid);
    my_putstr("\nwaiting for enemy connection...\n\n");
}

void connect_play_two(__attribute__((unused))int tmp, __attribute__((unused))siginfo_t *player, __attribute__((unused))void *data)
{
    static int tempo = 0;

    if (tempo == 0) {
        my_putstr("\nsuccessfully connected\n\n");
        tempo++;
    }
}