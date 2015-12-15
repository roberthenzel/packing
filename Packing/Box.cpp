#include "stdafx.h"
#include "Box.h"
#include <cmath>



Box::Box(){	
	srand(time(NULL)); //do maina
	Box::baseSize = rand() % 10 + 1;
}

Box::~Box(){
	
}

short Box::base() {
	return baseSize;
}

Cube::Cube() {
	auto a = base();
	Cube::volume = a * a * a;
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
	short a = base();
	Tetrahederon::volume = (sqrt(2) / 12) * pow(a, 3);
}

Tetrahederon::~Tetrahederon() {

}