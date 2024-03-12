#ifndef MAIN_OBJECT_H_
#define MAIN_OBJECT_H_

#include "Common_Function.h"
#include "BaseObject.h"

#define WIDTH_MAIN_OBJECT  90 // Example value, change it accordingly
#define HEIGHT_MAIN_OBJECT 108 // Example value, change it accordingly

class MainObject : public BaseObject {
public:
    MainObject();
    ~MainObject(); 

    void HandleInputAction(SDL_Event events,MainObject* p_obj);
    void HandleMove();

private: 
    int x_val_; 
    int y_val; 
};

#endif
