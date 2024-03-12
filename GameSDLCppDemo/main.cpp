#include "Common_Function.h"
#include "MainObject.h"
#include "CakeObject.h"

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
	CakeObject*	p_cake1 = new CakeObject();
	ret = p_cake1->LoadImg("doyaki.png");
	if(ret == false){
		return 0; 
	}
	p_cake1->SetRect(120 + rand() % 80, -100);

	CakeObject*	p_cake2 = new CakeObject();
	ret = p_cake2->LoadImg("cake.png");
	if(ret == false){
		return 0; 
	}
	p_cake2->SetRect(120 + rand() % 80, -100);

	CakeObject*	p_cake3 = new CakeObject();
	ret = p_cake3->LoadImg("takoyaki.png");
	if(ret == false){
		return 0; 
	}
	p_cake3->SetRect(120 + rand() % 80, -100);

	CakeObject*	p_star = new CakeObject();
	ret = p_star->LoadImg("star.png");
	if(ret == false){
		return 0; 
	}
	p_star->SetRect(360 + rand() % 80, -5000);

	CakeObject* p_bomb = new CakeObject();
	ret = p_bomb->LoadImg("bom.png");
	if (ret == false)
	{
		return 0;
	}
	p_bomb->SetRect(480 + rand() % 80, -300);


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

			p_cake1->set_y_val(1);		
			p_cake1->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
			p_cake1->Show(g_screen);

			p_cake2->set_y_val(2);
			p_cake2->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
			p_cake2->Show(g_screen);

			p_cake3->set_y_val(1);
			p_cake3->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
			p_cake3->Show(g_screen);

			p_star->set_y_val(5);
			p_star->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
			p_star->Show(g_screen);

			p_bomb->set_y_val(2);
			p_bomb->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
			p_bomb->Show(g_screen);

			if (SDL_Flip(g_screen) == -1) return 0;
    }
    
    SDLCommonFunc::CleanUp();
    SDL_Quit();
    return 1;
}
