/*
 * cyber_bots.h
 *
 *  Created on: 2/04/2011
 *      Author: james
 */

#ifndef CYBER_BOTS_H_
#define CYBER_BOTS_H_

#ifdef _WIN32 
#include <SDL.h>
#endif

#ifdef _LINUX
#include <SDL/SDL.h>
#endif

#include <iostream>
#include <string>

#include "cyber_event.h"
#include "cyber_surface.h"

class CyberSurface;

class Cyber : public CyberEvent{

private:
	bool running;

	int winner;

	SDL_Surface* surfDisplay;

	SDL_Surface* surfX;
	SDL_Surface* surfO;
	SDL_Surface* surfXWon;
	SDL_Surface* surfOWon;
	SDL_Surface* surfGrid;

	CyberSurface* cyberSurface;

	int grid[3][3];

	int currentPlayer;

	enum {
		GRID_TYPE_NONE = 0,
		GRID_TYPE_X,
		GRID_TYPE_O
	};

public:
	Cyber();
	int onExecute();

	bool onInit();
	void onEvent(SDL_Event* event);
	void onLButtonDown(int mX, int mY);
	void onExit();
	void onLoop();
	void onRender();
	void onCleanup();
	void reset();

	void setCell(int horizontal, int verticle, int type);
	void checkForWinner(int recurseLevel);
	int getValueFromGrid(int i, int g);
	static std::string cleanFilename(std::string filename);
};

#endif /* CYBER_BOTS_H_ */
