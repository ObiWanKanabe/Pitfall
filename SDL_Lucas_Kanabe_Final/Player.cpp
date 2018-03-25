#include "Player.h"
#include <iostream>

Player::Player(const Window &window, float x, float y, float w, float h, int r, int g, int b, int a, bool isFlipped) {
	Image = new Rect(window, x, y, w, h, r, g, b, a, isFlipped);
	setSpawnX(x);
	setSpawnY(y);
}

Player::Player(const Window &window, float x, float y, float w, float h, const std::string &image_path, bool isFlipped) {
	Image = new Rect(window, x, y, w, h, image_path, isFlipped);
	setSpawnX(x);
	setSpawnY(y);
}

Player::~Player() {
	delete Image;

	Image = nullptr;
}

// Jump the player by a velocity, does an int check to see if it can jump again
void Player::jump() {
	if (canJump <= 1) {
		vY = -300.0f;
		canJump++;
	}
}

// Move Right, simple
void Player::moveRight() {
	vX += 150.0f;
	if (vX >= 150.0f) {
		vX = 150.0f;
		aX = 0.0f;
	}
}

// Move Left, Simple
void Player::moveLeft() {
	vX += -150.0f;
	if (vX <= -150.0f) {
		vX = -150.0f;
		aX = 0.0f;
	}
}

// Stop Moving player, had to do this for keyboard state input
void Player::stopMovingRight() {
		aX += -50.0f;
		if (vX >= 0.0f) {
			aX = 0.0f;
			vX = 0.0f;
		}
}

// Stop Moving player, had to do this for keyboard state input
void Player::stopMovingLeft() {
		aX += 50.0f;
		if (vX <= 0.0f) {
			aX = 0.0f;
			vX = 0.0f;
		}
}

void Player::Animate() {
	// The Implentation of my Crude Animation class
	// Checks for conditions given by it's velocity, or bools
	// set by the Physics class
	if (vX != 0.0f) {
		LoadRunAnimation();
	}
	else if (isRightWall == true) {
		LoadWallSlideAnimation();
		Image->reset();
	}
	else if (isLeftWall == true) {
		LoadWallSlideAnimation();
		Image->flip();
	} else if (vX == 0.0f) {
		LoadIdleAnimation();
	}
	anim.Animate(*this, 8);

	// Simple Flip if velocity is going right or left
	if (vX < 0) {
		Image->flip();
	}
	else if (vX > 0) {
		Image->reset();
	}
}

// Stops all the physics of the player, used when window is moved
void Player::stopMovement() {
	vX = 0.0f;
	vY = 0.0f;
	aX = 0.0f;
	aY = 0.0f;
}

// Loading the Idle Images into the Animation
void Player::LoadIdleAnimation() {
	anim.Clear();
	anim.Load("res/stickManIdle1White.png", 0);
	anim.Load("res/stickManIdle1White.png", 1);
	anim.Load("res/stickManIdle2White.png", 2);
	anim.Load("res/stickManIdle1White.png", 3);
}

// Loading the Running Images into the Animation
void Player::LoadRunAnimation() {
	anim.Clear();
	anim.Load("res/stickMan1White.png", 0);
	anim.Load("res/stickMan2White.png", 1);
	anim.Load("res/stickMan3White.png", 2);
	anim.Load("res/stickMan4White.png", 3);
}

// Loading the WallSliding Images into the Animation
void Player::LoadWallSlideAnimation() {
	anim.Load("res/stickManWall1white.png", 0);
	anim.Load("res/stickManWall1white.png", 1);
	anim.Load("res/stickManWall2white.png", 2);
	anim.Load("res/stickManWall2white.png", 3);
}