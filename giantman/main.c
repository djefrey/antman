/*
** EPITECH PROJECT, 2021
** giantman
** File description:
** main
*/

#include "giantman.h"

int main(int ac, char *av[])
{
    if (ac == 3) {
        if (*av[2] == '1' || *av[2] == '2')
            return (text_file_process(av[1]));
        else
            return (84);
    } else
        return (84);
    return (0);
}