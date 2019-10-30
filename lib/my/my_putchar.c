/*
** EPITECH PROJECT, 2018
** my_putchar
** File description:
** putchar
*/

#include <unistd.h>

void my_putchar(char a)
{
    write(1, &a, 1);
}
