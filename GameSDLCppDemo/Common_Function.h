#ifndef COMMON_FUNCTION_H_
#define COMMON_FUNCTION_H_

#include <Windows.h>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>

#define GA_FAILED -1
#define GA_SUCCESS 0;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int SCREEN_BPP = 32;

static SDL_Surface* g_screen = NULL;
static SDL_Surface* g_bkground = NULL;
static SDL_Event g_even;
static SDL_Surface* g_img_menu = NULL;
static SDL_Surface* g_exit_menu = NULL;
static Mix_Chunk* g_sound_cake[3];
static Mix_Chunk* g_sound_star ; 
static Mix_Chunk g_sound_bob ; 
static Mix_Chunk* g_sound_gameOver ; 

static char g_name_background[] = {"bkground.png"};
static char g_name_exp_main[] = {"explosion.png"};

static char g_name_cake_object_1[] = {"doyaki.png"};
static char g_name_cake_object_2[] = {"cake.png"};
static char g_name_cake_object_3[] = {"takoyaki.png"};
static char g_name_cake_object_star[] = {"star.png"};
static char g_name_cake_object_bomb[] = {"bom.png"};
static char g_name_background_exit[] = {"bkexit.png"};

namespace SDLCommonFunc
{
	SDL_Surface* LoadImage(std::string file_path);
	void CleanUp();
	SDL_Rect ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y);
	void ApplySurfaceClip(SDL_Surface* src, SDL_Surface* des, SDL_Rect* clip, int x, int y);
	bool CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2);
	int ShowMenu(SDL_Surface* des, TTF_Font* font);
	bool CheckFocusWithRect(const int& x, const int& y,  const SDL_Rect& rect);
}


#endif 
