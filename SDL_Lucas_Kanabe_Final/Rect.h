#ifndef RECT_H
#define RECT_H

#include "Window.h"

class Rect : public Window {
public:
	Rect(const Window &window, float x, float y, float w, float h, int r, int g, int b, int a, bool isFlipped);
	Rect(const Window &window, float x, float y, float w, float h, const std::string &image_path, bool isFlipped);
	~Rect();

	void draw() const;
	void Load(const std::string &image_path);

	inline float getX() { return _x; };
	inline float getY() { return _y; };
	inline float getWidth() { return _w; };
	inline float getHeight() { return _h; };

	// Flips the Image or puts it to Original
	inline void flip() { _isFlipped = true; }
	inline void reset() { _isFlipped = false; };
	
	void setX(float x);
	void setY(float y);

private:
	float _x, _y;
	float _w, _h;
	int _r, _g, _b, _a;
	bool _isFlipped;
	SDL_Texture *_texture = nullptr;
};

#endif