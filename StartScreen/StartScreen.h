#pragma once
#include <iostream>
#include <fstream>
#include <windows.h>
#include <string>
#include <mmsystem.h>
using namespace std;


void fixConsoleWindow();

void goToXY(int x, int y);

void textcolor(int x);

void noCursorType();

void SetWindowSize(SHORT width, SHORT height);

//***************************************************************

void startScreen(int x0, int y0);

void khtn(int x, int y, int speed, int delay, int color);

void team5(int x, int y, int speed, int delay, int color);