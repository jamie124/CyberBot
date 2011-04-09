/*
 * cyber_oncleanup.cpp
 *
 *  Created on: 2/04/2011
 *      Author: james
 */

#include "cyber_bots.h"

void Cyber::onCleanup(){
	SDL_FreeSurface(displaySurf);

	for (int i = 0; i < CyberEntity::entityList.size(); i++){
		if (!CyberEntity::entityList[i]) continue;

		CyberEntity::entityList[i]->onCleanup();
	}

	CyberEntity::entityList.clear();

	cyberArea->onCleanup();

	SDL_Quit();
}
