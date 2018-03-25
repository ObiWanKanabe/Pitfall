#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Window.h"
#include "Rect.h"

class GameObject{
	friend class Physics;
	friend class Level;
public:
	GameObject();
	explicit GameObject(const Window &window, float x, float y, int w, int h, int r, int g, int b, int a, bool isFlipped);
	explicit GameObject(const Window &window, float x, float y, float w, float h, const std::string &image_path, bool isFlipped);
	virtual ~GameObject();
	Rect *Image;

	// Bool to let us know if the object will hurt the player
	bool danger = false;
protected:
	float vX = 0;
	float vY = 0;
	float aX = 0;
	float aY = 0;
	float spawnX;
	float spawnY;
	
	// Gave these to the GameObject so that Player can use them later
	int canJump = 0;
	bool isRightWall;
	bool isLeftWall;
public:
	virtual void setSpawnX(float x);
	virtual void setSpawnY(float y);
};


#endif