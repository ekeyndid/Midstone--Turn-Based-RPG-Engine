#include "playerObject.h"

bool playerObject::OnCreate() {
	pos = Vec3();
	vel = Vec3();
	accel = Vec3();
	mass = 1;
	Name = "bad";
	SphereRadiusBox = 1;
	Image = nullptr;
	Tag = "Player";
	return true;
}
bool playerObject::OnCreate(Vec3 pos_, Vec3 vel_, Vec3 accel_, float mass_, std::string name_, float Rad_) {
	pos = pos_;
	vel = vel_;
	accel = accel_;
	mass = mass_;
	Name = name_;
	SphereRadiusBox = Rad_;
	Image = IMG_Load("player.jpg");
	if (Image != nullptr) {
		return true;
		grounded = false;
	}
	else {
		return false;
	}
}
void playerObject::OnDestory() {
	Image = nullptr;
	delete Image;
}
void playerObject::Update(const float deltaTime) {
	std::cout << charge << std::endl;
	if (pos.x < -100) {
		pos.x = 99;
	}
	else if (pos.x > 100) {
		pos.x = -99;
	}
	
	if (grounded && ijump) {
		vel.y = 0;
		accel.y = 0;
		ijump = false;
		charge = 2.0f;
		WalkSpeed = 10;
	}
	else if (!grounded && !floating) {
		ApplyForce(Vec3(0.0f, -10.0f, 0.0f));
	}
	else if (floating) {
		vel.y = YVel*WalkSpeed;
		WalkSpeed = 20;
	}
	ApplyVel(Vec3(Direction * WalkSpeed * XLock, vel.y, vel.z));
	// TEMP TEST
	if (pos.y < -5.0f) {
		grounded = true;
	}
	pos.x += vel.x * deltaTime + 0.5f * accel.x * deltaTime * deltaTime;
	vel.x += accel.x * deltaTime;

	pos.y += vel.y * deltaTime + 0.5f * accel.y * deltaTime * deltaTime;
	vel.y += accel.y * deltaTime;

	pos.z += vel.z * deltaTime + 0.5f * accel.z * deltaTime * deltaTime;
	vel.z += accel.z * deltaTime;
	if (floating) {
		charge -= 0.01;
	}
	if (charge <= 0) {
		floating = false;
		charge = 0.0f;
	}
}
void playerObject::ApplyVel (Vec3 Velos) {
	

	vel.x = Velos.x;
	vel.y = Velos.y;
	vel.z = Velos.z;
}
void playerObject::Render() const{

}
void playerObject::Jump(float Force) {
	if (grounded && !ijump) {
		ijump = true;
		Direction = Direction;
		grounded = false;
		ApplyVel(Vec3(Direction, Force, 0));
	}
	else if (!grounded && ijump && !floating) {
		floating = true;

	}
	

}
void playerObject::HandleEvents(const SDL_Event& SDL_Event) {
	switch (SDL_Event.type) {
	case SDL_EventType::SDL_KEYDOWN:

		switch (SDL_Event.key.keysym.sym) {
		case SDLK_LEFT:
			//std::cout << "Left press" << std::endl;
			Direction = -1;
			break;
		case SDLK_UP:
			YVel = 1;
			XLock = 0;
			break;
		case SDLK_DOWN:
			YVel = -1;
			XLock = 0;
			break;
		case SDLK_RIGHT:
			//std::cout << "Right press" << std::endl;
			Direction = 1;
			break;
		case SDLK_SPACE:
			Jump(20.0f);
		default:
			//std::cout << "No Press" << std::endl;
			Direction = 0;
			break;
		}
		break;
	case SDL_EventType::SDL_KEYUP:

		switch (SDL_Event.key.keysym.sym) {
		case SDLK_LEFT:
			//std::cout << "Left press up" << std::endl;
			Direction = 0;
			break;
		case SDLK_RIGHT:
			//std::cout << "Right press up" << std::endl;
			Direction = 0;
			break;
		case SDLK_SPACE:
		case SDLK_DOWN:
			YVel = 0;
			XLock = 1;
			break;
		case SDLK_UP:
			YVel = 0;
			XLock = 1;
			break;
		default:
			//std::cout << "No Press up" << std::endl;
			Direction = 0;
			break;
		}
		break;


	default:
		break;

	}
	
}




