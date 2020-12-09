#include "Enemy.h"



bool Enemy::OnCreate(const float hpv, const float mpv, const float Speedt, const float Defencev, const Vec3 Posv, const char* Imagee, std::string namev, int loadout) { // Create a player with the follows params
	Tag = "Enemy";
	Name = namev;
	MaxHP = hpv; //Hp, set to max
	CurrHP = MaxHP;
	MaxMP = mpv;
	CurrMP = MaxMP; // Mp, set to max
	Speed = Speedt;
	Evasion = Speed <= 0 ? 1 : Speed * 2;
	Position = Posv; // Position on screen
	Defence = Defencev; //defensive value
	Image = IMG_Load(Imagee); //Static image of character
	//if image load fails, return false oncreate
	if (!Image) {
		printf("IMG LOAD ERROR: %s\n", IMG_GetError());
		return false;
	}
	switch (loadout) {
	case 1:

		Attack1 = new EnemyBasicAttack;
		AttackList.push_back(Attack1);
		break;
	}
	return true;
	//all done, return true
}

void Enemy::Update(const float deltaTime)
{
}

void Enemy::Render(SDL_Surface* currentsurface, Matrix4 projectionTake) const
{
	Vec3 screenPos = projectionTake * Position;

	SDL_Rect dstrect;
	dstrect.x = static_cast<int>(screenPos.x);
	dstrect.y = static_cast<int>(screenPos.y);
	SDL_BlitSurface(Image, nullptr, currentsurface, &dstrect);
}

void Enemy::HandleEvents(const SDL_Event& SDL_Event)
{
}



bool Enemy::CurrentAttack() {

	return true;
}



Enemy::~Enemy()
{
	OnDestory();
}

Enemy::Enemy()
{
	Tag = "Enemy";
	Name = "doe";
	MaxHP = CurrHP = 100;
	MaxMP = CurrMP = 100;
	Speed = 0;
	Evasion = 1;
	Position = Vec3();
	
}

void Enemy::OnDestory() {
	Image = NULL;
	delete Image;
}



