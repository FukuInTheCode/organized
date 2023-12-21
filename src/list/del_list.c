/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

int del_el(my_item_t **list, uint32_t id)
{
    my_item_t *previous = NULL;

    for (my_item_t *current = *list; current != NULL;) {
        if (current->id != id) {
            previous = current;
            current = current->next;
            continue;
        }
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
