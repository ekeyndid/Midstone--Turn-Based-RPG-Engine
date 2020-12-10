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


bool sortCharacters(CharacterBase* i, CharacterBase* j) { return i->DiceRoll > j->DiceRoll; } //custom sorting func
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
	Characters.push_back(new Player()); //add player to list (character*)
	MainPlayer = dynamic_cast<Player*>(Characters.back()); //cast it to player, so it keeps vars that I set (Player*)
	if (!MainPlayer) { return false; } //check if exist
	Characters.push_back(new Player());
	SidePlayer = dynamic_cast<Player*>(Characters.back());
	if (!SidePlayer) { return false; }
	Allies.push_back(MainPlayer); //add allies
	Allies.push_back(SidePlayer);

	
	//declare enemies
	Characters.push_back(new Enemy());
	Enemy1 = dynamic_cast<Enemy*>(Characters.back());
	if (!Enemy1) { return false; }
	Characters.push_back(new Enemy());
	Enemy2 = dynamic_cast<Enemy*>(Characters.back());
	if (!Enemy2) { return false; }
	Enemies.push_back(Enemy1); //add enemies
	Enemies.push_back(Enemy2);

	//on creates to set vars
	if (!MainPlayer->OnCreate(50.0f , 50.0f, 2, 2, Vec3(30,50,0), "good boi.png","Protag",1)) { return false; }
	if (!SidePlayer->OnCreate(45.0f, 45.0f, 5, 0, Vec3(50, 0, 0), "good boi.png", "Side", 1)) { return false; }
	if (!Enemy1->OnCreate(40.0f, 40.0f, 2, 1, Vec3(-30, 50, 0), "good boi.png","Goblin",1)) { return false; }
	if (!Enemy2->OnCreate(60.0f, 60.0f, -5, 1, Vec3(-50, 0, 0), "good boi.png", "Orc", 1)) { return false; }
	std::cout << "Encountered " << Enemy1->Name << " and " << Enemy2->Name << "!" << std::endl; // starting text
	printf("\n Before sorting the attack list is: \n"); //text
	//polietly ask everyone to roll initiative
	MainPlayer->ReturnSpeedRoll();
	SidePlayer->ReturnSpeedRoll();
	Enemy1->ReturnSpeedRoll();
	Enemy2->ReturnSpeedRoll();
	
	for (int n = 0; n < Characters.size(); n++) {
		std::cout << Characters[n]->DiceRoll << "(" << Characters[n]->Speed << ")" << "  " << Characters[n]->Name << std::endl; //display character name roll
	}
	//std::cout << MainPlayer->DiceRoll << std::endl;
	printf("After sorting the attack list is: \n");
	std::sort(Characters.begin(), Characters.end(), sortCharacters); //sort them using custom func
	for (int n = 0; n < Characters.size(); n++) {
		std::cout << Characters[n]->DiceRoll << "  " << Characters[n]->Name << std::endl; //display sorted character roll and name
	}
	Sleep(3000);
	return true;
}

void Scene0::OnDestroy() {
	delete MainPlayer;
	MainPlayer = nullptr;
	delete Enemy1;
	Enemy1 = nullptr;
	delete SidePlayer;
	SidePlayer = nullptr;
	delete Enemy2;
	Enemy2 = nullptr;
	

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
	if (PlayerPassIn->CurrHP <= 0) {
		std::cout << PlayerPassIn->Name << " Health: " << PlayerPassIn->CurrHP << std::endl;
		std::cout << PlayerPassIn->Name << " Is down! \n" << std::endl;

		return true;
	}
	if (PlayerPassIn->Tag == "Player") {
		
		std::cout << PlayerPassIn->Name << " Health: "<< PlayerPassIn->CurrHP << std::endl;
		std::cout << "Select an Action, 1 2 3 or 4" << std::endl;
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
		//std::cout << result << std::endl;
		CommitAction(PlayerPassIn, result);
	}
	else if (PlayerPassIn->Tag == "Enemy") {
		std::cout << PlayerPassIn->Name << " Health: " << PlayerPassIn->CurrHP << std::endl;
		std::cout << PlayerPassIn->Name << " Selects an action.. \n" << std::endl;
		float Action;
		result = 1;//(rand() % 4) + 1;
		CommitAction(PlayerPassIn, result);
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
			//std::cout << SelectedTarget << std::endl;
			HandleDamage(PlayerPassIn, Enemies[SelectedTarget], PlayerPassIn->AttackList[0]);
		}
		else if (PlayerPassIn->Tag == "Enemy") {
			int AlliesSize = Allies.size();
			int SelectedTarget = (rand() % AlliesSize) + 1;
			SelectedTarget = SelectedTarget - 1;
			HandleDamage(PlayerPassIn, Allies[SelectedTarget], PlayerPassIn->AttackList[0]);
		}

		break;
	case 2:
		if (PlayerPassIn->Tag == "Player") {
			std::cout << "No Valid Known Magic! \n" << std::endl;
		}
		else if (PlayerPassIn->Tag == "Enemy") {
			std::cout << "No Valid Known Magic! \n" << std::endl;
		}
		break;
	case 3:
		if (PlayerPassIn->Tag == "Player") {
			std::cout << PlayerPassIn->Name << " Defends themself from attacks! \n" << std::endl;
		}
		else if (PlayerPassIn->Tag == "Enemy") {
			std::cout << PlayerPassIn->Name << " Defends themself from attacks! \n" << std::endl;
		}
		break;
	case 4:
		if (PlayerPassIn->Tag == "Player") {
			std::cout << PlayerPassIn->Name << " Attempts to flee!" << std::endl;
			Sleep(2000);
			std::cout << PlayerPassIn->Name << " failed to flee... \n" << std::endl;
		}
		else if (PlayerPassIn->Tag == "Enemy") {
			std::cout << PlayerPassIn->Name << " Attempts to flee!" << std::endl;
			Sleep(2000);
			std::cout << PlayerPassIn->Name << " failed to flee! \n" << std::endl;
		}
		break;

	default:
		std::cout << PlayerPassIn->Name << " Skipped their turn! \n" << std::endl;
		break;
	}

	return false;
}

bool Scene0::HandleDamage(CharacterBase* Attacker, CharacterBase* Defender, BaseAttack* AttackBeingMade)
{
	float HitAcc = AttackBeingMade->getAccuracy() - Defender->Evasion;
	float RandomValue = (rand() % 100) + 1;
	//std::cout << "random: " << RandomValue << std::endl;
	//std::cout << "below " << HitAcc << " to hit" << std::endl;
	if (RandomValue <= HitAcc) {
		float damage = AttackBeingMade->getDamage() - Defender->Defence;
		if (damage < 0) { damage = 0; }
		Defender->TakeDmg(damage);
		PrintAction(Attacker->Name,AttackBeingMade->getName() , Defender->Name, damage, false);
		//std::cout << Defender->CurrHP;
		return true;
	}
	else { PrintAction(Attacker->Name, AttackBeingMade->getName(), Defender->Name, 69, true); return true; }//AttackBeingMade->Name
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
	SidePlayer->Render(screenSurface, projection);
	Enemy1->Render(screenSurface, projection);
	Enemy2->Render(screenSurface, projection);
	
	
	
	
		
		SDL_UpdateWindowSurface(window);
		//SDL_BlitSurface(Player.Image, nullptr, screenSurface, &dstrect);
		PostRender = true;
}


