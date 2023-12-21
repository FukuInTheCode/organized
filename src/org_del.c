/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

static bool is_num(char const *s)
{
    for (int i = 0; s[i]; i++)
        if (!('0' <= s[i] && s[i] <= '9'))
            return false;
    return true;
}

int del(void *data, char **args)
{
    if (!*args)
        return 84;
    for (int i = 0; args[i]; i++) {
        if (!is_num(args[i]))
            return 84;
        if (del_el(data, my_getnbr(args[i]), true))
            return 84;
    }
    return 0;
}
