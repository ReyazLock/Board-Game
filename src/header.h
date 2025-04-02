#ifndef HEADER_H
#define HEADER_H

#include <string>


enum valueInput {
	program_name = 0,
	input_file_name = 1,
	expected_argc = 2
};

enum valueOutput {
	SUCCESS = 0,
	USER_QUIT = -1,
	DRAW_END = -2,
	USAGE_ERROR = -3,
	UNEXPECTED_ERROR = -4,
	MEMORY_BAD_ALLOC_ERROR = -5
};

int usage(const char* programName, const char* message);

#endif