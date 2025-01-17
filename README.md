push swap project of 42

> Because Swap_push isn’t as natural

## Summary
given a stack of random value with no duplicate, sort these value using a temporary stack
with restricted operation.

this repo use the Turk algorithm (https://medium.com/@ayogun/push-swap-c1f5d2d41e97)

## Allowed operations
- `swap stack` Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
- `push stack` Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
- `rotate stack` Shift up all elements of stack b by 1.
The first element becomes the last one.

## Compile it yourself
first clone the repo
```
git clone https://github.com/Maxime-juncker/push_swap.git
cd push_swap
```
then build it using make
```
make
```

## How to run
after building it

go to the bin directory
```
cd bin/
```

run push swap
```
./push_swap ‹random values›
```

or run a benchmark
```
bash benshmark.sh
```
the benchmark will test push swap 500 time with random value, then output the average and maximum number of operations push swap took
