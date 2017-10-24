#include "GraphicsEngine.h"

GraphicsEngine::GraphicsEngine()
{
	_window = nullptr;
	_screenWidth = 1024;
	_screenHeight = 768;
	_gameState = GameState::RUNNING;
}

void GraphicsEngine::run() {
	initSystems();

	mainLoop();
}


void GraphicsEngine::initSystems() {

	/** Init SDL to use everything SDL offers.. **/
	SDL_Init(SDL_INIT_EVERYTHING);
	/** Create a window and check if it exists **/
	_window = SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, _screenWidth, _screenHeight, SDL_WINDOW_SHOWN);
	if (_window == nullptr)
		printf("error with window.\n");
	/** Initialize GLEW and check if it initialized properly **/
	gRenderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
	if (gRenderer == nullptr) {
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
	}

	mainLoop();
}

GraphicsEngine::~GraphicsEngine()
{

	SDL_DestroyRenderer(gRenderer);
	gRenderer = nullptr;

	SDL_DestroyWindow(_window);
	_window = nullptr;

	SDL_Quit();
}

void GraphicsEngine::mainLoop()
{
	
	while (_gameState != GameState::EXIT) {
		processInput();
		drawGame();

		//Clear screen
		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(gRenderer);
		SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0xFF, 0xFF);
		SDL_RenderDrawLine(gRenderer, _screenWidth / 2, _screenHeight, _screenWidth / 2, 0);
		SDL_RenderPresent(gRenderer);
	}
}

void GraphicsEngine::processInput() {

	SDL_Event sdlEvent;

	while (SDL_PollEvent(&sdlEvent)) {
		switch (sdlEvent.type) {
		case SDL_QUIT:
			_gameState = GameState::EXIT;
			break;
		case SDL_KEYDOWN:
			//handle key input
			break;
		}
	}
}

void GraphicsEngine::drawGame() {
	
}