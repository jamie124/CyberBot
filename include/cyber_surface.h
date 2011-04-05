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


class CyberSurface{
public:
	CyberSurface();

	static SDL_Surface * onLoad(char* file);
	static bool onDraw(SDL_Surface* destSurf, SDL_Surface* srcSurf, int x, int y);

	static bool transparent(SDL_Surface* surfDest, int r, int g, int b);

};

#endif /* CYBER_SURFACE_H_ */
