#include "Physics.h"
#include <iostream>

Physics::Physics() {

}

Physics::~Physics() {
	
}

void Physics::Collide(GameObject &go1, GameObject &go2) {

	// Final AABB distance function
	if (isColliding(go1, go2)) {

		// Math, lots of math, all of it needs to be here, oh well

		// Center of body 1
		float cAX = go1.Image->getX() + go1.Image->getWidth() / 2;
		float cAY = go1.Image->getY() + go1.Image->getHeight() / 2;

		// Half-extent of body 1
		float hfextAX = go1.Image->getWidth() / 2;
		float hfextAY = go1.Image->getHeight() / 2;

		// Center of body 2
		float cBX = go2.Image->getX() + go2.Image->getWidth() / 2;
		float cBY = go2.Image->getY() + go2.Image->getHeight() / 2;

		// Half-extend of body 2
		float hfextBX = go2.Image->getWidth() / 2;
		float hfextBY = go2.Image->getHeight() / 2;

		// Distance between both bodies
		float Dx = abs(cAX - cBX) - (hfextAX + hfextBX);
		float Dy = abs(cAY - cBY) - (hfextAY + hfextBY);

		// Position (bottom-left corner) and width and height of body 1
		float x1 = go1.Image->getX();
		float y1 = go1.Image->getY();
		float w1 = go1.Image->getWidth();
		float h1 = go1.Image->getHeight();

		// Position (bottom-left corner) and width and height of body 2
		float x2 = go2.Image->getX();
		float y2 = go2.Image->getY();
		float w2 = go2.Image->getWidth();
		float h2 = go2.Image->getHeight();

		// Player is right side of a wall
		if (x1 + w1 < cBX && y1 + h1 > y2 + 10.0f && y1 < y2 + h2 - 10.0f) {
			go1.Image->setX(go1.Image->getX() + Dx);
			go1.vX = 0.0f;
			go1.canJump = 1;
			go1.isRightWall = false;
			go1.isLeftWall = true;
		} 
		// Player is left side of a wall
		else if (x1 > cBX && y1 + h1 > y2 + 10.0f && y1 < y2 + h2 - 10.0f) {
			go1.Image->setX(go1.Image->getX() - Dx);
			go1.vX = 0.0f;
			go1.canJump = 1;
			go1.isRightWall = true;
			go1.isLeftWall = false;
		}
		// Player is on the floor and not hitting a wall
		else if (y1 + h1 < cBY && x1 + w1 > x2 + 10.0f && x1 < x2 + w2 - 10.0f) {
			go1.Image->setY(go1.Image->getY() + Dy);
			go1.vY = 0.0f;
			go1.canJump = 0;
			go1.isRightWall = false;
			go1.isLeftWall = false;
		}
		// Player has hit a ceiling
		else if (y1 > cBY && x1 + w1 > x2 + 10.0f && x1 < x2 + w2 - 10.0f) {
			go1.Image->setY(go1.Image->getY() - Dy);
			go1.vY = 0.0f;
		}
		// In air
		else {
			go1.isRightWall = false;
			go1.isLeftWall = false;
		}
	}
}

// Simple AABB check for if two Images (Rects) are colliding
bool Physics::isColliding(const GameObject &go1, const GameObject &go2) {
	if (go1.Image->getX() + go1.Image->getWidth() >= go2.Image->getX() && go1.Image->getX() <= go2.Image->getX() + go2.Image->getWidth() &&
		go1.Image->getY() + go1.Image->getHeight() >= go2.Image->getY() && go1.Image->getY() <= go2.Image->getY() + go2.Image->getHeight()) {
		return true;
	}
	else
		return false;
}

void Physics::updatePhysics(GameObject &go, const float deltaTime) {

	// Updating velocity and position, setting a constant gravity, and setting gameworld bounds
	go.vX += go.aX * deltaTime;
	go.vY += go.aY * deltaTime;
	go.Image->setX(go.Image->getX() + (go.vX * deltaTime + 0.5f * go.aX * deltaTime * deltaTime));
	go.Image->setY(go.Image->getY() + (go.vY * deltaTime + 0.5f * go.aY * deltaTime * deltaTime));
	go.aY = 800.0f;
	setBounds(go);
}

// Unused distance X function, replaced
float Physics::distanceX(const GameObject &go1, const GameObject &go2) {
	if (go1.Image->getX() < go2.Image->getX())
		return go2.Image->getX() - (go1.Image->getX() + go1.Image->getWidth());
	else if (go1.Image->getX() > go2.Image->getX())
		return (go2.Image->getX() + go2.Image->getWidth()) - go1.Image->getX();
}

// Unused distance Y function, replaced
float Physics::distanceY(const GameObject &go1, const GameObject &go2) {
	if (go1.Image->getY() < go2.Image->getY())
		return go2.Image->getY() - (go1.Image->getY() + go1.Image->getHeight());
	else if (go1.Image->getY() > go2.Image->getY())
		return (go2.Image->getY() + go2.Image->getHeight()) - go1.Image->getY();
}

// Puts you back at the beginning of the Level if you hit the lava
void Physics::lavaCheck(const GameObject &go1, const GameObject &go2) {
	if (isColliding(go1, go2)) {
		go1.Image->setX(go1.spawnX);
		go1.Image->setY(go1.spawnY);
	}
}

// Set the boundary for the player
void Physics::setBounds(const GameObject &go) {
	if (go.Image->getX() < 0.0f) {
		go.Image->setX(0.0f);
	}

	if (go.Image->getX() + go.Image->getWidth() > SCREEN_WIDTH) {
		go.Image->setX(SCREEN_WIDTH - go.Image->getWidth());
	}

	if (go.Image->getY() < 0.0f) {
		go.Image->setY(0.0f);
	}

	if (go.Image->getY() + go.Image->getHeight() > SCREEN_HEIGHT) {
		go.Image->setY(SCREEN_HEIGHT - go.Image->getHeight());
	}
}