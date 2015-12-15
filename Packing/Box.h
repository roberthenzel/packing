#pragma once
#ifndef BOX_H
#define BOX_H

#include <stdlib.h>
#include <time.h>
#include <cmath>

class Box
{
private:
	short baseSize;
public:
	Box();
	virtual ~Box();
	short base();
};

class Ball : public Box
{
private:
	float volume;
public:
	Ball();
	virtual ~Ball();
};

class Cube : public Box
{
private:
	float volume;
public:
	Cube();
	virtual	~Cube();
};

class Tetrahederon : public Box
{
private:
	float volume;
public:
	Tetrahederon();
	virtual ~Tetrahederon();
	
};

#endif // BOX_H