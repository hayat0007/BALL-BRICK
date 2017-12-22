#include "stdafx.h"
#include "Brick.h"
//Brick.cpp
Brick::Brick()
{
	X = 0.0;
	Y = 0.0;

}
Brick::Brick(float X_CO, float Y_CO)
{
	X = X_CO;
	Y = Y_CO;
}

sf::RectangleShape Brick::displayBrick()
{
	sf::RectangleShape brick(sf::Vector2f(50, 25));
	brick.setFillColor(sf::Color(255, 10, 10));//Coloring the entire figure
	brick.setPosition(sf::Vector2f(X, Y));//sets Position of Brick
	brick.setOutlineThickness(1.3);

	brick.setOutlineColor(sf::Color::Blue);
	return brick;
}

float Brick::get_Xco()
{
	return X;
}

float Brick::get_Yco()
{
	return Y;
}

Brick::~Brick()
{
}