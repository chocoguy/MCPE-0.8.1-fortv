#pragma once
#include <mcpe_types.h>

struct BinaryBlob
{
	char* data;
	int length;

	BinaryBlob(char* d, int sz) {
		this->data = d;
		this->length = sz;
	}
};
