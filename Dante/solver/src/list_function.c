/*
** EPITECH PROJECT, 2023
** dante
** File description:
** list function
*/
#include "../include/my.h"

void set_add_o(open_t **head, int end, tab *solvtab, open_t *ptr)
{
    open_t *tempop, *current = *head;
    maze *temp;
    tempop = malloc(sizeof(open_t));
    temp = malloc(sizeof(maze));
    temp->start = solvtab->start;
    temp->end = end;
    temp->total = solvtab->start + end;
    temp->col = solvtab->col;
    temp->row = solvtab->row;
    temp->parent = ptr->node;
    tempop->node = temp;
    while (tempop->node->total >= current->node->total && current->next != NULL)
        current = current->next;
    if (current->next == NULL){
        tempop->next = NULL;
        current->next = tempop;
        return;
    }
    tempop->next = current->next;
    current->next = tempop;
}

void set_add_c(open_t **head, maze *node, tab *solvtab)
{
    open_t *tempop;
    tempop = malloc(sizeof(open_t));
    tempop->node = node;
    tempop->next = *head;
    *head = tempop;
}

void del_node(open_t **head, int position)
{
    int i = 0;
    open_t *temp;
    open_t *ptr;
    ptr = *head;
    if (position == 0){
        *head = (*head)->next;
        free(ptr);
        return;
    }
    temp = *head;
    for (i = 0; i != position && ptr->next != NULL; i++){
        if (ptr->next == NULL)
            return;
        ptr = ptr->next;
    }
    for (i = 0; i != position - 1; i++)
        temp = temp->next;
    temp->next = ptr->next;
    ptr->next = NULL;
    free(ptr);
}

int small_number(open_t *head)
{
    int total = head->node->total;
    while (head != NULL){
        if (total > head->node->total)
            total = head->node->total;
        head = head->next;
    }
    return (total);
}

void free_list(open_t *tail)
{
    open_t *next;
    while (tail != NULL){
        next = tail->next;
        free(tail);
        tail = next;
    }
}
