#include "Interface.h"
#include <iomanip>

int main()
{
	setlocale(LC_ALL, "ru");
	std::string inputFileName = "input.txt";
	std::string outputFileName = "output.txt";
	Init(inputFileName, outputFileName);
}