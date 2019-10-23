NAME		=	get_next_line

SRCS		=	get_next_line.c			\
				get_next_line_utils.c	\
				main.c					\

_SRCS		=	$(addprefix ./src/, $(SRCS))

OBJS		=	$(_SRCS:.c=.o)

CC			=	cc

CFLAGS		+=	-W -Wall -Wextra -Werror  -D BUFFER_SIZE=$(S)

RM			=	rm -f

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				$(CC) -o $(NAME) $(OBJS)



clean		:
				$(RM) $(OBJS)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all

test_s_0	: 	clean $(OBJS)
				gcc -o ./expected_output/get_next_line_teacher -W -Wall -Wextra -Werror $(OBJS)

test_s_1	:	clean $(OBJS)
				gcc -o ./expected_output/get_next_line_teacher -W -Wall -Wextra -Werror $(OBJS)

test_s_2	:	clean $(OBJS)
				gcc -o ./expected_output/get_next_line_teacher -W -Wall -Wextra -Werror $(OBJS)

test_s_10	:	clean $(OBJS)
				gcc -o ./expected_output/get_next_line_teacher -W -Wall -Wextra -Werror $(OBJS)

test_s_52	:	clean $(OBJS)
				gcc -o ./expected_output/get_next_line_teacher -W -Wall -Wextra -Werror $(OBJS)

test_s_100	:	clean $(OBJS)
				gcc -o ./expected_output/get_next_line_teacher -W -Wall -Wextra -Werror $(OBJS)

test_s_1000	:	clean $(OBJS)
				gcc -o ./expected_output/get_next_line_teacher -W -Wall -Wextra -Werror $(OBJS)

test_s_1000000	: clean $(OBJS)
				gcc -o ./expected_output/get_next_line_teacher -W -Wall -Wextra -Werror $(OBJS)
