#include "stdafx.h"
#include "BAT.h"

//BAT.cpp
BAT::BAT() :X(400), Y(580)
{
	Bat.setSize(sf::Vector2f(80, 15));
	Bat.setFillColor(sf::Color::Red);
	Bat.setOutlineThickness(2);
	Bat.setOutlineColor(sf::Color::Yellow);
	Bat.setPosition(sf::Vector2f(X, Y));
}

sf::RectangleShape BAT::displayBAT()
{

	return Bat;
}

float BAT::get_Xco()
{
	return Bat.getPosition().x;
}

float BAT::get_Yco()
{
	return Bat.getPosition().y;
}

void BAT::bat_move_left()
{
	Bat.move(sf::Vector2f(-0.7, 0));
}

void BAT::bat_move_right()
{
	Bat.move(sf::Vector2f(0.7, 0));
}

BAT::~BAT()
{
}