#include "ofxLoadingThread.h"


ofxLoadingThread::ofxLoadingThread() : bLoaded(false)
{
	
}


ofxLoadingThread::~ofxLoadingThread()
{
}

void ofxLoadingThread::initContext()
{
	// get current device
	m_hdc = wglGetCurrentDC();

	// get current opengl context
	m_current_rc = wglGetCurrentContext();
	// create a opengl context from current device
	m_loading_rc = wglCreateContext(m_hdc);

	// share current opengl context to loading context
	wglShareLists(m_loading_rc, m_current_rc);
	//wglShareLists(g_current_rc, g_loading_rc);

	wglMakeCurrent(m_hdc, m_current_rc);
}

void ofxLoadingThread::start()
{
	bLoaded = false;
	startThread();
}

void ofxLoadingThread::threadedFunction()
{
	// set current thread opengl context
	wglMakeCurrent(m_hdc, m_loading_rc);

	// call load func
	if ( func != nullptr ) func();

	bLoaded = true;
}
