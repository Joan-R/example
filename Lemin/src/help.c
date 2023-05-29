/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-lemin-tom.calogheris
** File description:
** help
*/

#include "../include/my.h"

int help(char *str)
{
    if (my_strcmp(str, "-h") == false)
        return my_putstr_err("'./lem_in -h'\n");
    return my_putstr("This is help\n");
}
