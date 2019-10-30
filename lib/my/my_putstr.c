/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** task02
*/

void my_putchar(char a);

int my_putstr(char const *str)
{
    int i;

    i = 0;
    while (str[i]) {
        my_putchar(str[i]);
        ++i;
    }
    return (1);
}
