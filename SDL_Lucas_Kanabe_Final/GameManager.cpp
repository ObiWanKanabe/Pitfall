#include <iostream>
#include "GameManager.h"
#include "Timer.h"
#include "Level.h"
#include "Level1.h"
#include "InputManager.h"

GameManager::GameManager() {
	Init();
}

GameManager::~GameManager() {
	// delete currentLevel;
	delete menu;
	delete event;
	delete window;

	// currentLevel = nullptr;
	menu = nullptr;
	event = nullptr;
	window = nullptr;
}

void GameManager::Init() {
	window = new Window("SDL_Game");
	currentLevel = new Level1(*window);
	menu = new Menu(*window);
	State = MainMenu;
}

void GameManager::Run() {
	// Start timer to be used for Physics in game
	Timer timer;
	timer.Start();
	// Main Game Loop
	while (isRunning) {
		timer.UpdateFrameTicks();
		Update(timer.GetDeltaTime());
		// Set FPS to 120, not unreasonably fast
		SDL_Delay(timer.GetSleepTime(FPS));
	}
}

void GameManager::Update(const float deltaTime) {
	// Creation of SDL Even to be used for input
	SDL_Event event;

	// State Machine used to switch between Game Screens.
	// Each contains their own Update and Draw, just call their Update
	// Input handling done by GameManager and InputManager
	switch (State) {
	case MainMenu:
		menu->UpdateMain(deltaTime);
		inputMainMenu(event);
		window->clear();
		break;
	case HelpMenu:
		menu->UpdateHelp(deltaTime);
		inputHelpMenu(event);
		window->clear();
		break;
	case Running:
		currentLevel->Update(deltaTime);
		inputRunning(event);
		window->clear();
		// This would be used later for the switching to other levels
		// Just making a new Level1 so you can keep playing every time
		if (currentLevel->levelComplete()) {
			State = GameWon;
			currentLevel = new Level1(*window);
		}
		break;
	case Paused:
		menu->UpdatePaused(deltaTime);
		inputPaused(event);
		window->clear();
		break;
	case GameWon:
		menu->UpdateWin(deltaTime);
		inputWinScreen(event);
		window->clear();
		break;
	}
}

void GameManager::inputMainMenu(SDL_Event &event) {
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			// X marks the corner of the window
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_ESCAPE:
				isRunning = false;
				break;
			default:
				break;
			}
			// UI Button Input, helping save space with Input Manager
		case SDL_MOUSEBUTTONDOWN:
			if (InputManager::UIButton(menu->playButton, event)) {
				std::cout << "You clicked Play!\n";
				State = Running;
			}
			if (InputManager::UIButton(menu->helpButton, event)) {
				std::cout << "You clicked Help!\n";
				State = HelpMenu;
			}
			if (InputManager::UIButton(menu->quitButton, event)) {
				std::cout << "You clicked Quit!\n";
				isRunning = false;
			}
		default:
			break;
		}
	}
}

void GameManager::inputHelpMenu(SDL_Event &event) {
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			// X marks the corner of the window
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
				// This changes based on the Current Screen
			case SDLK_ESCAPE:
				State = MainMenu;
				break;
			default:
				break;
			}
			// UI Button Input, helping save space with Input Manager
		case SDL_MOUSEBUTTONDOWN:
			if (InputManager::UIButton(menu->menuButton, event)) {
				std::cout << "You clicked Return to Menu!\n";
				State = MainMenu;
			}
		default:
			break;
		}
	}
}

void GameManager::inputRunning(SDL_Event &event) {
	while (SDL_PollEvent(&event)) {

		// Discovered KeyEvents would not translate well to gameplay
		// Switched to KeyboardState for much better results
		const Uint8 *state = SDL_GetKeyboardState(nullptr);

		// Arrow Key Movement
		if (state[SDL_SCANCODE_RIGHT])
			currentLevel->player->moveRight();
		if (state[SDL_SCANCODE_LEFT])
			currentLevel->player->moveLeft();
		if (!state[SDL_SCANCODE_RIGHT])
			currentLevel->player->stopMovingRight();
		if (!state[SDL_SCANCODE_LEFT])
			currentLevel->player->stopMovingLeft();

		switch (event.type) {
			// X marks the corner of the window
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_WINDOWEVENT:
			currentLevel->player->stopMovement();
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
				// This changes based on the Current Screen
			case SDLK_ESCAPE:
				State = Paused;
				break;
				// Jump for the player
			case SDLK_UP:
				currentLevel->player->jump();
				break;
			default:
				break;
			}
		}
	}
}

void GameManager::inputPaused(SDL_Event &event) {
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			// X marks the corner of the window
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
				// This changes based on the Current Screen
			case SDLK_ESCAPE:
				State = Running;
				break;
			default:
				break;
			}
			// UI Button Input, helping save space with Input Manager
		case SDL_MOUSEBUTTONDOWN:
			if (InputManager::UIButton(menu->resumeButton, event)) {
				std::cout << "You clicked Return to Game!\n";
				State = Running;
			}
			if (InputManager::UIButton(menu->menuButton, event)) {
				std::cout << "You clicked Return to Menu!\n";
				State = MainMenu;
			}
		default:
			break;
		}
	}
}

void GameManager::inputWinScreen(SDL_Event &event) {
	while (SDL_PollEvent(&event)) {
		switch (event.type) {
			// X marks the corner of the window
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
				// This changes based on the Current Screen
			case SDLK_ESCAPE:
				State = MainMenu;
				break;
			default:
				break;
			}

			// UI Button Input, helping save space with Input Manager
		case SDL_MOUSEBUTTONDOWN:
			if (InputManager::UIButton(menu->menuButton, event)) {
				std::cout << "You clicked Return to Menu!\n";
				State = MainMenu;
			}
		default:
			break;
		}
	}
}