/*
** EPITECH PROJECT, 2018
** evalexpr
** File description:
** main
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "include/my.h"
#include "include/str_utils.h"
#include "include/calc.h"

char *get_entry(void) {
     int buffer_size = 64;
     char buffer[buffer_size];
     int readed = buffer_size;
     char *str = malloc(sizeof(char) * 1);
     char *tmp;
     
     while (readed > 0) {
         readed = read(0, buffer, buffer_size);
         tmp = my_realloc_str(str, readed + 1);
         str = tmp;
         str = my_strncat(str, buffer, readed);
     }
     return str;
}


int main(int ac, char **av)
{
    param p;
    char *expr;
    if (ac == 3) {
        expr = get_entry();
        if (get_param(av[1], av[2], &p)) {
            printf("alright\n");
            printf("expr : \"%s", expr);
        }
        else
            printf("invalid parameters\n");
        /*
        str = tej_myspace(av[1]);
        if (!str) {
            printf("error missing opperator\n");
            return 84;
        }
        res = check_expr(str);
        if (checked > 0)
            printf("\nvalid :: %i\n", res);
        else
            printf("\nerror\n");
        return 0;
        */
    }
    else
        printf("invalid number of parameters (%i)\n", ac -1);
    return (84);
}
