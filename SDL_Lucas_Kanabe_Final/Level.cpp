
#include "Level.h"

Level::Level(Window& window) : windowPtr(&window) {
	hasWon = false;
}

Level::~Level() {
	delete player;

	player = nullptr;
}

void Level::Init() {

}

void Level::Update(const float deltaTime) {

}

void Level::drawUpdate() {

}