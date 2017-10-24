#ifndef __GRAPHICSENG_H_
#define __GRAPHICSENG_H_

#include <SDL/SDL.h>
#include <iostream>
#include <stack>
#include "panel.h"


enum GameState { EXIT, MAIN };

class GraphicsEngine {
public:
	GraphicsEngine();
	~GraphicsEngine();
	
	void run();
private:
	std::stack<GameState> _stateLayers;
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