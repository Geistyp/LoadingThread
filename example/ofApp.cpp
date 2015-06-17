#include "ofApp.h"
#include "ofxLoadingThread.h"

void ofApp::preload()
{
	img.load("1.jpg");
}

//--------------------------------------------------------------
void ofApp::setup(){

	loadingThread.initContext();
	loadingThread.setLoadFunc(std::bind(&ofApp::preload, this));
	loadingThread.start();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	if (!loadingThread.isLoaded()){
		ofDrawBitmapString("Loading~", 10, 10);
		return;
	}
	if (img.bAllocated()) img.draw(0, 0);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
