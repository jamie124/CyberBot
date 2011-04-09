#ifndef CYBER_AREA_H_
#define CYBER_AREA_H_

#include "cyber_map.h"

class CyberMap;

class CyberArea {
private:
	int areaSize;
	SDL_Surface* tilesetSurf;

	CyberSurface* cyberSurface;
public:
	CyberArea(CyberSurface* surface);

	//static CyberArea areaControl;
	std::vector<CyberMap*> mapList;

	bool onLoad(char* file);
	void onRender(SDL_Surface* displaySurf, int cameraX, int cameraY);
	void onCleanup();

};
#endif
