#include "Common_Function.h"
#include "MainObject.h"
#include "CakeObject.h"
#include "ExplosionObject.h"
#include "PlayerPower.h"
#include "TextObject.h"
#include <SDL_mixer.h>

TTF_Font* g_font_text = NULL;
TTF_Font* g_font_menu = NULL;

bool Init()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == GA_FAILED)
	{
		return false;
	}

	g_screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_BPP, SDL_SWSURFACE);

	if (g_screen == NULL)
		return false;

	if (TTF_Init() == GA_FAILED)
	{
		return false;
	}


	g_font_text = TTF_OpenFont("PressStart2P-vaV7.ttf", 20);
	g_font_menu = TTF_OpenFont("SportGame-K7nWo.otf", 30);
	if (g_font_text == NULL || g_font_menu == NULL)
	{
		return false;
	}

	return true;
}

int main(int argc, char* argv[]) {

    bool is_quit = false;
    if (!Init())
        return 0;
	// load image

    g_bkground = SDLCommonFunc::LoadImage(g_name_background);
    if (g_bkground == NULL) {
        return 0;
    }
	g_exit_menu = SDLCommonFunc::LoadImage(g_name_background_exit);
	if(g_exit_menu == NULL) return 0 ;
    SDLCommonFunc::ApplySurface(g_bkground, g_screen, 0, 0);

	// load player_power 
	PlayerPower player_power;
	player_power.Init();


	// Load text 
	TextObject mark_game ;
	mark_game.SetColor(TextObject::YELLOW_TEXT);

	// Load human object
    MainObject human_object;
    human_object.SetRect(300, 420);
    bool ret = human_object.LoadImg("object.png");
    if (!ret) {
        return 0;
    }

	// Load Explosion Object 
    ExplosionObject* exp_main = new ExplosionObject(); 
    ret = exp_main->LoadImg(g_name_exp_main); 
	exp_main->set_clips();
    if (ret == false) return 0;

	// Set Cake Object
    CakeObject* p_cake1 = new CakeObject();
    ret = p_cake1->LoadImg(g_name_cake_object_1);
    if (ret == false) {
        return 0;
    }
    p_cake1->SetRect(120 + rand() % 80, -100);

    CakeObject* p_cake2 = new CakeObject();
    ret = p_cake2->LoadImg(g_name_cake_object_2);
    if (ret == false) {
        return 0;
    }
    p_cake2->SetRect(120 + rand() % 80, -100);

    CakeObject* p_cake3 = new CakeObject();
    ret = p_cake3->LoadImg(g_name_cake_object_3);
    if (ret == false) {
        return 0;
    }
    p_cake3->SetRect(120 + rand() % 80, -100);

    CakeObject* p_star = new CakeObject();
    ret = p_star->LoadImg(g_name_cake_object_star);
    if (ret == false) {
        return 0;
    }
    p_star->SetRect(360 + rand() % 80, -5000);

    CakeObject* p_bomb = new CakeObject();
    ret = p_bomb->LoadImg(g_name_cake_object_bomb);
    if (ret == false) {
        return 0;
    }
    p_bomb->SetRect(480 + rand() % 1000, -1000);

    bool is_gameover = false;

	unsigned int die_count = 0 ;
	unsigned int mark_value = 0 ;
	unsigned int star_value = 0 ;

	int ret_menu = SDLCommonFunc::ShowMenu(g_screen, g_font_menu);
	if (ret_menu == 1)
	{
		is_quit = true;
	}
	// While Loop
    while (!is_quit) 
	{
        while (SDL_PollEvent(&g_even)) 
		{
            if (g_even.type == SDL_QUIT) 
			{
                is_quit = true;
                break;
            }
            human_object.HandleInputAction(g_even, &human_object);
        }
        SDLCommonFunc::ApplySurface(g_bkground, g_screen, 0, 0);
        human_object.HandleMove(); 
        human_object.Show(g_screen);

        p_cake1->set_y_val(1);
        p_cake1->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
        p_cake1->Show(g_screen);

        p_cake2->set_y_val(2);
        p_cake2->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
        p_cake2->Show(g_screen);

        p_cake3->set_y_val(3);
        p_cake3->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
        p_cake3->Show(g_screen);

        p_star->set_y_val(5);
        p_star->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
        p_star->Show(g_screen);

        p_bomb->set_y_val(2);
        p_bomb->HandleMove(SCREEN_WIDTH, SCREEN_HEIGHT);
        p_bomb->Show(g_screen);

        // Check collision main and cake

        // bomb is named to threats

        bool is_col =  SDLCommonFunc::CheckCollision(human_object.GetRect(), p_cake1->GetRect());
        bool is_col1 = SDLCommonFunc::CheckCollision(human_object.GetRect(), p_cake2->GetRect());
        bool is_col2 = SDLCommonFunc::CheckCollision(human_object.GetRect(), p_cake3->GetRect());
        bool is_col3 = SDLCommonFunc::CheckCollision(human_object.GetRect(), p_star->GetRect());

        if (is_col || is_col1 || is_col2 || is_col3) 
		{
            if (is_col3) 
			{
				mark_value += 10;
				p_star->Reset(-5000);
				star_value++;
            } 
			else 
			{
				mark_value += 30;
            }

            if (is_col) 
			{
                p_cake1->Reset(-50);
            }

            if (is_col1) 
			{
                p_cake2->Reset(-100);
            }

            if (is_col2)
			{
                p_cake3->Reset(-20);
            }
        }

		// check collision cake 
		player_power.Render(g_screen);
		bool is_die1 = p_cake1->CakeExit(p_cake1->GetRect().y);
		bool is_die2 = p_cake2->CakeExit(p_cake2->GetRect().y);
		bool is_die3 = p_cake3->CakeExit(p_cake3->GetRect().y);

		if (is_die1 || is_die2 || is_die3) 
		{
			die_count++;
			player_power.Decrease();
			player_power.Render(g_screen);
			if (is_die1) 
			{
				p_cake1->Reset(-100);
				is_die1 = false;
			}
			if (is_die2)
			{
				p_cake2->Reset(-50);
				is_die2 = false;
			}
			if (is_die3) 
			{
				p_cake3->Reset(-200);
				is_die3 = false;
			}
		}
		//if(star_value == 10)
		//{
		//	if(die_count > 0)
		//	{
		//		die_count--;
		//	}
		//	player_power.Increase();
		//	player_power.Render(g_screen);
		//	star_value = 0 ;
		//}

        //check collision main with bomb
		bool is_bomb = SDLCommonFunc::CheckCollision(human_object.GetRect(), p_bomb->GetRect());

		if (is_bomb) 
		{
			for (int ex = 0; ex < 4; ex++)
			{
				int x_pos = (p_bomb->GetRect().x + p_bomb->GetRect().w * 0.5) - EXPLOSION_WIDTH * 0.5;
				int y_pos = (p_bomb->GetRect().y + p_bomb->GetRect().h * 0.5) - EXPLOSION_HEIGHT * 0.5;
				exp_main->set_frame(ex);
				exp_main->SetRect(x_pos, y_pos);
				exp_main->ShowEx(g_screen);
				SDL_Delay(150);
				if (SDL_Flip(g_screen) == -1) 
				{
					return 0;
				}
			}
			p_bomb->Reset(-200);
		}
		// Show mark to the screen 
		std::string val_str_mark = std::to_string(mark_value);
		std::string strMark("Mark: ");
		strMark += val_str_mark;

		mark_game.SetText(strMark);   
		mark_game.CreateGameText(g_font_text, g_screen);
		// Handle Game Over 

		if(die_count > 3 || is_bomb)
		{
			SDL_Delay(1000);
			is_gameover = true;
			// not fix the is_gameover with is_bomb
			SDLCommonFunc::CleanUp();
			int ret_back_menu = SDLCommonFunc::ShowBackMenu(g_screen, g_font_menu);
			if (ret_back_menu == 1)
			{
				is_quit = true;
			}

			/*SDLCommonFunc::ApplySurface(gMark, g_screen, 250, 250);*/
		}


		//update screen;
        if (SDL_Flip(g_screen) == -1)
		{
			SDLCommonFunc::CleanUp();
			SDL_Quit();
			return 0;
		}
    }
    // Clean up resources
    SDLCommonFunc::CleanUp();
    SDL_Quit();
	TTF_Quit();
    return 1;
}