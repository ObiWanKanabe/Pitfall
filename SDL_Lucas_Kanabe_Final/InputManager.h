#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "GameManager.h"

class InputManager {
public:
	InputManager();
	~InputManager();

	static bool UIButton(Rect *button, SDL_Event event);
};

#endif