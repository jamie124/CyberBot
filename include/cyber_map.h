#ifndef CYBER_MAP_H_
#define CYBER_MAP_H_

#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL/SDL.h>
#endif

#include <vector>

#include "cyber_tile.h"
#include "cyber_surface.h"
#include "define.h"

class CyberSurface;

class CyberMap {
private:
	std::vector<CyberTile> tileList;

	CyberSurface* cyberSurface;

public:
	SDL_Surface* tilesetSurf;

	CyberMap(CyberSurface* surface);

	bool onLoad(char* file);
	void onRender(SDL_Surface* displaySurf, int mapX, int mapY);

};

#endif
