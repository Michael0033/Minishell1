##
## Makefile for Makefile in /home/besnai_m/rendu/C-Prog ELEM/CPE_2014_bsq
## 
## Made by michael besnainou
## Login   <besnai_m@epitech.net>
## 
## Started on  Mon Jan 12 14:01:57 2015 michael besnainou
## Last update Sun Feb  1 23:34:19 2015 michael besnainou
##

SRC	= mysh.c \
	biggest_functions.c \
	small_functions.c 

SRCS	= lib/my/my_putchar.c \
	lib/my/my_strlen.c \
	lib/my/my_putstr.c \
	lib/my/my_put_nbr.c \
	lib/my/get_next_line.c \
	lib/my/my_strncmp.c \
	lib/my/my_str_to_wordtab.c \
	lib/my/my_strcatdup.c \
	lib/my/my_putstr_error.c 

OBJ	= $(SRC:.c=.o)

OBJS	= $(SRCS:.c=.o)

CC	= gcc

RM	= rm -rf

LIB	= libmy.a

FILE	= mysh

CFLAGS	= -Wall -Werror -Wextra -pedantic

all: $(LIB) $(FILE)

$(LIB): $(OBJS)
	ar rc $(LIB) $(OBJS)
	ranlib $(LIB)

$(FILE): $(LIB) $(OBJ)
	$(CC) -o $(FILE) $(OBJ) $(LIB)

clean: 
	$(RM) $(OBJ)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(LIB)
	$(RM) $(FILE)

re: fclean all

.PHONY: all clean fclean re
