#ifndef BALL_H
#define BALL_H


#include "Body.h"
#include "GameObject.h"

class Ball : public GameObject, public Body {
	
public:
	SDL_Surface* ballimage;
	Ball();
	Ball(Vec3 pos_, Vec3 vel_, Vec3 accel_, float Rad_, float mass_, std::string name_);
	~Ball();
	void Update(const float deltaTime);
	bool OnCreate();
	void OnDestory();
	//void Update(const float deltaTime);
	void Render() const;
	void HandleEvents(const SDL_Event& SDL_Event);
	
	
	

private:
	


};


#endif // !BALL_H
