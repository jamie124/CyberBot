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
#else
#include <SDL/SDL.h>
#endif

#include <iostream>
#include <string>

#include "cyber_event.h"
#include "cyber_surface.h"
#include "cyber_logger.h"
#include "cyber_utils.h"
#include "cyber_animation.h"

class CyberSurface;
class CyberLogger;
class CyberAnimation;

class Cyber: public CyberEvent {

private:
	bool running;

	int winner;

	SDL_Surface* surfDisplay;

	CyberSurface* cyberSurface;
	CyberLogger* cyberLogger;
	CyberAnimation* yoshiAnimation;
	
	int grid[3][3];

	int currentPlayer;

	enum {
		GRID_TYPE_NONE = 0, GRID_TYPE_X, GRID_TYPE_O
	};

public:
	Cyber();
	~Cyber();

	int onExecute();

	bool onInit();
	void onEvent(SDL_Event* event);
	void onLButtonDown(int mX, int mY);
	void onKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
	void onExit();
	void onLoop();
	void onRender();
	void onCleanup();
	void reset();

	void setCell(int horizontal, int verticle, int type);
	void checkForWinner(int recurseLevel);
	int getValueFromGrid(int i, int g);
	static std::string cleanFilename(std::string filename);

	// Clear screen
	static void clearScreen();

};

#endif /* CYBER_BOTS_H_ */
