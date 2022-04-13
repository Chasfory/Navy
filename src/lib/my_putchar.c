/*
** EPITECH PROJECT, 2021
** my_putchar.c
** File description:
** Task
*/

#include <unistd.h>
#include "navy.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
