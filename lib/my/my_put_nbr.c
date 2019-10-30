/*
** EPITECH PROJECT, 2018
** my_put_nbr
** File description:
** task07
*/

void my_putchar(char a);

int my_put_nbr(int nb)
{
    int a;

    a = 1;
    if (nb == -2147483648) {
        my_put_nbr(-2147483);
        my_put_nbr(648);
    }
    else if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    while (nb / a >= 10)
        a *= 10;
    while (a && nb != -2147483648)
    {
        my_putchar(48 + nb / a);
        nb -= (nb / a) * a;
        a /= 10;
    }
    return (1);
}
