
#ifndef CHARACTERBASE_H
#define CHARACTERBASE_H



#include <SDL_image.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "GameObject.h"

class CharacterBase : public GameObject {
public:
	virtual void TakeDmg(float value) = 0;
	virtual void DealDmg(float value) = 0;
	virtual void SetHP(float value) = 0;
	virtual void SetMP(float value) = 0;
	virtual bool CurrentAttack(enum Attack) = 0;
	
	enum Attacks;
	float MaxHP;
	float CurrHP;
	float MaxMP;
	float CurrMP;

};
#endif // CHARACTERBASE_H
