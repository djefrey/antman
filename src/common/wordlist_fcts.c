/*
** EPITECH PROJECT, 2021
** antman
** File description:
** wordlist fct for list
*/

#include "antman.h"
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
    int nb = (int) data;

    return (wordlist->nb > nb);
}

int filter_word(void *word_v)
{
    wordlist_t *wordlist = (wordlist_t*) word_v;

    if (wordlist->nb == 1)
        return (0);
    else if (wordlist->nb * wordlist->len < MIN_WEIGHT)
        return (0);
    else
        return (1);
}