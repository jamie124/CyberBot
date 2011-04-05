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

class CyberSurface{
	
private: 
	typedef std::map<std::string, SDL_Surface*> *Surfaces;
	//typedef std::pair<std::string, SDL_Surface*> SurfacePair;
//	Surfaces surfaces;
	//std::map<std::string, SDL_Surface*> *surfaces;
		
	Surfaces surfaces;
public:
	CyberSurface();

	SDL_Surface * onLoad(char* file);
	bool onDraw(SDL_Surface* destSurf, SDL_Surface* srcSurf, int x, int y);

	static bool transparent(SDL_Surface* surfDest, int r, int g, int b);

	bool addSurface(std::string, SDL_Surface*);
	SDL_Surface* getSurface(std::string);

	//int test;
};

#endif /* CYBER_SURFACE_H_ */
