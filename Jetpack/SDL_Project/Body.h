#ifndef BODY_H
#define BODY_H
#include "Vector.h"
#include <SDL_image.h>
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace MATH;

class Body{
	friend class Physics;
protected:
	Vec3 pos;
	Vec3 vel;
	Vec3 accel;
	float mass;
	std::string Name = "Big Meme";

private:
	//Vec3 pos;
	//Vec3 vel;
	//Vec3 accel;
	//float mass;
	//std::string Name = "JetSki";
	
	

public:
	
	
	Body();
	~Body();
	void BodyOnCreate(Vec3 pos_, Vec3 vel_, Vec3 accel_,float mass_,std::string name_,float Rad_);
	void Update(const float deltaTime);
	// Updates acceleration using the equation a = F/m
	void ApplyForce(Vec3 force);
	Vec3 GetPos();
	float GetMass();
	void SetVel(Vec3 vel_);
	void Print();
	float Radius;

	


};











#endif

