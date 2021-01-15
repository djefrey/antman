/*
** EPITECH PROJECT, 2021
** giantman
** File description:
** main
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

int main(int ac, char *av[])
{
    list_t *list;
    char *str;
    int len;

    if (ac >= 2) {
        if (read_file(av[1], &str, &len))
            return (84);
        list = create_dictionnary(str);
        write_content(str, len, list);
        free_dictionnary(list);
        free(str);
    }
    return (0);
}