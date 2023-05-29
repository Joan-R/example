/*
** EPITECH PROJECT, 2023
** lem_in
** File description:
** check_garbage
*/

#include "../include/my.h"

char **free_other_line(char **file, int i)
{
    free(file[i]);
    char *add = NULL;
    file[i] = add;
    i++;
    while (file[i]) {
        free(file[i]);
        i++;
    }
    return (file);
}

bool next_line(char **file, int i)
{
    if ((my_strcmp("##end", file[i]) &&
    my_strcmp("##end", file[i + 1])) ||
    (my_strcmp("##start", file[i]) &&
    my_strcmp("##start", file[i + 1]))) {
        return (false);
    }
    return (true);
}

bool good_line(char *line)
{
    int i = 0;
    while (line[i]) {
        if (line[i] == ' ' || line[i] == '-' ||
        (line[i] == '#' && line[i + 1] != '#')) {
            return (true);
        }
        i++;
    }
    return (false);
}

char **check_garbage(char **file, recup *data)
{
    if (file[0] == NULL)
        return (file);
    int i = 1;
    while (file[i]) {
        if (good_line(file[i]) && next_line(file, i)) {
            i++;
        } else {
            file = free_other_line(file, i);
            data->Statut = Garbage;
            return (file);
        }
    }
    return (file);
}
