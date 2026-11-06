#pragma once
#include <mcpe_types.h>

struct DimensionFactory{
	static struct Dimension* createDefaultDimension(struct LevelData*);
};
