/*
** EPITECH PROJECT, 2018
** libmy
** File description:
** get nbr
*/

int my_getnbr(char const *str)
{
    int i = 0;
    int nb = 0;
    int neg = 1;
    int temp;

    while (str[i] == '-' || str[i] == '+') {
        if (str[i] == '-')
            neg *= -1;
        ++i;
    }
    while (str[i] && str[i] >= '0' && str[i] <= '9') {
        temp = nb * 10 + str[i] - 48;
        if (temp != nb * 10 + str[i] - 48)
            return -1;
        else
            nb = temp;
        ++i;
    }
    return (nb * neg);
}
