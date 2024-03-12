#include "Common_Function.h"
#include "MainObject.h"

bool Init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
        return false;
    }
    g_screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);
    if (g_screen == NULL) {
        return false;
    }
    return true;
}

int main(int argc, char* argv[]) {
    bool is_quit = false;
    if (!Init())
        return 0;

    g_bkground = SDLCommonFunc::LoadImage("bkground.png");
    if (g_bkground == NULL) {
        return 0;
    }

    SDLCommonFunc::ApplySurface(g_bkground, g_screen, 0, 0);

    MainObject human_object;
    human_object.SetRect(300, 420);
    bool ret = human_object.LoadImg("object.png");
    if (!ret) {
        return 0;
    }


    while (!is_quit) {
        while (SDL_PollEvent(&g_even)) {
            if (g_even.type == SDL_QUIT) {
                is_quit = true;
                break;
            }
            human_object.HandleInputAction(g_even,&human_object);
        }
		SDLCommonFunc::ApplySurface(g_bkground, g_screen , 0, 0);
        human_object.HandleMove(); // Move the object continuously
		human_object.Show(g_screen);

        if (SDL_Flip(g_screen) == -1)
            return 0;
    }
    
    SDLCommonFunc::CleanUp();
    SDL_Quit();
    return 1;
}
