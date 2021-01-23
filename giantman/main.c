/*
** EPITECH PROJECT, 2021
** giantman
** File description:
** main
*/

#include <stdlib.h>
#include "giantman.h"
#include "common.h"

static int compress(char *str, int len, char mode)
{
    switch (mode) {
        case '1':
            return (lzss(str, len));
        case '2':
            return (lzss(str, len));
        case '3':
            return (image(str, len));
        default:
            return (84);
    }
}

int main(int ac, char *av[])
{
    char *str;
    int len;
    int ret;

    if (ac == 3) {
        if (read_file(av[1], &str, &len))
            return (84);
        if (len == 0)
            return (0);
        ret = compress(str, len, *av[2]);
        free(str);
        return (ret);
    } else
        return (84);
    return (0);
}