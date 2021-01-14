/*
** EPITECH PROJECT, 2021
** antman
** File description:
** main
*/

#include <stdlib.h>
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
    return (list);
}

int main(int ac, char *av[])
{
    wordlist_t *wordlist;
    list_t *list;
    char *str;
    int len;

    if (ac >= 2) {
        if (read_file(av[1], &str, &len))
            return (84);
        list = list_words(str, len);
        my_sort_list(&list, &cmp_word_nb);
        for (list_t *cpy = list; cpy; cpy = cpy->next) {
            wordlist = (wordlist_t*) cpy->data;
            printf("%s => %i\n", wordlist->word, wordlist->nb);
        }
        destroy_wordlist(list);
        free(str);
    }
    return (0);
}