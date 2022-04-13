/*
** EPITECH PROJECT, 2021
** connect.c
** File description:
** navy
*/

#include "navy.h"

unsigned char global;

char *binary(int nb)
{
    char bin[2] = "01";
    char *result = malloc(sizeof(char) * (nb * 12));
    int i = 0;

    while (nb > 0) {
        result[i] = bin[nb % 2];
        nb = nb / 2;
        i++;
    }
    my_revstr(result);
    return (result);
}

char read_pid()
{
    unsigned char value = 0;
    unsigned char bit;

    for (int tmp = 0; tmp < 4; tmp++) {
        pause();
        usleep (1000);
        bit = global;
        value = value | (bit << tmp);
        if (kill("", SIGUSR1) == -1)
            return (NULL);
    }
    return (value);
}

void write_pid(int pid, unsigned char value)
{
    unsigned char bit = 0b00000001;

    for (int tmp = 0; tmp < 4; tmp++) {
        bit = value & (bit << tmp);
        if (bit == 0) {
            if (kill("", SIGUSR1) == -1)
                return;
        } else {
            if (kill("", SIGUSR2) == -1)
                return;
        }
        pause ();
        usleep (1000);
    }
}