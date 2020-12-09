#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SDL.h>
#include <stdlib.h>
#include "MMath.h"
using namespace MATH;
class GameObject {
public:
	virtual void OnDestory() = 0;
	virtual void Update(const float deltaTime) = 0;
	virtual void Render(SDL_Surface* currentsurface, Matrix4 projectionTake) const = 0;
	virtual void HandleEvents(const SDL_Event &SDL_Event) = 0;
	std::string Tag;
	SDL_Surface* Image;

	//We learned about this last sem guys, cmon. But to recap.
	//This is a baseclass for anything really, itll come with the usual functions,
	//and a nifty tag to Identify it.



};









#endif
