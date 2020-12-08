#ifndef PLAYER_H
#define PLAYER_H
#include "CharacterBase.h"
#include <cstdlib>
#include <ctime>
class Player : public CharacterBase
{
public:
	bool OnCreate();
	bool OnCreate(const float hpv, const float mpv, const float Speedt, const float Defencev, const Vec3 Posv, const char* Imagee,std::string namev,int loadout);
	void OnDestory();
	void Update(const float deltaTime);
	void Render(SDL_Surface* currentsurface, Matrix4 projectionTake) const;
	void HandleEvents(const SDL_Event& SDL_Event);
	virtual bool CurrentAttack();
	BaseAttack* Attack1;
	
	
	
	
	
	

	
	
	
	
	
};

#endif // PLAYER_H
