#!/bin/bash

AVRG=0
MAX=0

make

for i in $(seq 1 50);
do
	COUNT=$(make rdebug | wc -l)
	if [ $[COUNT-1] -gt $MAX ]; then
		MAX=$[COUNT-1]
		echo -e "push_swap score: \e[31m$[COUNT-1]\e[0m"
	else
		echo -e "push_swap score: \e[32m$[COUNT-1]\e[0m"
	fi
done

echo -e "\e[31mmax: $MAX"

make clog