/*
** EPITECH PROJECT, 2021
** antman
** File description:
** wordlist fct for list
*/

#include "wordlist.h"

int cmp_word_weight(void *word1_v, void *word2_v)
{
    wordlist_t *word1 = (wordlist_t*) word1_v;
    wordlist_t *word2 = (wordlist_t*) word2_v;

    return (word2->nb * word2->len - word1->nb * word1->len);
}

int test_word_nb(void *word_v, void *data)
{
    wordlist_t *wordlist = (wordlist_t*) word_v;
    int nb = data;

    return (wordlist->nb > nb);
}