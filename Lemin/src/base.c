/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-lemin-tom.calogheris
** File description:
** base
*/

#include "../include/my.h"

base_t *find_base(base_list_t *list, char *name)
{
    while (list) {
        if (my_strcmp(name, list->base->name) == true) return list->base;
        list = list->next;
    }
    return NULL;
}

base_t *create_base(char *name, enum start_end_n position)
{
    base_t *base = malloc(sizeof(base_t));
    my_memset(base, 0, sizeof(base_t));
    int len = my_strlen(name);
    base->name = malloc(sizeof(char) * (len + 1));
    my_memset(base->name, '\0', sizeof(char) * (len + 1));
    for (int i = 0; name[i]; i++) {
        base->name[i] = name[i];
    }
    base->position = position;
    base->branches = NULL;
    base->full = false;
    base->dist_stock = -1;
    return base;
}
