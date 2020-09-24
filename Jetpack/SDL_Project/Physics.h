#ifndef PHYSICS_H
#define PHYSICS_H
#include "Ball.h"
#include "VMath.h"

class Physics{
private:

public:
	bool static isCollideSphereSphere(const Body &a, const Body &b);
	void static CollideSphereSphere(Body &a, Body &b);
	bool static isCollideSpherePlane(const Body& Object, const Plane& Plane_);


};










#endif // !PHYSICS_H

