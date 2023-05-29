/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-lemin-tom.calogheris
** File description:
** string
*/

#include "../include/my.h"

bool my_strcmp(char *str1, char *str2)
{
    if (str1 == NULL || str2 == NULL)
        return (false);
    int i = 0;
    for (; str1[i] && str2[i]; i++) {
        if (str1[i] != str2[i])
            return false;
    } if (str1[i] != str2[i])
        return false;
    return true;
}

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

void my_putnbr(long long nb)
{
    if (nb < 0) {
        nb = nb * -1;
        my_putchar('-');
    }
    if (nb < 10) {
        my_putchar(nb + 48);
        return;
    }
    my_putnbr(nb / 10);
    my_putchar(nb % 10 + 48);
}

char *my_strdup(char *str)
{
    char *dup = malloc(sizeof(char) * (my_strlen(str) + 1));
    int i = 0;
    for (; str[i]; i++) {
        dup[i] = str[i];
    } dup[i] = '\0';
    return dup;
}
