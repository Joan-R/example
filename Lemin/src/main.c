/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-lemin-tom.calogheris
** File description:
** main
*/

#include "../include/my.h"

int parsing(char *buffer, recup *data)
{
    int poubelle = 0;
    data->file = my_str_to_words_array(buffer);
    data->file = check_garbage(data->file, data);
    data->start = NULL;
    data->end = NULL;
    data->nb_start = 0, data->nb_end = 0;
    if (data->Statut == Garbage)
        poubelle = 1;
    data->Statut = 0;
    check_start_end(data);
    init_room(data);
    tuyaux(data);
    if (poubelle == 1 && data->Statut == Error)
        data->Statut = Garbage;
    if (data->Statut == Error || data->Statut == Garbage) {
        affichage(data);
        all_free(NULL, data, 1);
        return (84);
    }
    return (0);
}

int main(int ac, char **av)
{
    if (ac > 2)
        return 84;
    if (ac == 2)
        return help(av[1]);
    char *buffer = NULL, return_val = 0;
    recup *data = malloc(sizeof(recup));
    data->Statut = 0;
    if ((buffer = recup_file()) == NULL){
        free(data);
        return (84);
    }
    if (parsing(buffer, data) == 84)
        return (84);
    affichage(data);
    graph_t *grap = create_graph(data);
    return_val = start_algo(grap);
    all_free(grap, data, 0);
    return return_val;
}
