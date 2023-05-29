/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-lemin-tom.calogheris
** File description:
** algo
*/

#include "../include/my.h"

bool dest_base_smaller(base_t *dest, base_t *ori)
{
    int num_ori = 0, num_dest = 0;
    tunnel_t *list = dest->branches;
    while (list) {
        if (list->base == ori) {
            num_ori = list->dist_end;
            break;
        }
        list = list->next;
    } list = ori->branches;
    while (list) {
        if (list->base == dest) {
            num_dest = list->dist_end;
            break;
        }
        list = list->next;
    }
    if (num_dest > num_ori) return false;
    return true;
}

int move_ant(ant_list_t **list_ant, ant_list_t *ant, graph_t *grap)
{
    bool beg = false;
    if (ant->base->position == START) beg = true;
    base_t *dest = find_smallest_base(ant->base, grap->num_ants);
    if (dest == NULL) {
        if (beg == true) return 1;
        return 0;
    }
    if (dest_base_smaller(dest, ant->base) == false) {
        if (beg == true) return 1;
        return 0;
    }
    ant->base->full = false;
    ant->base = dest;
    if (ant->base->position == BASE) {
        ant->base->full = true;
    } print_ant(ant);
    if (ant->base->position == END) remove_ant(list_ant, ant);
    return 2;
}

void step_algo(graph_t *grap, ant_list_t **list_ant)
{
    int res = 0;
    ant_list_t *list = *list_ant, *next = NULL;
    while (list) {
        next = list->next;
        res = move_ant(list_ant, list, grap);
        if (res == 1) break;
        if (res == 2) my_putchar(' ');
        list = next;
    }
    my_putchar('\n');
}

int start_algo(graph_t *grap)
{
    ant_list_t *list_ant = create_list_ant(grap->num_ants, grap->start);
    int find_start = 0;
    change_dist_end(grap->end, &find_start);
    if (find_start == 0) return 84;
    my_putstr("#moves\n");
    base_list_set_empty(grap->list_b);
    while (list_ant) {
        step_algo(grap, &list_ant);
    }
    return 0;
}
