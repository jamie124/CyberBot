#include "cyber_map.h"

CyberMap::CyberMap() {
	tilesetSurf = NULL;
}

bool CyberMap::onLoad(char* file) {
	tileList.clear();

	FILE* fileHandle = fopen(file, "r");

	if (fileHandle == NULL) {
		return false;
	}

	for(int Y = 0;Y < MAP_HEIGHT;Y++) {
		for(int X = 0;X < MAP_WIDTH;X++) {
			CTile tempTile;

			fscanf(FileHandle, "%d:%d ", &tempTile.TileID, &tempTile.TypeID);

			TileList.push_back(tempTile);
		}
		fscanf(FileHandle, "\n");
	}

	fclose(fileHandle);

	return true;
}
