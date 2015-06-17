//  [GeistYp]

#pragma once

#include "ofMain.h"
#include "GLFW/glfw3.h"
// Loading Thread use OpenGL share context 
// eg. 
//		ofxLoadingThread loader;
//		loader.initContext();
//		loader.setLoadFunc(std::bind(&ofApp::load, this));
//		loader.start()
class ofxLoadingThread : public ofThread
{
public:
	ofxLoadingThread();
	~ofxLoadingThread();

	void initContext();
	void setLoadFunc(std::function<void()> f){ func = f; }

	void start();
	virtual void threadedFunction();
	bool isLoaded(){ return bLoaded; }

private:

	//auto func;
	std::function<void()> func;

	GLFWwindow* shared_context;

	bool	bLoaded;

};

