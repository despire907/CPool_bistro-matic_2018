/*
** EPITECH PROJECT, 2018
** my_strncar
** File description:
** tasks3
*/

int my_strlen(char const *str);

char *my_strncat(char *dest, char const *src, int n)
{
    int i = 0;
    int len = my_strlen(dest);

    while (src[i] && (i < n || n < 0))
    {
        dest[len + i] = src[i];
        ++i;
    }
    if (src[i])
        dest[len + i] = 0;
    return dest;
}
