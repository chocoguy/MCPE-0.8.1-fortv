#pragma once
#include <mcpe_types.h>

struct LightLayer
{
	static LightLayer Sky;
	static LightLayer Block;

	int32_t baseLight;

	LightLayer(int baseLight)
		: baseLight(baseLight) {
	}
};
