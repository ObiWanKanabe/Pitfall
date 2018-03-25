#ifndef PLAYER_H
#define PLAYER_H

#include "GameObject.h"
#include "Animation.h"

class Player : public GameObject {
public:
	Player(const Window &window, float x, float y, float w, float h, int r, int g, int b, int a, bool isFlipped);
	Player(const Window &window, float x, float y, float w, float h, const std::string &image_path, bool isFlipped);
	~Player();
	
	//Input Methods called by GameManagers Input Methods
	void jump();
	void moveRight();
	void moveLeft();
	void stopMovingLeft();
	void stopMovingRight();
	void stopMovement();
	void Animate();
private:
	Animation anim;

	void LoadIdleAnimation();
	void LoadRunAnimation();
	void LoadWallSlideAnimation();

};

#endif