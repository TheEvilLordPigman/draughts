#include "stdafx.h"
#include "Debug.h"

Debug::Debug() {
	file = new std::ofstream();
	file->open("log.txt");
}

Debug::~Debug() {
	file->close();
}

void Debug::write(std::string toWrite) {
	*file << toWrite.c_str();
}

void Debug::writeln(std::string toWrite) {
	*file << toWrite.c_str();
	*file << "\n";
}

void Debug::tabs(int numTabs) {
	for(int i=0; i<numTabs; i++) {
		write("\t");
	}
}