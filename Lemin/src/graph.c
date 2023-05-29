/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-lemin-tom.calogheris
** File description:
** graph
*/

#include "../include/my.h"

void print_graph(graph_t *grap)
{
    base_list_t *list = grap->list_b;
    while (list) {
        my_putstr(list->base->name);
        my_putchar('\n');
        list = list->next;
    }
}

void add_base_graph(graph_t *grap, char *name, enum start_end_n state)
{
    base_t *base = create_base(name, state);
    if (state == START) grap->start = base;
    if (state == END) grap->end = base;
    add_base_to_list(&(grap->list_b), base);
}

graph_t *create_graph(recup *data)
{
    graph_t *grap = malloc(sizeof(graph_t));
    my_memset(grap, 0, sizeof(graph_t));
    grap->end = NULL, grap->start = NULL, grap->list_b = NULL;
    grap->num_ants = data->nb_ant;
    char *str_start = data->start->name, *str_end = data->end->name;
    llr *list_room = data->room;
    pipe_ *list_tunnel = data->tuyaux;
    enum start_end_n status_room = 0;
    while (list_room) {
        status_room = BASE;
        if (my_strcmp(list_room->name, str_start))
            status_room = START;
        if (my_strcmp(list_room->name, str_end))
            status_room = END;
        add_base_graph(grap, list_room->name, status_room);
        list_room = list_room->next;
    } while (list_tunnel) {
        link_two_base(grap, list_tunnel->enter, list_tunnel->exit_);
        list_tunnel = list_tunnel->next;
    } return grap;
}
