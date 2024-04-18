#ifndef FOLLOWER_H_
#define FOLLOWER_H_

#include "Common_Function.h"
#include "BaseObject.h"

class Follower : public BaseObject{
public:
	Follower();
	~Follower();
	void ShowFollower(SDL_Surface *des);
	void MoveFollower(SDL_Rect human);
	void SetPreviousPosition(const int& x, const int& y){
		previous_position.x = x;
		previous_position.y = y;
	}
	SDL_Rect GetPreviousPosition(){return previous_position;}


private:
	int x_val_;
	int y_val_;
	SDL_Rect previous_position;
};
#endif