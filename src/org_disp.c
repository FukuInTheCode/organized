/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

int disp(void *data, char **args)
{
    if (*args)
        return 84;
    for (my_item_t *list = *(my_item_t **)data; list; list = list->next) {
        write(1, list->type, my_strlen(list->type));
        write(1, " n'", 3);
        my_put_nbr(list->id);
        write(1, " - \"", 4);
        write(1, list->name, my_strlen(list->name));
        write(1, "\"\n", 2);
    }
    return 0;
}
