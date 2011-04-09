#include "cyber_entity.h"

std::vector<CyberEntity*>CyberEntity::entityList;

CyberEntity::CyberEntity(CyberSurface* surface){
	cyberSurface = surface;
	entitySurf = NULL;
	x = y = 0.0f;
	width = height = 0;
	animationState = 0;
}

CyberEntity::~CyberEntity(){
}

bool CyberEntity::onLoad(char* file, int width, int height, int maxFrames){
	if ((entitySurf = cyberSurface->onLoad(file)) == NULL){
		return false;
	}

	this->width = width;
	this->height = height;
	animationControl.maxFrames = maxFrames;

	return true;
}

void CyberEntity::onLoop(){
	animationControl.onAnimate();
}

void CyberEntity::onRender(SDL_Surface* displaySurf){
	if (entitySurf == NULL || displaySurf == NULL) return;

	cyberSurface->onDraw(displaySurf, entitySurf, x, y, animationState * width, animationControl.getCurrentFrame() * height, width, height);
}

void CyberEntity::onCleanup(){
	if (entitySurf){
		SDL_FreeSurface(entitySurf);
	}

	entitySurf = NULL;
}
