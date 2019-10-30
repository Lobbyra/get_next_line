if (($1 == "normal"))
then
	gcc -W -Wall -Wextra -Werror -o get_next_line -D BUFFER_SIZE=$2 main.c get_next_line.c get_next_line_utils.c
fi

if (($1 == "bonus"))
then
	gcc -W -Wall -Wextra -Werror -o get_next_line -D BUFFER_SIZE=$2 main.c get_next_line.c get_next_line_utils.c
fi

if (($1 == "all"))
then
	gcc -W -Wall -Wextra -Werror -o get_next_line -D BUFFER_SIZE=$2 main.c get_next_line.c get_next_line_utils.c
	gcc -W -Wall -Wextra -Werror -o get_next_line_bonus -D BUFFER_SIZE=$2 main.c get_next_line_bonus.c get_next_line_utils_bonus.c
fi

