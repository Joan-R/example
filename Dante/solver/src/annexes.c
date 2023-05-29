/*
** EPITECH PROJECT, 2023
** dante_solve
** File description:
** les fonctions annexes
*/
#include "../include/my.h"

char *my_strcpy(char *dest, char *src)
{
    int i = 0, j = 0;
    for (i = 0; src[i] != '\0'; i++, j++);
    dest = malloc(sizeof(char) * (j + 1));
    for (i = 0, j = 0; src[i] != '\0'; i++, j++)
        dest[j] = src[i];
    dest[j] = '\0';
    return dest;
}

void free_array(char **arr)
{
    int i = 0;
    for (i = 0; arr[i] != NULL; i++){
        free(arr[i]);
    }
    free (arr);
}

void my_put_nbr(int nbr)
{
    int  i = 0, m = 0, d = 1;
    if (nbr < 0){
        my_putchar('-');
        nbr = nbr * (-1);
    }
    if (nbr >= 0 && nbr < 10)
        my_putchar(nbr + 48);
    if (nbr > 9){
        i = nbr;
        while (i > 9){
            i = i / 10;
            d = d * 10;
        }
        while (d > 0){
            m = nbr / d;
            m = m % 10;
            my_putchar(m + 48);
            d = d / 10;
        }
    }
}

void change_c(tab *solvtab, int i)
{
    int j = 0;
    for (j = 0; solvtab->arr[i][j] != '\n'; j++){
        if (solvtab->arr[i][j] == '\0')
            break;
        if (solvtab->arr[i][j] == 'P' || solvtab->arr[i][j] == 'C')
            solvtab->arr[i][j] = '*';
    }
}

open_t *init_list(tab *solvtab)
{
    open_t *head = malloc(sizeof(open_t));
    maze *temp = malloc(sizeof(maze));
    temp->start = 0;
    temp->end = (solvtab->colmax - 0) + (solvtab->rowmax - 0);
    temp->total = temp->end;
    temp->col = solvtab->col;
    temp->row = solvtab->row;
    temp->parent = NULL;
    head->node = temp;
    head->next = NULL;
    return (head);
}
