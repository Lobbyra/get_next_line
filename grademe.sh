#Content management testing#

fun_test_engine()
{
	local i=1

	for i in `seq 1 8`
	do
		local exp_out=$(echo "user_output/_S_"$1"_"$i"_user.log")
		local usr_out=$(echo "expected_output/_S_"$1"_"$i"_expected.log")
		if (($i != 2 && $1 >= 10))
		then
			./get_next_line "test_files/"$i* > $usr_out
			./expected_output/get_next_line_teacher "test_files/"$i* > $exp_out
			local ret=$(diff $exp_out $usr_out)
			local count=$(echo $ret | wc -c | tr -d " \n")
			if [ $count != "1" ]
			then
				echo $(echo "There is a diff with "$exp_out" and "$usr_out"\n) " >> deeptough)
				echo -n $ret >> deeptough
			fi
		fi
	done
}

fun_check_dirs ()
{
	if [ ! -d "./user_output" ]
	then
		mkdir ./user_output
	fi
	if [ ! -d "./expected_output" ]
	then
		mkdir ./expected_output
	fi
}

fun_cleaning ()
{
	rm -f ./user_output/*.log
	rm -f ./expected_output/*.log
	rm -f ./deeptough
}

fun_fclean ()
{
	rm -f ./deeptough
	rm -rf ./user_output
	rm -rf ./expected_output
}

fun_main ()
{
	buf_lengths=(0 1 2 10 52 100 1000 1000000)

	fun_check_dirs
	fun_cleaning
	fun_welcome_message
	for temp in "${buf_lengths[@]}"
	do
		make re "S="$temp
		make grademe 'S='$temp
		fun_test_engine $temp
	done
	fun_end_message
}

fun_main
