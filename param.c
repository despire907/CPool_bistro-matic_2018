/*
** EPITECH PROJECT, 2018
** evalexpr
** File description:
** main
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "include/my.h"
#include "include/str_utils.h"
#include "include/calc.h"
#include "include/bistromatic.h"

int check_occurences(char *s1, char *s2)
{
    int i = 0;
    int j;

    printf("Checking identical characters ... ");
    while (s1[i]) {
        j = 0;
        while (s2[j]) {
            if (s1[i] == s2[j]) {
                printf("KO\n");
                return 0;
            }
            ++j;
        }
        ++i;
    }
    printf("OK\n");
    return 1;
}

int check_unique_char(char *str)
{
    int i = 0;
    int j;

    printf("checking  occurences in %s ... ", str);
    while (str[i]) {
        j = 1;
        while(str[i + j]) {
            if (str[i] == str[i + j]) {
                printf("KO\n");
                return 0;
            }
            ++j;
        }
        ++i;
    }
    printf("OK\n");
    return 1;
}

t_param get_param(char *base, char *opp)
{
    t_param params;
    if (check_unique_char(base) && my_strlen(base) > 1) {
        params.base = base;
        params.bsize = my_strlen(base);
    } else {
        put_strerr(SYNTAX_ERROR_MSG);
        exit(EXIT_BASE);
    }
    if (check_unique_char(opp) && my_strlen(opp) == 7) {
        params.opp = opp;
    } else {
        put_strerr(SYNTAX_ERROR_MSG);
        exit(EXIT_OPS);
    }
    if (!check_occurences(base, opp)) {
        put_strerr(SYNTAX_ERROR_MSG);
        exit(EXIT_OPS);
    }
    my_putstr("-- ALL OK --\n");
    return params;
}

char *read_str_n(int nb_to_read) {
     int buffer_size = 64;
     char buffer[buffer_size];
     int readed = buffer_size;
     char *str = malloc(sizeof(char) * 1);
     char *tmp;
     int nb = 0;
     
     while (readed > 0 && nb <= nb_to_read) {
         readed = read(0, buffer, buffer_size);
        if (readed < 0) {
            put_strerr(ERROR_MSG);
            exit(EXIT_READ);
        }
        if (nb + readed > nb_to_read)
            readed = nb_to_read - nb;
         tmp = my_realloc_str(str, readed + 1);
         str = tmp;
         str = my_strncat(str, buffer, readed);
         nb += readed;
     }
    return str;
}

char *get_entry(char const *str)
{
    char *res;
    int size_to_read = my_getnbr(str);

    if (size_to_read <= 0) {
        put_strerr(SYNTAX_ERROR_MSG);
        exit(EXIT_SIZE_NEG);
    } else
        res = read_str_n(size_to_read);
    return res;
}