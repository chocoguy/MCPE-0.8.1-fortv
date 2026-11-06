#pragma once
#include <mcpe_types.h>

struct TileEntityFactory
{
	static struct TileEntity* createTileEntity(int32_t type);
};
