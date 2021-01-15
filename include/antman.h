/*
** EPITECH PROJECT, 2021
** antman
** File description:
** main header
*/

#ifndef ANTMAN_H_
#define ANTMAN_H_

#define MIN_WEIGHT 5

#include "my_list.h"

list_t *list_words(char *str, int str_len);
void clear_list(list_t **list);
void write_dictionnary(list_t *list);

#endif /* !ANTMAN_H_ */
