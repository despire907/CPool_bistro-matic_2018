/*
** EPITECH PROJECT, 2018
** bistromatik
** File description:
** error
*/

#include "include/bistromatic.h"
#include <unistd.h>

void put_strerr(char const *str)
{
    int i = 0;

    while (str[i]) {
        write(2, &str[i], 1);
        ++i;
    }
}
