#ifndef APPLICATION_H
#define APPLICATION_H
#include "DrawMgr.h"

class Application
{
public:
	static Application* getApp();
	void Start();
	~Application();




// void Start();
	// void Quit();
private:
	Application();

	static Application* app;

};

#endif
