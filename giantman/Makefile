##
## EPITECH PROJECT, 2021
## antman
## File description:
## makefile
##


SRC_GIANT	=	main.c			\
				lzss.c
SRC_COMMON	=	../common/files.c			\
				../common/wordlist.c		\
				../common/wordlist_fcts.c

OBJ_GIANT	=	$(SRC_GIANT:.c=.o)
OBJ_COMMON	=	$(SRC_COMMON:.c=.o)

LIB_DIR		=	../mylib
INC_DIR		=	../include

CFLAGS		+=	-W -Wall -I$(INC_DIR)

NAME_GIANT	=	giantman

all: $(NAME_GIANT)

lib:
	make -C $(LIB_DIR)

$(NAME_GIANT): lib $(OBJ_GIANT) $(OBJ_COMMON)
	gcc -o $(NAME_GIANT) $(OBJ_GIANT) $(OBJ_COMMON) -I$(INC_DIR) -L$(LIB_DIR) -lmy

debug:	CFLAGS	+= -g
debug: lib $(OBJ_GIANT) $(OBJ_COMMON)
	gcc -g -o $(NAME_GIANT) $(OBJ_GIANT) $(OBJ_COMMON) -I$(INC_DIR) -L$(LIB_DIR) -lmy

clean:
	make -C $(LIB_DIR) clean
	rm -rf $(OBJ_GIANT)
	rm -rf $(OBJ_COMMON)

fclean: clean
	make -C $(LIB_DIR) fclean
	rm -f $(NAME_GIANT)

re: fclean all