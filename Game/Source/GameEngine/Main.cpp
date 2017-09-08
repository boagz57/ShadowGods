/*TODO: Turn off exceptions (for speed purposes):	

		- https://stackoverflow.com/questions/553103/can-i-disable-exceptions-in-stl 

	and when handling std stl errors without exceptions:

		- https://stackoverflow.com/questions/3870435/handling-stl-errors-without-exceptions

	and make sure no exception based library is used. 
*/

#include "Graphics\ShaderProgram.h"
#include "Graphics\Window.h"
#include "Scene.h"
#include "../Game.h"
#include "Fighter.h"
#include "Timing\Timing.h"
#include "Animation\AnimationManager.h"
#include "Input\InputManager.h"
#include "Graphics\RenderManager.h"
#include "AI\AIManager.h"
#include "Physics\PhysicsManager.h"

Blz::Graphics::RenderManager Renderer;
Blz::Input::InputManager Input;
Blz::AI::AIManager AI;
Blz::Animation::AnimationManager animation;
Blz::Physics::PhysicsManager Physics;
Scene scene;

int main(int agrc, char** argv)
{
	Blz::Graphics::Window window(1280, 720);
	Blz::Graphics::ShaderProgram colorShaderProgram;

	Game game;

	colorShaderProgram.Init("Source/GameEngine/Shaders/VertexShader.glsl", "Source/GameEngine/Shaders/FragmentShader.glsl");
	colorShaderProgram.Compile();
	colorShaderProgram.AddAttribute("vertexPosition");
	colorShaderProgram.AddAttribute("textCoord");
	colorShaderProgram.Link();
	colorShaderProgram.Bind();

	//Initialize systems
	game.Init();
	Renderer.Init(scene, window);
	animation.Init(scene);

	//Game loop
	while (true)
	{
		Input.Update(scene);

		game.Update();

		Physics.Update(scene);
		AI.Update(scene);
		animation.Update(scene);

		window.ClearBuffers();

		Renderer.Update(scene, colorShaderProgram);

		window.SwapBuffers();

		Blz::Timing::CalculateAndDisplayFPS();
	}

	return 0;
}
