#!/bin/bash

ret_code=0

for i in $(seq 1 5);
do
	echo -n -e "test${i}.c:"
	for bit in "64" "32";
	do
		strace > /dev/null 2>&1 ./tests/test${i}.c.${bit}.out <<< test
		r=$?
		./ft_strace > /dev/null 2>&1 ./tests/test${i}.c.${bit}.out <<< test
		r2=$?
		echo -n -e " ${bit}: "
		if [ $r -eq $r2 ];
		then
			echo -n -e "OK";
		else
			echo -n -e "KO (${r} != ${r2})";
			ret_code=1
		fi;
	done;
	echo
done;

exit $ret_code
