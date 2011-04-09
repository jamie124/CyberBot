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

	checkForWinner(0);

}

void Cyber::onKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode){
	switch(sym){
		case SDLK_r:
			Cyber::reset();
			break;
		case SDLK_ESCAPE:
			running = false;
			break;
		case SDLK_UP:
			cyberCamera->onMove(0, 5);
			break;
		case SDLK_DOWN:
			cyberCamera->onMove(0, -5);
			break;
		case SDLK_LEFT:
			cyberCamera->onMove(5, 0);
			break;
		case SDLK_RIGHT:
			cyberCamera->onMove(-5, 0);
			break;
		default:
			break;
	}
}

void Cyber::onExit() {
	running = false;
}
