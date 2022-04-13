/*
** EPITECH PROJECT, 2021
** my_getnbr.c
** File description:
** return a number sent to the function as a string
*/
#include <stdio.h>
#include <unistd.h>

int my_get_nbr(char const *str)
{
    int nb = 0;
    int n = 1;
    int i = 0;

    for (; str[i] == '-' || str[i] == '+'; i++) {
        if (str[i] == '-')
            n *= -1;
    }
    for (; str[i] >= '0' && str[i] <= '9'; i++) {
        nb = (nb * 10 + (str[i] - 48));
        if ((nb < 0 && nb != -2147483648 && n == -1) || (nb < 0 && n == 1))
            return (0);
    }
    return (nb * n);
}
