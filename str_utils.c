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

int parser(char const *str, param p)
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

int check_nbr(char const *str, param p)
{
    int i = 0;
    int status = 0;
    
    while (str[i] == p.opp[3] || str[i] == p.opp[2])
        ++i;
    while (str[i] == p.base[0]) {
        ++i;
        status = 1;
    }
    while (str[i]) {
        if (!check_occ(str[i], p.opp)) {
            printf("KO\n");
            return 0;
        }
        ++i;
    }
    if (!i) {
        printf("KO\n");
        return -1;
    }
    printf("OK\n");
    return i;
}

int check_opp(char c, param p)
{
    int i = 2;

    while (i < 7) {
        if (c == p.opp[i]) {
            printf("OK (%c)\n");
            return i;
        }
        ++i;
    }
    printf("KO\n");
    return -1;
}

int check_expr(char const *str, param p)
{
    int i = 0;
    int mode = 1;
    int jump = 0;
    int checked = 1;
    char *cpy;
    int len = my_strlen(str);
    int result = 0;


    printf("str :: %s :: %i ::::::::::%i\n", str, len);
    while (i < len && checked) {
        if (str[i] == p.opp[0] && mode) {
            printf("parsing...\n");
            jump = parser(&str[i], p);
            if (jump == -1) {
                printf("err1\n");
                return 0;
            }
            else {
                printf("malloc %i :: %c : %c\n", jump+1, str[i+1], str[i + jump]);
                cpy = malloc(sizeof(char) * (jump + 1));                                                                                                                                
                cpy = my_strncpy(cpy, &str[i+1], jump);
                checked = check_expr(cpy, p);
                i += jump+2;
                mode = 0;
            }
        } else if (str[i] == p.opp[0])
            return 0;
        if (mode && i < len) {
            printf("checking number[%i] %c...", i, str[i]);
            jump = check_nbr(&str[i], p);
            printf("jump : %i\n", jump);
            if (jump == -1 && i < len) {
                printf("err2\n");
                return 0;
            }
            else {
                i += jump;
                mode = 0;
            }
        } else if (i < len){
            printf("checking opperator %c...", str[i]);
            if (check_opp(str[i], p) != -1)
                ++i;
            else {
                printf("err3\n");
                return 0;
            }
            mode = 1;
        }
    }
    printf("check -- %i -- mode = %i\n", checked, mode);
    printf("total : %i\n", result);
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
        if (!(str[i] == ' ')) {
            cpy[space] = str[i];
            ++space;
        }
        ++i;
    }
    cpy[space] = 0;
    return cpy;
}
