#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetRectMode(OF_RECTMODE_CENTER);
	for (auto i = 0; i < 15; ++i) {
		const float xPosition = ofRandomWidth();
		const float yPosition = ofRandomHeight();
		const float xSpeed = ofRandom(-4, 4);
		const float ySpeed = ofRandom(-4, 4);

		// We could first create a bouncer object and then push
		// it to the vector.
		// Bouncer bouncer{xPosition, yPosition, xSpeed, ySpeed};
		// bouncers.push_back(bouncer);

		// Or we could have the vector construct the bouncer while
		// it places it at the end of the vector.
		bouncers.emplace_back(xPosition, yPosition, xSpeed, ySpeed);
	}
}

//--------------------------------------------------------------
void ofApp::update() {
	for (auto& bouncer : bouncers) {
		bouncer.updatePosition();
		bouncer.updateSpeed(ofGetWidth(), ofGetHeight());
	}
}

//--------------------------------------------------------------
void ofApp::draw() {
	for (auto bouncer : bouncers) {
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
