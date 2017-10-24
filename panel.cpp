#include "panel.h"



Panel::Panel(int Width, int Height, int yDiv, int xDiv)
{
	_screenWidth = Width;
	_screenHeight = Height;
	_yDividor = yDiv;
	_xDividor = xDiv;
}


Panel::~Panel()
{
}

void Panel::draw(SDL_Window* &_window, SDL_Renderer* &_gRenderer) {
	SDL_SetRenderDrawColor(_gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(_gRenderer);
	SDL_SetRenderDrawColor(_gRenderer, 0x00, 0x00, 0xFF, 0xFF);
	SDL_Rect outlineRect;
	SDL_Rect fillRect;
	for (int i = 0; i < _xDividor; i++) {
		outlineRect = { 0, (_screenHeight / _yDividor)*i, _screenWidth / _xDividor, (_screenHeight / _yDividor)*(i+1) };
		fillRect = { 0, (_screenHeight / _yDividor)*i, _screenWidth / _xDividor, (_screenHeight / _yDividor)*(i + 1) };
		SDL_SetRenderDrawColor(_gRenderer, 0xFF, 0x00, 0x00, 0xFF);
		SDL_RenderFillRect(_gRenderer, &fillRect);
		SDL_SetRenderDrawColor(_gRenderer, 0x00, 0xFF, 0x00, 0xFF);
		SDL_RenderDrawRect(_gRenderer, &outlineRect);
	}
	SDL_RenderDrawLine(_gRenderer, _screenWidth / _xDividor, _screenHeight, _screenWidth / _xDividor, 0);
	SDL_RenderPresent(_gRenderer);
}