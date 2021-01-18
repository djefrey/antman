/*
** EPITECH PROJECT, 2021
** antman
** File description:
** text file process
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "antman.h"
#include "common.h"
#include "wordlist.h"

void write_word(char *str, int word_len, list_t *list)
{
    wordlist_t *wordlist;
    char word[word_len + 1];
    char call[2];

    call[0] = CALL_DIC_CHAR;
    my_strncpy(word, str, word_len);
    for (int i = 0; list; i++, list = list->next) {
        wordlist = (wordlist_t*) list->data;
        if (wordeq(word, wordlist->word)) {
            call[1] = (char) i;
            write(1, call, 2);
            return;
        }
    }
    write(1, word, word_len);
}

void write_content(char *str, int str_len, list_t *list)
{
    char *start = str;
    int word_len = 0;

    for (int i = 0; i < str_len; i++, str += 1) {
        if (*str == ' ' || *str == '\t' || *str == '\n' ||
        *str == '.' || *str == ',' || *str == ':' || *str == ';') {
            if (word_len > 0)
                write_word(start, word_len, list);
            write(1, str, 1);
            start = str + 1;
            word_len = 0;
        } else
            word_len += 1;
    }
    if (word_len > 0)
        write_word(start, word_len, list);
}

int text_file_process(char *file)
{
    list_t *list;
    char *str;
    int len;

    if (read_file(file, &str, &len))
        return (84);
    list = list_words(str, len);
    if (!list) {
        free(str);
        return (84);
    }
    clear_list(&list);
    write_dictionnary(list);
    write_content(str, len, list);
    destroy_wordlist(list);
    free(str);
    return (0);
}