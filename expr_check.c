/*
** EPITECH PROJECT, 2018
** evalxpr
** File description:
** tej_my_space
*/

#include "include/my.h"
#include "include/calc.h"
#include <stdlib.h>
#include <stdio.h>

int check_expr(char *str, t_param p);

int parser(char const *str, t_param p)
{
    int parenthesis = 0;
    int i = 0;
    int beg_p;
    char *cpy;
    
    while (str[i] && parenthesis >= 0) {
        if (str[i] == p.opp[0] && !parenthesis) {
            ++parenthesis;
            beg_p = i + 1;
        } else if (str[i] == p.opp[0] && parenthesis)
            ++parenthesis;
        if (str[i] == p.opp[1] && parenthesis == 1) {
            --parenthesis;
            return (i - beg_p);
        } else if (str[i] == p.opp[1])
            --parenthesis;
        ++i;
    }
    if (parenthesis != 0)
        return -1;
    return 1;
}

int check_occ(char c, char const *str)
{
    int i = 0;
    int found = 0;

    while (str[i]) {
        if (str[i] == c)
            return 1;
        ++i;
    }
    return 0;
}

int check_nbr(char const *str, t_param p)
{
    int i = 0;

    while (str[i] && check_occ(str[i], p.base)) {
        ++i;
    }
    if (!i) {
        printf("KO\n");
        return -1;
    }
    printf("OK\n");
    return i;
}

int check_opp(char c, t_param p)
{
    int i = 2;

    while (i < 7) {
        if (c == p.opp[i]) {
            printf("opp %c found\n", c);
            return i;
        }
        ++i;
    }
    printf("opp %c not found\n", c);
    return -1;
}

int is_opp(char c, t_param p)
{
    if (check_opp(c, p) != -1)
        return 1;
    printf("err3\n");
    return 0;
}

int is_nb(char *str, t_param p, int *check)
{
    int i = 0;
    int jump;
    char *cpy;

    while (str[i] == p.opp[3] || str[i] == p.opp[2])
        ++i;
    if (str[i] == p.opp[0]) {
        printf("parsing\n");
        jump = parser(&str[i], p);
        if (jump == -1)
            *check = 0;
        else
            cpy = malloc(sizeof(char) * (jump + 1));
            cpy = my_strncpy(cpy, &str[i + 1], jump);
            *check = check_expr(cpy, p);
            return (i + jump + 2);
    } else {
        jump = check_nbr(&str[i], p);
        if (jump == -1)
            *check = 0;
        else
            return i + jump;
    }
    return 0;
}

int check_expr(char *str, t_param p)
{
    int i = 0;
    int mode = 1;
    int jump = 0;
    int checked = 1;
    char *cpy;
    int len = my_strlen(str);


    printf("=> %s :: %i\n", str, len);
    while (i < len && checked) {
        if (mode) {
            printf("checking number %c...", str[i]);
            jump = is_nb(&str[i], p, &checked);
            i += jump;
            mode = 0;
        } else if (!mode && i < len){
            printf("checking opperator %c...", str[i]);
            checked = is_opp(str[i], p);
            ++i;
            mode = 1;
        }
    }
    printf("check -- %i -- mode = %i\n", checked, mode);
    return (checked - mode);
}

char *tej_myspace(char const *str)
{
    int i = 0;
    int space = 0;
    int len = my_strlen(str);
    int nbr = 0;
    char *cpy;
    while (str[i]) {
        if (str[i] > 47 && str[i] < 59)
            nbr = 1;
        else if (!(str[i] > 47 && str[i] < 59) && nbr && str[i] != ' '){
            nbr = 0;
        }
        if (str[i] == ' ' && (str[i+1] > 47 && str[i+1] < 59) && nbr)
            return 0;
        if (str[i] == ' ')
            ++space;
        ++i;
    }
    cpy = malloc(sizeof(char) * (len - space));
    i = 0;
    space = 0;
    while (str[i]) {
        printf("str %c\n", str[i]);
        if (!(str[i] == ' ')) {
            printf("cpy %c\n", str[i]);
            cpy[space] = str[i];
            ++space;
        }
        ++i;
    }
    cpy[space] = 0;
    return cpy;
}
