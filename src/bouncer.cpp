#include "bouncer.h"
#include "ofGraphics.h"
#include "ofMath.h"

// TODO: Make some overloaded constructors and add square size as a private member.
Bouncer::Bouncer(const float x, const float y, const float xs, const float ys, const float s)
	: xPosition{x}, yPosition{y}, xSpeed{xs}, ySpeed{ys}, size{s} {
	// New Initializer for size
}

Bouncer::Bouncer(int maxWidth, int maxHeight) {

	xPosition = maxWidth / 2.0;
	yPosition = maxHeight / 2.0;
	xSpeed = ofRandom(minSpeed, maxSpeed);
	ySpeed = ofRandom(minSpeed, maxSpeed);
	size = ofRandom(5, 15);
}

Bouncer::~Bouncer() {
	std::cout << "Bouncer Destructor Called\n";
}

void Bouncer::updatePosition() {
	xPosition += xSpeed;
	yPosition += ySpeed;
}

void Bouncer::updateSpeed(const float canvasWidth, const float canvasHeight) {
	if (xPosition > canvasWidth || xPosition < 0) {
		xSpeed *= -1;
	}

	if (yPosition > canvasHeight || yPosition < 0) {
		ySpeed *= -1;
	}
}

void Bouncer::draw() const {
	ofDrawRectangle(xPosition, yPosition, size, size);
}
