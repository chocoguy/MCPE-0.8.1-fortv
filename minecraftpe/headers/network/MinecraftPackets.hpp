#pragma once
#include <mcpe_types.h>

struct Packet;
struct MinecraftPackets
{
	static Packet* createPacket(int32_t pid);
};
