//  [GeistYp]

#pragma once

#include "ofMain.h"

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

	// auto func;
	std::function<void()> func;

	HDC		m_hdc;				// current win device
	HGLRC	m_current_rc;		// current opengl context
	HGLRC	m_loading_rc;		// created opengl context

	bool	bLoaded;

};

