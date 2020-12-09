
#ifndef CHARACTERBASE_H
#define CHARACTERBASE_H


#include "Vector.h"
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include "GameObject.h"
#include "BaseAttack.h" // This will later be a class full of Base attacks molded into attacks
#include "BasicAttack.h"
using namespace MATH;

class CharacterBase : public GameObject { //Base class for all characters, enemies and allies.
public:
	//Setting up some functions they'll need
	inline void TakeDmg(float value) { CurrHP -= value; } //take damage
	 // deal damage (probably will be yeeted. Idk.)
	inline virtual void SetHP(float value1, float value2) { CurrHP = value1; CurrMP = value2; }//set current hp to float set current mp to float
	virtual bool CurrentAttack() = 0; //tell the scene what attack im using
	
	inline int ReturnSpeedRoll()
	{
		int randd;
		randd = (rand() % 20) + 1;
		DiceRoll = randd + Speed;
		return DiceRoll;
	}
	std::string Name;
	int DiceRoll;
	std::vector<BaseAttack*> AttackList;
	float MaxHP; //max hp and current hp
	float CurrHP;
	float MaxMP; //max mp and current mp
	float CurrMP;
	float Defence;
	float Speed;
	float Evasion;
protected:
	
	
	
	//AttackList Current Attack; // used later when attacklist is done
	Vec3 Position; //Position on screen
	SDL_Surface* Image;
};
#endif // CHARACTERBASE_H
