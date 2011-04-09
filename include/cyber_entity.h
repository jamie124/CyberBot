//#pragma once

#include <vector>

#include "cyber_animation.h"
#include "cyber_surface.h"

class CyberSurface;

class CyberEntity{
public:
	static std::vector<CyberEntity*> entityList;

private:
	CyberSurface*	cyberSurface;

protected:
	CyberAnimation	animationControl;
	SDL_Surface*	entitySurf;

public:
	float			x;
	float			y;
	int				width;
	int				height;
	int				animationState;

	CyberEntity(CyberSurface* cyberSurface);
	virtual ~CyberEntity();

	virtual bool onLoad(char* file, int width, int height, int maxFrames);
	virtual void onLoop();
	virtual void onRender(SDL_Surface* displaySurf);
	virtual void onCleanup();
};
