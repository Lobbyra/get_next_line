rm -rf log src test tests sortie_correct test.c test.sh gnlkiller 42TESTERS-GNL
STR="--extra"
if [[ "$1" == "$STR" ]];
then
	git clone https://github.com/Mazoise/42TESTERS-GNL.git
	cd 42TESTERS-GNL
	bash all_tests_with_bonus.sh
	bash runSTDIN+LEAKS.sh
	cd ..
	git clone https://github.com/Sherchryst/gnlkiller.git
	mv gnlkiller/* .
	sh test.sh > log
	diff log sortie_correct
	rm -rf src test tests sortie_correct test.c test.sh gnlkiller 42TESTERS
else
	echo "If you want extra tests type ./compilator --extra."
	gcc -W -Wall -Wextra -Werror -o get_next_line -D BUFFER_SIZE=$1 main.c get_next_line.c get_next_line_utils.c
	gcc -W -Wall -Wextra -Werror -o get_next_line_bonus -D BUFFER_SIZE=$1 main.c get_next_line_bonus.c get_next_line_utils_bonus.c
fi

