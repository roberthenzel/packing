#include "stdafx.h"
#include "Box.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include <list>
#include <iostream>




Box::Box(){	
	baseSize = rand() % 10 + 1;
}

Box::~Box(){
	
}

double Box::getVolume() {
	return volume;
}
void Box::showVolume() {
	std::cout << volume << "\n";
}

short Box::base() {
	return baseSize;
}

Ball::Ball() {
	short r = base();
	volume = M_PI * 4 / 3 * pow(r, 3);
}

bool Ball::operator<(Ball const &b) {
	return this->volume < b.volume;
}

Ball::~Ball() {
}

Cube::Cube() {
	auto a = base();
	volume = a * a * a;
}
bool Cube::operator<(Cube const &c) {
	return this->volume < c.volume;
}


Cube::~Cube() {

}


Tetrahederon::Tetrahederon() {
	auto a = base();
	volume = (sqrt(2) / 12) * pow(a, 3);
}
bool Tetrahederon::operator<(Tetrahederon const &t) {
	return this->volume < t.volume;
}

Tetrahederon::~Tetrahederon() {

}

Raport::Raport() {
	text = "Empty";
	packageVolume = 0.0;
}
Raport::Raport(std::string text, double packageVolume) {
	this->text = text;
	this->packageVolume = packageVolume;
}
void Raport::addVolume(int itemOutput, double iterationVolume, int iterationNumber) {
	
	std::cout << "W " << iterationNumber << " godzinie wyprodukowano " << itemOutput << " opakowan szesciennych o lacznej objetosci: ";
	std::cout << iterationVolume << std::endl;
	//if((iterationVolume / packageVolume) * 100>100.0)
	//std::cout << "Zapelniono " << 100 <<"% paczki. ";
}
Raport::~Raport() {
}

Pack::Pack() {
	time = 0;
	cubeOutput = 0;
	ballOutput = 0;
	tetrahederonOutput = 0;
	packageVolume = 0.0;
}

Pack::Pack(int t, int cube, int ball, int tetrahedereon, double package) {
	time = t;
	cubeOutput = cube;
	ballOutput = ball;
	tetrahederonOutput = tetrahedereon;
	packageVolume = package;
	
	std::list<Cube> cubes;
	std::list<Ball> balls;
	std::list<Tetrahederon> tetras;

	Raport raport("Raport z produkcji\n",packageVolume);


	for (int i = 0 ; i < time; i++) {
		std::cout << "\n";
		std::cout << packageVolume << " Iteracja " << i + 1 << " \n";
		std::cout << "\n";

		addBallsToList(ballOutput, balls, i, raport);
		addCubesToList(cubeOutput, cubes, i, raport);
		addTetrasToList(tetrahederonOutput, tetras, i, raport);

		substructBallsFromList(ballOutput, balls);
		substractCubesFromList(cubeOutput, cubes);
		substractTetraFromList(tetrahederonOutput,tetras);

		
		std::cout << "\n";
		std::cout << packageVolume << " Po Iteracji " << i +1<< " \n";
		std::cout << "\n";

		packageVolume = package;
	}
}

void Pack::addCubesToList(int cubeOutput, std::list<Cube> &cubes, int i, Raport r) {
	double sumOfVolume = 0.0;

	for (int j = 0; j < cubeOutput; j++) {
		Cube Cube;
		Cube.showVolume();
		sumOfVolume += Cube.getVolume();								
		cubes.push_back(Cube);	
	}
	cubes.sort();
	
	r.addVolume(cubeOutput,sumOfVolume,i + 1);
}

void Pack::substractCubesFromList(int cubeOutput, std::list<Cube> &cubes) {
	int endOfLoop = cubes.size();
	int counter = 0;
	for (int j = 0; j < endOfLoop; j++) {
		Cube *temp;
		temp = &cubes.back();
		double v = temp->getVolume();
		std::cout << v << "c ";
		if (packageVolume > v) {
			packageVolume -= v;
			cubes.pop_back();
			std::cout << packageVolume << std::endl;
		}
		else {
			temp = &cubes.front();
			v = temp->getVolume();
			std::cout << v << "c ";
			if(packageVolume > v){
				packageVolume -= v;
				cubes.pop_front();
				std::cout << packageVolume << std::endl;
			}
			else break;
		}
	}	
		counter++;
}

void Pack::addBallsToList(int ballOutput, std::list<Ball> &balls, int i, Raport r){
	double sumOfVolume = 0.0;

	for (int j = 0; j < ballOutput; j++) {
		Ball Ball;
		Ball.showVolume();
		sumOfVolume += Ball.getVolume();
		balls.push_back(Ball);
	}
	balls.sort();

	r.addVolume(ballOutput, sumOfVolume, i + 1);
}

void Pack::substructBallsFromList(int ballOutput, std::list<Ball> &balls) {
	int endOfLoop = balls.size();
	int counter = 0;
	for (int j = 0; j < endOfLoop; j++) {
		Ball *temp;
		temp = &balls.back();
		double v = temp->getVolume();
		std::cout << v << "b ";
		if (packageVolume > v) {
			packageVolume -= v;
			balls.pop_back();
			std::cout << packageVolume << std::endl;
		}
		else {
			temp = &balls.front();
			v = temp->getVolume();
			std::cout << v << "b ";
			if (packageVolume > v) {
				packageVolume -= v;
				balls.pop_front();
				std::cout << packageVolume << std::endl;
			}
			else break;
		}
	}
	counter++;
}

void Pack::addTetrasToList(int tetraOutput, std::list<Tetrahederon> &tetras, int i, Raport r) {
	double sumOfVolume = 0.0;

	for (int j = 0; j < tetraOutput; j++) {
		Tetrahederon Tetra;
		Tetra.showVolume();
		sumOfVolume += Tetra.getVolume();
		tetras.push_back(Tetra);
	}
	tetras.sort();
	r.addVolume(tetraOutput, sumOfVolume, i + 1);
}

void Pack::substractTetraFromList(int tetraOutput, std::list<Tetrahederon> &tetras) {
	int endOfLoop = tetras.size();
	int counter = 0;
	for (int j = 0; j < endOfLoop; j++) {
		Tetrahederon *temp;
		temp = &tetras.back();
		double v = temp->getVolume();
		std::cout << v << "t ";
		if (packageVolume > v) {
			packageVolume -= v;
			tetras.pop_back();
			std::cout << packageVolume << std::endl;
		}
		else {
			temp = &tetras.front();
			v = temp->getVolume();
			std::cout << v << "t ";
			if (packageVolume > v) {
				packageVolume -= v;
				tetras.pop_front();
				std::cout << packageVolume << std::endl;
			}
			else break;
		}
	}
	counter++;
}

Pack::~Pack() {
}


