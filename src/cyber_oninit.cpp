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

	if ((surfGrid = CyberSurface::onLoad("images/grid.png")) == NULL)
		return false;

	if ((surfX = CyberSurface::onLoad("images/x.png")) == NULL)
		return false;

	if ((surfO = CyberSurface::onLoad("images/o.png")) == NULL)
		return false;

	if ((surfXWon = CyberSurface::onLoad("images/x_won.png")) == NULL)
		return false;

	if ((surfOWon = CyberSurface::onLoad("images/o_won.png")) == NULL)
		return false;

	CyberSurface::transparent(surfO, 255, 0, 255);
	CyberSurface::transparent(surfX, 255, 0, 255);

	CyberSurface::transparent(surfXWon, 255, 0, 255);
	CyberSurface::transparent(surfOWon, 255, 0, 255);


	reset();

	return true;
}
