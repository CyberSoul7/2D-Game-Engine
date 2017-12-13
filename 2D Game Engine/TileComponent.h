#pragma once

#include "ECS.h"
#include "Components.h"
#include "SDL.h"

enum TileType {
	WATER,
	GRASS,
	DIRT
};

class TileComponent : public Component {
public:
	TransformComponent* transform;
	SpriteComponent* sprite;

	SDL_Rect tileRect;
	TileType type;
	const char* path;

	TileComponent() = default;

	TileComponent(int x, int y, int w, int h, TileType type) {
		tileRect.x = x;
		tileRect.y = y;
		tileRect.w = w;
		tileRect.h = h;
		this->type = type;

		switch (type)
		{
		case WATER:
			path = "assets/water.png";
			break;
		case DIRT:
			path = "assets/dirt.png";
			break;
		case GRASS:
			path = "assets/grass.png";
		default:
			break;
		}

	}

	void init() override {
		entity->addComponent<TransformComponent>(tileRect.x, tileRect.y, tileRect.w, tileRect.h, 1);
		transform = &entity->getComponent<TransformComponent>();

		entity->addComponent<SpriteComponent>(path);
		sprite = &entity->getComponent<SpriteComponent>();
	}

};