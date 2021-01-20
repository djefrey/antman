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
#include "giantman.h"
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

int text_file_process(char *file)
{
    list_t *list;
    char *str;
    int len;

    if (read_file(file, &str, &len))
        return (84);
    list = create_dictionnary(str);
    if (!list) {
        if (str[0] != END_DIC_CHAR) {
            free(str);
            return (84);
        } else
            write(1, str, len);
    } else {
        write_content(str, len, list);
        free_dictionnary(list);
    }
    free(str);
    return (0);
}