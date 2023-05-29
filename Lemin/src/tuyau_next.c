/*
** EPITECH PROJECT, 2023
** lem_in
** File description:
** la suite de la verification des tuyaux
*/

#include "../include/my.h"


bool is_same_pipe(struct tuyau *connect, struct tuyau *temp, recup *get)
{
    while (temp) {
        if (my_strcmp(connect->enter, temp->enter)
        && my_strcmp(connect->exit_, temp->exit_)) {
            get->Statut = Error;
            return (true);
        }
        temp = temp->next;
    }
    return (false);
}

bool same_pipe(struct tuyau *connect, recup *get)
{
    struct tuyau *temp = connect;
    while (connect->next) {
        temp = temp->next;
        if (is_same_pipe(connect, temp, get))
            return (true);
        connect = connect->next;
        temp = connect;
    }
    return (false);
}

void put_in_ll_exit(char *name, recup *get)
{
    pipe_ *temp = get->tuyaux;
    while (temp && temp->next) {
        temp = temp->next;
    }
    temp->exit_ = my_strdup(name);
}

void put_in_ll_enter(char *name, recup *get)
{
    pipe_ *temp = get->tuyaux;
    pipe_ *add = malloc(sizeof(pipe_));
    add->enter = my_strdup(name);
    add->exit_ = NULL;
    add->next = NULL;
    if (temp == NULL) {
        get->tuyaux = add;
        return;
    }
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = add;
    return;
}
