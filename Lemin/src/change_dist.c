/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-lemin-tom.calogheris
** File description:
** change_dist
*/

#include "../include/my.h"

void change_dist_adj(base_t *new, base_t *old, int dist)
{
    if (new->dist_stock == -1) new->dist_stock = dist;
    tunnel_t *branches = new->branches;
    while (branches) {
        if (branches->base == old) {
            branches->dist_end = dist - 1;
            return;
        }
        branches = branches->next;
    }
}

void change_dist_list(base_t *base, int *find_start, base_list_t **list)
{
    tunnel_t *branches = base->branches;
    if (base->position == START) *find_start = 1;
    int dist = base->dist_stock + 1;
    while (branches) {
        if (branches->base->full == false) {
            branches->dist_end = dist;
            change_dist_adj(branches->base, base, dist);
            add_base_to_end_list(list, branches->base);
        }
        branches = branches->next;
    } base->full = true;
    remove_first_base_list(list);
}

void change_dist_end(base_t *base, int *find_start)
{
    base_list_t *list = NULL;
    base->dist_stock = 0;
    add_base_to_end_list(&list, base);
    while (list) {
        change_dist_list(list->base, find_start, &list);
    }
}
