#include "cyber_camera.h"

CyberCamera::CyberCamera() {
	x = y = 0;

	targetX = targetY = NULL;

	targetMode = TARGET_MODE_NORMAL;
}

void CyberCamera::onMove(int moveX, int moveY) {
	x += moveX;
	y += moveY;
}

int CyberCamera::getX() {
	if (targetX != NULL) {
		if (targetMode == TARGET_MODE_CENTRE) {
			return *targetX - (WWIDTH / 2);
		}

		return *targetX;
	}

	return x;
}

int CyberCamera::getY() {
	if (targetY != NULL) {
		if (targetMode == TARGET_MODE_CENTRE) {
			return *targetY - (WHEIGHT / 2);
		}

		return *targetY;
	}

	return y;
}

void CyberCamera::setPos(int x, int y){
	this->x = x;
	this->y = y;
}

void CyberCamera::setTarget(int* x, int* y){
	targetX = x;
	targetY = y;
}
