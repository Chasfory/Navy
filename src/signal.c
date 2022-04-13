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

char *tony(int i)
{
    static char c[16];
    static int d = 0;

    if (i == 1) {
        c[d] = '1';
        d++;
        return (c);
    } 
    if (i == 0) {
        c[d] = '0';
        d++;
        return (c);
    }
    else if (i == 2) {
        d = 0;
        return(c);
    }
    return (c);
}

void signal_1(__attribute__((unused))int tmp, __attribute__((unused))siginfo_t *play, __attribute__((unused))void *data)
{
    tony(0);
}

void signal_2(__attribute__((unused))int tmp, __attribute__((unused))siginfo_t *play, __attribute__((unused))void *data)
{
    tony(1);
}

void hole(__attribute__((unused))int tmp, __attribute__((unused))siginfo_t *game, __attribute__((unused))void *data)
{
    tmp = tmp;
}

void continu_game(player_t *game)
{
    kill(game->pid_bis, SIGUSR1);
}