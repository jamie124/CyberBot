/*
 * cyber_event.h
 *
 *  Created on: 3/04/2011
 *      Author: james
 */

#ifndef CYBER_EVENT_H_
#define CYBER_EVENT_H_

#ifdef _WIN32 
#include <SDL.h>
#endif

#ifdef _LINUX
#include <SDL/SDL.h>
#endif

class CyberEvent {

public:
	CyberEvent();

	virtual ~CyberEvent();
	virtual void onEvent(SDL_Event* event);
	virtual void onInputFocus();
	virtual void onInputBlur();
	virtual void onKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
	virtual void onKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);
	virtual void onMouseFocus();
	virtual void onMouseBlur();
	virtual void onMouseMove(int mX, int mY, int relX, int relY, bool left,
			bool right, bool middle);
	virtual void onMouseWheel(bool up, bool down);		// Not implemented
	virtual void onLButtonDown(int mX, int mY);
	virtual void onLButtonUp(int mX, int mY);
	virtual void onRButtonDown(int mX, int mY);
	virtual void onRButtonUp(int mX, int mY);
	virtual void onMButtonDown(int mX, int mY);
	virtual void onMButtonUp(int mX, int mY);
	virtual void onJoyAxis(Uint8 which, Uint8 axis, Sint16 value);
	virtual void onJoyButtonDown(Uint8 which, Uint8 button);
	virtual void onJoyButtonUp(Uint8 which, Uint8 button);
	virtual void onJoyHat(Uint8 which, Uint8 hat, Uint8 value);
	virtual void onJoyBall(Uint8 which, Uint8 ball, Sint16 xrel, Sint16 yrel);
	virtual void onMinimize();
	virtual void onRestore();
	virtual void onResize(int w, int h);
	virtual void onExpose();
	virtual void onExit();
	virtual void onUser(Uint8 type, int code, void* data1, void* data2);
};

#endif /* CYBER_EVENT_H_ */
