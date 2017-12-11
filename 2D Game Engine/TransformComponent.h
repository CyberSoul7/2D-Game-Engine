#pragma once

#include "Components.h"

class TransformComponent : public Component {
public:

	TransformComponent() {
		xpos = 0;
		ypos = 0;
	}

	TransformComponent(int x, int y) {
		xpos = x;
		ypos = y;
	}

	int x() { return xpos; }
	int y() { return ypos; }

	void update() override {
		xpos++;
		ypos++;
	}

	void setPosition(int x, int y) {
		xpos = x;
		ypos = y;
	}
private:
	int xpos, ypos;
};