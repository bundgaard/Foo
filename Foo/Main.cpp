#include <SDL2/SDL.h>

#pragma comment(lib, "sdl2")
#pragma comment(lib, "SDL2main")

int main(int argc, char **argv)
{
	SDL_Init(SDL_INIT_VIDEO);

	auto window = SDL_CreateWindow("Foo", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 512, 512, 0);
	auto renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);


	int dx = 1;
	int dy = -1;
	SDL_Rect rct = { 13, 5, 64, 64 };
	bool quit = false;
	SDL_Event event;
	while(!quit)
	{
		while(SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				quit = true;
				break;
			}
		}
		auto blue = (255 * cos(((SDL_GetTicks() * 0.005) * 2 * 3.14) / 3.1457 / 180.0));
		rct.w = blue;
		rct.x += dx;
		rct.y += dy;

		if (rct.x < 0 || rct.x + rct.w > 512)
		{
			dx *= -1;
		}
		if (rct.y < 0 ||rct.y + rct.h > 512)
		{
			dy *= -1;
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);
		
		SDL_SetRenderDrawColor(renderer, (int)blue>>2, 255, (int)blue, 255);
		SDL_RenderFillRect(renderer, &rct);

		SDL_RenderPresent(renderer);

		SDL_Delay(10);
	}
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
	return 0;
}