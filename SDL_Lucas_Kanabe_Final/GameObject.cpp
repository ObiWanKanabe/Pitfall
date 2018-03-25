#include "GameObject.h"
#include "Window.h"
#include "Rect.h"

GameObject::GameObject() {

}

GameObject::GameObject(const Window &window, float x, float y, int w, int h, int r, int g, int b, int a, bool isFlipped) {
	Image = new Rect(window, x, y, w, h, r, g, b, a, isFlipped);
	setSpawnX(x);
	setSpawnY(y);
}

GameObject::GameObject(const Window &window, float x, float y, float w, float h, const std::string &image_path, bool isFlipped) {
	Image = new Rect(window, x, y, w, h, image_path, isFlipped);
	setSpawnX(x);
	setSpawnY(y);
}

GameObject::~GameObject() {
	delete Image;

	Image = nullptr;
}

void GameObject::setSpawnX(float x) {
	spawnX = x;
}

void GameObject::setSpawnY(float y) {
	spawnY = y;
}