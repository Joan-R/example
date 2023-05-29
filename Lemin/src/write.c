/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-lemin-tom.calogheris
** File description:
** write
*/

#include "../include/my.h"

int my_strlen(char *str)
{
    int i = 0;
    if (str == NULL)
        return 0;
    while (str[i] != '\0'){
        i++;
    }
    return i;
}

int my_putchar(char lt)
{
    write(1, &lt, 1);
    return 0;
}

int my_putstr(char *str)
{
    write(1, str, my_strlen(str));
    return 0;
}

int my_putchar_err(char lt)
{
    write(2, &lt, 1);
    return 84;
}

int my_putstr_err(char *str)
{
    write(2, str, my_strlen(str));
    return 84;
}
