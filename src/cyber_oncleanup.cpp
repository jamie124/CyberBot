/*
 * cyber_oncleanup.cpp
 *
 *  Created on: 2/04/2011
 *      Author: james
 */

#include "cyber_bots.h"

void Cyber::onCleanup(){
	SDL_FreeSurface(surfGrid);
	SDL_FreeSurface(surfX);
	SDL_FreeSurface(surfO);
	SDL_FreeSurface(surfXWon);
	SDL_FreeSurface(surfOWon);

	SDL_FreeSurface(surfDisplay);
	SDL_Quit();
}
