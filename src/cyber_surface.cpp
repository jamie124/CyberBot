/*
 * cyber_surface.cpp
 *
 *  Created on: 2/04/2011
 *      Author: james
 */

#include "cyber_surface.h"

CyberSurface::CyberSurface(){

}

SDL_Surface* CyberSurface::onLoad(char* file){
	SDL_Surface* tempSurf = NULL;
	SDL_Surface* returnSurf = NULL;

	if ((tempSurf = IMG_Load(file)) == NULL){
		printf("Couldn't load %s:%s\n",file,IMG_GetError());
		return NULL;
	}

	returnSurf = SDL_DisplayFormatAlpha(tempSurf);
	SDL_FreeSurface(tempSurf);

	return returnSurf;
}

bool CyberSurface::onDraw(SDL_Surface* destSurf, SDL_Surface* srcSurf, int x, int y){
	if (destSurf == NULL || srcSurf == NULL)
		return false;

	SDL_Rect destRect;

	destRect.x = x;
	destRect.y = y;

	SDL_BlitSurface(srcSurf, NULL, destSurf, &destRect);

	return true;
}

bool CyberSurface::transparent(SDL_Surface* surfDest, int r, int g, int b){
	if (surfDest == NULL){
		return false;
	}

	SDL_SetColorKey(surfDest, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(surfDest->format, r, g, b));

	return true;
}
