#ifndef APPLICATION_H
#define APPLICATION_H

#include "DrawMgr.h"
#include "Cube.h"

class Application
{
public:
	static Application* getApp();
	void Start();
	~Application();

private:
	Application();

	static Application* app;

};

#endif
