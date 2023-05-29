/*
** EPITECH PROJECT, 2023
** lem_in
** File description:
** recup le fichier dans le getline
*/

#include "../include/my.h"

char *my_strcat(char *buffer ,char *co)
{
    char *tout = malloc(sizeof(char) * my_strlen(buffer) + my_strlen(co) + 1);
    int i = 0, y = 0;
    while (co != NULL && co[i]) {
        tout[i] = co[i];
        i++;
    }
    while (buffer[y]) {
        tout[i] = buffer[y];
        i++;
        y++;
    }
    tout[i] = 0;
    free(co);
    return (tout);
}

char *recup_file(void)
{
    char *buffer = NULL;
    char *commande = NULL;
    size_t size = 0;
    while (getline(&buffer, &size, stdin) != - 1) {
        if (!buffer[0] || (buffer[0] == '#' && buffer[1] != '#')) {
        } else {
            commande = my_strcat(buffer, commande);
        }
    }
    free(buffer);
    return (commande);
}
