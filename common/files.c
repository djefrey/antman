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

static int get_file_size(int fd, char *path, struct stat *statbuf)
{
    if (stat(path, statbuf) == 1) {
        close(fd);
        return (-1);
    }
    return (statbuf->st_size);
}

int read_file(char *path, char **str, int *len)
{
    int fd = open(path, O_RDONLY);
    struct stat statbuf;
    char *tmp;

    if (fd == -1 || (*len = get_file_size(fd, path, &statbuf)) == -1)
        return (1);
    tmp = malloc(sizeof(char) * (*len + 1));
    *str = tmp;
    if (!str) {
        close(fd);
        return (1);
    }
    if (read(fd, *str, *len) == -1) {
        close(fd);
        free(tmp);
        return (1);
    }
    close(fd);
    return (0);
}