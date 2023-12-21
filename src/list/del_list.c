/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

static int print_del(my_item_t *i)
{
    write(1, i->type, my_strlen(i->type));
    write(1, " n°", 4);
    my_put_nbr(i->id);
    write(1, " - \"", 4);
    write(1, i->name, my_strlen(i->name));
    write(1, "\" deleted.\n", 11);
    return 0;
}

int del_el(my_item_t **list, uint32_t id, bool print)
{
    my_item_t *previous = NULL;

    for (my_item_t *current = *list; current != NULL;) {
        if (current->id != id) {
            previous = current;
            current = current->next;
            continue;
        }
        if (print)
            print_del(current);
        if (previous == NULL)
            *list = current->next;
        if (previous != NULL)
            previous->next = current->next;
        free(current->name);
        free(current->type);
        free(current);
        current = (previous == NULL) ? *list : previous->next;
    }
    return 0;
}
