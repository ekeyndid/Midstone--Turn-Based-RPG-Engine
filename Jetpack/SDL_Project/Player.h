#ifndef PLAYER_H
#define PLAYER_H
#include "CharacterBase.h"
class Player : CharacterBase
{
	bool OnCreate();
	bool OnCreate(float hpv, float mpv, Vec3 Posv, const char* Imagee);
	void OnDestory();
	void Update(const float deltaTime);
	void Render() const;
	void HandleEvents(const SDL_Event& SDL_Event);
	
	std::string Tag = "Player";

	void TakeDmg(float value);
	void DealDmg(float value);
	void SetHP(float value);
	void SetMP(float value);
	bool CurrentAttack(enum Attack);
	
	enum Attacks;
	
	float MaxHP; 
	float CurrHP;
	float MaxMP; 
	float CurrMP;
	Vec3 Position;
	SDL_Surface* Image;
};

#endif // PLAYER_H
