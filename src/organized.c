/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

static int free_list(my_item_t **items)
{
    for (; *items; del_el(items, (*items)->id, false));
    return 0;
}

int main(int argc, char **argv, char **envp)
{
    my_item_t *items = NULL;
    int return_value = workshop_shell(&items);

    if (argc != 1)
        return 84;
    free_list(&items);
    return return_value;
}
