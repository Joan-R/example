/*
** EPITECH PROJECT, 2023
** Dante_solve
** File description:
** main temporaire
*/
#include "../include/my.h"

int main(int argc, char **argv)
{
    int i = 0, j = 0, end_row = 0, end_col = 0;
    if (argc != 2 && argc != 4)
        return (84);
    tab *solvtab = malloc(sizeof(tab));
    solvtab->arr = load_file(argv[1], solvtab);
    for (end_row = 0; solvtab->arr[end_row] != NULL; end_row++);
    while (solvtab->arr[0][end_col] != '\n'
        && solvtab->arr[0][end_col] != '\0')
        end_col++;
    if (argc == 2){
        solvtab->rowmax = end_row - 1;
        solvtab->colmax = end_col - 1;
    } else {
        solvtab->rowmax = atoi(argv[2]) - 1;
        solvtab->colmax = atoi(argv[3]) - 1;
    }
    find_path(solvtab);
    free_array(solvtab->arr);
    return (0);
}
