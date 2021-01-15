/*
** EPITECH PROJECT, 2021
** antman
** File description:
** giantman
*/

#ifndef GIANTMAN_H_
#define GIANTMAN_H_

list_t *create_dictionnary(char *str);
void free_dictionnary(list_t *list);
void create_word(char *start_word, int word_len, list_t **list);

#endif /* !GIANTMAN_H_ */
