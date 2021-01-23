/*
** EPITECH PROJECT, 2021
** antman
** File description:
** file managment
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int read_file(char *path, char **str, int *len)
{
    int fd = open(path, O_RDONLY);
    struct stat statbuf;
    char *tmp;

    if (fd == -1 || stat(path, &statbuf) == 1)
        return (1);
    *len = statbuf.st_size;
    tmp = malloc(sizeof(char) * (*len + 1));
    *str = tmp;
    if (!str) {
        close(fd);
        return (1);
    }
    if (read(fd, *str, *len) == -1) {
        close(fd);
        free(tmp);
        return (84);
    }
    close(fd);
    return (0);
}