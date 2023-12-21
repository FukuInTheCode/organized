/*
** EPITECH PROJECT, 2023
** MY_H
** File description:
** Placeholder
*/

#ifndef MY_H
    #define MY_H
    #include <stdio.h>
    #include <unistd.h>
    #include <stdint.h>
    #include <time.h>
    #include <limits.h>
    #include <stdarg.h>
    #include <errno.h>
    #include <fcntl.h>
    #include <math.h>
    #include <stdlib.h>
    #include <sys/stat.h>

    #include <criterion/criterion.h>
    #include <criterion/redirect.h>

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/Config.h>
    #include <SFML/GPUPreference.h>
    #include <SFML/Network.h>
    #include <SFML/OpenGL.h>
    #include <SFML/System.h>
    #include <SFML/Window.h>
    #define GETNBR_CHECK (is_int_stred(str[i]) || is_sign_stred(str[i]))
    #include "../shell/shell.h"

typedef int(*func)();

typedef struct item {
    uint32_t id;
    char *type;
    char *name;
    struct item *next;
} my_item_t;

size_t my_strlen(char const *);
int my_strcmp(char const *, char const *);
char *my_strcpy(char *, char const *);
char *my_strdup(char const *);
int add_el(my_item_t **, char const *, char const *);
int del_el(my_item_t **, uint32_t, bool);
int my_put_nbr(int);
int my_getnbr(char const *);
int sort_list(my_item_t **, func cmp);
int my_cmp_name(my_item_t *a, my_item_t *b);
#endif
