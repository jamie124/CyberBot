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

	if ((displaySurf = SDL_SetVideoMode(WWIDTH, WHEIGHT, 32,
			SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL) {
		return false;
	}

	if (cyberArea->onLoad("maps/1.area") == false){
		return false;
	}

	SDL_EnableKeyRepeat(1, SDL_DEFAULT_REPEAT_INTERVAL / 3);
	/*
	 if (yoshiEntity->onLoad("images/yoshi.png", 64, 64, 8) == false)
	 return false;

	 CyberEntity::entityList.push_back(yoshiEntity);

	 if (yoshiEntity2->onLoad("images/yoshi.png", 64, 64, 8) == false)
	 return false;


	 yoshiEntity2->x = 100;

	 CyberEntity::entityList.push_back(yoshiEntity2);
	 */

	/*
	 if (cyberSurface->onLoad("images/grid.png") == false)
	 return false;

	 if (cyberSurface->onLoad("images/yoshi.png") == false)
	 return false;

	 yoshiAnimation = new CyberAnimation;
	 yoshiAnimation->maxFrames = 8;
	 yoshiAnimation->oscillate = true;
	 */

	/*
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
	 */

	reset();

	return true;
}
