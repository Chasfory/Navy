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

int check_other_element(char *boat)
{
    if (boat[1] != ':' || boat[4] != ':')
        return (84);
    if (boat[9] != ':'|| boat[12] != ':')
        return (84);
    if (boat[17] != ':'|| boat[20] != ':')
        return (84);
    else if (boat[25] != ':'|| boat[28] != ':')
        return (84);
    return (0);
}

int check_post_boat(char *boat)
{
    if (boat[2] < 'A' || boat[2] > 'H'
    || boat[5] < 'A' || boat[5] > 'H')
        return (84);
    if (boat[10] < 'A' || boat[10] > 'H'
    || boat[13] < 'A' || boat[13] > 'H')
        return (84);
    if (boat[18] < 'A' || boat[18] > 'H'
    || boat[21] < 'A' || boat[21] > 'H')
        return (84);
    if (boat[26] < 'A' || boat[26] > 'H'
    || boat[29] < 'A' || boat[29] > 'H')
        return (84);
    else if (check_other_element(boat) == 84)
        return (84);
    return (0);
}

int check_boat_number(char *boat)
{
    if (boat[3] < '1' || boat[3] > '8'
    || boat[6] < '1' || boat[6] > '8')
        return (84);
    if (boat[11] < '1' || boat[11] > '8'
    || boat[14] < '1' || boat[14] > '8')
        return (84);
    if (boat[19] < '1' || boat[19] > '8'
    || boat[22] < '1' || boat[22] > '8')
        return (84);
    if (boat[27] < '1' || boat[27] > '8'
    || boat[30] < '1' || boat[30] > '8')
        return (84);
    else if (check_post_boat(boat) == 84)
        return (84);
    return (0);
}

int check_boat_bis(char *boat)
{
    int compt = 0;

    for (int i = 1; boat[i] != '\0'; i++) {
        if (boat[i] == '\n')
            compt++;
    }
    if (compt != 3)
        return (84);
    else if (check_boat_number(boat) == 84)
        return (84);
    return (0);
}

int check_boat(char *boat)
{
    if (check_boat_bis(boat) == 84)
        return (84);
    if (check_long_boat(boat) == 84)
        return (84);
    return (0);
}