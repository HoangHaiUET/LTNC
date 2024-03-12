#include "CakeObject.h"
#include "Common_Function.h"
#include "BaseObject.h"

CakeObject::CakeObject() {
    rect_.x = SCREEN_WIDTH * 0.2;
    rect_.y = 0;
    rect_.w = WIDTH_CAKE;
    rect_.h = HEIGHT_CAKE;
    y_val_ = 0;
}

CakeObject::~CakeObject() {
}

void CakeObject::HandleMove(const int& x_border, const int& y_border) {
    rect_.y += y_val_;

    if (rect_.y > SCREEN_HEIGHT + 20) {
        rect_.y = -10;
        int rand_x = rand() % 500;
        if (rand_x > SCREEN_WIDTH) {
            rand_x = (int)(SCREEN_WIDTH * 0.1);
        }
        rect_.x = rand_x;
    }
}

void CakeObject::Reset(const int& yboder) {
    rect_.y = yboder;

    int rand_x = rand() % 500;
    if (rand_x > SCREEN_WIDTH) {
        rand_x = (int)(SCREEN_WIDTH * 0.5);
    }
    rect_.x = rand_x;
}

bool CakeObject::CakeExit(const int& ye) {
    if (ye >= SCREEN_HEIGHT + 2) {
        return true;
    }
    return false;
}
