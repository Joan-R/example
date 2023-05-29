/*
** EPITECH PROJECT, 2023
** B-CPE-200-MAR-2-1-lemin-tom.calogheris
** File description:
** find_base
*/

#include "../include/my.h"

base_t *find_smallest_base(base_t *base, int num_ants)
{
    if (base->branches == NULL) return NULL;
    base_t *small = base->branches->base, *another = NULL;
    tunnel_t *tunel = base->branches;
    int dist_small = tunel->dist_end, dist_small2;
    while (tunel) { if (tunel->dist_end < dist_small ||
            (tunel->dist_end == dist_small && tunel->base->full == false &&
            small->full == true)) { small = tunel->base;
        } tunel = tunel->next;
    } if (small->full == false) return small;
    tunel = base->branches;
    while (tunel) { if (another == NULL && tunel->base->full == false) {
            another = tunel->base;
            dist_small2 = tunel->dist_end;
        } if (another && tunel->base->full == false
            && tunel->dist_end < dist_small2) { another = tunel->base;
            dist_small2 = tunel->dist_end;
        } tunel = tunel->next;
    } if (another == NULL) return NULL;
    if (dist_small - dist_small2 < num_ants) return another;
    return NULL;
}
