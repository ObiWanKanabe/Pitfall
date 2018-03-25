#ifndef LEVEL1_H
#define LEVEL1_H

#include "Level.h"

class Level1 : public Level {
public:
	explicit Level1(Window& window);
	virtual ~Level1();
	virtual void Init();
	virtual void Update(const float deltaTime);
	virtual void drawUpdate();
	virtual bool levelComplete();
private:
	// All Game Assets Needed
	GameObject* Portal;
	GameObject* Map[37];
	GameObject* Lava[30];
	Window window;
	int r = 75;
	int g = 75;
	int b = 75;
};

#endif