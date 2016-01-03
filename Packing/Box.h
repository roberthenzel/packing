#pragma once
#ifndef BOX_H
#define BOX_H

#include <cmath>
#include <list>
#include <iostream>

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
	bool operator<(Ball const &b);
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
	bool operator<(Tetrahederon const &t);
	virtual ~Tetrahederon();	
};

class Raport {
private:
	std::string text;
	double packageVolume;
public:
	Raport();
	Raport(std::string text, double packageVolume);
	void addVolume(int cubeOutput, double iterationVolume, int iterationNumber);
	~Raport();
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
	void addCubesToList(int cubeOutput,std::list<Cube> &cubes, int i, Raport r);
	void addBallsToList(int ballOutput, std::list<Ball> &balls, int i, Raport r);
	void addTetrasToList(int tetraOutput, std::list<Tetrahederon> &tetras, int i, Raport r);
	void substractCubesFromList(int cubeOutput, std::list<Cube> &cubes);
	void substructBallsFromList(int ballOutput, std::list<Ball> &balls);
	void substractTetraFromList(int tetraOutput, std::list<Tetrahederon> &tetras);
};

#endif // BOX_H