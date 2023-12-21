/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

int add(void *data, char **args)
{
    if (!*args || !args[1])
        return 84;
    for (int i = 0; args[i]; i++) {
        if (!args[i + 1] || (my_strcmp(args[i], "WIRE") &&
            my_strcmp(args[i], "PROCESSOR") && my_strcmp(args[i], "SENSOR") &&
            my_strcmp(args[i], "DEVICE") && my_strcmp(args[i], "ACTUATOR")))
            return 84;
        i++;
    }
    return 0;
}
