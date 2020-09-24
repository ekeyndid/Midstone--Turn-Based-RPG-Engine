#ifndef PLAYEROBJECT_H
#define PLAYEROBJECT_H
#include "Body.h"
#include "GameObject.h"
#include <SDL.h>
#include "MMath.h"

class playerObject : public GameObject, public Body
{
public:
	SDL_Surface* Image;
	float Direction = 0;
	float SphereRadiusBox = 69;
	bool grounded = false;
	bool ijump = true;
	bool floating = false;
	float charge = 2.0f;
	float WalkSpeed = 10;
	float YVel = 0;
	float XLock = 1;
	//void Update(const float deltaTime);
	void Jump(float Force);
	bool OnCreate();
	bool OnCreate(Vec3 pos_, Vec3 vel_, Vec3 accel_, float mass_, std::string name_, float Rad_);
	void OnDestory();
	void Update(const float deltaTime);
	void Render() const;
	void HandleEvents(const SDL_Event& SDL_Event);
	void ApplyVel(Vec3 Velos);

};





#endif // PLAYEROBJECT_H