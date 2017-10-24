#pragma once
#include <SDL/SDL.h>
class Panel
{
public:
	Panel(int Width, int Height, int yDiv, int xDiv);
	~Panel();
	void draw(SDL_Window* &_window, SDL_Renderer* &_gRenderer);

private:
	SDL_Window *_window;
	SDL_Renderer *_gRenderer;
	int _screenWidth;
	int _screenHeight;
	int _yDividor;
	int _xDividor;
};

