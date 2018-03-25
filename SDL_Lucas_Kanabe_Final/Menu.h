#ifndef MENU_H
#define MENU_H

#include "rect.h"

class Menu {
	friend class GameManager;
public:
	Menu(Window& window);
	~Menu();
	virtual void UpdateMain(const float deltaTime);
	virtual void UpdateHelp(const float deltaTime);
	virtual void UpdatePaused(const float deltaTime);
	virtual void UpdateWin(const float deltaTime);
	
	virtual void drawUpdateMain();
	virtual void drawUpdateHelp();
	virtual void drawUpdatePaused();
	virtual void drawUpdateWin();

private:
	// All UI Elements, background and buttons
	Rect *bgMain;
	Rect *bgHelp;
	Rect *bgPaused;
	Rect *bgWin;
	Rect *playButton;
	Rect *helpButton;
	Rect *quitButton;
	Rect *resumeButton;
	Rect *menuButton;
	Window* windowPtr;

	bool _isClosed = false;

};
#endif