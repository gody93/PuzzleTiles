﻿#ifndef APPLICATION_H
#define APPLICATION_H
#include "DrawMgr.h"

class Application
{
public:
	Application();
	~Application();

	void Start();
	void Quit();
private:

};

extern Application gApp;

#endif