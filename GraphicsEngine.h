#ifndef __GRAPHICSENG_H_
#define __GRAPHICSENG_H_

#include <SDL/SDL.h>
#include <GL/glew.h>
#include <iostream>

enum GameState { PRELOGIN, LOGIN, RUNNING, PAUSED, EXIT };

class GraphicsEngine {
public:
	GraphicsEngine();
	~GraphicsEngine();
	
	void run();
private:

	SDL_Window *_window;
	SDL_Renderer* gRenderer;
	GameState _gameState;
	void initSystems();
	void mainLoop();
	void processInput();
	void drawGame();
	int _screenWidth;
	int _screenHeight;

};

#endif