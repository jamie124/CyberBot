/*
 * cyber_oncleanup.cpp
 *
 *  Created on: 2/04/2011
 *      Author: james
 */

#include "cyber_bots.h"

void Cyber::onCleanup(){
	SDL_FreeSurface(surfDisplay);


	SDL_Quit();
}
