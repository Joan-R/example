/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-lemin-tom.calogheris
** File description:
** ants
*/

#include "../include/my.h"

void add_ant_list(int nb, base_t *start, ant_list_t **list)
{
    ant_list_t *cur = *list, *pre = cur, *new = malloc(sizeof(ant_list_t));
    my_memset(new, 0, sizeof(ant_list_t));
    new->base = start, new->nb = nb, new->next = NULL;
    while (cur) {
        if (pre != cur) pre = pre->next;
        cur = cur->next;
    }
    if (pre == NULL) {
        *list = new;
        return;
    }
    pre->next = new;
}

ant_list_t *create_list_ant(int nb, base_t *start)
{
    ant_list_t *list = NULL;
    for (int i = 1; i <= nb; i++) {
        add_ant_list(i, start, &list);
    }
    return list;
}

void print_ant(ant_list_t *ant)
{
    my_putchar('P');
    my_putnbr(ant->nb);
    my_putchar('-');
    my_putstr(ant->base->name);
}

void remove_ant(ant_list_t **list, ant_list_t *ant)
{
    int i = 0, num = ant->nb;
    ant_list_t *cur = *list, *pre = cur;
    while (cur) {
        if (cur->nb == num) break;
        if (pre != cur) pre = pre->next;
        cur = cur->next;
    }
    if (pre == cur) {
        *list = cur->next;
        free(ant);
        return;
    } pre->next = cur->next;
    free(ant);
}
