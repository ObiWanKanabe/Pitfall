#include "Level1.h"
#include "Physics.h"
#include <iostream>

Level1::Level1(class Window& window) : Level(window) {
	// Instantiating all Objects in constructor
	// SDL means I had to put everythings positions and size, manually...
	hasWon = false;

	player = new Player(window, 50.0f, 750.0f, 25.0f, 35.0f, "res/stickMan1white.png", false);
	player->setSpawnX(50.0f);
	player->setSpawnY(750.0f);

	Portal = new GameObject(window, 875.0f, 500.0f, 50.0f, 50.0f, "res/portal.png" , false);

	Map[0] = new GameObject(window, 100.0f, 0.0f, 50.0f, 50.0f, r, g, b, 0, false);
	Map[1] = new GameObject(window, 450.0f, 0.0f, 50.0f, 50.0f, r, g, b, 0, false);
	Map[2] = new GameObject(window, 700.0f, 0.0f, 50.0f, 50.0f, r, g, b, 0, false);
	Map[3] = new GameObject(window, 200.0f, 100.0f, 50.0f, 150.0f, r, g, b, 0, false);
	Map[4] = new GameObject(window, 550.0f, 100.0f, 100.0f, 25.0f, r, g, b, 0, false);
	Map[5] = new GameObject(window, 800.0f, 100.0f, 100.0f, 25.0f, r, g, b, 0, false);
	Map[7] = new GameObject(window, 150.0f, 150.0f, 50.0f, 300.0f, r, g, b, 0, false);
	Map[8] = new GameObject(window, 300.0f, 150.0f, 50.0f, 50.0f, r, g, b, 0, false);
	Map[9] = new GameObject(window, 450.0f, 150.0f, 50.0f, 50.0f, r, g, b, 0, false);
	Map[10] = new GameObject(window, 950.0f, 150.0f, 75.0f, 450.0f, r, g, b, 0, false);
	Map[11] = new GameObject(window, 250.0f, 200.0f, 700.0f, 50.0f, r, g, b, 0, false);
	Map[12] = new GameObject(window, 0.0f, 250.0f, 50.0f, 25.0f, r, g, b, 0, false);
	Map[13] = new GameObject(window, 500.0f, 250.0f, 150.0f, 50.0f, r, g, b, 0, false);
	Map[15] = new GameObject(window, 100.0f, 350.0f, 150.0f, 50.0f, r, g, b, 0, false);
	Map[16] = new GameObject(window, 700.0f, 375.0f, 50.0f, 25.0f, r, g, b, 0, false);
	Map[17] = new GameObject(window, 800.0f, 360.0f, 50.0f, 200.0f, r, g, b, 0, false);
	Map[19] = new GameObject(window, 350.0f, 400.0f, 100.0f, 25.0f, r, g, b, 0, false);
	Map[20] = new GameObject(window, 0.0f, 450.0f, 50.0f, 25.0f, r, g, b, 0, false);
	Map[21] = new GameObject(window, 500.0f, 450.0f, 150.0f, 100.0f, r, g, b, 0, false);
	Map[22] = new GameObject(window, 250.0f, 485.0f, 50.0f, 65.0f, r, g, b, 0, false);
	Map[24] = new GameObject(window, 0.0f, 550.0f, 950.0f, 50.0f, r, g, b, 0, false);
	Map[25] = new GameObject(window, 600.0f, 600.0f, 50.0f, 125.0f, r, g, b, 0, false);
	Map[26] = new GameObject(window, 975.0f, 575.0f, 50.0f, 150.0f, r, g, b, 0, false);
	Map[28] = new GameObject(window, 400.0f, 700.0f, 50.0f, 100.0f, r, g, b, 0, false);
	Map[29] = new GameObject(window, 800.0f, 700.0f, 100.0f, 200.0f, r, g, b, 0, false);
	Map[30] = new GameObject(window, 0.0f, 800.0f, 200.0f, 100.0f, r, g, b, 0, false);
	Map[31] = new GameObject(window, 300.0f, 800.0f, 250.0f, 100.0f, r, g, b, 0, false);
	Map[32] = new GameObject(window, 700.0f, 800.0f, 100.0f, 100.0f, r, g, b, 0, false);
	Map[6] = new GameObject(window, 1150.0f, 200.0f, 50.0f, 25.0f, r, g, b, 0, false);
	Map[14] = new GameObject(window, 1025.0f, 275.0f, 50.0f, 25.0f, r, g, b, 0, false);
	Map[18] = new GameObject(window, 1150.0f, 350.0f, 50.0f, 25.0f, r, g, b, 0, false);
	Map[23] = new GameObject(window, 1150.0f, 500.0f, 50.0f, 25.0f, r, g, b, 0, false);
	Map[33] = new GameObject(window, 1025.0f, 800.0f, 175.0f, 100.0f, r, g, b, 0, false);
	Map[27] = new GameObject(window, 1150.0f, 650.0f, 50.0f, 25.0f, r, g, b, 0, false);
	Map[36] = new GameObject(window, 1025.0f, 700.0f, 50.0f, 25.0f, r, g, b, 0, false);
	Map[34] = new GameObject(window, 1025.0f, 425.0f, 50.0f, 25.0f, r, g, b, 0, false);
	Map[35] = new GameObject(window, 1025.0f, 575.0f, 50.0f, 25.0f, r, g, b, 0, false);

	Lava[0] = new GameObject(window, 425.0f, 0.0f, 25.0f, 50.0f, 200, 0, 0, 0, false);
	Lava[1] = new GameObject(window, 500.0f, 0.0f, 25.0f, 50.0f, 200, 0, 0, 0, false);
	Lava[2] = new GameObject(window, 675.0f, 0.0f, 25.0f, 50.0f, 200, 0, 0, 0, false);
	Lava[3] = new GameObject(window, 750.0f, 0.0f, 25.0f, 50.0f, 200, 0, 0, 0, false);
	Lava[4] = new GameObject(window, 100.0f, 50.0f, 50.0f, 25.0f, 200, 0, 0, 0, false);
	Lava[5] = new GameObject(window, 250.0f, 175.0f, 50.0f, 25.0f, 200, 0, 0, 0, false);
	Lava[6] = new GameObject(window, 350.0f, 175.0f, 100.0f, 25.0f, 200, 0, 0, 0, false);
	Lava[7] = new GameObject(window, 500.0f, 175.0f, 450.0f, 25.0f, 200, 0, 0, 0, false);
	Lava[8] = new GameObject(window, 125.0f, 200.0f, 25.0f, 150.0f, 200, 0, 0, 0, false);
	Lava[9] = new GameObject(window, 500.0f, 300.0f, 150.0f, 25.0f, 200, 0, 0, 0, false);
	Lava[10] = new GameObject(window, 800.0f, 335.0f, 50.0f, 25.0f, 200, 0, 0, 0, false);
	Lava[11] = new GameObject(window, 850.0f, 360.0f, 25.0f, 190.0f, 200, 0, 0, 0, false);
	Lava[12] = new GameObject(window, 925.0f, 360.0f, 25.0f, 190.0f, 200, 0, 0, 0, false);
	Lava[13] = new GameObject(window, 200.0f, 400.0f, 50.0f, 25.0f, 200, 0, 0, 0, false);
	Lava[14] = new GameObject(window, 325.0f, 400.0f, 25.0f, 25.0f, 200, 0, 0, 0, false);
	Lava[15] = new GameObject(window, 1175.0f, 375.0f, 25.0f, 125.0f, 200, 0, 0, 0, false);
	Lava[16] = new GameObject(window, 0.0f, 525.0f, 100.0f, 25.0f, 200, 0, 0, 0, false);
	Lava[17] = new GameObject(window, 300.0f, 525.0f, 200.0f, 25.0f, 200, 0, 0, 0, false);
	Lava[18] = new GameObject(window, 650.0f, 525.0f, 150.0f, 25.0f, 200, 0, 0, 0, false);
	Lava[19] = new GameObject(window, 1175.0f, 525.0f, 25.0f, 125.0f, 200, 0, 0, 0, false);
	Lava[20] = new GameObject(window, 1150.0f, 775.0f, 50.0f, 25.0f, 200, 0, 0, 0, false);
	Lava[21] = new GameObject(window, 200.0f, 850.0f, 100.0f, 50.0f, 200, 0, 0, 0, false);
	Lava[22] = new GameObject(window, 550.0f, 850.0f, 150.0f, 50.0f, 200, 0, 0, 0, false);
	Lava[23] = new GameObject(window, 900.0f, 850.0f, 200.0f, 50.0f, 200, 0, 0, 0, false);
	Lava[24] = new GameObject(window, 450.0f, 400.0f, 25.0f, 25.0f, 200, 0, 0, 0, false);
	Lava[25] = new GameObject(window, 1175.0f, 225.0f, 25.0f, 125.0f, 200, 0, 0, 0, false);
	Lava[26] = new GameObject(window, 0.0f, 0.0f, 25.0f, 250.0f, 200, 0, 0, 0, false);
	Lava[27] = new GameObject(window, 1025.0f, 300.0f, 25.0f, 125.0f, 200, 0, 0, 0, false);
	Lava[28] = new GameObject(window, 1025.0f, 450.0f, 25.0f, 125.0f, 200, 0, 0, 0, false);
	Lava[29] = new GameObject(window, 1025.0f, 600.0f, 25.0f, 100.0f, 200, 0, 0, 0, false);
	
}

Level1::~Level1() {
	delete Map[37];
	delete Lava[30];
	delete player;
	delete Portal;

	Map[37] = nullptr;
	Lava[30] = nullptr;
	player = nullptr;
	Portal = nullptr;
}

void Level1::Init() {
	
}

// General Update function, mostly used for physics and Game World elements 
void Level1::Update(const float deltaTime) {
	Physics::updatePhysics(*player, deltaTime);

	for (int i = 0; i < 37; i++) {
		Physics::Collide(*player, *Map[i]);
	}

	for (int i = 0; i < 30; i++) {
		Physics::Collide(*player, *Lava[i]);
		Physics::lavaCheck(*player, *Lava[i]);

	}

	if (Physics::isColliding(*player, *Portal))
		hasWon = true;

	drawUpdate();
}

// Draw at the end, so everything is resolved before showing the player
void Level1::drawUpdate() {
	for (int i = 0; i < 37; i++) {
		Map[i]->Image->draw();
	}

	for (int i = 0; i < 30; i++) {
		Lava[i]->Image->draw();
	}

	Portal->Image->draw();
	player->Animate();
	player->Image->draw();
}

// Simpel function to return when the level is complete
bool Level1::levelComplete() {
	return hasWon;	
}