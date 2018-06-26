#include "Fruit.h"



Fruit::Fruit()
{
	//set values for default constructor
	setType("null");
	setColour(Scalar(0,0,0));

}

Fruit::Fruit(string name){

	setType(name);
	
	if(name=="Unripe"){

		setHSVmin(Scalar(0,79,179));
		setHSVmax(Scalar(101,230,256));

		setColour(Scalar(0,255,0));

	}
	if(name=="Ripe"){


		setHSVmin(Scalar(0,115,0));
		setHSVmax(Scalar(8,248,216));

		
		setColour(Scalar(0,0,255));

	}



}

Fruit::~Fruit(void)
{
}

int Fruit::getXPos(){

	return Fruit::xPos;

}

void Fruit::setXPos(int x){

	Fruit::xPos = x;

}

int Fruit::getYPos(){

	return Fruit::yPos;

}

void Fruit::setYPos(int y){

	Fruit::yPos = y;

}

Scalar Fruit::getHSVmin(){

	return Fruit::HSVmin;

}
Scalar Fruit::getHSVmax(){

	return Fruit::HSVmax;
}

void Fruit::setHSVmin(Scalar min){

	Fruit::HSVmin = min;
}


void Fruit::setHSVmax(Scalar max){

	Fruit::HSVmax = max;
}