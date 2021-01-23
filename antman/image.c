/*
** EPITECH PROJECT, 2021
** antman-lzss [WSL: Ubuntu]
** File description:
** image
*/

#include <stdlib.h>
#include <unistd.h>

static void skip_header(char *str, int *i)
{
    int header_len = 0;

    for (int n = 0 ; n != 5; *i += 1) {
        if (str[*i] == '\n')
            n++;
        header_len++;
    }
    write(1, str, header_len);
}

static void print_color(char *str, int pos, int nb_len)
{
    char color = 0;

    for (int i = 0; i < nb_len; i++)
        color = color * 10 + (str[pos + i] - '0');
    write(1, &color, 1);
}

int compress_img(char *str, int len)
{
    int i = 0;
    int nb_len = 0;

    if (len == 0)
        return (0);
    skip_header(str, &i);
    for (; i < len; i++) {
        for (nb_len = 0; str[i + nb_len] && str[i + nb_len] != '\n'; nb_len++);
        print_color(str, i, nb_len);
        i += nb_len;
    }
    return (0);
}