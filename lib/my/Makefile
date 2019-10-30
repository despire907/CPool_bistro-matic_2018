##
## EPITECH PROJECT, 2018
## makefile libmy
## File description:
## task1
##


LIB_NAME = 	my

LIB =		"lib$(LIB_NAME).a"

HEADER =	"$(LIB_NAME).h"

SRCS =		my_putchar.c \
		my_isneg.c \
		my_put_nbr.c \
		my_swap.c \
		my_putstr.c \
		my_strlen.c \
		my_strncpy.c \
		my_strncat.c \
		my_realloc_str.c \
		my_getnbr.c

OBJS =		$(SRCS:.c=.o)

all:		$(LIB)

$(LIB):
		gcc -c $(SRCS)
		ar rc $(LIB) $(OBJS)
		cp -f $(HEADER) ../../include/

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(LIB_NAME)

re:		clean all

parle:
		echo "lib$(LIB_NAME)"
