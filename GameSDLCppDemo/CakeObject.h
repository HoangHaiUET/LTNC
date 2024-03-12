#ifndef CAKE_OBJECT_H_
#define CAKE_OBJECT_H_

#include "Common_Function.h"
#include "BaseObject.h"

#define WIDTH_CAKE 40
#define HEIGHT_CAKE 40

class CakeObject : public BaseObject {
public:
    CakeObject();
    ~CakeObject();

    void HandleMove(const int& x_border, const int& y_border);
    void set_y_val(const int& val) { y_val_ = val; }
    void Reset(const int& yboder);
    bool CakeExit(const int& ye);

private:
    int x_val_; // This member variable is not used in the provided implementation
    int y_val_; // This member variable is used for vertical movement
};

#endif
