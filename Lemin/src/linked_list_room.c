/*
** EPITECH PROJECT, 2023
** lem_in
** File description:
** Fonctions pour les listes chainées des rooms
*/

#include "../include/my.h"

void set_add_sae(char *name, char *pos, int se, recup *data)
{
    sae *node = malloc(sizeof(sae)), *current;
    if (se == 0)
        current = data->start;
    if (se == 1)
        current = data->end;
    node->name = name;
    node->pos = pos;
    node->next = NULL;
    if (current == NULL){
        if (se == 0)
            data->start = node;
        if (se == 1)
            data->end = node;
        return;
    }
    while (current->next != NULL)
        current = current->next;
    current->next = node;
}

void set_add_room(char *name, char *pos, recup *data)
{
    llr *node = malloc(sizeof(llr));
    llr *current = data->room;
    node->name = name;
    node->pos = pos;
    node->next = NULL;
    if (current == NULL){
        data->room = node;
        return;
    }
    while (current->next != NULL)
        current = current->next;
    current->next = node;
}

void print_start_end(llr *current, recup *data)
{
    sae *ptr_s = data->start, *ptr_e = data->end;
    while (ptr_s != NULL){
        if (data->nb_start != 0 && my_strcmp(current->name, ptr_s->name)
            && my_strcmp(current->pos, ptr_s->pos))
            my_putstr("##start\n");
        ptr_s = ptr_s->next;
    }
    while (ptr_e != NULL){
        if (data->nb_end != 0 && my_strcmp(current->name, ptr_e->name)
            && my_strcmp(current->pos, ptr_e->pos))
            my_putstr("##end\n");
        ptr_e = ptr_e->next;
    }
}

void print_list(recup *data)
{
    llr *current = data->room;
    pipe_ *ptr = data->tuyaux;
    while (current != NULL){
        print_start_end(current, data);
        my_putstr(current->name);
        my_putchar(' ');
        my_putstr(current->pos);
        my_putchar('\n');
        current = current->next;
    }
    if (data->Statut == Garbage && data->tuyaux == NULL)
        return;
    my_putstr("#tunnels\n");
    while (ptr != NULL){
        my_putstr(ptr->enter);
        my_putchar('-');
        my_putstr(ptr->exit_);
        my_putchar('\n');
        ptr = ptr->next;
    }
}
