/*
** EPITECH PROJECT, 2018
** bistromatik
** File description:
** main header
*/

#ifndef H_CALC
# define H_CALC

typedef struct param {
    char *opp;
    char *base;
    int bsize;
} t_param;

t_param get_param(char *base, char *opp);
char *get_entry(char const *str);
int check_nbr(char const *str, t_param p);
void put_strerr(char const *str);
int check_occurences(char *s1, char *s2);
#endif
