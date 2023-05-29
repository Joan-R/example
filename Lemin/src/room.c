/*
** EPITECH PROJECT, 2023
** lem_in
** File description:
** Pour initialiser les rooms avec gestion d'erreur
*/

#include "../include/my.h"

char *take_coord(int i, int j, recup *data)
{
    int l = 0, k = 0;
    char *pos = NULL;
    k += check_coord(i, j, data);
    pos = malloc(sizeof(char) * (k + 1));
    pos[k] = '\0';
    for (l = 0; data->file[i][j] != '\0'; j++, l++)
        pos[l] = data->file[i][j];
    return (pos);
}

void check_name_and_pos(char *name, char *pos, recup *data)
{
    llr *current = data->room;
    while (current != NULL){
        if (my_strcmp(current->name, name) || my_strcmp(current->pos, pos))
            data->Statut = Error;
        current = current->next;
    }
}

void create_room(int i, recup *data)
{
    int j = 0;
    char *name = NULL, *pos = NULL;
    for (j = 0; data->file[i][j] != ' '; j++);
    name = malloc(sizeof(char) * (j + 1));
    name[j] = '\0';
    for (j = 0; data->file[i][j] != ' '; j++)
        name[j] = data->file[i][j];
    pos = take_coord(i, j + 1, data);
    check_name_and_pos(name, pos, data);
    set_add_room(name, pos, data);
}

void seek_room(int i, recup *data)
{
    int j = 0;
    if (data->file[i][0] == '#'){
        if (my_strcmp(data->file[i], "##start") == false
            && my_strcmp(data->file[i], "##end") == false)
            data->Statut = Error;
        return;
    }
    for (j = 0; data->file[i][j] != '\0'; j++){
        if (data->file[i][j] == ' '){
            create_room(i, data);
            return;
        }
        if (data->file[i][j] == '-')
            return;
    }
}

void init_room(recup *data)
{
    int i = 0, j = 0;
    data->room = NULL;
    data->nb_ant = 0;
    for (j = 0; data->file[i][j] != '\0'; j++){
        if (data->file[i][j] < 48 || data->file[i][j] > 57){
            data->Statut = Error;
            data->nb_ant = -1;
            break;
        } else
            data->nb_ant = (data->file[i][j] - 48) + data->nb_ant * 10;
    }
    if (data->nb_ant == 0)
        data->Statut = Error;
    for (i = 0; data->file[i] != NULL; i++){
        seek_room(i, data);
    }
}
