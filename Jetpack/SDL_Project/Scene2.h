#ifndef SCENE2_H
#define SCENE2_H
#include "Body.h"
#include "Body.h"
#include "MMath.h"
#include "Scene.h"
#include <SDL.h>

using namespace MATH;
class Scene2 :public Scene
{
private:
	SDL_Window* window;
	Matrix4 projection;



public:
	Scene2(SDL_Window* sdlWindow);
	Body Sun1;
	Body Sun2;
	Body Planet;
	float GravConst = 1.0f;
	SDL_Surface* Sun1Pic;
	SDL_Surface* Sun2Pic;
	SDL_Surface* PlanetPic;
	~Scene2();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();
	void HandleEvents(const SDL_Event& event);
};


#endif



