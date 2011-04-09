#ifndef CYBER_ANIMATION_H_
#define CYBER_ANIMATION_H_

#include <SDL.h>

class CyberAnimation{
private:
	int currentFrame;
	int frameInc;
	int frameRate;
	long oldTime;

public:
	int maxFrames;
	bool oscillate;


	CyberAnimation();

	void onAnimate();
	void setFrameRate(int rate);
	void setCurrentFrame(int frame);
	int getCurrentFrame();
};

#endif