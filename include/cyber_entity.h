#include <vector>

#include "cyber_animation.h"
#include "cyber_surface.h"

class CyberEntity{
public:
	static std::vector<CyberEntity*> entityList;

protected:
	CyberAnimation	animationControl;
	SDL_Surface*	entitySurf;

public:
	float			x;
	float			y;
	int				width;
	int				height;
	int				animationState;

	CyberEntity();
	virtual ~CyberEntity();

	virtual bool onLoad(char* file, int width, int height, int maxFrames);
	virtual void onLoop();
	virtual void onRender(SDL_Surface* displaySurf);
	virtual void onCleanup();
};