/*
** EPITECH PROJECT, 2021
** antman-lzss [WSL: Ubuntu]
** File description:
** image
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

int my_getnbr(char const *str)
{
    int i = 0;
    int neg = 1;
    long number = 0;

    while (str[i] != '\0' && (str[i] == '-' || str[i] == '+')) {
        if (str[i] == '-')
            neg *= -1;
        i++;
    }
    while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9')) {
        number = number * 10 + (str[i] - '0');
        i++;
    }
    number *= neg;
    if (number > 2147483647 || number < -2147483648)
        return (0);
    return (number);
}

void my_strncpy_pos(char *dest, char const *src, int n, int pos)
{
    unsigned char add_border = 1;
    int i = 0;

    while (i < n) {
        dest[i] = src[i + pos];
        if (src[i + pos] == '\0') {
            add_border = 1;
            break;
        }
        i++;
    }
    if (add_border)
        dest[i] = '\0';
}

static void skip_header(char *str, int *i)
{
    for (int n = 0 ; n != 5; *i += 1) {
        if (str[*i] == '\n')
            n++;
        my_putchar(str[*i]);
    }
}

int compress_img(char *str, int len)
{
    int i = 0;
    char *tmp;
    int int_tmp;
    int j;

    skip_header(str, &i);
    for (; i < len; i++) {
        for (j = i; str[j] != '\n' && str[j] != '\0'; j++);
        tmp = malloc(sizeof(char) * (j - i + 1));
        my_strncpy_pos(tmp, str, j - i, i);
        int_tmp = my_getnbr(tmp);
        write(1, &int_tmp, 1);
        free(tmp);
        i = j;
    }
    return (0);
}