#pragma once
#include "GameEngine/Input/InputManager.h"
#include "GameEngine/Physics/PhysicsManager.h"
#include "GameEngine/Animation/AnimationManager.h"
#include "Containers/Map.h"
#include "Fighter.h"

enum class AnimationState
{
	WALKINGUP
};

class Game
{
public:
	Game() = default;

	void Init();
	void Update();
	void Shutdown();

private:
	Blz::Input::Manager input;
	Blz::Animation::Manager animation;

	Fighter* p_Player;
	Fighter* p_AI;

	uint16 animation1;
	uint16 animation2;
};

