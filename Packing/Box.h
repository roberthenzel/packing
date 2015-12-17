#pragma once
#ifndef BOX_H
#define BOX_H

#include <cmath>

class Box
{
private:
	short baseSize;
protected:	
	float volume;
public:
	Box();
	virtual ~Box();
	short base();
};

class Ball : public Box
{
private:
public:
	Ball();
	virtual ~Ball();
};

class Cube : public Box
{
private:
public:
	Cube();
	virtual	~Cube();
};

class Tetrahederon : public Box
{
private:
public:
	Tetrahederon();
	virtual ~Tetrahederon();
	
};

#endif // BOX_H