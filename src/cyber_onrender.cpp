/*
 * cyber_onrender.cpp
 *
 *  Created on: 2/04/2011
 *      Author: james
 */

#include "cyber_bots.h"

void Cyber::onRender() {
	CyberSurface::onDraw(surfDisplay, surfGrid, 0, 0);

	for (int i = 0; i < 3; i++) {
		for (int g = 0; g < 3; g++) {
			int x = i * 200;
			int y = g * 200;

			if (grid[i][g] == GRID_TYPE_X) {
				CyberSurface::onDraw(surfDisplay, surfX, x, y);
			} else if (grid[i][g] == GRID_TYPE_O) {
				CyberSurface::onDraw(surfDisplay, surfO, x, y);
			}
		}
	}

	if (winner > -1){
		if (winner == 1)
			CyberSurface::onDraw(surfDisplay, surfXWon, 200, 100);
		else if (winner == 2)
			CyberSurface::onDraw(surfDisplay, surfOWon, 200, 100);
	}

	SDL_Flip(surfDisplay);
}
