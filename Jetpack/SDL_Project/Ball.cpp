#include "Ball.h"

Ball::Ball(Vec3 pos_,Vec3 vel_,Vec3 accel_, float Rad_, float mass_,std::string name_){
	ballimage = IMG_Load("ball.png");
	BodyOnCreate(pos_, vel_, accel_, mass_, name_,Rad_);
}

Ball::Ball() {


}


Ball::~Ball() {

}



void Ball::Update(const float deltaTime) {

	pos.x += vel.x * deltaTime + 0.5f * accel.x * deltaTime * deltaTime;
	vel.x += accel.x * deltaTime;

	pos.y += vel.y * deltaTime + 0.5f * accel.y * deltaTime * deltaTime;
	vel.y += accel.y * deltaTime;

	pos.z += vel.z * deltaTime + 0.5f * accel.z * deltaTime * deltaTime;
	vel.z += accel.z * deltaTime;

	if (pos.x<-19.0f || pos.x > 19.0f) {
		vel.x *= -1.0f;
	}
	else if (pos.y > 19.0f || pos.y < -19.0f) {
		vel.y *= -1.0f;
	}
	
	
	


}


bool Ball::OnCreate() {
	return false;
}

void Ball::OnDestory() {

}

void Ball::HandleEvents(const SDL_Event& SDL_Event) {

}

void Ball::Render() const {
	
}


