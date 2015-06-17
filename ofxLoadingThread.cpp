#include "ofxLoadingThread.h"

ofxLoadingThread::ofxLoadingThread() 
	: bLoaded(false),
	shared_context(NULL)
{
	
}


ofxLoadingThread::~ofxLoadingThread()
{
	stopThread();
	if (shared_context) glfwDestroyWindow(shared_context);
}

void ofxLoadingThread::initContext()
{
	GLFWwindow* current_context = glfwGetCurrentContext();
	shared_context = glfwCreateWindow(1, 1, "loading thread", NULL, current_context);
	//glfwShowWindow(shared_context);
	glfwMakeContextCurrent(current_context);
}

void ofxLoadingThread::start()
{
	bLoaded = false;
	startThread();
}

void ofxLoadingThread::threadedFunction()
{
// 	if (!bInited)
// 	{
// 		initContext();
// 	}
	// set shared context
	glfwMakeContextCurrent(shared_context);

	// call load func
	if ( func != nullptr ) func();

	bLoaded = true;
}
