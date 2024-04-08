#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include<SDL.h>
#include<string>
#include<Windows.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include <fstream>
#include <SDL_events.h>
#include<math.h>
#include <sstream>
#include <cstdarg>
#include <cwchar>
#include <iomanip>
#include <SDL_Mixer.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;

static SDL_Surface *g_screen = NULL;
static SDL_Surface *g_bkground = NULL;
static SDL_Event g_even;

static Mix_Chunk* g_sound_cake[3];
static Mix_Chunk* g_sound_star ; 
static Mix_Chunk g_sound_bob ; 
static Mix_Chunk* g_sound_gameOver ; 



namespace SDLCommonFunc {
    SDL_Surface* LoadImage(std::string file_path);
    void ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y);
	void ApplySurfaceClip(SDL_Surface* src, SDL_Surface* des,SDL_Rect* clip,int x, int y);
	bool CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2);
    void CleanUp();
}

#endif 
