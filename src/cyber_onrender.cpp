/*
 * cyber_onrender.cpp
 *
 *  Created on: 2/04/2011
 *      Author: james
 */

#include "cyber_bots.h"

void Cyber::onRender() {
	cyberSurface->onDraw(surfDisplay, cyberSurface->getSurface("grid.png"), 0, 0);

	for (int i = 0; i < 3; i++) {
		for (int g = 0; g < 3; g++) {
			int x = i * 200;
			int y = g * 200;

			if (grid[i][g] == GRID_TYPE_X) {
				cyberSurface->onDraw(surfDisplay, cyberSurface->getSurface("x.png"), x, y);
			} else if (grid[i][g] == GRID_TYPE_O) {
				cyberSurface->onDraw(surfDisplay, cyberSurface->getSurface("o.png"), x, y);
			}
		}
	}

	if (winner > -1){
		if (winner == 1)
			cyberSurface->onDraw(surfDisplay, cyberSurface->getSurface("x_won.png"), 200, 100);
		else if (winner == 2)
			cyberSurface->onDraw(surfDisplay, cyberSurface->getSurface("o_won.png"), 200, 100);
	}

	SDL_Flip(surfDisplay);
}
