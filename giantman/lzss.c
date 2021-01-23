/*
** EPITECH PROJECT, 2021
** giantman
** File description:
** lzss
*/

#include <unistd.h>
#include "lzss.h"

static void add_char(char buffer[BUFFER_SIZE],
int *buff_size, char c)
{
    if (*buff_size == BUFFER_SIZE - 1)
        write(1, &(buffer[BUFFER_SIZE - 1]), 1);
    else if (*buff_size < BUFFER_SIZE - 1)
        *buff_size += 1;
    for (int i = *buff_size; i > 0; i--)
        buffer[i] = buffer[i - 1];
    buffer[0] = c;
}

static void add_str(char buffer[BUFFER_SIZE], int *buff_size,
char str[READER_SIZE], int str_len)
{
    int diff = 0;

    if (*buff_size + str_len >= BUFFER_SIZE - 1) {
        diff = (*buff_size + str_len) - (BUFFER_SIZE - 1);
        for (int i = *buff_size; i > BUFFER_SIZE - 1 - diff; i--)
            write(1, &(buffer[i]), 1);
        *buff_size = BUFFER_SIZE - 1;
    } else
        *buff_size += str_len;
    for (int i = *buff_size; i >= str_len; i--)
        buffer[i] = buffer[i - str_len];
    for (int i = 0; i < str_len; i++)
        buffer[i] = str[str_len - 1 - i];
}

static void add_str_from_dic(char buffer[BUFFER_SIZE],
int *buff_size, char c1, char c2)
{
    int pos = ((c1 << 4) | ((c2 & 240) >> 4)) & 4095;
    int len = c2 & 15;
    char add[READER_SIZE] = {0};

    for (int i = 0; i < len; i++)
        add[i] = buffer[pos - 1 - i];
    add_str(buffer, buff_size, add, len);
}

static void write_buffer(char buffer[BUFFER_SIZE], int buff_size)
{
    int start = buff_size == BUFFER_SIZE - 1 ? buff_size : buff_size - 1;

    for (int i = start; i >= 0; i--)
        write(1, &(buffer[i]), 1);
}

int lzss(char *str, int len)
{
    char buffer[BUFFER_SIZE] = {0};
    int buff_size = 0;
    char prefix = 0;
    int count_prefix = 0;

    for (int i = 0; i < len; i++, count_prefix++) {
        if (count_prefix % 9 == 0) {
            prefix = str[i];
            continue;
        }
        if (prefix & (1 << (8 - count_prefix % 9))) {
            add_str_from_dic(buffer, &buff_size, str[i], str[i + 1]);
            i++;
        } else
            add_char(buffer, &buff_size, str[i]);
    }
    write_buffer(buffer, buff_size);
    return (0);
}