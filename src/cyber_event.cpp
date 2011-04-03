/*
 * CyberEvent.cpp
 *
 *  Created on: 3/04/2011
 *      Author: james
 */

#include "cyber_event.h"

CyberEvent::CyberEvent() {

}

CyberEvent::~CyberEvent() {
	// Do nothing
}

void CyberEvent::onEvent(SDL_Event* event) {
	switch (event->type) {
		case SDL_ACTIVEEVENT: {
			switch (event->active.state) {
				case SDL_APPMOUSEFOCUS: {
					if (event->active.gain)
						onMouseFocus();
					else
						onMouseBlur();
					break;
				}
				case SDL_APPINPUTFOCUS: {
					if (event->active.gain)
						onInputFocus();
					else
						onInputBlur();
					break;
				}
				case SDL_APPACTIVE: {
					if (event->active.gain)
						onRestore();
					else
						onMinimize();
					break;
				}
			}
			break;
		}
		case SDL_KEYDOWN: {
			onKeyDown(event->key.keysym.sym, event->key.keysym.mod,
					event->key.keysym.unicode);
			break;
		}
		case SDL_KEYUP: {
			onKeyUp(event->key.keysym.sym, event->key.keysym.mod,
					event->key.keysym.unicode);
			break;
		}
		case SDL_MOUSEMOTION: {
			onMouseMove(event->motion.x, event->motion.y, event->motion.xrel,
					event->motion.yrel,
					(event->motion.state & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0,
					(event->motion.state & SDL_BUTTON(SDL_BUTTON_RIGHT)) != 0,
					(event->motion.state & SDL_BUTTON(SDL_BUTTON_MIDDLE)) != 0);
			break;
		}
		case SDL_MOUSEBUTTONDOWN: {
			switch (event->button.button) {
				case SDL_BUTTON_LEFT: {
					onLButtonDown(event->button.x, event->button.y);
					break;
				}
				case SDL_BUTTON_RIGHT: {
					onRButtonDown(event->button.x, event->button.y);
					break;
				}
				case SDL_BUTTON_MIDDLE: {
					onMButtonDown(event->button.x, event->button.y);
					break;
				}
			}
			break;
		}
		case SDL_MOUSEBUTTONUP: {
			switch (event->button.button) {
				case SDL_BUTTON_LEFT: {
					onLButtonUp(event->button.x, event->button.y);
					break;
				}
				case SDL_BUTTON_RIGHT: {
					onRButtonUp(event->button.x, event->button.y);
					break;
				}
				case SDL_BUTTON_MIDDLE: {
					onMButtonUp(event->button.x, event->button.y);
					break;
				}
			}
			break;
		}
		case SDL_JOYAXISMOTION: {
			onJoyAxis(event->jaxis.which, event->jaxis.axis, event->jaxis.value);
			break;
		}

		case SDL_JOYBALLMOTION: {
			onJoyBall(event->jball.which, event->jball.ball, event->jball.xrel,
					event->jball.yrel);
			break;
		}
        case SDL_JOYBUTTONDOWN: {
            onJoyButtonDown(event->jbutton.which,event->jbutton.button);
            break;
        }

        case SDL_JOYBUTTONUP: {
            onJoyButtonUp(event->jbutton.which,event->jbutton.button);
            break;
        }

        case SDL_QUIT: {
            onExit();
            break;
        }

        case SDL_SYSWMEVENT: {
            //Ignore
            break;
        }

        case SDL_VIDEORESIZE: {
            onResize(event->resize.w,event->resize.h);
            break;
        }

        case SDL_VIDEOEXPOSE: {
            onExpose();
            break;
        }

        default: {
            onUser(event->user.type,event->user.code,event->user.data1,event->user.data2);
            break;
        }
	}
}

void CyberEvent::onInputFocus() {
    //Pure virtual, do nothing
}

void CyberEvent::onInputBlur() {
    //Pure virtual, do nothing
}

void CyberEvent::onKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) {
    //Pure virtual, do nothing
}

void CyberEvent::onKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) {
    //Pure virtual, do nothing
}

void CyberEvent::onMouseFocus() {
    //Pure virtual, do nothing
}

void CyberEvent::onMouseBlur() {
    //Pure virtual, do nothing
}

void CyberEvent::onMouseMove(int mX, int mY, int relX, int relY, bool left,bool right,bool middle) {
    //Pure virtual, do nothing
}

void CyberEvent::onMouseWheel(bool up, bool down) {
    //Pure virtual, do nothing
}

void CyberEvent::onLButtonDown(int mX, int mY) {
    //Pure virtual, do nothing
}

void CyberEvent::onLButtonUp(int mX, int mY) {
    //Pure virtual, do nothing
}

void CyberEvent::onRButtonDown(int mX, int mY) {
    //Pure virtual, do nothing
}

void CyberEvent::onRButtonUp(int mX, int mY) {
    //Pure virtual, do nothing
}

void CyberEvent::onMButtonDown(int mX, int mY) {
    //Pure virtual, do nothing
}

void CyberEvent::onMButtonUp(int mX, int mY) {
    //Pure virtual, do nothing
}

void CyberEvent::onJoyAxis(Uint8 which,Uint8 axis,Sint16 value) {
    //Pure virtual, do nothing
}

void CyberEvent::onJoyButtonDown(Uint8 which,Uint8 button) {
    //Pure virtual, do nothing
}

void CyberEvent::onJoyButtonUp(Uint8 which,Uint8 button) {
    //Pure virtual, do nothing
}

void CyberEvent::onJoyHat(Uint8 which,Uint8 hat,Uint8 value) {
    //Pure virtual, do nothing
}

void CyberEvent::onJoyBall(Uint8 which,Uint8 ball,Sint16 xrel,Sint16 yrel) {
    //Pure virtual, do nothing
}

void CyberEvent::onMinimize() {
    //Pure virtual, do nothing
}

void CyberEvent::onRestore() {
    //Pure virtual, do nothing
}

void CyberEvent::onResize(int w,int h) {
    //Pure virtual, do nothing
}

void CyberEvent::onExpose() {
    //Pure virtual, do nothing
}

void CyberEvent::onExit() {
    //Pure virtual, do nothing
}

void CyberEvent::onUser(Uint8 type, int code, void* data1, void* data2) {
    //Pure virtual, do nothing
}
