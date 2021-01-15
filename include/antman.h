/*
** EPITECH PROJECT, 2021
** antman
** File description:
** main header
*/

#ifndef ANTMAN_H_
#define ANTMAN_H_

#define END_DIC_CHAR "\1"
#define DIC_SEPARATOR_CHAR "\2"
#define CALL_DIC_CHAR '\3'

#define MIN_WEIGHT 5

#include "my_list.h"

list_t *list_words(char *str, int str_len);
void clear_list(list_t **list);
void write_dictionnary(list_t *list);

int read_file(char *path, char **str, int *len);

#endif /* !ANTMAN_H_ */
