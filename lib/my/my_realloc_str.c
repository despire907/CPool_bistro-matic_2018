/*
** EPITECH PROJECT, 2018
** realloc
** File description:
** 
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_realloc_str(char *str, int nb)
{
    int len = nb + my_strlen(str);
    char *cpy = malloc(sizeof(char) * len);
    int i = 0;

    while (str[i] && i < len) {
        cpy[i] = str[i];
        ++i;
    }
    cpy[len - 1] = '\0';
    return cpy;
}
