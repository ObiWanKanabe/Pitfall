#ifndef LEVEL_H
#define LEVEL_H

#include "Window.h"
#include "Player.h"
#include "GameObject.h"

class Level {
	friend class GameManager;
public:
	explicit Level(class Window& window);
	~Level();
	virtual void Init() = 0;
	virtual void Update(const float deltaTime) = 0;
	virtual void drawUpdate() = 0;
	virtual bool levelComplete() = 0;

protected:
	// Must be a player in every level, Gamemanager has to access it's functions for input
	Window* windowPtr;
	Player* player;
	bool hasWon = false;

};

#endif