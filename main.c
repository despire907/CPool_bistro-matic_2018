/*
** EPITECH PROJECT, 2018
** evalexpr
** File description:
** main
*/

#include <stdio.h>
#include "include/my.h"
#include "include/str_utils.h"
#include "include/calc.h"
#include "include/bistromatic.h"

int main(int ac, char **av)
{
    t_param p;
    char *expr;

    if (ac == 4) {
        expr = get_entry(av[3]);
        p = get_param(av[1], av[2]);
        if (check_occurences(" ", p.opp) && check_occurences(" ", p.base)) {
            printf("tejspace\n");
            expr = tej_myspace(expr);
        }
        if (!expr) {
            printf("error missing opperator\n");
            return 84;
        }
        if (check_expr(expr, p) > 0)
            printf("\nvalid expression\n");
        else
            printf("\nerror\n");
        return 0;
    }
    else
        put_strerr(SYNTAX_ERROR_MSG);
    return (84);
}
