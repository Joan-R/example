/*
** EPITECH PROJECT, 2023
** lem_in
** File description:
** Pour l'affichage des valeurs
*/

#include "../include/my.h"

void affichage(recup *data)
{
    my_putstr("#number_of_ants");
    my_putchar('\n');
    my_putstr(data->file[0]);
    if (data->Statut == Garbage && data->room == NULL){
        my_putchar('\n');
        return;
    }
    my_putstr("\n#rooms\n");
    print_list(data);
}
