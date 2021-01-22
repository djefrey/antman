/*
** EPITECH PROJECT, 2021
** antman
** File description:
** main
*/

#include "antman.h"

int main(int ac, char *av[])
{
    char *str;
    int len;

    if (read_file(file, &str, &len))
        return (84);
    if (ac == 3) {
        if (*av[2] == '1' || *av[2] == '2')
            return (lzss(str));
        else
            return (84);
    } else
        return (84);
    return (0);
}