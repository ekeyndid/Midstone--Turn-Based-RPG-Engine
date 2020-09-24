#include "Scene0.h"
#include <SDL_image.h> 
#include <SDL.h>
#include <SDL_ttf.h>

Scene0::Scene0(SDL_Window* sdlWindow_){
	window = sdlWindow_;
	
}

Scene0::~Scene0(){
}

bool Scene0::OnCreate() {
	
	int w, h;
	SDL_GetWindowSize(window,&w,&h);
	Matrix4 ndc = MMath::viewportNDC(w, h);
	Matrix4 ortho = MMath::orthographic(-100.0f, 100.0f, -15.0f, 100.0f, 0.0f, 1.0f);
	projection = ndc * ortho;
	
	if (!Player.OnCreate(Vec3(0.0f, 0.0f, 0.0f),
		Vec3(0.0f, 0.0f, 0.0f),
		Vec3(0.0f, 0.0f, 0.0f),
		1, "PlayerObject", 1)) {
		std::cout << "Player Creation Failed" << std::endl;
		return false;
	}
	else {
		std::cout << "Player Creation Succeded" << std::endl;
	}

	
	Player.Print();

	//jetski = new Body();
	//jetski->BodyOnCreate(Vec3(0.0f, 0.0f, 0.0f),
	//	Vec3(0.0f, 0.0f, 0.0f),
	//	Vec3(0.0f, 0.0f, 0.0f), 200.0f, "Umer and Scott");
	//
	//jetski2 = new Body();
	//jetski2->BodyOnCreate(Vec3(-10.0f, 0, 0.0f),
	//	Vec3(0.0f, 0.0f, 0.0f),
	//	Vec3(0.0f, 0.0f, 0.0f), 200.0f, "Jetski2");

	
	
	
	return true;
}

void Scene0::OnDestroy() {
	Player.OnDestory();
	
}

void Scene0::Update(const float time) {
	Player.Update(time);
}

void Scene0::HandleEvents(const SDL_Event& event) {
	

	Player.HandleEvents(event);
}


void Scene0::Render() {
	//std::cout << "Scene0 Rendering" << std::endl;
	Vec3 pos = Player.GetPos();
	
	Vec3 screenPos = projection * pos;

	SDL_Rect dstrect;
	dstrect.x = static_cast<int>(screenPos.x);
	dstrect.y = static_cast<int>(screenPos.y);





	
	SDL_Surface *screenSurface = SDL_GetWindowSurface(window);
	SDL_FillRect(screenSurface, nullptr, SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF));
	SDL_BlitSurface(Player.Image, nullptr, screenSurface, &dstrect);

	
	
	
	
		
		SDL_UpdateWindowSurface(window);
		//SDL_BlitSurface(Player.Image, nullptr, screenSurface, &dstrect);
}


