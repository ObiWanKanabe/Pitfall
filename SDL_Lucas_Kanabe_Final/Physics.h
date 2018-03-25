#ifndef PHYSICS_H
#define PHYSICS_H

#include "GameObject.h"

class Physics {
public:
	Physics();
	virtual ~Physics();
	static void Collide(GameObject &go1, GameObject &go2);
	static bool isColliding(const GameObject &go1, const GameObject &go2);
	static void updatePhysics(GameObject &go, const float deltaTime);
	static float distanceX(const GameObject &go1, const GameObject &go2);
	static float distanceY(const GameObject &go1, const GameObject &go2);
	static void lavaCheck(const GameObject &go1, const GameObject &go2);
	static void setBounds(const GameObject &go);
};

#endif