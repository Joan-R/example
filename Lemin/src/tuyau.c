/*
** EPITECH PROJECT, 2023
** lem_in
** File description:
** verification des tuyaux
*/

#include "../include/my.h"

int malloc_size_temp(char *line)
{
    int i = 0, y = 0;
    while (line[i]) {
        if (line[i] == '-')
            y = i + 1;
        i++;
    }
    return ((i - y) + 1);
}

bool recup_exit_pipe(char *line, llr *salle, recup *get)
{
    int i = 0, y = 0;
    char *temp = malloc(sizeof(char) * malloc_size_temp(line));
    for (; line[i] != '-'; i++);
    for (i = i + 1; line[i]; i++, y++)
        temp[y] = line[i];
    temp[y] = 0;
    while (salle) {
        if (my_strcmp(salle->name, temp)) {
            put_in_ll_exit(salle->name, get);
            free(temp);
            return (true);
        }
        salle = salle->next;
    }
    put_in_ll_exit(temp, get);
    free(temp);
    get->Statut = Error;
    return (false);
}

bool recup_enter_pipe(char *line, llr *salle, recup *get)
{
    int i = 0, y = 0;
    for (i = 0; line[i] != '-'; i++);
    char *temp = malloc(sizeof(char) * i + 1);
    while (line[y] != '-') {
        temp[y] = line[y];
        y++;
    }
    temp[y] = 0;
    while (salle) {
        if (my_strcmp(salle->name, temp)) {
            put_in_ll_enter(salle->name, get);
            free(temp);
            return (true);
        }
        salle = salle->next;
    }
    put_in_ll_enter(temp, get);
    free(temp);
    get->Statut = Error;
    return (false);
}

bool check_char_tuyaux(char *line, llr *salle, recup *get)
{
    int i = 0, moin = 0;
    while (line[i]) {
        if (line[i] == ' ')
            return (false);
        if (line[i] == '-')
            moin++;
        i++;
    }
    if (moin < 1)
        return (false);
    recup_enter_pipe(line, salle, get);
    recup_exit_pipe(line, salle, get);
    return (true);
}

bool tuyaux(recup *get)
{
    int i = 0, compt = 0;
    llr *salle = get->room;
    get->tuyaux = NULL;
    while (get->file[i]) {
        if (check_char_tuyaux(get->file[i], salle, get))
            compt++;
        i++;
    }
    struct tuyau *temp = get->tuyaux;
    if (compt == 0 || same_pipe(temp, get) || get->Statut == Error) {
        get->Statut = Error;
        return (true);
    }
    return (false);
}
