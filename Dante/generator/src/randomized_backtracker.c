/*
** EPITECH PROJECT, 2023
** my_gen
** File description:
** Dante
*/
#include "../include/generator.h"

int set_error_rc(int *rows, int *cols, char **argv)
{
    *rows = atoi(argv[1]), *cols = atoi(argv[2]);
    if (*rows <= 0 || *cols <= 0
    || *rows > 50000 || *cols > 50000) return (84);
    return (0);
}

void entry_exit(maze_t grid)
{
    int dec = (grid.rows + 1) * grid.cols;

    if (!grid.rows || !grid.cols)
        return;
    grid.str[0] = '*';
    grid.str[dec - 2] = '*';

    if (!(grid.rows & 1) && !(grid.cols & 1))
        grid.str[dec - 3] = '*';
}

int main(int argc, char **argv)
{
    maze_t grid;
    visi_t **stack;
    int rows = 0, cols = 0, perfect = 0;
    if (argc < 2 || argc > 4) return (84);
    srand(time(NULL));
    parse_inputs(argv, &perfect);
    if (set_error_rc(&rows, &cols, argv) == 84) return (84);
    grid = new_grid(rows, cols);
    grid = initialize_visited_cells(rows, cols, grid);
    if (!grid.str || !(stack = malloc(sizeof(visi_t) * (grid.v.x * grid.v.y))))
        return (84);
    entry_exit(grid);
    if (rows > 1 && cols > 1) {
        randomized_dfs(&grid, stack, perfect);
    }
    write(1, grid.str, (rows + 1) * cols - 1);
    free(grid.str), free(grid.tab), free(stack);
    return (0);
}
