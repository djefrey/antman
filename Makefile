##
## EPITECH PROJECT, 2021
## antman
## File description:
## makefile
##


SRC_ANT		=	src/antman/main.c			\
				src/antman/dictionnary.c
SRC_GIANT	=	src/giantman/main.c
SRC_COMMON	=	src/common/files.c			\
				src/common/wordlist.c		\
				src/common/wordlist_fcts.c

OBJ_ANT		=	$(SRC_ANT:.c=.o)
OBJ_GIANT	=	$(SRC_GIANT:.c=.o)
OBJ_COMMON	=	$(SRC_COMMON:.c=.o)

LIB_DIR		=	./mylib
INC_DIR		=	./include

CFLAGS		+=	-W -Wall -I$(INC_DIR)

NAME_ANT	=	antman
NAME_GIANT	=	giantman

all: $(NAME_ANT) $(NAME_GIANT)

lib:
	make -C $(LIB_DIR)

$(NAME_ANT): lib $(OBJ_ANT) $(OBJ_COMMON)
	gcc -o $(NAME_ANT) $(OBJ_ANT) $(OBJ_COMMON) -I$(INC_DIR) -L$(LIB_DIR) -lmy

$(NAME_GIANT): lib $(OBJ_GIANT) $(OBJ_COMMON)
	gcc -o $(NAME_GIANT) $(OBJ_GIANT) $(OBJ_COMMON) -I$(INC_DIR) -L$(LIB_DIR) -lmy

debug:	CFLAGS	+= -g
debug: lib $(OBJ_ANT) $(OBJ_GIANT) $(OBJ_COMMON)
	gcc -g -o $(NAME_ANT) $(OBJ_ANT) $(OBJ_COMMON) -I$(INC_DIR) -L$(LIB_DIR) -lmy
	gcc -g -o $(NAME_GIANT) $(OBJ_GIANT) $(OBJ_COMMON) -I$(INC_DIR) -L$(LIB_DIR) -lmy

clean:
	make -C $(LIB_DIR) clean
	rm -rf $(OBJ_ANT)
	rm -rf $(OBJ_GIANT)
	rm -rf $(OBJ_COMMON)

fclean: clean
	make -C $(LIB_DIR) fclean
	rm -f $(NAME_ANT)
	rm -f $(NAME_GIANT)

re: fclean all