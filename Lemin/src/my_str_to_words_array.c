/*
** EPITECH PROJECT, 2023
** lem_in
** File description:
** char * en char **
*/

#include "../include/my.h"

char **suite_str(char *src, char **file, str *a)
{
    while (src[a->i] && !end_of_string(src, a->i)) {
        while (src[a->i] && src[a->i] != 10 && good_letter(src[a->i])) {
            file[a->l1][a->l2] = src[a->i];
            a->l2++, a->i++;
        }
        while (src[a->i] && src[a->i] != 10 && !good_letter(src[a->i]))
            a->i++;
        file[a->l1][a->l2] = ' ';
        a->l2++;
    }
    file = put_eof_end_of_string(file, a);
    a->l2 = 0, a->l1++;
    if (src[a->i] == '#' && src[a->i + 1] != '#') {
        while (src[a->i] && src[a->i] != 10)
            a->i++;
    }
    while (src[a->i] && (src[a->i] == 10 || !good_letter(src[a->i])))
        a->i++;
    return (file);
}

int nombre_de_lettre_in_ligne(char *buffer, int y)
{
    int compt = 0;
    while (buffer[y] && (buffer[y] == 10 || !good_letter(buffer[y])))
        y++;
    while (!end_of_string(buffer, y)) {
        while (buffer[y] && buffer[y] != 10 && good_letter(buffer[y])) {
            y++;
            compt++;
        }
        while (buffer[y] && buffer[y] != 10 && !good_letter(buffer[y]))
            y++;
        compt++;
    }
    return (compt);
}

int nombre_de_lettre(char *buffer, int i)
{
    int y = 0;
    while (i > 0) {
        while (buffer[y] && buffer[y] != 10)
            y++;
        while (buffer[y] && buffer[y] == 10)
            y++;
        i--;
    }
    return (nombre_de_lettre_in_ligne(buffer, y));
}

int nombre_de_ligne(char *buffer)
{
    int count = 0, i = 0;
    while (buffer[i]) {
        if (buffer[i] == '\n' && buffer[i + 1] != 10) {
            count++;
        }
        i++;
    }
    if (i - 1 >= 0 && buffer[i - 1] != 10) {
        count++;
    }
    return (count + 1);
}

char **my_str_to_words_array(char *buffer)
{
    char **file = NULL;
    int nml = nombre_de_ligne(buffer);
    str *a = malloc(sizeof(str));
    a->i = 0;
    a->l1 = 0;
    a->l2 = 0;
    file = malloc(sizeof(char *) * nml);
    for (int y = 0; y < nml - 1; y++)
        file[y] = malloc(sizeof(char) * nombre_de_lettre(buffer, y));
    while (buffer[a->i] && (buffer[a->i] == 10 || !good_letter(buffer[a->i])))
        a->i++;
    while (buffer[a->i]) {
        file = suite_str(buffer, file, a);
    }
    file[a->l1] = NULL;
    free(buffer);
    free(a);
    return (file);
}
