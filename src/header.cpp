#include "header.h"
#include <iostream>

using namespace std;


int usage(const char* programName, const char* message) {
	cerr << "Usage: " << programName << " " << message << endl;
	return USAGE_ERROR;
}