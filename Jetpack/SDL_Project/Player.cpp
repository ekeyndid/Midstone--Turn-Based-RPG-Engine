#include "Player.h"



bool Player::OnCreate(const float hpv, const float mpv, const Vec3 Posv, const char* Imagee) { // Create a player with the follows params
	MaxHP = CurrHP = hpv; //Hp, set to max
	MaxMP = CurrMP = mpv; // Mp, set to max
	Position = Posv; // Position on screen
	Image = IMG_Load(Imagee); //Static image of character
	//if image load fails, return false oncreate
	if (!Image) {
		printf("IMG LOAD ERROR: %s\n", IMG_GetError());
		return false;
	}
	return true;
	//all done, return true
}

void Player::Update(const float deltaTime)
{
}

void Player::Render() const
{
}

void Player::HandleEvents(const SDL_Event& SDL_Event)
{
}

bool Player::OnCreate()
{
	MaxHP = CurrHP = 100;
	MaxMP = CurrMP = 100;
	Position = Vec3();
	Image = IMG_Load("Test.png");
	if (!Image) {
		printf("IMG LOAD ERROR: %s\n", IMG_GetError());
		return false;
	}
	return true;
}

void Player::OnDestory() {
	Image = NULL;
	delete Image;
}


