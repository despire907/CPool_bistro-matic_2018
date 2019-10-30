##
## EPITECH PROJECT, 2018
## rush2
## File description:
## makefile
##

EXEC_NAME = calc

TEST_EXEC_NAME = cr_test

MAIN =		main.c

MAINt =		main2.c

SRCS =		expr_check.c \
			param.c \
			error.c

TEST_SRCS =	

LIB =		-L./lib/my -lmy

OBJS = $(SRCS:.c=.o)

C_FLAGS = -fno-builtin -W -Wall

all	:
		make $(EXEC_NAME)

$(EXEC_NAME):	$(OBJS)
		gcc $(C_FLAGS) -o $(EXEC_NAME) $(MAIN) $(OBJS) $(LIB)

test_run:
		gcc -o $(TEST_EXEC_NAME) $(SRCS) $(TEST_SRCS) $(LIB) --coverage -lcriterion

clean:
		rm -f $(OBJS) $(MAIN:.c=.o)

fclean:		clean
		rm -f $(EXEC_NAME)

cclean:		fclean
		rm -f *.gcda *.gcno

re:		fclean all

test_re:	cclean test_run
