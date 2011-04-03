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

	surfDisplay = NULL;
	surfGrid = NULL;
	surfX = NULL;
	surfO = NULL;
	surfXWon = NULL;
	surfOWon = NULL;

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

int Cyber::getValueFromGrid(int i, int g){
	int value = grid[i][g];

	if (value == 1)
		return 1;
	else if (value == 2)
		return 4;
	else
		return 0;
}

void Cyber::checkForWinner(int recurseLevel) {
	int nextRecurseLevel = 1;
	bool keepRecursing = true;
	int horizontalTotal = 0;
	int verticalTotal = 0;

	for (int i = 0; i < 3; i++) {
		switch (recurseLevel){
			case 0:{
				for (int g = 0; g < 3; g++) {

					// To prevent an X and O next to each other causing a win make 2 increase by 4 instead
					verticalTotal += getValueFromGrid(g, i);

					if (verticalTotal == 3) {
						winner = 1;
						keepRecursing = false;
					} else if (verticalTotal == 12) {
						winner = 2;
						keepRecursing = false;
					}
				}
				break;
			}
			case 1: {
				for (int g = 0; g < 3; g++) {

					// To prevent an X and O next to each other causing a win make 2 increase by 4 instead
					horizontalTotal += getValueFromGrid(i, g);

					if (horizontalTotal == 3) {
						winner = 1;
						keepRecursing = false;
					} else if (horizontalTotal == 12) {
						winner = 2;
						keepRecursing = false;
					}
				}
				break;
			}
		}
			// Go to next recursion level
			if (nextRecurseLevel < 2)
				nextRecurseLevel++;
			else
				keepRecursing = false;
		
	}
		// Reset totals for next row
	verticalTotal = 0;
	horizontalTotal = 0;
	

	// Now check for horizontal winners
	if (keepRecursing)
		checkForWinner(nextRecurseLevel);
}

int main(int argc, char* argv[])
{
	Cyber cyber;

	return cyber.onExecute();
}
