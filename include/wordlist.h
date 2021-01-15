/*
** EPITECH PROJECT, 2021
** countwords
** File description:
** main header
*/

#include "my_list.h"

typedef struct wordlist {
    char *word;
    int len;
    int nb;
} wordlist_t;

wordlist_t *create_wordlist(list_t **list, char *word, int len);
void destroy_wordlist(list_t *list);
void destroy_single_wordlist(wordlist_t *wordlist);

void register_word(char *str, int size, list_t **list);

int wordeq(char *word, char *reg_word);

int cmp_word_weight(void *word1, void *word2);
int test_word_nb(void *word_v, void *data);
int filter_word(void *word_v);