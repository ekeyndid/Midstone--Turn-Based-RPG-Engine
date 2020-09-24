#ifndef SCENE1_H
#define SCENE1_H
#include "Body.h"
#include "Ball.h"
#include "MMath.h"
#include "Scene.h"
#include <SDL.h>

using namespace MATH;
class Scene1:public Scene
{
private:
	SDL_Window* window;
	Matrix4 projection;
	


public:
	Scene1(SDL_Window* sdlWindow);
	Ball Balls[6];
	Plane Roof;
	~Scene1();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();
	void HandleEvents(const SDL_Event& event);
};


#endif

