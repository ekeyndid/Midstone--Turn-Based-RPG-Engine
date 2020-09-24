#include "Physics.h"


bool Physics::isCollideSphereSphere(const Body &a, const Body &b) {
	if (VMath::distance(a.pos, b.pos) < (a.Radius + b.Radius)) {
		return true;
	}
	return false;
}

bool Physics::isCollideSpherePlane(const Body& Object, const Plane& Plane_) {
	

	return false;
}

void Physics::CollideSphereSphere(Body &a, Body &b) {
	float e = 1.0f;
	Vec3 LineOfAction = a.pos - b.pos;
	Vec3 NormalizedLOA = VMath::normalize(LineOfAction);
	
	float Vector1P = VMath::dot(NormalizedLOA, a.vel);
	float Vector2P = VMath::dot(NormalizedLOA, b.vel);
	
	if (Vector1P - Vector2P > 0.0f) { //I dont care scott, I dont want my balls stickin
		return;
	}
	
	float Vector1New = (((a.mass - e * b.mass) * Vector1P) + ((1.0f + e) * b.mass * Vector2P)) / (a.mass + b.mass);
	float Vector2New = (((b.mass - e * a.mass) * Vector2P) + ((1.0f + e) * a.mass * Vector1P)) / (a.mass + b.mass);

	
	a.vel += (Vector1New - Vector1P) * NormalizedLOA;
	a.Print();
	b.vel += (Vector2New - Vector2P) * NormalizedLOA;
	b.Print();
}





