//============================================================================
// Name        : cyber_bots.cpp
// Author      : James Whitwell
// Version     :
// Copyright   : 2011 James Whitwell
//============================================================================

#include <iostream>
//#include "stdafx.h"
#include "cyber_bots.h"

Cyber::Cyber() {

	currentPlayer = 0;

	cyberSurface = new CyberSurface;

	surfDisplay = NULL;

	running = true;
}

int Cyber::onExecute() {
	if (onInit() == false)
		return -1;

	SDL_Event event;

	while (running) {
		while (SDL_PollEvent(&event)) {
			onEvent(&event);
		}

		onLoop();
		onRender();
	}

	onCleanup();

	return 0;
}

void Cyber::reset() {
	for (int i = 0; i < 3; i++) {
		for (int x = 0; x < 3; x++)
			grid[i][x] = GRID_TYPE_NONE;
	}
}

void Cyber::setCell(int horizontal, int verticle, int type) {
	if (horizontal < 0 || horizontal >= 3 || verticle < 0 || verticle >= 3)
		return;
	if (type < 0 || type > GRID_TYPE_O)
		return;

	grid[horizontal][verticle] = type;
}

int Cyber::getValueFromGrid(int i, int g) {
	int value = grid[i][g];

	if (value == 1)
		return 1;
	else if (value == 2)
		return 4;
	else
		return 0;
}

void Cyber::checkForWinner(int recurseLevel) {
	int nextRecurseLevel = recurseLevel;
	bool keepRecursing = true;
	int horizontalTotal = 0;
	int verticalTotal = 0;

	for (int i = 0; i < 3; i++) {
		switch (recurseLevel) {
			case 0: {
				for (int g = 0; g < 3; g++) {

					// To prevent an X and O next to each other causing a win make 2 increase by 4 instead
					horizontalTotal += getValueFromGrid(g, i);

					if (horizontalTotal == 3) {
						winner = 1;
						keepRecursing = false;
					} else if (horizontalTotal == 12) {
						winner = 2;
						keepRecursing = false;
					}
					std::cout << "Horizontal recurse i = " << i << " g = " << g
							<< std::endl;
				}

				std::cout << " Total = " << horizontalTotal << std::endl;
				break;
			}
			case 1: {
				for (int g = 0; g < 3; g++) {

					// To prevent an X and O next to each other causing a win make 2 increase by 4 instead
					verticalTotal += getValueFromGrid(i, g);

					if (verticalTotal == 3) {
						winner = 1;
						keepRecursing = false;
					} else if (verticalTotal == 12) {
						winner = 2;
						keepRecursing = false;
					}

					std::cout << "Vertical recurse i = " << i << " g = " << g
							<< std::endl;
				}

				std::cout << " Total = " << verticalTotal << std::endl;
				break;
			}
		}
		// Reset totals for next row
		verticalTotal = 0;
		horizontalTotal = 0;

	}

	std::cout << std::endl;

	// Go to next recursion level
	if (nextRecurseLevel < 2)
		nextRecurseLevel++;
	else
		keepRecursing = false;

	// Now check for horizontal winners
	if (keepRecursing)
		checkForWinner(nextRecurseLevel);
}

// Removes any directories from a filepath so just the filename is returned
std::string Cyber::cleanFilename(std::string filename) {
	char* filepath = (char *) filename.c_str();
	int posOfLastSlash = 1;

	while (*filepath++) {
		if (*filepath == '/') {
			posOfLastSlash++;
			break;
		} else {
			posOfLastSlash++;
		}
	}

	return filename.erase(0, posOfLastSlash);

}

// Lazy and dirty method, it's kinda platform friendly though
void Cyber::clearScreen() {
    std::cout << std::string( 100, '\n' );
}

int main(int argc, char* argv[]) {
	Cyber cyber;

	return cyber.onExecute();
}
