/*
** EPITECH PROJECT, 2021
** antman
** File description:
** file managment
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int read_file(char *path, char **str, int *len)
{
    int fd = open(path, O_RDONLY);
    struct stat statbuf;

    if (fd == -1)
        return (1);
    stat(path, &statbuf);
    *len = statbuf.st_size;
    *str = malloc(sizeof(char) * (*len + 1));
    if (!str) {
        close(fd);
        return (1);
    }
    read(fd, *str, *len);
    close(fd);
    return (0);
}