#ifndef __GRAPHICSENG_H_
#define __GRAPHICSENG_H_

#include <SDL/SDL.h>
#include <GL/glew.h>
#include <iostream>

enum GameState { PRELOGIN, LOGIN, RUNNING, PAUSED, EXIT };

class GraphicsEngine {
public:
	GraphicsEngine(Uint32 FLAGS);
	~GraphicsEngine();
	void mainLoop();

private:
	SDL_Window *window = nullptr;
	SDL_GLContext screenContext = nullptr;
	GameState gameState = PRELOGIN;
};

#endif