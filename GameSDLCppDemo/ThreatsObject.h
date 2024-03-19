#ifndef THREATS_OBJECT_H
#define THREATS_OBJECT_H
#include "Common_Function.h";
#include "BaseObject.h";
#define WIDTH_THREAT
#define HEIGHT_THREAT 

class ThreatsObject : public BaseObject{
	ThreatsObject();
	~ThreatsObject();

	void HandleMove(const int& x_bordr,const int& y_bordr);
	void HandleInputAction(SDL_Event events);
private:
	int x_val_ ;
	int y_val_ ;

};
#endif