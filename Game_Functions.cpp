#include "stdafx.h"
#include "Game_Functions.h"
//Game_Function.cpp
#include<iostream>
#include<conio.h>
using namespace std;
Game_Functions::Game_Functions() :MoveX(0.0), MoveY(-0.7), Ypositive(1), Third_line_Bricks(13), Second_line_Bricks(12), First_line_Bricks(13), score(0)
{
}


Game_Functions::~Game_Functions()
{
}

float Game_Functions::get_MoveX()
{
	return MoveX;
}

float Game_Functions::get_MoveY()
{
	return MoveY;
}

bool Game_Functions::get_Ypositive()
{
	return Ypositive;
}

int Game_Functions::get_Second_line_bricks()
{
	return Second_line_Bricks;
}

int Game_Functions::get_Third_line_bricks()
{
	return Third_line_Bricks;
}

int Game_Functions::get_First_line_bricks()
{
	return First_line_Bricks;
}


void Game_Functions::set_MoveX(float temp_MoveX)
{
	MoveX = temp_MoveX;
}

void Game_Functions::set_MoveY(float temp_MoveY)
{
	MoveY = temp_MoveY;
}

void Game_Functions::set_Ypositive(bool temp_Ypositive)
{
	Ypositive = temp_Ypositive;
}

void Game_Functions::check_Ball_Bat_Collision(BAT &BAT, BALL &BALL)
{
	if (BALL.get_Yco() >= BAT.get_Yco() - 7 && BALL.get_Yco() <= BAT.get_Yco() - 5)//Evaluates if BALL is down enough to check for collison with BAT
	{
		if (BALL.get_Xco() >= BAT.get_Xco() - 10 && BALL.get_Xco() <= BAT.get_Xco() + 80)//Checks if BALL collide with the BAT
		{
			Ypositive = 1;
			/*   DIVIDING THE BAT INTO 5 PARTS TO DEFINE THE DIRECTION OF BALL AFTER COLLISION WITH THE BAT   */
			if (BALL.get_Xco() >= BAT.get_Xco() - 10 && BALL.get_Xco() <= BAT.get_Xco() + 8)
			{
				MoveX = -0.25;
			}

			else if (BALL.get_Xco() > BAT.get_Xco() + 8 && BALL.get_Xco() <= BAT.get_Xco() + 26)
			{
				MoveX = -0.15;
			}

			else if (BALL.get_Xco() > BAT.get_Xco() + 26 && BALL.get_Xco() <= BAT.get_Xco() + 44)
			{
				MoveX = 0.0;
			}

			else if (BALL.get_Xco() > BAT.get_Xco() + 44 && BALL.get_Xco() <= BAT.get_Xco() + 62)
			{
				MoveX = 0.15;
			}


			else if (BALL.get_Xco() > BAT.get_Xco() + 62 && BALL.get_Xco() <= BAT.get_Xco() + 80)
			{
				MoveX = 0.25;
			}

		}//end of if that checks wheather BALL comes onto the BAT (along X-axis)
	}//end of if that checks if  BALL is at same height as BAT (along Y-axis)
}

void Game_Functions::ball_moving_up(BALL &BALL, Brick BL1[], Brick BL2[], Brick BL3[], sf::RenderWindow &GameWindow)
{

	//float MoveX = get_MoveX();
	//float MoveY = get_MoveY();
	BALL.move_Ball(MoveX, MoveY);
	if (BALL.get_Yco() <= 0)//checks if BALL has reached the TOP. if so it has to move down now.
	{
		Ypositive = 0;
	}

	if (BALL.get_Xco() < 0 || BALL.get_Xco() > 790)//BALL should remain within the Windows(Limiting X-axis)
	{

		MoveX = -MoveX;
	}
	if (BALL.get_Yco() >= 105 && BALL.get_Yco() <= 107)//FOR DESTROYING BRICKS OF THIRD LINE
	{
		for (int i = 0; i < Third_line_Bricks; i++)//checks which brick is being destroyed
		{
			if (BALL.get_Xco() >= BL3[i].get_Xco() - 10 && BALL.get_Xco() <= BL3[i].get_Xco() + 53)
			{
				score += 3;
				Ypositive = 0;
				if (i < Third_line_Bricks)
				{
					for (int k = i; k < Third_line_Bricks; k++)
					{
						BL3[k] = BL3[k + 1];
					}
					Third_line_Bricks--;
				}
				else
				{
					Third_line_Bricks--;
				}
			}
		}
	}

	if (BALL.get_Yco() >= 70 && BALL.get_Yco() <= 72)//FOR DESTROYING BRICKS OF Second LINE
	{
		for (int i = 0; i < Second_line_Bricks; i++)
		{
			if (BALL.get_Xco() >= BL2[i].get_Xco() - 7 && BALL.get_Xco() <= BL2[i].get_Xco() + 53)
			{
				score += 4;
				Ypositive = 0;
				if (i < Second_line_Bricks)
				{
					for (int k = i; k < Second_line_Bricks; k++)
					{
						BL2[k] = BL2[k + 1];
					}
					Second_line_Bricks--;
				}
				else
				{
					Second_line_Bricks--;
				}
			}
		}
	}//end of destroying of second line Bricks

	if (BALL.get_Yco() >= 33 && BALL.get_Yco() <= 35)//FOR DESTROYING BRICKS OF First LINE
	{
		for (int i = 0; i < First_line_Bricks; i++)
		{
			if (BALL.get_Xco() >= BL1[i].get_Xco() - 7 && BALL.get_Xco() <= BL1[i].get_Xco() + 53)
			{
				score += 5;
				Ypositive = 0;
				//		BAT.setSize(sf::Vector2f(90, 15));//ADDITION  BY DANYAL
				if (i < First_line_Bricks)
				{
					for (int k = i; k < First_line_Bricks; k++)
					{
						BL1[k] = BL1[k + 1];
					}
					First_line_Bricks--;
				}
				else
				{
					First_line_Bricks--;
				}
			}
		}
	}//end of destroying of First line Brick
	if (First_line_Bricks == 0 && Second_line_Bricks == 0 && Third_line_Bricks == 0)
	{
		GameWindow.close();
		cout << " YOU WIN! \n";
		cout << "SCORE: " << score;
		_getch();
	}
}//end of ball_moving_up




void Game_Functions::ball_moving_down(BALL &BALL, Brick BL1[], Brick BL2[], Brick BL3[], sf::RenderWindow &GameWindow, BAT &BAT)
{
	//float MoveX = Function.get_MoveX();
	//float MoveY = Function.get_MoveY();
	BALL.move_Ball(MoveX, -MoveY);
	if (BALL.get_Xco() < 0 || BALL.get_Xco()>790)
	{
		MoveX = -MoveX;
	}
	if (BALL.get_Yco() >= 600)
	{
		GameWindow.close();

		cout << "\nGAME OVER" << endl;
		cout << "SCORE: " << score;
		_getch();
	}

	/*        CHECK IF BRICK IS DESTROYED        */

	if (BALL.get_Yco() <= 82 && BALL.get_Yco() >= 80)//third line brick destroyed?
	{
		for (int i = 0; i < Third_line_Bricks; i++)
		{
			if (BALL.get_Xco() >= BL3[i].get_Xco() - 7 && BALL.get_Xco() <= BL3[i].get_Xco() + 53)
			{
				score += 3;
				Ypositive = 1;
				if (i < Third_line_Bricks)
				{
					for (int k = i; k < Third_line_Bricks; k++)
					{
						BL3[k] = BL3[k + 1];
					}
					Third_line_Bricks--;

				}


				else
				{
					Third_line_Bricks--;
				}
			}
		}
	}//END of if Third Line brick Destroyed

	if (BALL.get_Yco() <= 52 && BALL.get_Yco() >= 50)//FOR DESTROYING BRICKS OF Second LINE
	{
		for (int i = 0; i < Second_line_Bricks; i++)
		{
			if (BALL.get_Xco() >= BL2[i].get_Xco() - 7 && BALL.get_Xco() <= BL2[i].get_Xco() + 53)
			{
				score += 4;
				Ypositive = 1;
				if (i < Second_line_Bricks)
				{
					for (int k = i; k < Second_line_Bricks; k++)
					{
						BL2[k] = BL2[k + 1];
					}
					Second_line_Bricks--;
				}


				else
				{
					Second_line_Bricks--;
				}
			}
		}
	}//end of destroying of second line Bricks

	if (BALL.get_Yco() <= 12 && BALL.get_Yco() >= 10)//FOR DESTROYING BRICKS OF First LINE
	{
		for (int i = 0; i < First_line_Bricks; i++)
		{
			if (BALL.get_Xco() >= BL1[i].get_Xco() - 7 && BALL.get_Xco() <= BL1[i].get_Xco() + 53)
			{

				Ypositive = 1;
				if (i < First_line_Bricks)
				{
					for (int k = i; k < First_line_Bricks; k++)
					{
						BL1[k] = BL1[k + 1];
					}
					First_line_Bricks--;
					score += 5;
				}
				else
				{
					First_line_Bricks--;
				}
			}
		}
	}//end of destroying of First line Brick

	if (First_line_Bricks == 0 && Second_line_Bricks == 0 && Third_line_Bricks == 0)
	{
		GameWindow.close();
		cout << " YOU WIN! \n";
		cout << "SCORE: " << score;
		_getch();
	}
	check_Ball_Bat_Collision(BAT, BALL);
}//end ball is moving down