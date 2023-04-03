#include "Defines.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

static int Alloc = 20;

ErrorCode executeCommand(const std::string &  command,
	std::vector<int *> & memory)
{
	istringstream istr(command);
	string str;
	istr >> str;
	int num;
	istr >> num;

	if (str[0] == 'A')	//allocate
	{

		if (num > memory.size())
			return ErrorCode::INDEX_OUT_OF_BOUND;
		if (memory[num] != nullptr)
			return ErrorCode::MEMORY_LEAK;

		memory[num] = &Alloc;
	}
	if (str[0] == 'D')
	{
		if (num > memory.size())
			return ErrorCode::INDEX_OUT_OF_BOUND;
		if (memory[num] == nullptr)
			return ErrorCode::DOUBLE_FREE;
		memory[num] = nullptr;
	}
	if (str[0] == 'I')
		return ErrorCode::EXECUTE_IDLE;

	return ErrorCode::EXECUTE_SUCCESS;
}

void printResult(const ErrorCode     errorCode,
	const std::string & command)
{
	string str;
	switch (errorCode)
	{
	case ErrorCode::EXECUTE_SUCCESS: str = "success";
			break;
		case ErrorCode::EXECUTE_IDLE: str = "this exam is a piece of cake! Where is the OOP already?!?";
			break;
		case ErrorCode::MEMORY_LEAK: str = "memory leak prevented, will not make allocation";
			break;
		case ErrorCode::DOUBLE_FREE: str = "system crash prevented, will skip this deallocation";
			break;
		case ErrorCode::INDEX_OUT_OF_BOUND: str = "out of bound";
			break;
	}
		

	cout << command << " - " << str << endl;
}