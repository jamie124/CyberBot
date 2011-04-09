#ifndef CYBER_CAMERA_H_
#define CYBER_CAMERA_H_

#ifdef _WIN32
#include <SDL.h>
#else
#include <SDL/SDL.h>
#endif

#include "define.h"

enum {
	TARGET_MODE_NORMAL = 0,
	TARGET_MODE_CENTRE
};

class CyberCamera{
private:
	int x;
	int y;
	int* targetX;
	int* targetY;

public:
	int targetMode;

	CyberCamera();

	void onMove(int moveX, int moveY);

	int getX();
	int getY();

	void setPos(int x, int y);
	void setTarget(int* x, int* y);
};

#endif
