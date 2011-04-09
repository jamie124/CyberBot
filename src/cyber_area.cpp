#include "cyber_area.h"

//CyberArea CyberArea::areaControl;

CyberArea::CyberArea(CyberSurface* surface) {
	cyberSurface = surface;
	areaSize = 0;
}

bool CyberArea::onLoad(char* file) {
	mapList.clear();

	cyberSurface->getLogger()->addMessage("Loading map...");

	FILE* fileHandle = fopen(file, "r");

	if (fileHandle == NULL)
		return false;

	char tilesetFile[255];

	fscanf(fileHandle, "%s\n", tilesetFile);

	if ((tilesetSurf = cyberSurface->onLoad(tilesetFile)) == false) {
		fclose(fileHandle);

		return false;
	}

	fscanf(fileHandle, "%d\n", &areaSize);

	for (int x = 0; x < areaSize; x++) {
		for (int y = 0; y < areaSize; y++) {
			char mapFile[255];

			fscanf(fileHandle, "%s ", mapFile);

			CyberMap* tempMap = new CyberMap(cyberSurface);

			if (tempMap->onLoad(mapFile) == false) {
				fclose(fileHandle);

				return false;
			}

			tempMap->tilesetSurf = tilesetSurf;

			cyberSurface->getLogger()->addMessage("Adding map...");

			mapList.push_back(tempMap);

		}
		fscanf(fileHandle, "\n");
	}
	fclose(fileHandle);

	return true;
}

void CyberArea::onRender(SDL_Surface* displaySurf, int cameraX, int cameraY) {
	int mapWidth = MAP_WIDTH * TILE_SIZE;
	int mapHeight = MAP_HEIGHT * TILE_SIZE;

	int firstID = -cameraX / mapWidth;
	firstID = firstID + ((-cameraY / mapHeight) * areaSize);

	for (int i = 0; i < 4; i++){
		int id = firstID + ((i / 2) * areaSize) + (i % 2);

		if (id < 0 || id >= mapList.size()) continue;

		int x = ((id % areaSize) * mapWidth) + cameraX;
		int y = ((id / areaSize) * mapHeight) + cameraY;

		mapList[id]->onRender(displaySurf, x, y);
	}
}

void CyberArea::onCleanup(){
	if (tilesetSurf)
		SDL_FreeSurface(tilesetSurf);

	mapList.clear();
}
