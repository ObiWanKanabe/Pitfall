#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Window.h"
#include "Menu.h"
#include "Level.h"
#include "Rect.h"


class GameManager {
	friend class Input;
public:
	GameManager();
	~GameManager();
	void Init();
	void Run();
	void Update(const float deltaTime);

	// Game State to help us switch screens
	enum GameState { MainMenu, HelpMenu, Running, Paused, GameWon };
	GameState State;

private:
	Menu *menu;
	Level *currentLevel;
	Window *window;
	SDL_Event *event;
	bool isRunning = true;

public:
	void inputMainMenu(SDL_Event &event);
	void inputHelpMenu(SDL_Event &event);
	void inputPaused(SDL_Event &event);
	void inputWinScreen(SDL_Event &event);
	void inputRunning(SDL_Event &event);
};

#endif