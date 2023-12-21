#include<SDL.h>

#include<stdio.h>
#define main SDL_main
bool running = true;
int hight = 500;
int color = 100;
Uint64 MousePosition;
int mouse_x, mouse_y;

void SetPixel(SDL_Surface* surface, int x, int y, uint8_t red, uint8_t green, uint8_t) {
	SDL_LockSurface(surface);

	uint8_t * pixel = (uint8_t*)surface->pixels;
	pixel[y * surface->format->BytesPerPixel + x] = red;
	SDL_UnlockSurface(surface);
	printf(" Mouse position : %d , %d", mouse_x, mouse_y);


}
int main(int argc,char* argv[]) {

	//Intailizing all the SDL Library
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("there is a problem here");
	}

	else {
		printf("Intialization is fine\n");
	}

	//Intitalizing SDL Variable 
	SDL_Window* PopUp;
	SDL_Surface* screen;
	SDL_Surface* image;
	int i = 30 ;


	// creating a window
	PopUp = SDL_CreateWindow("Animation", 20, 20, hight, hight, SDL_WINDOW_SHOWN);


	while ( true) {
		SDL_Event Event;

	

		MousePosition= SDL_GetMouseState(&mouse_x, &mouse_y);

		//create surface in the void
		screen = SDL_GetWindowSurface(PopUp);
		//create a variable to store the image
		image = SDL_LoadBMP("C:/Users/aryam/Downloads/PO.bmp");
		//display the imagine on the screen
		SDL_BlitSurface(image, NULL, screen, NULL);
		SDL_FreeSurface(image);
		// free the surface
		SDL_UpdateWindowSurface(PopUp);
		while (SDL_PollEvent(&Event)) {

			if (Event.type == SDL_QUIT) {
				running = false;
				break;
				
			}
			if (Event.button.button == SDL_BUTTON_LEFT) {

				SetPixel(screen, mouse_x, mouse_y, 255, 0, 0);
				SDL_UpdateWindowSurface(PopUp);

			}
		}

	}
	SDL_DestroyWindow(PopUp);
	SDL_Quit();
	return 0;
	
}