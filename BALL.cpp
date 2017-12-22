#include "stdafx.h"
#include "BALL.h"
//BALL.cpp

BALL::BALL() :X(437), Y(567)
{
	Ball.setRadius(6);
	Ball.setFillColor(sf::Color::White);
	Ball.setPosition(sf::Vector2f(X, Y));
}

sf::CircleShape BALL::displayBALL()
{
	return Ball;
}

float BALL::get_Xco()
{
	return Ball.getPosition().x;
}

float BALL::get_Yco()
{
	return Ball.getPosition().y;
}

void BALL::move_Ball(float MoveX, float MoveY)
{
	Ball.move(sf::Vector2f(MoveX, MoveY));
}

BALL::~BALL()
{
}
