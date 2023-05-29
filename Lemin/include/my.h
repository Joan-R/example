/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-lemin-tom.calogheris
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_
    #define _GNU_SOURCE
    #define ERROR_EXIT 84
    #define SUCCES_EXIT 0
    #define bool unsigned int
    #define true 1
    #define false 0
    #include <unistd.h>
    #include <stdlib.h>
    #include "struct.h"
    #include <stdio.h>

/*affichage.c*/
void affichage(recup *data);

/*algo.c*/
int start_algo(graph_t *grap);

/*ants.c*/
ant_list_t *create_list_ant(int nb, base_t *start);
void print_ant(ant_list_t *ant);
void remove_ant(ant_list_t **list, ant_list_t *ant);

/*base_list.c*/
void base_list_set_empty(base_list_t *list);
void add_base_to_list(base_list_t **list, base_t *base);
void print_base_list(base_list_t *list);
void add_base_to_end_list(base_list_t **list, base_t *base);
void remove_first_base_list(base_list_t **list);

/*base.c*/
base_t *create_base(char *name, enum start_end_n position);
base_t *find_base(base_list_t *list, char *name);

/*change_dist.c*/
void change_dist_end(base_t *base, int *find_start);

/*check_garbage.c*/
char **check_garbage(char **file, recup *data);

/*find_base.c*/
base_t *find_smallest_base(base_t *base, int num_ants);

/*free.c*/
void free_list(recup *data);
void all_free(graph_t *grap, recup *data, int err);

/*gestion_erreur*/
int check_coord(int i, int j, recup *data);
void check_start_end(recup *data);

/*graph.c*/
graph_t *create_graph(recup *data);
void print_graph(graph_t *grap);

/*help.c*/
int help(char *str);

/*linked_list_room.c*/
void set_add_room(char *name, char *pos, recup *data);
void set_add_sae(char *name, char *pos, int se, recup *data);
void print_list(recup *data);

/*memset.c*/
void* my_memset(void *s, int c, long unsigned int n);

/*my_str_to_words_array*/
char **my_str_to_words_array(char *buffer);

/*recup_file*/
char *recup_file(void);

/*room.c*/
void check_name_and_pos(char *name, char *pos, recup *data);
void init_room(recup *data);

/*string.c*/
bool my_strcmp(char *str1, char *str2);
void my_put_nbr(int nbr);
void my_putnbr(long long nb);
char *my_strdup(char *str);

/*suite_my_str_to_words_array*/
bool good_letter(char c);
bool end_of_string(char *buffer, int i);
char **put_eof_end_of_string(char **file, str *a);

/*tuyau.c*/
bool tuyaux(recup *get);

/*tuyau_next.c*/
void put_in_ll_exit(char *name, recup *get);
void put_in_ll_enter(char *name, recup *get);
bool same_pipe(struct tuyau *connect, recup *get);

/*tunnel.c*/
void link_two_base(graph_t *grap, char *name_1, char *name_2);

/*write.c*/
int my_strlen(char *str);
int my_putchar(char lt);
int my_putstr(char *str);
int my_putchar_err(char lt);
int my_putstr_err(char *str);

#endif /* !MY_H_ */
