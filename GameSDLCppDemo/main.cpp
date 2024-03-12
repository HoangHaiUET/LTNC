#include "Common_Function.h"
#include "MainObject.h"
#include "CakeObject.h"
#include "ExplosionObject.h"

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

    ExplosionObject* exp_main = new ExplosionObject(); // Corrected initialization
    ret = exp_main->LoadImg("explosion.png"); // Provide the correct image file path
	exp_main->set_clips();
    if (ret == false) return 0;

    CakeObject* p_cake1 = new CakeObject();
    ret = p_cake1->LoadImg("doyaki.png");
    if (ret == false) {
        return 0;
    }
    p_cake1->SetRect(120 + rand() % 80, -100);

    CakeObject* p_cake2 = new CakeObject();
    ret = p_cake2->LoadImg("cake.png");
    if (ret == false) {
        return 0;
    }
    p_cake2->SetRect(120 + rand() % 80, -100);

    CakeObject* p_cake3 = new CakeObject();
    ret = p_cake3->LoadImg("takoyaki.png");
    if (ret == false) {
        return 0;
    }
    p_cake3->SetRect(120 + rand() % 80, -100);

    CakeObject* p_star = new CakeObject();
    ret = p_star->LoadImg("star.png");
    if (ret == false) {
        return 0;
    }
    p_star->SetRect(360 + rand() % 80, -5000);

    CakeObject* p_bomb = new CakeObject();
    ret = p_bomb->LoadImg("bom.png");
    if (ret == false) {
        return 0;
    }
    p_bomb->SetRect(480 + rand() % 80, -300);

    bool is_gameover = false;

    while (!is_quit) {
        while (SDL_PollEvent(&g_even)) {
            if (g_even.type == SDL_QUIT) {
                is_quit = true;
                break;
            }
            human_object.HandleInputAction(g_even, &human_object);
        }
        SDLCommonFunc::ApplySurface(g_bkground, g_screen, 0, 0);
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

        // Check collision main and cake
        // bomb is named to threats

        bool is_col = SDLCommonFunc::CheckCollision(human_object.GetRect(), p_cake1->GetRect());
        bool is_col1 = SDLCommonFunc::CheckCollision(human_object.GetRect(), p_cake2->GetRect());
        bool is_col2 = SDLCommonFunc::CheckCollision(human_object.GetRect(), p_cake3->GetRect());
        bool is_col3 = SDLCommonFunc::CheckCollision(human_object.GetRect(), p_star->GetRect());

        if (is_col || is_col1 || is_col2 || is_col3) {
            if (is_col3) {
                // mark
            } else {
                // mark
            }

            if (is_col) {
                p_cake1->Reset(-50);
            }

            if (is_col1) {
                p_cake2->Reset(-100);
            }

            if (is_col2) {
                p_cake3->Reset(-20);
            }

            if (is_col3) {
                p_star->Reset(-5000);
            }
        }

        // Check collision with bomb
        bool is_bomb = SDLCommonFunc::CheckCollision(human_object.GetRect(), p_bomb->GetRect());
        if (is_bomb) {
            for (int ex = 0; ex < 4; ex++) {
                int x_pos = (p_bomb->GetRect().x + p_bomb->GetRect().w * 0.5) - EXPLOSION_WIDTH * 0.5;
                int y_pos = (p_bomb->GetRect().y + p_bomb->GetRect().h * 0.5) - EXPLOSION_HEIGHT * 0.5;
                exp_main->set_frame(ex); // Set the frame before showing
                exp_main->SetRect(x_pos, y_pos);
                exp_main->ShowEx(g_screen);
                SDL_Delay(150);
                if (SDL_Flip(g_screen) == -1) {
                    return 0;
                }
            }
            // Handle game over
            is_gameover = true;
            break; // Exit the loop to handle game over actions
        }

        if (SDL_Flip(g_screen) == -1) return 0;
    }

    // Handle game over actions here

    // Clean up resources
    SDLCommonFunc::CleanUp();
    SDL_Quit();
    return 1;
}