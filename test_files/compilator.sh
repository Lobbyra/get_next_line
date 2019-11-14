RED="\e[91m"
ERROR_EMOJI="\xE2\x9D\x8C"
CRINGE_EMOJI="\xF0\x9F\x98\x85"
PINK="\e[95m"
YELLOW="\e[93m"
WHITE="\e[97m"
if [ "$#" -ne 1 ]
then
    printf "$CRINGE_EMOJI$YELLOW[Illegal number of parameters]$CRINGE_EMOJI$WHITE"
	exit 1;
fi
rm -rf log deeptough src test tests sortie_correct test.c test.sh gnlkiller 42TESTERS-GNL
STR="--extra"
GREEN="\e[92m"
BLUE="\e[96m"
TICK_GREEN="\xE2\x9C\x85"
LIGHT_EMOJI="\xF0\x9F\x92\xA1"
HUNDRED_EMOJI="\xF0\x9F\x92\xAF"
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
	mv get_next_line ..
	cd ..
fi

