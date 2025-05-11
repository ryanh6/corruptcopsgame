#include <iostream>

bool init();

bool loadMedia();

void close();

SDL_Texture* loadTexture(std::string path);

SDL_Window* gameWindow = NULL;

SDL_Renderer* gameRenderer = NULL;

bool init() {
    bool success = true;

    if (SDL_Init(SDLInitVideo) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        success = false;
    } else {
        gameWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (gameWindow == NULL) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
        } else {
            gameScreen = SDL_GetWindowSurface(gameWindow);
        }
    }

    return success;
}

bool loadMedia()
{
    bool success = true;
    return success;
}

void close()
{
    SDL_FreeSurface(gameHelloWorld);
    gameHelloWorld = NULL;

    SDL_DestroyWindow(gameWindow);
    gameWindow = NULL;

    SDL_Quit();
}

int main(int argc, char* args[]) {
    if (!init()) {
		printf("Failed to initialize!\n");
	} else {
		if (!loadMedia()){
		    printf("Failed to load media!\n");
		} else {	
			bool quit = false;

			SDL_Event event;

			while (!quit) {
				while (SDL_PollEvent(&event) != 0) {
					if(event.type == SDL_QUIT) {
						quit = true;
					}
				}

				SDL_SetRenderDrawColor(gameRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gameRenderer);

				SDL_Rect fillRect = {SCREEN_WIDTH / 4, SCREEN_HEIGHT / 4, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2};
				SDL_SetRenderDrawColor(gameRenderer, 0xFF, 0x00, 0x00, 0xFF);		
				SDL_RenderFillRect(gameRenderer, &fillRect);

				SDL_Rect outlineRect = {SCREEN_WIDTH / 6, SCREEN_HEIGHT / 6, SCREEN_WIDTH * 2 / 3, SCREEN_HEIGHT * 2 / 3};
				SDL_SetRenderDrawColor(gameRenderer, 0x00, 0xFF, 0x00, 0xFF);		
				SDL_RenderDrawRect(gameRenderer, &outlineRect);
				
				SDL_SetRenderDrawColor(gameRenderer, 0x00, 0x00, 0xFF, 0xFF);		
				SDL_RenderDrawLine(gameRenderer, 0, SCREEN_HEIGHT / 2, SCREEN_WIDTH, SCREEN_HEIGHT / 2);

				SDL_SetRenderDrawColor(gameRenderer, 0xFF, 0xFF, 0x00, 0xFF);
				for (int i = 0; i < SCREEN_HEIGHT; i += 4) {
					SDL_RenderDrawPoint(gameRenderer, SCREEN_WIDTH / 2, i);
				}

				SDL_RenderPresent(gameRenderer);
			}
		}
	}

	close();

	return 0;
}