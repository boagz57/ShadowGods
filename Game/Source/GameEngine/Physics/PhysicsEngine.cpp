#include "../Scene.h"
#include "Systems/PhysicsSystems.h"
#include "Components/Position.h"
#include "PhysicsEngine.h"

namespace Blz
{
	namespace Physics
	{
		void Engine::Init()
		{
		}

		void Engine::Shutdown()
		{

		}

		void Engine::Update(Scene& scene)
		{
			ec.AddContext("When updating Physics engine");

			for (Fighter& fighter : scene.fighters)
			{
				Comp::Position newFighterPosition = CompSystem::MoveFighter(fighter.transform, fighter.position);

				fighter.position = newFighterPosition;
			}
		}
	}
}