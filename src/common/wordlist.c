/*
** EPITECH PROJECT, 2021
** antman
** File description:
** wordlist
*/

#include <stdlib.h>
#include "my.h"
#include "wordlist.h"

static int wordeq(char *word, char *reg_word)
{
    for (; *word && *reg_word; word += 1, reg_word += 1) {
        if (*word != *reg_word)
            return (0);
    }
    return (*word == *reg_word);
}

void register_word(char *str, int size, list_t **list)
{
    wordlist_t *wordlist;
    char word[size + 1];

    if (size < 3)
        return;
    my_strncpy(word, str, size);
    for (list_t *sel_list = *list; sel_list; sel_list = sel_list->next) {
        wordlist = (wordlist_t*) sel_list->data;
        if (wordeq(word, wordlist->word)) {
            wordlist->nb += 1;
            return;
        }
    }
    create_wordlist(list, my_strdup(word), size);
}

void destroy_wordlist(list_t *list)
{
    list_t *tmp;
    wordlist_t *wordlist;

    for (; list; list = tmp) {
        tmp = list->next;
        wordlist = (wordlist_t*) list->data;
        free(wordlist->word);
        free(wordlist);
        free(list);
    }
}

wordlist_t *create_wordlist(list_t **list, char *word, int len)
{
    wordlist_t *wordlist = malloc(sizeof(wordlist_t));

    if (!wordlist)
        return (NULL);
    wordlist->word = word;
    wordlist->len = len;
    wordlist->nb = 1;
    create_list(list, wordlist);
    return (wordlist);
}