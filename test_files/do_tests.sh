i=1
while ((i < 10))
do
	echo "[Test with $(echo ./test_files/$i*)]"
	./get_next_line $(echo ./test_files/$i*)
	printf "\n"
	read -p "Press enter to the next test"
	printf "\n"
	let i++
done
a=1
while ((a < 10))
do
	echo "[Test with $(echo ./test_files/$a*)]"
	./get_next_line_bonus $(echo ./test_files/$a*)
	printf "\n"
	read -p "Press enter to the next test"
	printf "\n"
	let a++
done
