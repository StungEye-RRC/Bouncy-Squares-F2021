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
	size = ofRandom(15, 30);
}

Bouncer::~Bouncer() {
	std::cout << "Bouncer Destructor Called\n";
}

void Bouncer::updatePosition() {
	if (state != bouncerState::paused) {
		xPosition += xSpeed;
		yPosition += ySpeed;
	}
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
	if (state == bouncerState::moving) {
		ofSetColor(255);
	} else if (state == bouncerState::hovered) {
		ofSetColor(0, 0, 255);
	} else if (state == bouncerState::paused) {
		ofSetColor(255, 0, 0);
	}

	ofSetRectMode(OF_RECTMODE_CENTER);
	ofDrawRectangle(xPosition, yPosition, size, size);
}

void Bouncer::setup(float x, float y, float xs, float ys, float s) {
	xPosition = x;
	yPosition = y;
	xSpeed = xs;
	ySpeed = ys;
	size = s;
}

void Bouncer::processMouse(float mouseX, float mouseY, bool isMousePressed) {
	if (isBouncerHovered(mouseX, mouseY) && isMousePressed) {
		state = bouncerState::paused;
	} else if (isBouncerHovered(mouseX, mouseY)) {
		state = bouncerState::hovered;
	} else {
		state = bouncerState::moving;
	}
}

bool Bouncer::isBouncerHovered(float mouseX, float mouseY) const {
	return (
		mouseX > (xPosition - (size / 2.0)) &&
		mouseX < (xPosition + (size / 2.0)) &&
		mouseY > (yPosition - (size / 2.0)) &&
		mouseY < (yPosition + (size / 2.0))
	);
}

std::ostream& operator<<(std::ostream& out, const Bouncer& bouncer) {
	out << "BOUNCER  xPos: " << bouncer.xPosition << " yPos: " << bouncer.yPosition;
	return out;
}
