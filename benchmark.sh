#!/bin/bash

AVRG=0
MAX=0
ITERATIONS=500

make

for i in $(seq 1 $ITERATIONS);
do
	COUNT=$(ARG="$(python3 rand_numbers.py)"; ./bin/push_swap "$ARG" | wc -l)
	AVRG=$((AVRG + COUNT))
	if [ $[COUNT] -gt $MAX ]; then
		MAX=$[COUNT]
		echo -e "push_swap score: \e[31m$[COUNT] (new max)\e[0m"
	else
		echo -e "push_swap score: \e[32m$[COUNT]\e[0m"
	fi
done

echo -e "\e[31mmax: $MAX"

# printing average
AVRG=$(echo "scale=1; $AVRG/$ITERATIONS" | bc)
echo -e "\e[32maverage: $AVRG"

make clog
