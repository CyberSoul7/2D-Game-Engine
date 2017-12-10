#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char* texturesheet, int x, int y) {
	this->texturesheet = texturesheet;

	xpos = x;
	ypos = y;
}

GameObject::~GameObject()
{}

void GameObject::update() {

	xpos += velx;
	ypos += vely;

	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos;
	destRect.y = ypos;
	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;

}

void GameObject::render(SDL_Renderer* renderer) {
	if (!objTexture) {
		objTexture = TextureManager::LoadTexture(texturesheet, renderer);
	}
	SDL_RenderCopy(renderer, objTexture, &srcRect, &destRect);
}