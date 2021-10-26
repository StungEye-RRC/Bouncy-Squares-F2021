#pragma once
#include <iostream>


class Bouncer {
	enum class bouncerState { moving, hovered, paused };

	const static int maxSpeed{3};
	const static int minSpeed{-3};
	float xPosition{0};
	float yPosition{0};
	float xSpeed{1};
	float ySpeed{1};
	float size{20};
	bouncerState state{bouncerState::moving};

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
	void setup(float x, float y, float xs, float ys, float s);
	void processMouse(float mouseX, float mouseY, bool isMousePressed);

	friend std::ostream& operator<<(std::ostream& out, const Bouncer& bouncer);

private:
	bool isBouncerHovered(float mouseX, float mouseY) const;

};
