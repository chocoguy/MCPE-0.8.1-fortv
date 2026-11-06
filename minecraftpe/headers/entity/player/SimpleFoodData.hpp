#pragma once
#include <mcpe_types.h>

struct SimpleFoodData
{
	int32_t currentLevel;

	SimpleFoodData(void);
	void eat(struct FoodItem*);
	void eat(int32_t);
	void tick(struct Player*);
};
