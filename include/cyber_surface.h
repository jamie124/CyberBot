#pragma once
/*
 * cyber_surface.h
 *
 *  Created on: 2/04/2011
 *      Author: james
 */

#ifndef CYBER_SURFACE_H_
#define CYBER_SURFACE_H_

#ifdef _WIN32
#include <SDL.h>
#include <SDL_image.h>
#else
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#endif

#include <string>
#include <map>
#include <iterator>

#include "cyber_bots.h"
#include "cyber_logger.h"

//class CyberLogger;

class CyberSurface {

private:
	typedef std::map<std::string, SDL_Surface*> *Surfaces;

	Surfaces surfaces;

	CyberLogger* cyberLogger;
public:
	CyberSurface(void);
	CyberSurface(CyberLogger*);
	~CyberSurface(void);

	SDL_Surface * onLoad(char* file);
	bool onDraw(SDL_Surface* destSurf, SDL_Surface* srcSurf, int x, int y);
	bool onDraw(SDL_Surface* destSurf, SDL_Surface* srcSurf, int x, int y,
			int x2, int y2, int w, int h);

	static bool transparent(SDL_Surface* surfDest, int r, int g, int b);

	bool addSurface(std::string, SDL_Surface*);
	SDL_Surface* getSurface(std::string);

	CyberLogger* getLogger();
};

#endif /* CYBER_SURFACE_H_ */
