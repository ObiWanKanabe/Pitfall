#ifndef WINDOW_H
#define WINDOW_H

#include <string>
#include <SDL.h>

#define SCREEN_WIDTH 1200.0f
#define SCREEN_HEIGHT 900.0f
#define FPS 120

class Window {
	friend class Input;
public:
	Window();
	Window(const std::string &title);
	~Window();
	
	void clear() const;

	inline bool isClosed() const { return _closed; }

private:
	bool init();

private:
	std::string _title;

	bool _closed = false;

	SDL_Window *_window = nullptr;

protected:
	SDL_Renderer *_renderer = nullptr;
};

#endif