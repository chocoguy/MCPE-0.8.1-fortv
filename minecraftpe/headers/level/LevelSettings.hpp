#include <mcpe_types.h>

struct LevelSettings
{
	int32_t seed, gameType;

	LevelSettings(int seed, int gt) : seed(seed), gameType(gt){

	}
};
