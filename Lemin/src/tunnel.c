/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-lemin-tom.calogheris
** File description:
** tunnel
*/

#include "../include/my.h"

void add_tunnel(tunnel_t **tunnel, base_t *base)
{
    tunnel_t *new = malloc(sizeof(tunnel_t));
    new->base = base;
    new->next = *tunnel;
    new->dist_end = 0;
    *tunnel = new;
}

void link_two_base(graph_t *grap, char *name_1, char *name_2)
{
    base_t *base_1 = find_base(grap->list_b, name_1);
    base_t *base_2 = find_base(grap->list_b, name_2);
    if (base_1 == NULL || base_2 == NULL) return;
    if (base_1 == base_2) return;
    add_tunnel(&(base_1->branches), base_2);
    add_tunnel(&(base_2->branches), base_1);
}
