#pragma once
#include <mcpe_types.h>

struct ChestTileEntity;
struct TileEntity;
struct Tile;
struct EntityTileRenderer
{
	static EntityTileRenderer* instance;
	void render(Tile*, int32_t, float);
};
