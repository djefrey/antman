/*
** EPITECH PROJECT, 2021
** antman
** File description:
** dictionnary
*/

#include <stdlib.h>
#include <unistd.h>
#include "common.h"
#include "wordlist.h"

list_t *list_words(char *str, int str_len)
{
    list_t *list = NULL;
    char *start = str;
    int word_len = 0;

    for (int i = 0; i < str_len; i++, str += 1) {
        if (*str == ' ' || *str == '\t' || *str == '\n' ||
        *str == '.' || *str == ',' || *str == ':' || *str == ';') {
            if (word_len > 0)
                register_word(start, word_len, &list);
            word_len = 0;
            start = str + 1;
        } else
            word_len += 1;
    }
    if (word_len > 0)
        register_word(start, word_len, &list);
    my_sort_list(&list, &cmp_word_weight);
    return (list);
}

void clear_list(list_t **list)
{
    list_t *cpy = *list;
    list_t *tmp;

    my_delete_nodes(list, NULL, &filter_word, &destroy_single_wordlist);
    if (my_list_size(cpy) > 127) {
        for (int i = 0; i <= 127; i++, cpy = cpy->next);
        tmp = cpy->next;
        destroy_wordlist(tmp);
        cpy->next = NULL;
    }
}

void write_dictionnary(list_t *list)
{
    wordlist_t *wordlist;
    char sep;

    for (; list; list = list->next) {
        wordlist = (wordlist_t*) list->data;
        write(1, wordlist->word, wordlist->len);
        sep = list->next ? DIC_SEPARATOR_CHAR : END_DIC_CHAR;
        write(1, &sep, 1);
    }
}