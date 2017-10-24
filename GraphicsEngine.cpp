#include "GraphicsEngine.h"

GraphicsEngine::GraphicsEngine(Uint32 FLAGS)
{
	/** Init SDL to use everything SDL offers.. **/
	SDL_Init(SDL_INIT_EVERYTHING);
	/** Create a window and check if it exists **/
	window = SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1024, 768, FLAGS);
	if (window == nullptr)
		printf("error.\n");
		//Logger::windowError("GraphicsEngine", "Unable to initialize window using SDL!"); // TODO: MAKE LOGGER
	/** Create an OpenGL context and check if it exists **/
	screenContext = SDL_GL_CreateContext(window);
	if (screenContext == nullptr)
		printf("error.\n");
		//Logger::windowError("GraphicsEngine", "Unable to create OpenGL Context!");
	/** Initialize GLEW and check if it initialized properly **/
	if (glewInit() != GLEW_OK)
		printf("error.\n");
		//Logger::windowError("GraphicsEngine", "Unable to initialize GLEW!");
	/** Set some attributes for OpenGL and set the 'clear color' to black **/
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.4f, 0.4f, 0.8f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 1024, 0.0, 768);
	glViewport(0, 0, 1024, 768);
	mainLoop();
}

GraphicsEngine::~GraphicsEngine()
{
}

void GraphicsEngine::mainLoop()
{
	SDL_Event sdlEvent;
	while (gameState != GameState::EXIT) {
		while (SDL_PollEvent(&sdlEvent)) {
			switch (sdlEvent.type) {
			case SDL_QUIT:
				gameState = GameState::EXIT;
				break;
			case SDL_KEYDOWN:
				//handle key input
				break;
			}
		}
		SDL_GL_SwapWindow(window);
	}
}
