/*
** EPITECH PROJECT, 2021
** giantman
** File description:
** image
*/

#include <unistd.h>
#include "my.h"

static void print_header(int *i, char *str, int len)
{
    int nb_return = 0;
    int nb_chars = 0;

    for (; *i < len && nb_return < 5; *i += 1, nb_chars++) {
        if (str[*i] == '\n')
            nb_return++;
    }
    write(1, str, nb_chars);
}

int image(char *str, int len)
{
    int i = 0;
    int nb = 0;

    print_header(&i, str, len);
    for (; i < len; i++) {
        nb = ((int) str[i]) & 255;
        my_put_nbr(nb);
        write(1, "\n", 1);
    }
    return (0);
}