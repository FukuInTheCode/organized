/*
** EPITECH PROJECT, 2023
** Pool Day 04
** File description:
** Placeholder
*/

#include "my.h"

static char is_int_stred(char c)
{
    return ('0' <= c && c <= '9');
}

static char is_sign_stred(char c)
{
    return ((c == '-') || (c == '+'));
}

static char get_the_sign(char const *str)
{
    char sign = 1;
    int len = my_strlen(str);

    for (int i = 0; i < len && is_sign_stred(str[i]) == 1; i++)
        sign = -1 * sign * (str[i] == '-') + sign * (str[i] == '+');
    return sign;
}

int my_getnbr(char const *str)
{
    long ret = 0;
    char sign = get_the_sign(str);
    int len = my_strlen(str);
    char has_started = 0;

    for (int i = 0; i < len && GETNBR_CHECK; i++) {
        if (is_sign_stred(str[i]) && has_started == 1)
            break;
        if (is_sign_stred(str[i]))
            continue;
        ret *= 10;
        ret += str[i] - '0';
        has_started = 1;
        if (ret * sign > INT_MAX || ret * sign < INT_MIN)
            return 0;
    }
    return sign * ret;
}
