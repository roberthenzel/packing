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

Cube::Cube() {
	auto a = base();
	volume = a * a * a;
}
bool Cube::operator<(Cube const &c) {
	return this->volume > c.volume;
}


Cube::~Cube() {

}

Ball::Ball() {
	short r = base();
	volume = M_PI * 4 / 3 * pow(r, 3);
	
}

Ball::~Ball() {

}

Tetrahederon::Tetrahederon() {
	auto a = base();
	volume = (sqrt(2) / 12) * pow(a, 3);
}

Tetrahederon::~Tetrahederon() {

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
	double originalPackageVolume = package;
	std::list<Cube> cubes;



	for (int i = 0 ; i < time; i++) {
		addCubesToList(cubeOutput, cubes);

		std::cout << "\n";
		std::cout << packageVolume << " Iteracja " << i+1 << " \n";
		std::cout << "\n";

		substractCubesFromList(cubeOutput, cubes);

		if (packageVolume > 0.0) {
			std::cout << "Powstal przestuj w pracy";
		}
		std::cout << "\n";
		std::cout << packageVolume << " Po Iteracji " << i +1<< " \n";
		std::cout << "\n";

	}
}

void Pack::addCubesToList(int cubeOutput, std::list<Cube> &cubes) {
	for (int j = 0; j < cubeOutput; j++) {
		Cube Cube;
		//Cube.showVolume();										//wyprodukowano x cubes o pojemnosci v volume
		cubes.push_back(Cube);	
	}
	cubes.sort();
}

void Pack::substractCubesFromList(int cubeOutput, std::list<Cube> &cubes) {
	for (int j = 0; j < cubeOutput; j++) {
		if (packageVolume > 0) {
			Cube *temp;
			temp = &cubes.back();
			double v = temp->getVolume();					
			if (packageVolume > v) {
				packageVolume -= v;
				cubes.pop_back();
				std::cout << packageVolume << std::endl;
			}
		}
	}
}


Pack::~Pack() {
}
