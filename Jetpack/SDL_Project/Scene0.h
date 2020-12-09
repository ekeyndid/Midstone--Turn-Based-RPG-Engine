#ifndef SCENE0_H
#define SCENE0_H
#include "MMath.h"
#include "Scene.h"
#include <SDL.h>
#include "CharacterBase.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <Windows.h>
#include <limits>
#include "BaseAttack.h"
using namespace MATH;
class Scene0 : public Scene {
private:
	SDL_Window *window;
	Matrix4 projection;
	Player* MainPlayer;
	Player* SidePlayer;
	Enemy* Enemy1;
	Enemy* Enemy2;
	bool PostRender;
	bool RunNextCycle;
	int TurnNumber;
	std::vector<CharacterBase*> Characters;
	std::vector<Enemy*> Enemies;
	std::vector<Player*> Allies;
public:
	Scene0(SDL_Window* sdlWindow);
	~Scene0();
	bool OnCreate();
	void OnDestroy();
	void Update(const float time);
	void Render();
	void HandleEvents(const SDL_Event& event);
	bool PrintTurn(CharacterBase* PlayerPassIn);
	bool PrintAction(std::string Attacker, std::string Action, std::string Defender, int damage,bool miss);
	bool CommitAction(CharacterBase* PlayerPassIn, int Action);
	bool HandleDamage(CharacterBase* Attacker, CharacterBase* Defender, BaseAttack* AttackBeingMade);
};

#endif

