/*
** EPITECH PROJECT, 2021
** giantman
** File description:
** test file managment
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "my_list.h"
#include "html.h"
#include "common.h"
#include "wordlist.h"

void write_word(char id, list_t *list)
{
    wordlist_t *wordlist;

    for (int i = 0; i < id; i++, list = list->next);
    wordlist = (wordlist_t*) list->data;
    write(1, wordlist->word, wordlist->len);
}

void write_content(char *str, int len, list_t *list)
{
    int i = 1;

    for (str += 1; *(str - 1) != END_DIC_CHAR; str += 1, i++);
    for (; i < len; str += 1, i++) {
        if (*str == CALL_DIC_CHAR) {
            write_word(*(str + 1), list);
            str += 1;
            i++;
            continue;
        } else
            write(1, str, 1);
    }
}

int html(char *str, int len)
{
    list_t *list = create_dictionnary(str);

    if (!list) {
        if (str[0] != END_DIC_CHAR)
            return (84);
        else
            write(1, str, len);
    } else {
        write_content(str, len, list);
        free_dictionnary(list);
    }
    return (0);
}