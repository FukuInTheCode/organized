/*
** EPITECH PROJECT, 2023
** Pool Day 03
** File description:
** Placeholder
*/

#include "my.h"

static int my_print(int nb)
{
    long rev_nb = 10;
    char to_print;
    int ret = 0;

    if (nb < 0) {
        nb *= -1;
        ret += write(1, "-", 1);
    }
    for (; nb != 0; nb = (nb - nb % 10) / 10) {
        rev_nb += nb % 10;
        rev_nb *= 10;
    }
    rev_nb /= 10;
    for (; rev_nb != 1; rev_nb = (rev_nb - rev_nb % 10) / 10) {
        to_print = 48 + rev_nb % 10;
        ret += write(1, &to_print, 1);
    }
    return ret;
}

int my_put_nbr(int nb)
{
    if (nb == INT_MIN)
        return write(1, "-2147483648", 11);
    if (nb == 0)
        return write(1, "0", 1);
    return my_print(nb);
}
