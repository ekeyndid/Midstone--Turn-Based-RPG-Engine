#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include <SDL.h>
#include <stdlib.h>
class GameObject {
public:
	virtual bool OnCreate() = 0;
	virtual void OnDestory() = 0;
	virtual void Update(const float deltaTime) = 0;
	virtual void Render() const = 0;
	virtual void HandleEvents(const SDL_Event &SDL_Event) = 0;
	std::string Tag;


	



};









#endif
