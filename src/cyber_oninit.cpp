/*
 * Cyber_OnInit.cpp
 *
 *  Created on: 2/04/2011
 *      Author: james
 */

#include "cyber_bots.h"

bool Cyber::onInit() {

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return false;

	if ((surfDisplay = SDL_SetVideoMode(600, 600, 32,
			SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
		return false;
	}

	if (cyberSurface->onLoad("images/grid.png") == false)
		return false;
	
	if (cyberSurface->onLoad("images/yoshi.png") == false)
		return false;

	yoshiAnimation = new CyberAnimation;
	yoshiAnimation->maxFrames = 8;
	yoshiAnimation->oscillate = true;

	if (cyberSurface->onLoad("images/bot.png") == false)
		return false;

	if (cyberSurface->onLoad("images/x.png") == false)
		return false;

	if (cyberSurface->onLoad("images/o.png") == false)
		return false;

	if (cyberSurface->onLoad("images/x_won.png") == false)
		return false;

	if (cyberSurface->onLoad("images/o_won.png") == false)
		return false;

		
	//CyberSurface::transparent(surfO, 255, 0, 255);
	//CyberSurface::transparent(surfX, 255, 0, 255);

	//CyberSurface::transparent(surfXWon, 255, 0, 255);
	//CyberSurface::transparent(surfOWon, 255, 0, 255);


	reset();

	return true;
}
