#Content management testing#
#!/bin/#!/bin/sh

set -v

rm -f ./user_output/*.log
rm -f ./user_output/*.log
rm -f ./expected_output/*.log
rm -f ./expected_output/*.log

fun_test_engine()
{
	local i=1

	for i in `seq 1 8`
	do
		local exp_out=$(echo "user_output/_S_"$1"_"$i"_user.log")
		local usr_out=$(echo "expected_output/_S_"$1"_"$i"_user.log")
		./get_next_line "test_files/"$i* > $usr_out
		./expected_output/get_next_line_teacher "test_files/"$i* > $exp_out
		diff $exp_out $usr_out >> deeptough
	done
}

fun_main ()
{
	buf_lengths=(0 1 2 10 52 100 1000 1000000)

	for temp in "${buf_lengths[@]}"
	do
		make re "S="$temp
		make "test_s_"$temp 'S='$temp
		fun_test_engine $temp
	done
}

fun_main
