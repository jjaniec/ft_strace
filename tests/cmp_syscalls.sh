#!/bin/bash

ret_code=0

for i in $(seq 1 5);
do
	echo "test${i}.c:"
	for bit in "64" "32";
	do
		strace -c ./tests/test${i}.c.${bit}.out <<< test |& grep total | cut -d ' ' -f 6- > total_strace
		./ft_strace -c ./tests/test${i}.c.${bit}.out <<< test |& grep total | cut -d ' ' -f 6- > total_ft_strace
		echo "${bit}: "
		echo -e "\tstrace:"
		cat total_strace
		echo -e "\tft_strace:"
		cat total_ft_strace
		diff total_strace total_ft_strace
		r=$?
		if [ ${r} -eq 0 ]; then
			echo "OK"
		else
			echo "KO"
			ret_code=1
		fi;
	done;
	echo
done;

exit $ret_code
