#include "Velocity.h"

namespace Comp
{
	glm::vec2 const Velocity::GetCurrentState() const
	{
		return currentVelocity;
	}

	void Velocity::Add(const sfloat x, const sfloat y)
	{
		this->currentVelocity.x += x;
		this->currentVelocity.y += y;
	}

	void Velocity::ZeroOut()
	{
		currentVelocity *= 0.0f;
	}
}