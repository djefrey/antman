/*
** EPITECH PROJECT, 2021
** antman
** File description:
** html
*/

#ifndef HTML_H_
#define HTML_H_

#define MIN_WEIGHT 5

#include "my_list.h"

/*
** ANTMAN
*/

list_t *list_words(char *str, int str_len);
void clear_list(list_t **list);
void write_dictionnary(list_t *list);

/*
** GIANTMAN
*/

list_t *create_dictionnary(char *str);
void free_dictionnary(list_t *list);
void create_word(char *start_word, int word_len, list_t **list);

#endif /* !HTML_H_ */
