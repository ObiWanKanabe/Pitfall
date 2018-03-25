#include "InputManager.h"

InputManager::InputManager() {

}

InputManager::~InputManager() {

}

// Small Line Saver to help GameManager
bool InputManager::UIButton(Rect *button, SDL_Event event) {
	if (event.motion.x > button->getX() && event.motion.x < button->getX() + button->getWidth()) {
		if (event.motion.y > button->getY() && event.motion.y < button->getY() + button->getHeight()) {
			return true;
		}
	}
	return false;
}