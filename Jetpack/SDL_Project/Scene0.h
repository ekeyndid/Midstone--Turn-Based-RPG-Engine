#ifndef SCENE0_H
#define SCENE0_H
#include "Body.h"
#include "Ball.h"
#include "MMath.h"
#include "Scene.h"
#include <SDL.h>
#include "playerObject.h"
using namespace MATH;
class Scene0 : public Scene {
private:
	SDL_Window *window;
	const SDL_Rect* ye;
	SDL_Surface* PlayerImage;
	Matrix4 projection;
	float elapsedTime;
	float Direction;
	playerObject Player;
	
	

	
public:
	Scene0(SDL_Window* sdlWindow);
	~Scene0();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();
	void HandleEvents(const SDL_Event& event);
	
	
};

#endif

