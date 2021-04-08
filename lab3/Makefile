all: clean main valgrind_check linter_check
buildMain: main.c
	gcc -o main main.c -std=c89 -lm

valgrind_check:
	echo "3" > input.txt
	valgrind ./tests < input.txt
	
linter_check:
	cpp main.c

.PHONY: clean
clean:
	rm -rf lab3/
