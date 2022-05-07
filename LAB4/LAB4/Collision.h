#pragma once
#include "RectangleNode.h"
#include "RingNode.h"

static class CollisionManager
{
public:
	static bool IsCollision(RectangleNode Rectangle1, RectangleNode Rectangle2);
	static bool IsCollision(RingNode Ring1, RingNode Ring2);
	static bool IsCollision(RingNode* Ring1, RingNode* Ring2);
};