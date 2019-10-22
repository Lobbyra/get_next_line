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

.PHONY		:	read
