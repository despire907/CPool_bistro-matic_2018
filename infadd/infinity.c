/*
** EPITECH PROJECT, 2018
** infinadd
** File description:
** Add Calculator
*/

#include<stdlib.h>
#include<stdio.h>

int my_strlen(char const *str);
int my_putstr(char const *str);

int plus_tmp(char **av)
{
    int i = 1;
    int tmp = 0;
    int len1 = my_strlen(av[1]);
    int len2 = my_strlen(av[2]);

    while (i <= len1) {
        if (i <= len2) {
            tmp = ((av[1][len1 - i] - 48) + (av[2][len2 - i] - 48) + tmp) / 10;
        } else {
            tmp = ((av[1][len1 - i] - 48) + tmp) / 10;
        }
        i = i + 1;
    }
    return (i + tmp);
}

char *swap(char **av)
{
    int len1 = my_strlen(av[1]);
    int len2 = my_strlen(av[2]);
    char *str;
    char *tmp;

    if (len1 < len2) {
        tmp = av[1];
        av[1] = av[2];
        av[2] = tmp;
    }
    str = malloc(sizeof(char) * plus_tmp(av));
    return(str);
}

char *addinf(char **av)
{
    char *str = swap(av);
    int i = 1;
    int tmp = 0;
    int len1 = my_strlen(av[1]);
    int len2 = my_strlen(av[2]);
    int len_str = plus_tmp(av) - 1;
    while (i <= len1 && 48 <= av[1][0] <= 57 || i <= len1 && av[1][0] == '-') {
        if (i <= len2 && 48 <= av[2][0] <= 57) {
            str[len_str - i] = ((av[1][len1 - i] - 48) + (av[2][len2 - i] - 48) + tmp) % 10 + 48;
            tmp = ((av[1][len1 - i] - 48) + (av[2][len2 - i] - 48) + tmp) / 10;
        } else if (i <= len2 && av[2][0] == '-') {
            av[1][0] = 0;
            av[2][0] = 0;
            my_putstr("jojo");
            str[len_str - i] = ((av[1][len1 - i] - 48) + (av[2][len2 - i] - 48) + tmp) % 10 + 48;
            tmp = ((av[1][len1 - i] - 48) + (av[2][len2 - i] - 48) + tmp) / 10;
        } else {
            str[len_str - i] = ((av[1][len1 - i] - 48) + tmp) % 10 + 48;
            tmp = ((av[1][len1 - i] - 48) + tmp) / 10;
        }
        i = i + 1;
    }
    if (tmp != 0)
        str[len_str - i] = tmp + 48;
    str[len_str] = '\0';
    return (str);
}

void debug(char *str, char **av)
{
    int i = 0;
    int len = plus_tmp(av);
    while (i < len) {
        printf("..%c..\n", str[i]);
        i = i + 1;
    }
}

int main(int ac, char **av)
{
    char *result = addinf(av);
    my_putstr(result);
    return (0);
}
