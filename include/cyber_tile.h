#ifndef CYBER_TILE_H
#define CYBER_TILE

enum {
	TILE_TYPE_NONE = 0, TILE_TYPE_NORMAL, TILE_TYPE_BLOCK
};

class CyberTile {
public:
	int tileID;
	int typeID;

	CyberTile();
};

#endif
