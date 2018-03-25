#include "Menu.h"

Menu::Menu(Window& window) : windowPtr(&window) {
	// Set positions for UI elements
	bgMain = new Rect(window, 0.0f, 0.0f, 1200.0f, 900.0f, "res/mainMenu.png", false);
	bgHelp = new Rect(window, 0.0f, 0.0f, 1200.0f, 900.0f, "res/helpMenu.png", false);
	bgPaused = new Rect(window, 0.0f, 0.0f, 1200.0f, 900.0f, "res/pauseMenu.png", false);
	bgWin = new Rect(window, 0.0f, 0.0f, 1200.0f, 900.0f, "res/winScreen.png", false);
	playButton = new Rect(window, 200.0f, 300.0f, 265.0f, 200.0f,  "res/playButton.png", false);
	helpButton = new Rect(window, 715.0f, 300.0f, 265.0f, 200.0f, "res/helpButton.png", false);
	quitButton = new Rect(window, 465.0f, 650.0f, 265.0f, 200.0f, "res/quitButton.png", false);
	resumeButton = new Rect(window, 250.0f, 650.0f, 265.0f, 200.0f, "res/resumeButton.png", false);
	menuButton = new Rect(window, 825.0f, 600.0f, 265.0f, 200.0f,  "res/menuButton.png", false);
}

Menu::~Menu() {
	delete bgMain;
	delete bgHelp;
	delete bgPaused;
	delete bgWin;
	delete playButton;
	delete helpButton;
	delete quitButton;
	delete resumeButton;
	delete menuButton;

	bgMain = nullptr;
	bgHelp = nullptr;
	bgPaused = nullptr;
	bgWin = nullptr;
	playButton = nullptr;
	helpButton = nullptr;
	quitButton = nullptr;
	resumeButton = nullptr;
	menuButton = nullptr;
}

void Menu::UpdateMain(const float deltaTime) {
	drawUpdateMain();
}

void Menu::drawUpdateMain() {
	bgMain->draw();
	quitButton->setX(465.0f);
	quitButton->setY(650.0f);
	playButton->draw();
	helpButton->draw();
	quitButton->draw();
}

void Menu::UpdateHelp(const float deltaTime) {
	drawUpdateHelp();
}

void Menu::drawUpdateHelp() {
	bgHelp->draw();
	menuButton->setX(825.0f);
	menuButton->setY(600.0f);
	menuButton->draw();
}

void Menu::UpdatePaused(const float deltaTime) {
	drawUpdatePaused();
}

void Menu::drawUpdatePaused() {
	bgPaused->draw();
	menuButton->setX(715.0f);
	menuButton->setY(650.0f);
	resumeButton->draw();
	menuButton->draw();


}

void Menu::UpdateWin(const float deltaTime) {
	drawUpdateWin();
}

void Menu::drawUpdateWin() {
	bgWin->draw();
	menuButton->setX(465);
	menuButton->setY(650);
	menuButton->draw();
}