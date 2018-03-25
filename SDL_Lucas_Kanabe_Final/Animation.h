#ifndef ANIMATION_H
#define ANIMATION_H

#include "GameObject.h"

// This animation class is very crude, and not something I would particularily use for a high end game,
// But it works just fine for simple animations of a character and a few enemies. Other methods would invlove 
// remaking the "Rect" Class to deal with one sprite sheet versus many sprite images, but I didn't have the time. 

class Animation {
public:
	Animation();
	~Animation();
	void Animate(GameObject &go, int speed);
	void Load(const std::string &image_path, int i);
	void Clear();

private:
	// Array to store the paths for the images
	std::string image_paths[12];

	// Steps to increment and check during the animation
	int animStep;
	int sizeStep;
};

#endif