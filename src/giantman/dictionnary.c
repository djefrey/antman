/*
** EPITECH PROJECT, 2021
** giantman
** File description:
** dictionnary
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "my_list.h"
#include "common.h"
#include "wordlist.h"

void create_word(char *start_word, int word_len, list_t **list)
{
    wordlist_t *wordlist = malloc(sizeof(wordlist_t));
    char *word = malloc(sizeof(char) * (word_len + 1));

    my_strncpy(word, start_word, word_len);
    wordlist->word = word;
    wordlist->len = word_len;
    wordlist->nb = 0;
    create_list(list, wordlist);
}

void free_dictionnary(list_t *list)
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

list_t *create_dictionnary(char *str)
{
    list_t *list = NULL;
    char *start_word = str;
    int word_len = 0;

    for (; *str; str += 1) {
        if (*str == END_DIC_CHAR)
            break;
        else if (*str == DIC_SEPARATOR_CHAR) {
            create_word(start_word, word_len, &list);
            start_word = str + 1;
            word_len = 0;
        } else
            word_len += 1;
    }
    create_word(start_word, word_len, &list);
    my_rev_list(&list);
    return (list);
}