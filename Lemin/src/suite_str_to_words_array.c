/*
** EPITECH PROJECT, 2023
** lem_in
** File description:
** suite char * en char **
*/

#include "../include/my.h"

char **put_eof_end_of_string(char **file, str *a)
{
    if (a->l2 - 1 > 0)
        file[a->l1][a->l2 - 1] = 0;
    else
        file[a->l1][a->l2] = 0;
    return (file);
}

bool good_letter(char c)
{
    if (c == '\t' || c == '\r' || c == ' ')
        return (false);
    return (true);
}

bool end_of_string(char *buffer, int i)
{
    if (buffer[i] == 0 || buffer[i] == 10)
        return (true);
    if (buffer[i] == '#' && buffer[i + 1] != '#')
        return (true);
    return (false);
}
