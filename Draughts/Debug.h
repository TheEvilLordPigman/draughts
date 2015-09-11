#ifndef DEBUG_H_
#define DEBUG_H_

#include "stdafx.h"
#include <fstream>
#include <ctime>
#include <string>
#include <cstdlib>

class Debug {
private:
	std::ofstream* file;
public:
	Debug();
	~Debug();
	void write(std::string toWrite);
	void writeln(std::string toWrite);
	void tabs(int numTabs);
};

#endif