#pragma once
#include <mcpe_types.h>

struct ThreadCollection;
struct Worker
{
	ThreadCollection* threadCollection;

	Worker(ThreadCollection&);
	void operator()(void);
};
