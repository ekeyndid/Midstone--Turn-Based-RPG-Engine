
#ifndef CHARACTERBASE_H
#define CHARACTERBASE_H


#include "Vector.h"
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "GameObject.h"
#include "BaseAttack.h" // This will later be a class full of Base attacks molded into attacks
using namespace MATH;

class CharacterBase : public GameObject { //Base class for all characters, enemies and allies.
public:
	//Setting up some functions they'll need
	virtual void TakeDmg(float value) = 0; //take damage
	virtual void DealDmg(float value) = 0; // deal damage (probably will be yeeted. Idk.)
	virtual void SetHP(float value) = 0; //set current hp to float
	virtual void SetMP(float value) = 0; //set current mp to float
	virtual bool CurrentAttack(enum Attack) = 0; //tell the scene what attack im using
	
	enum Attacks;
	float MaxHP; //max hp and current hp
	float CurrHP;
	float MaxMP; //max mp and current mp
	float CurrMP;
	//AttackList Current Attack; // used later when attacklist is done
	Vec3 Position; //Position on screen
};
#endif // CHARACTERBASE_H
