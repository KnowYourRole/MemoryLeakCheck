#include <iostream>
#include <vector>
#include <string>
#include "Defines.h"

ErrorCode executeCommand(const std::string &  command,
	std::vector<int *> & memory);

void printResult(const ErrorCode     errorCode,
	const std::string & command);

int main()
{
	std::string        command;
	int                memorySize = 0;
	int 			   inputSize = 0;	//number of getlines to be added
	std::vector<int *> memory;

	std::cin >> memorySize >> inputSize;
	std::cin.ignore();

	memory.resize(memorySize, nullptr);

	for (int i = 0; i < inputSize; ++i)
	{
		getline(std::cin, command);

		const ErrorCode errorCode = executeCommand(command, memory);

		printResult(errorCode, command);
	}

	return 0;
}


/*
5 2
Allocate 3
Deallocate 3

2 4
Deallocate 21
Allocate 1
Idle
Allocate 1

*/