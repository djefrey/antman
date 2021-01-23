##
## EPITECH PROJECT, 2021
## antman
## File description:
## makefile
##


SRC_ANT		=	main.c			\
				lzss.c
SRC_COMMON	=	../common/files.c

OBJ_ANT		=	$(SRC_ANT:.c=.o)
OBJ_COMMON	=	$(SRC_COMMON:.c=.o)

LIB_DIR		=	../mylib
INC_DIR		=	../include

CFLAGS		+=	-W -Wall -I$(INC_DIR)

NAME_ANT	=	antman

all: $(NAME_ANT)

lib:
	make -C $(LIB_DIR)

$(NAME_ANT): lib $(OBJ_ANT) $(OBJ_COMMON)
	gcc -o $(NAME_ANT) $(OBJ_ANT) $(OBJ_COMMON) -I$(INC_DIR) -L$(LIB_DIR) -lmy

debug:	CFLAGS	+= -g
debug: lib $(OBJ_ANT) $(OBJ_COMMON)
	gcc -g -o $(NAME_ANT) $(OBJ_ANT) $(OBJ_COMMON) -I$(INC_DIR) -L$(LIB_DIR) -lmy

clean:
	make -C $(LIB_DIR) clean
	rm -rf $(OBJ_ANT)
	rm -rf $(OBJ_COMMON)

fclean: clean
	make -C $(LIB_DIR) fclean
	rm -f $(NAME_ANT)

re: fclean all