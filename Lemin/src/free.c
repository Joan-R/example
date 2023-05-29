/*
** EPITECH PROJECT, 2023
** lem_in
** File description:
** pour free et etre propre
*/

#include "../include/my.h"

void free_list(recup *data)
{
    llr *current = data->room, *next;
    pipe_ *ptr = data->tuyaux, *suivant;
    while (current != NULL){
        next = current->next;
        free(current->name);
        free(current->pos);
        free(current);
        current = next;
    }
    while (ptr != NULL){
        if (ptr->enter != NULL)
            free(ptr->enter);
        if (ptr->exit_ != NULL)
            free(ptr->exit_);
        suivant = ptr->next;
        free(ptr);
        ptr = suivant;
    }
}

void free_sae(recup *data)
{
    sae *current = data->start, *next, *ptr = data->end, *suivant;
    while (current != NULL){
        next = current->next;
        free(current->name);
        free(current->pos);
        free(current);
        current = next;
    }
    while (ptr != NULL){
        suivant = ptr->next;
        free(ptr->name);
        free(ptr->pos);
        free(ptr);
        ptr = suivant;
    }
}

void free_tunnel(tunnel_t *tunnel)
{
    tunnel_t *pre = tunnel;
    while (tunnel) {
        tunnel = tunnel->next;
        free(pre);
        pre = tunnel;
    }
}

void free_graph(graph_t *grap)
{
    base_list_t *current = grap->list_b, *pre = current;
    while (current) {
        current = current->next;
        free(pre->base->name);
        free_tunnel(pre->base->branches);
        free(pre->base);
        free(pre);
        pre = current;
    }
}

void all_free(graph_t *grap, recup *data, int err)
{
    int i = 0;
    free_sae(data);
    for (i = 0; data->file[i] != NULL; i++)
        free(data->file[i]);
    free(data->file);
    free_list(data);
    free(data);
    if (err == 1)
        return;
    free_graph(grap);
    free(grap);
}
