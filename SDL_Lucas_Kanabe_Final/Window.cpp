#include "Window.h"
#include <SDL_image.h>
#include <iostream>

Window::Window() {

}

Window::Window(const std::string &title) : _title(title) {
	_closed = !init();
}

Window::~Window() {
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	IMG_Quit();
	SDL_Quit();
}

bool Window::init() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cerr << "Failed to initialize SDL.\n";
		return false;
	}

	if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG) {
		std::cerr << "Failed to initialize SDL_image.\n";
		return false;
	}

	_window = SDL_CreateWindow(_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

	if (_window == nullptr) {
		std::cerr << "Failed to create window.\n";
		return false;
	}

	_renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);

	if (_renderer == nullptr) {
		std::cerr << "Failed to create renderer.\n";
		return false;
	}

	return true;
}

void Window::clear() const {
	SDL_RenderPresent(_renderer);
	SDL_SetRenderDrawColor(_renderer, 10, 10, 10, 255);
	SDL_RenderClear(_renderer);
}