/*
** EPITECH PROJECT, 2018
** evalxpr
** File description:
** tej_my_space
*/

#include "include/my.h"
#include "include/opperators.h"
#include <stdlib.h>

int check_expr(char const *str);

int parser(char const *str)
{
    int parenthesis = 0;
    int i = 0;
    int beg_p;
    char *cpy;
    
    while (str[i] && parenthesis >= 0) {
        if (str[i] == '(' && !parenthesis) {
            ++parenthesis;
            beg_p = i + 1;
        } else if (str[i] == '(' && parenthesis)
            ++parenthesis;
        if (str[i] == ')' && parenthesis == 1) {
            --parenthesis;
            return (i - beg_p);
        } else if (str[i] == ')')
            --parenthesis;
        ++i;
    }
    if (parenthesis != 0)
        return -1;
    return 1;
}

int check_nbr(char const *str)
{
    int i = 0;
    int status = 0;
    
    while (str[i] == '-' || str[i] == '+')
        ++i;
    while (str[i] == '0') {
        ++i;
        status = 1;
    }
    while (str[i] > 47 && str[i] < 59) {
        if (!(str[i] > 47 && str[i] < 59) && !status) {
            printf("KO\n");
            return -1;
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

int check_opp(char c)
{
    int i = 0;

    while (i < 5) {
        if (c == FUNCS[i].opp) {
            printf("OK (%c)\n", FUNCS[i].opp);
            return 1;
        }
        ++i;
    }
    printf("KO\n");
    return 0;
}

int check_expr(char const *str)
{
    int i = 0;
    int mode = 1;
    int jump = 0;
    int checked = 1;
    char *cpy;
    int len = my_strlen(str);

    printf("str :: %s :: %i\n", str, len);
    while (i < len && checked) {
        if (str[i] == '(') {
            printf("parsing...\n");
            jump = parser(&str[i]);
            if (jump == -1) {
                printf("err1\n");
                return 0;
            }
            else {
                printf("malloc %i :: %c : %c\n", jump+1, str[i+1], str[i + jump]);
                cpy = malloc(sizeof(char) * (jump + 1));                                                                                                                                
                cpy = my_strncpy(cpy, &str[i+1], jump);
                checked = check_expr(cpy);
                i += jump+2;
                mode = 0;
            }
        }
        if (mode && i < len) {
            printf("checking number[%i] %c...", i, str[i]);
            jump = check_nbr(&str[i]);
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
            if (check_opp(str[i]))
                ++i;
            else {
                printf("err3\n");
                return 0;
            }
            mode = 1;
        }
    }
    printf("check -- %i -- mode = %i\n",checked, mode);
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
