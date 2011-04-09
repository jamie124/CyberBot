#include "cyber_map.h"

CyberMap::CyberMap(CyberSurface* surface) {
	tilesetSurf = NULL;
	cyberSurface = surface;
}

bool CyberMap::onLoad(char* file) {
	tileList.clear();

	FILE* fileHandle = fopen(file, "r");

	if (fileHandle == NULL) {
		return false;
	}

	for (int y = 0; y < MAP_HEIGHT; y++) {
		for (int x = 0; x < MAP_WIDTH; x++) {
			CyberTile tempTile;

			fscanf(fileHandle, "%d:%d ", &tempTile.tileID, &tempTile.typeID);

			tileList.push_back(tempTile);
		}
		fscanf(fileHandle, "\n");
	}

	fclose(fileHandle);

	return true;
}

void CyberMap::onRender(SDL_Surface* displaySurf, int mapX, int mapY) {
	if (tilesetSurf == NULL)
		return;

	int tilesetWidth = tilesetSurf->w / TILE_SIZE;
	int tilesetHeight = tilesetSurf->h / TILE_SIZE;

	int id = 0;

	for (int y = 0; y < MAP_HEIGHT; y++) {
		for (int x = 0; x < MAP_WIDTH; x++) {
			if (tileList[id].typeID == TILE_TYPE_NONE) {
				id++;
				continue;
			}

			int tX = mapX + (x * TILE_SIZE);
			int tY = mapY + (y * TILE_SIZE);

			int tilesetX = (tileList[id].tileID % tilesetWidth) * TILE_SIZE;
			int tilesetY = (tileList[id].tileID / tilesetWidth) * TILE_SIZE;

			cyberSurface->onDraw(displaySurf, tilesetSurf, tX, tY, tilesetX, tilesetY, TILE_SIZE, TILE_SIZE);
			id++;
		}
	}
}
