#include "Follower.h"

Follower::Follower(){
	x_val_ = 0;
	y_val_ = 0;
	previous_position.x = 0;
	previous_position.y = 0;
}

Follower::~Follower(){

}

void Follower::ShowFollower(SDL_Surface *des){
	p_object_ = SDLCommonFunc::LoadImage("Dora_rinh.png"); 
	SDLCommonFunc::ApplySurface(p_object_, des, rect_.x, rect_.y);
}

void Follower::MoveFollower(SDL_Rect human) {
	// Calculate the direction from the follower to the human
	int dx = human.x - rect_.x;
	int dy = human.y - rect_.y;

	// Move the follower towards the human (adjust speed as needed)
	rect_.x += dx * 0.1;
	rect_.y += dy * 0.1;
}
