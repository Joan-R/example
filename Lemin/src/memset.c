/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-lemin-tom.calogheris
** File description:
** memset
*/

#include "../include/my.h"

void* my_memset(void *s, int c, long unsigned int n)
{
    char *new_pointer = (char *)s;
    long unsigned int i = 0;
    while (i < n) {
        new_pointer[i] = (char)c;
        i++;
    }
    return s;
}
