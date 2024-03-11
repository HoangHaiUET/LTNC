#include <Windows.h>
#include <SDL.h>
#include <string>
#include <SDL_image.h>

SDL_Surface* LoadImage(std::string file_path) {
    SDL_Surface* load_image = NULL;
    SDL_Surface* optimaze_image = NULL;
    load_image = IMG_Load(file_path.c_str());
    if (load_image != NULL) {
        optimaze_image = SDL_DisplayFormat(load_image);
        SDL_FreeSurface(load_image);
    }
    return optimaze_image;
}

int main(int argc, char* argv[]) {
    SDL_Surface* screen = NULL;
    SDL_Surface* image = NULL;
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
        return 1;
    }
    screen = SDL_SetVideoMode(1200, 600, 32, SDL_SWSURFACE);
    image = LoadImage("bkground.png");

    SDL_BlitSurface(image, NULL, screen, NULL);
    SDL_Flip(screen);
    SDL_Delay(5000);
    SDL_FreeSurface(image);
    SDL_Quit();

    return 0;
}
