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

int check_long_boat(char *boat)
{
    if ((((boat[5] + boat[6]) - (boat[2] + boat[3])) + '1') != boat[0])
        return (84);
    if ((((boat[13] + boat[14]) - (boat[10] + boat[11])) + '1') != boat[8])
        return (84);
    if ((((boat[21] + boat[22]) - (boat[18] + boat[19])) + '1') != boat[16])
        return (84);
    else if ((((boat[30] + boat[29]) -
        (boat[27] + boat[26])) + '1') != boat[24])
        return (84);
    return (0);
}

int check_error(char *sms)
{
    if ((sms == NULL) || (my_strlen(sms) > 2))
        return (84);
    if ((sms[0] < 'A') || (sms[0] > 'H'))
        return (84);
    if ((sms[1] < '1') || (sms[1] > '8'))
        return (84);
    else
        return (0);
}