#!/bin/bash

AVRG=0
MAX=0
ITERATIONS=500

make

for i in $(seq 1 $ITERATIONS);
do
	COUNT=$(make rdebug | wc -l)
	AVRG=$((AVRG + COUNT - 1))
	if [ $[COUNT-1] -gt $MAX ]; then
		MAX=$[COUNT-1]
		echo -e "push_swap score: \e[31m$[COUNT-1] (new max)\e[0m"
	else
		echo -e "push_swap score: \e[32m$[COUNT-1]\e[0m"
	fi
done

echo -e "\e[31mmax: $MAX"

# printing average
AVRG=$(echo "scale=1; $AVRG/$ITERATIONS" | bc)
echo -e "\e[32maverage: $AVRG"

make clog