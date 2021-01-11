/*
** EPITECH PROJECT, 2021
** antman
** File description:
** main
*/

void write_6_bits(int fd, char c, char *buf, int *offset)
{
    if (*offset == 0) {
        *buf = c << 2;
        *offset = 6;
    } else if (*offset == 2) {
        *buf = *buf | c;
        write(fd, buf, 1);
        *buf = 0;
        *offset = 0;
    } else {
        *buf = *buf | (c >> *offset);
        write(fd, buf, 1);
        *buf = c << (8 - *offset);
        *offset = 8 - *offset;
    }
}

void convert_8_to_6(char c, char *mode, char *buf, char *offset)
{
    char c_6b;

    if (c >= 'A') {
        if (*mode == 0) {
            write_6_bits(1, 63, buf, offset);
            *mode = 1;
        }
        c_6b = c - 'A';
    } else {
        if (*mode == 1) {
            write_6_bits(1, 63, buf, offset);
            *mode = 0;
        }
        if (c == 0)
            c_6b = 0;
        else if (c <= '\n')
            c_6b = c - '\t' + 1;
        else
            c_6b = c - ' ' + 3;
    }
    write_6_bits(1, c_6b, buf, offset);
}

int main(int ac, char *av[])
{
    char mode = 0;
    char buf = 0;
    int offset = 0;

    for (char *str = av[1]; *str; str += 1)
        convert_8_to_6(*str, &mode, &buf, &offset);
    if (buf != 0)
        write(1, &buf, 1);
    write(1, "\n", 1);
}