/*
 * cyber_onevent.cpp
 *
 *  Created on: 2/04/2011
 *      Author: james
 */

#include "cyber_bots.h"

void Cyber::onEvent(SDL_Event * event) {
	CyberEvent::onEvent(event);
}

void Cyber::onLButtonDown(int mX, int mY) {
	int horizontal = mX / 200;
	int verticle = mY / 200;

	if (grid[horizontal][verticle]  != GRID_TYPE_NONE){
		return;
	}

	if (currentPlayer == 0){
		setCell(horizontal, verticle, GRID_TYPE_X);
		currentPlayer = 1;
	} else {
		setCell(horizontal, verticle, GRID_TYPE_O);
		currentPlayer = 0;
	}

	checkForWinner(true);

}

void Cyber::onExit() {
	running = false;
}
