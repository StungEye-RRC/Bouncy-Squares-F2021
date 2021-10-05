#pragma once
#include <iostream>

class Bouncer {
	const static int maxSpeed{6};
	const static int minSpeed{-6};
	float xPosition{0};
	float yPosition{0};
	float xSpeed{1};
	float ySpeed{1};
	float size{20};

public:
	// Constructors
	Bouncer() = default;
	Bouncer(float x, float y, float xs, float ys, float s);
	Bouncer(int maxWidth, int maxHeight);

	// Destructor
	~Bouncer();

	// Member Functions / Instance Functions / Methods
	void updatePosition();
	void updateSpeed(float canvasWidth, float canvasHeight);
	virtual void draw() const;
};
