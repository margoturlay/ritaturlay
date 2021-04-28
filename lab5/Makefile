useful: buildTest test valgrind_check linter_check
buildMain: main.cpp
	gcc -o main main.cpp 

buildTest: tests.cpp
	gcc -o tests -Dmain=_main main.cpp tests.cpp
test:
	./tests
	
valgrind_check:
	echo "20" > input.txt
	valgrind ./tests < input.txt
	
linter_check:
	cpp main.cpp

.PHONY: clean
clean:
	rm -rf lab5/
