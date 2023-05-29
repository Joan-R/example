/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-lemin-tom.calogheris
** File description:
** struct
*/

#ifndef STRUCT_H_
    #define STRUCT_H_
    #include "my.h"

enum start_end_n {
    BASE = 0,
    START,
    END
};

typedef struct base {
    char *name;
    enum start_end_n position;
    bool full;
    struct tunnel *branches;
    int dist_stock;
} base_t;

typedef struct base_list {
    base_t *base;
    struct base_list *next;
} base_list_t;

typedef struct graph {
    base_list_t *list_b;
    base_t *start;
    base_t *end;
    int num_ants;
} graph_t;

typedef struct tunnel {
    int dist_end;
    struct tunnel *next;
    base_t *base;
} tunnel_t;

typedef struct ant_list_t {
    int nb;
    base_t *base;
    struct ant_list_t *next;
} ant_list_t;

enum exit_ {
    Statut = 0,
    Good,
    Error,
    Garbage
};

typedef struct str {
    int i;
    int l1;
    int l2;
} str;

typedef struct ll_room {
    char *name;
    char *pos;
    struct ll_room *next;
} llr;

typedef struct start_and_end {
    char *name;
    char *pos;
    struct start_and_end *next;
} sae;

typedef struct tuyau {
    char *enter;
    char *exit_;
    struct tuyau *next;
} pipe_;

typedef struct donnee_recup {
    struct start_and_end *start;
    struct start_and_end *end;
    struct ll_room *room;
    struct tuyau *tuyaux;
    char **file;
    int nb_ant;
    int nb_start;
    int nb_end;
    enum exit_ Statut;
} recup;

#endif /* !STRUCT_H_ */
