/*
 * cyber_onloop.cpp
 *
 *  Created on: 2/04/2011
 *      Author: james
 */

#include "cyber_bots.h"

void Cyber::onLoop(){

	for (int i = 0; i < CyberEntity::entityList.size(); i++){
		if (!CyberEntity::entityList(i)) continue;

		CyberEntity::entityList(i)->onLoop();
	}
}
