#ifndef CYBER_ANIMATION_H_
#define CYBER_ANIMATION_H_

#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL/SDL.h>
#endif

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
