﻿#ifndef APPLICATION_H
#define APPLICATION_H

#include "DrawMgr.h"
#include "Board.h"

class Application
{
public:
	static Application* getApp();
	void Start();
	~Application();

private:
	Application();
	static Application* app;
    bool pressStart;
};

#endif
