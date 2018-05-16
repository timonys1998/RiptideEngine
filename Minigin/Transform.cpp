#include "MiniginPCH.h"
#include "Transform.h"

dae::Transform::Transform()
{
	
}

dae::Transform::~Transform()
{
}

void dae::Transform::SetPosition(const float x, const float y)
{
	transform[0][2] = x;
	transform[1][2] = y;
}

void dae::Transform::translate(float x, float y)
{
	transform[0][2] += x;
	transform[1][2] += y;
}
