/*
 * cyber_surface.cpp
 *
 *  Created on: 2/04/2011
 *      Author: james
 */

#include "cyber_surface.h"

CyberSurface::CyberSurface(){
	surfaces = new std::map<std::string, SDL_Surface*>;
}

CyberSurface::CyberSurface(CyberLogger * logger){
	surfaces = new std::map<std::string, SDL_Surface*>;
	cyberLogger = logger;
}

CyberSurface::~CyberSurface(){
	delete surfaces;
	//delete cyberLogger;
}

SDL_Surface* CyberSurface::getSurface(std::string filename){
	std::map<std::string, SDL_Surface*>::iterator itr;

	itr = surfaces->find(filename);

	return itr->second;
}

bool CyberSurface::addSurface(std::string filename, SDL_Surface* surface){
	//std::map<std::string, SDL_Surface*> surfaces;
	
	std::cout << "Adding surface: " << filename << std::endl;
	cyberLogger->addMessage("Adding surface: " + filename);

	surfaces->insert(std::pair<std::string, SDL_Surface*>(filename, surface));

		return true;
	//} else {
		//std::cout << "Could not add \"" << filename << "\". A surface with that name has already been used." << std::endl;
		//return false;
	//}
}

SDL_Surface* CyberSurface::onLoad(char* file){
	SDL_Surface* tempSurf = NULL;
	SDL_Surface* returnSurf = NULL;

	if ((tempSurf = IMG_Load(file)) == NULL){
		std::cout << "Couldn't load file: " << file << " Error message: " << IMG_GetError() << std::endl;
		return NULL;
	}

	returnSurf = SDL_DisplayFormatAlpha(tempSurf);
	
	CyberSurface::addSurface(Cyber::cleanFilename(file), returnSurf);

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

bool CyberSurface::onDraw(SDL_Surface* destSurf, SDL_Surface* srcSurf, int x, int y, int x2, int y2, int w, int h){
	if (destSurf == NULL || srcSurf == NULL)
		return false;

	SDL_Rect destRect;

	destRect.x = x;
	destRect.y = y;

	SDL_Rect srcRect;

	srcRect.x = x2;
	srcRect.y = y2;
	srcRect.w = w;
	srcRect.h = h;

	SDL_BlitSurface(srcSurf, &srcRect, destSurf, &destRect);

	return true;
}

bool CyberSurface::transparent(SDL_Surface* surfDest, int r, int g, int b){
	if (surfDest == NULL){
		return false;
	}

	SDL_SetColorKey(surfDest, SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(surfDest->format, r, g, b));

	return true;
}
