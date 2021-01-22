/*
** EPITECH PROJECT, 2021
** antman
** File description:
** lzss
*/

#include <unistd.h>
#include "lzss.h"

static int compare_to_reader(char *start, char *reader, int pos, int len)
{
    int size = 0;

    while (start[size] == reader[size]) {
        if (size == READER_SIZE || start + size == reader ||
        pos + size == len - 1)
            return (size);
        size++;
    }
    return (size);
}

void search_similar_data(char *str, int pos, int similar_data[2], int len)
{
    int biggest_pos = 0;
    int biggest_len = 0;
    int result = 0;
    char *reader = str + pos;

    for (int i = 1; i < BUFFER_SIZE && i < pos; i++) {
        result = compare_to_reader(reader - i, reader, pos, len);
        if (result >= MIN_SIZE && result > biggest_len) {
            biggest_len = result;
            biggest_pos = i;
        }
    }
    similar_data[0] = biggest_pos;
    similar_data[1] = biggest_len;
}

void register_data(char *str, int similar_data[2], char data[17], int nb_add)
{
    int pos = 1;

    if (similar_data[0])
        data[0] |= (1 << (7 - nb_add));
    for (int i = 0; i < nb_add; i++) {
        if (data[0] & (1 << (7 - i)))
            pos += 2;
        else
            pos += 1;
    }
    if (similar_data[0]) {
        data[pos] = (char) (similar_data[0] & 4080);
        data[pos + 1] =
        (char) ((similar_data[0] & 15) << 4) | (similar_data[1] & 15);
    } else
        data[pos] = *str;
}

void write_data(char data[17], int nb_add)
{
    int max = 1;

    for (int i = 0; i <= nb_add; i++) {
        if (data[0] & (1 << (7 - i)))
            max += 2;
        else
            max += 1;
    }
    for (int i = 0; i < max; i++) {
        write(1, &(data[i]), 1);
    }
    for (int i = 0; i < 17; i++)
        data[i] = 0;
}

int lzss(char *str, int len)
{
    char data[17] = {0};
    int nb_add = 0;
    int similar_data[2] = {0};

    for (int pos = 0; pos < len; nb_add++) {
        search_similar_data(str, pos, similar_data, len);
        register_data(str + pos, similar_data, data, nb_add);
        pos += similar_data[1] == 0 ? 1 : similar_data[1];
        similar_data[0] = 0;
        similar_data[1] = 0;
        if (nb_add == 7) {
            write_data(data, nb_add);
            nb_add = -1;
        }
    }
    if (nb_add)
        write_data(data, nb_add);
    return (0);
}