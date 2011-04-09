//============================================================================
// Name        : cyber_animation.cpp
// Author      : James Whitwell
// Copyright   : 2011 James Whitwell
// Description : Handles Cyber Bots animation logic
//============================================================================


#include "cyber_animation.h"

CyberAnimation::CyberAnimation(){
	currentFrame	= 0;
	maxFrames		= 0;
	frameInc		= 1;
	frameRate		= 100; // Milliseconds;
	oldTime			= 0;
	oscillate		= false;
}

void CyberAnimation::onAnimate(){
	if (oldTime + frameRate > SDL_GetTicks()){
		return;
	}

	oldTime = SDL_GetTicks();

	currentFrame += frameInc;

	if (oscillate){
		if (frameInc > 0){
			if (currentFrame >= maxFrames - 1){
				frameInc = -frameInc;
			}
		} else {
			if (currentFrame <= 0){
				frameInc = -frameInc;
			}
		}
	} else {
		if (currentFrame >= maxFrames -1){
			currentFrame = 0;
		}
	}
}

void CyberAnimation::setFrameRate(int rate){
	frameRate = rate;
}

void CyberAnimation::setCurrentFrame(int frame){
	if(frame < 0 || frame >= maxFrames) return;

	currentFrame = frame;
}

int CyberAnimation::getCurrentFrame(){
	return currentFrame;
}