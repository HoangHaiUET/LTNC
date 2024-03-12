#include "Common_Function.h"

SDL_Surface* SDLCommonFunc::LoadImage(std::string file_path) {
    SDL_Surface * load_image = NULL;
    SDL_Surface* optimize_image = NULL;
    load_image = IMG_Load(file_path.c_str());
    if (load_image != NULL) {
        optimize_image= SDL_DisplayFormat(load_image);
        SDL_FreeSurface(load_image);
        if (optimize_image != NULL) {
            UINT32 color_key = SDL_MapRGB(optimize_image->format, 0, 0, 0);
            SDL_SetColorKey(optimize_image, SDL_SRCCOLORKEY, color_key);
        }
    }
    return optimize_image;
}

void SDLCommonFunc::ApplySurface(SDL_Surface* src, SDL_Surface* des, int x, int y) {
    SDL_Rect offset;
    offset.x = x;
    offset.y = y;
    SDL_BlitSurface(src, NULL, des, &offset);
}
bool SDLCommonFunc::CheckCollision(const SDL_Rect& object1, const SDL_Rect& object2)
{
	int left_a = object1.x;
	int right_a = object1.x + object1.w;
	int top_a = object1.y;
	int bottom_a = object1.y + object1.h;

	int left_b = object2.x;
	int right_b = object2.x + object2.w;
	int top_b = object2.y;
	int bottom_b = object2.y + object2.h;

	if (left_b > left_a + 20 && left_b < right_a - 20)
	{
		if (bottom_b > top_a + 20 && bottom_b < bottom_a - 20)
		{
			return true;
		}
	}

	if (right_b > left_a + 20 && right_b < right_a - 20)
	{
		if (bottom_b > top_a + 20 && bottom_b < bottom_a - 20)
		{
			return true;
		}
	}

	if (left_b > left_a + 20 && left_b < right_a - 20)
	{
		if (top_b > top_a + 20 && top_b < bottom_a - 20)
		{
			return true;
		}
	}

	if (right_b > left_a + 20 && right_b < right_a - 20)
	{
		if (top_b > top_a + 20 && top_b < bottom_a - 20)
		{
			return true;
		}
	}
	return false;
}
void SDLCommonFunc::CleanUp() {
    SDL_FreeSurface(g_screen);
    SDL_FreeSurface(g_bkground);
}
