useful: buildTest test valgrind_check linter_check
buildMain: main.c
	gcc -o main main.c -std=c89 -lm

buildTest: tests.c
	gcc -o tests -Dmain=_main main.c tests.c -std=c89 -pedantic -lm

test:
	./tests
	
valgrind_check:
	echo "0.2" > input.txt
	valgrind ./tests < input.txt
	
linter_check:
	cpp main.c

.PHONY: clean
clean:
	rm -rf task2/
