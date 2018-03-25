#include "Animation.h"
#include "GameManager.h"

Animation::Animation() {
	Clear();
}

Animation::~Animation() {

}

// Animate the GameObject, Speed = # of images / second
void Animation::Animate(GameObject &go, int speed) {
	if (sizeStep == 12 || image_paths[sizeStep] == "0")
		sizeStep = 0;

	animStep++;
	if (animStep == FPS / speed) {
		go.Image->Load(image_paths[sizeStep]);
		animStep = 0;
		sizeStep++;
	}
}

// Load An Image into the animation, and give it's index in the array, There is a max of 12 frames per animation
void Animation::Load(const std::string &image_path, int i) {
	image_paths[i] = image_path;
}

// Clear the Animation Array for new images
void Animation::Clear() {
	for (int i = 0; i < 12; i++) {
		image_paths[i] = "0";
	}
}