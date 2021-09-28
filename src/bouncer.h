#pragma once

class Bouncer {
	float xPosition{0};
	float yPosition{0};
	float xSpeed{1};
	float ySpeed{1};

public:
	Bouncer(float x, float y, float xs, float ys);
	void updatePosition();
	void updateSpeed(float canvasWidth, float canvasHeight);
	void draw();
};
