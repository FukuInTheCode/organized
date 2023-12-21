/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

static uint32_t find_id(my_item_t *next)
{
    if (!next)
        return 0;
    return next->id + 1;
}

int add_el(my_item_t **list, char const *type, char const *name)
{
    my_item_t *new_item = malloc(sizeof(my_item_t));

    if (!new_item)
        return 84;
    new_item->name = my_strdup(name);
    new_item->type = my_strdup(type);
    if (!new_item->name || !new_item->type)
        return 84;
    new_item->id = find_id(*list);
    new_item->next = *list;
    *list = new_item;
    return 0;
}
