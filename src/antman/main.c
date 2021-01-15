/*
** EPITECH PROJECT, 2021
** antman
** File description:
** main
*/

#include "antman.h"

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