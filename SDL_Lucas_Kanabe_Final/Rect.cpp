#include "rect.h"
#include <SDL_image.h>
#include <iostream>

Rect::Rect(const Window &window, float x, float y, float w, float h, int r, int g, int b, int a, bool isFlipped) : Window(window), _x(x), _y(y), _w(w), _h(h), _r(r), _g(g), _b(b), _a(a), _isFlipped(isFlipped) {

}

// Create the surface for the texture
Rect::Rect(const Window &window, float x, float y, float w, float h, const std::string &image_path, bool isFlipped) : Window(window), _x(x), _y(y), _w(w), _h(h), _isFlipped(isFlipped) {
	auto surface = IMG_Load(image_path.c_str());
	if (!surface) {
		std::cerr << "Failed to create surface. \n";
	}
	_texture = SDL_CreateTextureFromSurface(_renderer, surface);
	if (!_texture) {
		std::cerr << "Failed to create texture.\n";
	}
	SDL_FreeSurface(surface);
}

Rect::~Rect() {
	SDL_DestroyTexture(_texture);
	_texture = nullptr;
}

// This is for changing the image but not the positon, good for my crude animation
void Rect::Load(const std::string &image_path) {
	auto surface = IMG_Load(image_path.c_str());
	if (!surface) {
		std::cerr << "Failed to create surface. \n";
	}
	_texture = SDL_CreateTextureFromSurface(_renderer, surface);
	if (!_texture) {
		std::cerr << "Failed to create texture.\n";
	}
	SDL_FreeSurface(surface);
}

// Draw the Rect in the screen
void Rect::draw() const {
	SDL_Rect rect = { int(_x), int(_y), int(_w), int(_h) };
	if (_texture && !_isFlipped) {
		SDL_RenderCopyEx(_renderer, _texture, nullptr, &rect, 0, nullptr, SDL_FLIP_NONE);
	}
	else if (_texture && _isFlipped) {
		SDL_RenderCopyEx(_renderer, _texture, nullptr, &rect, 0, nullptr, SDL_FLIP_HORIZONTAL);
	}
	else {
		SDL_SetRenderDrawColor(_renderer, _r, _g, _b, _a);
		SDL_RenderFillRect(_renderer, &rect);
	}
}

// Since I'm using the rects X and Y for physics, this is needed, along with getters in .H file
void Rect::setX(float x){
	_x = x;
}

void Rect::setY(float y){
	_y = y;
}