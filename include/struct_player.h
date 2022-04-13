/*
** EPITECH PROJECT, 2021
** navy.h
** File description:
** navy
*/

#ifndef _NAVY_H_
#define _NAVY_H_

#include <signal.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct player_s {
    char **map_enemy;
    char **map;
    int compt;
    int pid;
    int pid_bis;
    long unsigned int v;
    long unsigned int i;
    char *mess_1;
    char *mess_2;
} player_t;

typedef struct maps_s {
    int x1;
    int y1;
    int y2;
    int x2;
    int fd;
    char *boat;
} maps_t;

#endif