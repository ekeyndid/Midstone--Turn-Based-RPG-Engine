#include "Scene0.h"
#include <SDL_image.h> 
#include <SDL.h>
#include <SDL_ttf.h>
#include <cstdlib>
Scene0::Scene0(SDL_Window* sdlWindow_){
	window = sdlWindow_;
	
}

Scene0::~Scene0(){
}


bool sortCharacters(CharacterBase* i, CharacterBase* j) { return i->DiceRoll > j->DiceRoll; }
bool Scene0::OnCreate() {
	RunNextCycle = false;
	PostRender = false;
	TurnNumber = 1;
	srand((unsigned)time(NULL));
	int w, h;
	SDL_GetWindowSize(window,&w,&h);
	Matrix4 ndc = MMath::viewportNDC(w, h);
	Matrix4 ortho = MMath::orthographic(-100.0f, 100.0f, -100.0f, 100.0f, 0.0f, 1.0f);
	projection = ndc * ortho;
	//declare player characters
	Characters.push_back(new Player());
	MainPlayer = dynamic_cast<Player*>(Characters.back());
	if (!MainPlayer) { return false; }
	Allies.push_back(MainPlayer); //add allies


	//declare enemies
	Characters.push_back(new Enemy());
	Enemy1 = dynamic_cast<Enemy*>(Characters.back());
	if (!Enemy1) { return false; }
	Enemies.push_back(Enemy1); //add enemies


	if (!MainPlayer->OnCreate(100.0f , 100.0f, 1, 1, Vec3(30,50,0), "good boi.png","Protag",1)) { return false; }
	if (!Enemy1->OnCreate(100.0f, 100.0f, -2, 1, Vec3(-30, 50, 0), "good boi.png","Goblin",1)) { return false; }
	printf("Before sorting the list is: \n");
	MainPlayer->ReturnSpeedRoll();
	Enemy1->ReturnSpeedRoll();
	
	for (int n = 0; n < Characters.size(); n++) {
		std::cout << Characters[n]->DiceRoll << "  " << Characters[n]->Name << std::endl;
	}
	std::cout << MainPlayer->DiceRoll << std::endl;
	printf("After sorting the list is: \n");
	std::sort(Characters.begin(), Characters.end(), sortCharacters);
	for (int n = 0; n < Characters.size(); n++) {
		std::cout << Characters[n]->DiceRoll << "  " << Characters[n]->Name << std::endl;
	}
	
	return true;
}

void Scene0::OnDestroy() {
	MainPlayer->OnDestory();
	Enemy1->OnDestory();
	delete MainPlayer;
	MainPlayer = nullptr;
	delete Enemy1;
	Enemy1 = nullptr;
	

	for (int n = 0; n < Characters.size(); n++) {
		delete Characters[n];
		Characters[n] = nullptr;
	}
	Characters.clear();
	for (int n = 0; n < Enemies.size(); n++) {
		delete Enemies[n];
		Enemies[n] = nullptr;
	}
	Enemies.clear();
	for (int n = 0; n < Allies.size(); n++) {
		delete Allies[n];
		Allies[n] = nullptr;
	}
	Allies.clear();
}

void Scene0::Update(const float time) {
	if (RunNextCycle) {
		std::cout << "Turn: " << TurnNumber << "\n" << std::endl;
		for (int i = 0; i < Characters.size(); i++) {
			PrintTurn(Characters[i]);
			Sleep(1000);
		}
		
		
		
		
		TurnNumber++;
		RunNextCycle = false;
		PostRender = false;
	}
	
	
	
	
	
	
	
	
	if (PostRender) {
		PostRender = false;
		Sleep(3000);
		system("CLS");
		RunNextCycle = true;
	}
}

void Scene0::HandleEvents(const SDL_Event& event) {
	

	
}

bool Scene0::PrintTurn(CharacterBase* PlayerPassIn)
{
	int result;
	if (PlayerPassIn->Tag == "Player") {
		std::cout << PlayerPassIn->Name << " Select an Action, 1 2 3 or 4" << std::endl;
		//print turn layout and call to turn handle func
		std::cout << "1. Attack \t" << "2. Magic \t\ \n" << "3. Defend \t" << "4. Run \n" << std::endl;
		std::cin >> result;
		while (std::cin.fail())
		{
			std::cout << "Invalid, Select again" << std::endl;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			std::cin.rdstate();
			std::cin >> result;
			
			
		}
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cin.rdstate();
		std::cout << result << std::endl;
		CommitAction(PlayerPassIn, result);
	}
	else if (PlayerPassIn->Tag == "Enemy") {
		std::cout << PlayerPassIn->Name << " Selects an Action... \n" << std::endl;
		//do stuff for enemy ahah
	}
		
		
		
		
		//PrintAction("Protag", "Sword", "Goblin", 20,false);
		//PrintAction("Goblin", "Dagger", "Protag", 5,false);
		//PrintAction("Protag", "Sword", "Goblin", 20, true);//moved in the future
		
	
		


	
	
	return true;
}

bool Scene0::PrintAction(std::string Attacker, std::string Action, std::string Defender, int damage,bool miss)
{
	Sleep(1000);
	std::cout << Attacker + " uses, ";
	Sleep(700);
	std::cout << Action << std::endl;
	Sleep(950);
	switch (miss) {
	case true:
		std::cout << "Miss!" << "\n" << std::endl;
		Sleep(2000);
		break;
	case false:
		std::cout << Defender + " takes, ";
		Sleep(700);
		std::cout << damage << " damage!" << "\n" << std::endl;
		Sleep(2000);
		break;
	}
	
	return true;
}

bool Scene0::CommitAction(CharacterBase* PlayerPassIn, int Action)
{
	switch (Action) {
	
	case 1:
		if (PlayerPassIn->Tag == "Player") {
			//check if target self or target ally team
			std::cout << "Select a Target:" << std::endl;
			int SelectedTarget;
			for (int n = 0; n < Enemies.size(); n++) {
				std::cout << n+1 << ". " << Enemies[n]->Name << std::endl;
			}
			std::cin >> SelectedTarget;
			while (std::cin.fail())
			{
				std::cout << "Invalid, Select again" << std::endl;
				std::cin.clear();
				std::cin.ignore(10000, '\n');
				std::cin.rdstate();
				std::cin >> SelectedTarget;
				
			}
			SelectedTarget = SelectedTarget - 1;
			if (SelectedTarget > Enemies.size()-1 || SelectedTarget < 0) { SelectedTarget = 0; }
			std::cout << SelectedTarget << std::endl;
			HandleDamage(PlayerPassIn, Enemies[SelectedTarget], PlayerPassIn->AttackList[0]);
		}
		else if (PlayerPassIn->Tag == "Enemy") {

		}

		break;
	case 2:
		if (PlayerPassIn->Tag == "Player") {

		}
		else if (PlayerPassIn->Tag == "Enemy") {

		}
		break;
	case 3:
		if (PlayerPassIn->Tag == "Player") {

		}
		else if (PlayerPassIn->Tag == "Enemy") {

		}
		break;
	case 4:
		if (PlayerPassIn->Tag == "Player") {

		}
		else if (PlayerPassIn->Tag == "Enemy") {

		}
		break;

	default:
		
		break;
	}

	return false;
}

bool Scene0::HandleDamage(CharacterBase* Attacker, CharacterBase* Defender, BaseAttack* AttackBeingMade)
{
	float HitAcc = 90;//AttackBeingMade->Accuracy - Defender->Evasion;
	float RandomValue = (rand() % 100) + 1;
	std::cout << "random: " << RandomValue << std::endl;
	std::cout << "to hit: " << HitAcc << std::endl;
	if (RandomValue <= HitAcc) {
		float damage = 19;//AttackBeingMade->Damage - Defender->Defence;
		if (damage < 0) { damage = 0; }
		Defender->TakeDmg(damage);
		PrintAction(Attacker->Name,"Basic Weapon Attack" , Defender->Name, damage, false);//AttackBeingMade->Name
		std::cout << Defender->CurrHP;
		return true;
	}
	else { PrintAction(Attacker->Name, "Basic Weapon Attack", Defender->Name, 69, true); return true; }//AttackBeingMade->Name
	return false;
}


void Scene0::Render() {
	//std::cout << "Scene0 Rendering" << std::endl;
	
	
	//Vec3 screenPos = projection * pos;

	//SDL_Rect dstrect;
	//dstrect.x = static_cast<int>(screenPos.x);
	//dstrect.y = static_cast<int>(screenPos.y);





	
	SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
	//SDL_BlitSurface(Player.Image, nullptr, screenSurface, &dstrect);
	//tell player to render and give them projection
	MainPlayer->Render(screenSurface, projection);
	Enemy1->Render(screenSurface, projection);
	
	
	
	
		
		SDL_UpdateWindowSurface(window);
		//SDL_BlitSurface(Player.Image, nullptr, screenSurface, &dstrect);
		PostRender = true;
}


