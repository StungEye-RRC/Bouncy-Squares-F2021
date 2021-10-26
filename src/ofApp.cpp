#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetWindowPosition(1200, 200);

	bouncers.reserve(numberOfBouncers);

	for (auto i = 0; i < numberOfBouncers; ++i) {
		// We could create bouncer objects and then push them to the vector.
		/*
		const float xPosition = ofRandomWidth();
		const float yPosition = ofRandomHeight();
		const float xSpeed = ofRandom(-4, 4);
		const float ySpeed = ofRandom(-4, 4);
		const float size = ofRandom(3, 75);

		Bouncer bouncer{xPosition, yPosition, xSpeed, ySpeed};
		bouncers.push_back(bouncer);
		*/

		// Or we could have the vector construct the bouncer while
		// it places it at the end of the vector.
		bouncers.emplace_back(ofGetWidth(), ofGetHeight());
	}
}

//--------------------------------------------------------------
void ofApp::update() {
	for (auto& bouncer : bouncers) {
		bouncer.processMouse(ofGetMouseX(), ofGetMouseY(), ofGetMousePressed());
		bouncer.updatePosition();
		bouncer.updateSpeed(ofGetWidth(), ofGetHeight());
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	for (const auto& bouncer : bouncers) {
		std::cout << " PRE " << bouncer << " POST " << "\n";
		bouncer.draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
