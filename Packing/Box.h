#pragma once
#ifndef BOX_H
#define BOX_H

#include <cmath>
#include <list>

class Box
{
private:
	short baseSize;
protected:	
	double volume;
public:
	Box();
	virtual ~Box();
	short base();
	void showVolume();
	double getVolume();
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
	bool operator<(Cube const &c);
	virtual	~Cube();
};

class Tetrahederon : public Box
{
private:
public:
	Tetrahederon();
	virtual ~Tetrahederon();
	
};

class Pack {
private:
	int time;
	int cubeOutput;
	int ballOutput;
	int tetrahederonOutput;
	double packageVolume;

	
	

public:
	Pack();
	Pack(int time, int c, int b, int t, double package);
	virtual ~Pack();
	
private:
	void addCubesToList(int cubeOutput,std::list<Cube> &cubes);
	void addBallsToList();
	void addTetraToList();
	void substractCubesFromList(int cubeOutput, std::list<Cube> &cubes);
	void substructBallsFromList();
	void substractTetraFromList();
};

#endif // BOX_H