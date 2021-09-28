#include "bouncer.h"
#include "ofGraphics.h"

// TODO: Make some overloaded constructors and add square size as a private member.
Bouncer::Bouncer(const float x, const float y, const float xs, const float ys)
	: xPosition{x}, yPosition{y}, xSpeed{xs}, ySpeed{ys} {
}

void Bouncer::updatePosition() {
	xPosition += xSpeed;
	yPosition += ySpeed;
}

void Bouncer::updateSpeed(float canvasWidth, float canvasHeight) {
	if (xPosition > canvasWidth || xPosition < 0) {
		xSpeed *= -1;
	}

	if (yPosition > canvasHeight || yPosition < 0) {
		ySpeed *= -1;
	}

}

// TODO: Make this function const so that we can use a const reference in the ofApp::draw loop.
void Bouncer::draw() {
	ofDrawRectangle(xPosition, yPosition, 20, 20);
}
