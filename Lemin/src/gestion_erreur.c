/*
** EPITECH PROJECT, 2023
** lem_in
** File description:
** gestion erreur
*/

#include "../include/my.h"

int check_coord(int i, int j, recup *data)
{
    int k = 0, espace = 0;
    if (data->file[i][j] != '-' && (data->file[i][j] < 48
        || data->file[i][j] > 57)) {
        data->Statut = Error;
    }
    for (k = 0, j++; data->file[i][j] != '\0'; j++, k++){
        if (data->file[i][j] != ' ' && (data->file[i][j] < 48
            || data->file[i][j] > 57)){
            data->Statut = Error;
        }
        if (data->file[i][j] == ' ')
            espace++;
    }
    if (espace != 1)
        data->Statut = Error;
    k++;
    return (k);
}

char *print_coord_start_end(int i, int j, int se, recup *data)
{
    int k = 0, l = 0;
    char *pos;
    k += check_coord(i, j, data);
    pos = malloc(sizeof(char) * (k + 1));
    pos[k] = '\0';
    for (l = 0; data->file[i][j] != '\0'; j++, l++)
        pos[l] = data->file[i][j];
    return (pos);
}

void room_start_end(int i, int se, recup *data)
{
    int j = 0, k = 0, l = 0;
    char *name, *pos;
    for (j = 0; data->file[i][j] != ' '; j++){
        if (data->file[i][j] == '\0'){
            data->Statut = Error;
            break;
        }
    }
    name = malloc(sizeof(char) * (j + 1));
    name[j] = '\0';
    for (j = 0; data->file[i][j] != ' ' && data->file[i][j] != '\0'; j++)
        name[j] = data->file[i][j];
    pos = print_coord_start_end(i, j + 1, se, data);
    set_add_sae(name, pos, se, data);
}

void check_start_end(recup *data)
{
    int i = 0;
    for (i = 0; data->file[i] != NULL; i++){
        if (data->file[i + 1] != NULL && my_strcmp("##start", data->file[i])){
            room_start_end(i + 1, 0, data);
            data->nb_start++;
        }
        if (data->file[i + 1] != NULL && my_strcmp("##end", data->file[i])){
            room_start_end(i + 1, 1, data);
            data->nb_end++;
        }
    }
    if (data->nb_start != 1 || data->nb_end != 1)
        data->Statut = Error;
}
