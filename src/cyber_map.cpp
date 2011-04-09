#include "cyber_map.h"
#include "define.h"

CyberMap::CyberMap() {
	tilesetSurf = NULL;
}

bool CyberMap::onLoad(char* file) {
	tileList.clear();

	FILE* fileHandle = fopen(file, "r");

	if (fileHandle == NULL) {
		return false;
	}

	for(int g = 0;g < 4;g++) {
		for(int X = 0;X < MAP_WIDTH;X++) {
			CyberTile tempTile;

			fscanf(fileHandle, "%d:%d ", &tempTile.tileID, &tempTile.typeID);

			tileList.push_back(tempTile);
		}
		fscanf(fileHandle, "\n");
	}

	fclose(fileHandle);

	return true;
}
