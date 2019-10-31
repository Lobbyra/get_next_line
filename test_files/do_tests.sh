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
