#include "Body.h"
#include <string.h>

Body::Body() {
	pos.x = pos.y = pos.z = 0.0f;
	vel.x = vel.y = vel.z = 0.0f;
	accel.x = accel.y = accel.z = 0.0f;
	mass = 1;
}

Body::~Body() {

}


void Body::BodyOnCreate(Vec3 pos_, Vec3 vel_, Vec3 accel_,float mass_,std::string name_,float Rad_) {
	
	pos.x = pos_.x;
	pos.y = pos_.y;
	pos.z = pos_.z;
	vel.x = vel_.x;
	vel.y = vel_.y;
	vel.z = vel_.z;
	accel.x = accel_.x;
	accel.y = accel_.y;
	accel.z = accel_.z;
	mass = mass_;
	Name = name_;
	Radius = Rad_;


}





//hiiii
void Body::Update(const float deltaTime) {
	
	pos.x += vel.x * deltaTime + 0.5f * accel.x * deltaTime * deltaTime;
	vel.x += accel.x * deltaTime;
	
	pos.y += vel.y * deltaTime + 0.5f * accel.y * deltaTime * deltaTime;
	vel.y += accel.y * deltaTime;
	
	pos.z += vel.z * deltaTime + 0.5f * accel.z * deltaTime * deltaTime;
	vel.z += accel.z * deltaTime;

}

void Body::ApplyForce(Vec3 force) {
	accel.x = force.x / mass;
	accel.y = force.y / mass;
	accel.z = force.z / mass;
}



Vec3 Body::GetPos() {
	return pos;
}

float Body::GetMass() {
	return mass;
}

void Body::SetVel(Vec3 vel_) {
	vel = vel_;
	
}

void Body::Print() {
	
	std::cout << "----------------------------\n" << "Name: " << Name << std::endl;
	std::cout << "Position(x,y): " << pos.x << " , " << pos.y << std::endl;
	std::cout << "Accel(x,y): " << accel.x << " , "  << accel.y << std::endl;
	std::cout << "Velocity(x,y): " << vel.x << " , "  << vel.y << std::endl;
	std::cout << "----------------------------\n" << std::endl;
	

	
}