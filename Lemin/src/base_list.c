/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-lemin-tom.calogheris
** File description:
** base_list
*/

#include "../include/my.h"

void base_list_set_empty(base_list_t *list)
{
    while (list) {
        list->base->full = false;
        list = list->next;
    }
}

void print_base_list(base_list_t *list)
{
    while (list) {
        my_putstr(list->base->name);
        my_putchar('\n');
        list = list->next;
    }
}

void add_base_to_list(base_list_t **list, base_t *base)
{
    base_list_t *cur = *list, *new = malloc(sizeof(base_list_t));
    new->base = base;
    new->next = cur;
    *list = new;
}

void add_base_to_end_list(base_list_t **list, base_t *base)
{
    base_list_t *cur = *list, *new = malloc(sizeof(base_list_t)), *pre = cur;
    new->next = NULL;
    new->base = base;
    while (cur) {
        if (cur->base == base) {
            free(new);
            return;
        }
        if (pre != cur) pre = pre->next;
        cur = cur->next;
    }
    if (pre == NULL) {
        *list = new;
        return;
    }
    pre->next = new;
}

void remove_first_base_list(base_list_t **list)
{
    base_list_t *cur = *list;
    *list = cur->next;
    free(cur);
}
