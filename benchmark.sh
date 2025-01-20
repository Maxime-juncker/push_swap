#!/bin/bash

AVRG=0
MAX=0
ITERATIONS=100

make

printf "\033[0m\e[?25l\n---------------------------------\n"
printf "push_swap benchmark starting for $ITERATIONS rounds\n\n"


for i in $(seq 1 $ITERATIONS);
do
	COUNT=$(ARG="$(python3 rand_numbers.py)"; ./bin/push_swap "$ARG" | wc -l)
	AVRG=$((AVRG + COUNT))
	if [ $[COUNT] -gt $MAX ]; then
		MAX=$[COUNT]
		printf "push_swap score: \e[31m$[COUNT] (new max)\e[0m\n"
	else
		printf "push_swap score: \e[32m$[COUNT] [i: $i]\e[0m\r"
	fi
done

printf "\n\n\033[33m---------------------------------\n"
printf "results:\n"
printf "\nmax: \e[34m$MAX\n"

# printing average
AVRG=$(echo "scale=1; $AVRG/$ITERATIONS" | bc)
printf "\033[33maverage: \033[34m$AVRG\n"

printf "\033[33m---------------------------------\n\e[?25h\n"

make clog
