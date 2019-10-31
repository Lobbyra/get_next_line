rm -rf log deeptough src test tests sortie_correct test.c test.sh gnlkiller 42TESTERS-GNL
STR="--extra"
RED="\e[91m"
GREEN="\e[92m"
PINK="\e[95m"
BLUE="\e[96m"
TICK_GREEN="\xE2\x9C\x85"
ERROR_EMOJI="\xE2\x9D\x8C"
LIGHT_EMOJI="\xF0\x9F\x92\xA1"
HUNDRED_EMOJI="\xF0\x9F\x92\xAF"
WHITE="\e[97m"
if [[ "$1" == "$STR" ]]
then
	if [ -a get_next_line.c ]
	then
		cd .
	else
		cd ..
	fi
	git clone https://github.com/Mazoise/42TESTERS-GNL.git
	cd 42TESTERS-GNL
	bash all_tests_with_bonus.sh
	bash runSTDIN+LEAKS.sh
	cd ..
	git clone https://github.com/Sherchryst/gnlkiller.git
	mv gnlkiller/* .
	sh test.sh > log
	diff log sortie_correct > deeptough
	rm -rf src log test tests sortie_correct test.c test.sh gnlkiller 42TESTERS-GNL
else
	printf "$BLUE$LIGHT_EMOJI[If you want extra tests type ./compilator --extra.]$LIGHT_EMOJI$WHITE\n"
	cd test_files/
	gcc -W -Wall -Wextra -Werror -o get_next_line -D BUFFER_SIZE=$1 main.c ../get_next_line.c ../get_next_line_utils.c
	if [ "$?" = "0" ]
	then
		printf "$TICK_GREEN$GREEN[Compilation done]$TICK_GREEN\n$WHITE"
	else
		printf "$ERROR_EMOJI$RED[Compilation error]$ERROR_EMOJI\n$WHITE"
	fi
	if [ -a ../get_next_line_bonus.c ]
	then
		gcc -W -Wall -Wextra -Werror -o get_next_line_bonus -D BUFFER_SIZE=$1 main.c ../get_next_line_bonus.c ../get_next_line_utils_bonus.c
		if [ "$?" = "0" ]
		then
			printf "$TICK_GREEN$GREEN[Compilation done]$TICK_GREEN\n$WHITE"
		else
			printf "$ERROR_EMOJI$RED[Compilation bonus error]$ERROR_EMOJI\n$WHITE"
		fi
	else
		printf "$HUNDRED_EMOJI$PINK[Bonus not found]$WHITE$HUNDRED_EMOJI"
	fi
		
	mv get_next_line ..
	mv get_next_line_bonus ..
	cd ..
fi

