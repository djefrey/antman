/*
** EPITECH PROJECT, 2021
** giantman
** File description:
** main
*/

#include "giantman.h"
#include "common.h"

int main(int ac, char *av[])
{
    char *str;
    int len;

    if (ac == 3) {
        if (read_file(av[1], &str, &len))
            return (84);
        if (*av[2] == '1' || *av[2] == '2')
            return (lzss(str, len));
        else
            return (84);
    } else
        return (84);
    return (0);
}