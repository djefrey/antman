##
## EPITECH PROJECT, 2021
## antman
## File description:
## makefile
##

all:
	make -C antman
	make -C giantman

clean:
	make -C antman clean
	make -C giantman clean

fclean: clean
	make -C antman fclean
	make -C giantman fclean

re: fclean all