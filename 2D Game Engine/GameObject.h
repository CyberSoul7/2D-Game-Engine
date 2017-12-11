#pragma once
#include "Game.h"

class GameObject {

public:
	GameObject(const char* texturesheet, int x, int y);
	~GameObject();

	void update();
	void render();
	
	int getX() {
		return xpos;
	}
	int getY() {
		return ypos;
	}
	int getVelX() {
		return velx;
	}
	int getVelY() {
		return vely;
	}

	void setX(int x) {
		xpos = x;
	}
	void setY(int y) {
		ypos = y;
	}
	void setVelX(int velx) {
		this->velx = velx;
	}
	void setVelY(int vely) {
		this->vely = vely;
	}

	bool registered() {
		return isRegistered;
	}

private:
	int xpos, ypos, velx, vely;

	const char* texturesheet;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;

	bool isRegistered;

};