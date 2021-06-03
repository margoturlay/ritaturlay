all : build_test run_test

build_test :
	g++ -ftest-coverage -fprofile-arcs -O0 -o test test.cpp Structures.cpp DataBase.cpp Outlook.cpp

run_test :
	./test
	gcov -abcfu Structures.cpp
	gcov -abcfu DataBase.cpp
	gcov -abcfu Outlook.cpp