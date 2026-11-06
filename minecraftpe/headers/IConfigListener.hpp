#pragma once
#include <mcpe_types.h>

struct Config;

struct IConfigListener{
	virtual ~IConfigListener(){}
	virtual void onConfigChanged(const Config&) = 0;
};
