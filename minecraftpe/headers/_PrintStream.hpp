#pragma once
#include <mcpe_types.h>
#include <string>

//is this some kind of terrible attempt to port nbt from java </3
struct PrintStream{
	void println(std::string v) {
		std::string n("\n");
	}
};
