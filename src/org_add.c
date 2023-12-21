/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

static int append(my_item_t **list, char const *type, char const *name)
{
    if (add_el(list, type, name))
        return 84;
    write(1, (*list)->type, my_strlen((*list)->type));
    write(1, " n°", 3);
    my_put_nbr((*list)->id);
    write(1, " - \"", 4);
    write(1, (*list)->name, my_strlen((*list)->name));
    write(1, "\" added.\n", 9);
    return 0;
}

int add(void *data, char **args)
{
    if (!*args || !args[1])
        return 84;
    for (int i = 0; args[i]; i++) {
        if (!args[i + 1] || (my_strcmp(args[i], "WIRE") &&
            my_strcmp(args[i], "PROCESSOR") && my_strcmp(args[i], "SENSOR") &&
            my_strcmp(args[i], "DEVICE") && my_strcmp(args[i], "ACTUATOR")) ||
            append(data, args[i], args[i + 1]))
            return 84;
        i++;
     }
    return 0;
}
