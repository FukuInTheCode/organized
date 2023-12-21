/*
** EPITECH PROJECT, 2023
** Unname file ^^
** File description:
** Placeholder
*/

#include "my.h"

static int my_cmp(my_item_t *a, my_item_t *b, char **args)
{
    int cmp_value = 0;

    if (!*args)
        return cmp_value;
    if (!my_strcmp(*args, "NAME"))
        cmp_value = my_strcmp(a->name, b->name);
    if (!my_strcmp(*args, "ID"))
        cmp_value = a->id - b->id;
    if (!my_strcmp(*args, "TYPE"))
        cmp_value = my_strcmp(a->type, b->type);
    args++;
    if (*args && !my_strcmp(*args, "-r")) {
        args++;
        if (cmp_value)
            cmp_value *= -1;
    }
    if (!cmp_value)
        cmp_value = my_cmp(a, b, args);
    return cmp_value;
}

static my_item_t *last_node(my_item_t *head)
{
    for (; head && head->next; head = head->next);
    return head;
}

static int my_swap(my_item_t *a, my_item_t *b)
{
    void *tmp = NULL;
    int tmp_id = 0;

    tmp = (void *)a->name;
    a->name = b->name;
    b->name = tmp;
    tmp = a->type;
    a->type = b->type;
    b->type = tmp;
    tmp_id = a->id;
    a->id = b->id;
    b->id = tmp_id;
    return 0;
}

static my_item_t *partition(my_item_t *first, my_item_t *last, char **args)
{
    my_item_t *pivot = first;
    my_item_t *front = first;

    for (; front && front != last; front = front->next) {
        if (my_cmp(front, last, args) < 0) {
            pivot = first;
            my_swap(first, front);
            first = first->next;
        }
    }
    my_swap(first, last);
    return pivot;
}

static int quick_sort(my_item_t *first, my_item_t *last, char **args)
{
    my_item_t *pivot = NULL;

    if (first == last)
        return 0;
    pivot = partition(first, last, args);
    if (pivot && pivot->next)
        quick_sort(pivot->next, last, args);
    if (pivot && first != pivot)
        quick_sort(first, pivot, args);
    return 0;
}

static bool check_args(char **args)
{
    if (!*args)
        return false;
    for (int i = 0; args[i]; i++) {
        if (my_strcmp(args[i], "NAME") && my_strcmp(args[i], "ID")
            && my_strcmp(args[i], "TYPE"))
            return false;
        if (!args[i + 1])
            continue;
        i += (my_strcmp(args[i + 1], "-r") == 0);
    }
    return true;
}

int sort(void *data, char **args)
{
    my_item_t **list = data;

    if (!check_args(args))
        return 84;
    return quick_sort(*list, last_node(*list), args);
}
