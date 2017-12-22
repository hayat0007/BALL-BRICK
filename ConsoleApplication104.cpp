// ConsoleApplication104.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//source.cpp
#include<iostream>
#include<SFML\Graphics.hpp>
#include<SFML\Audio.hpp>
#include<conio.h>
#include"Game_Functions.h"
#include"Brick.h"
#include"BAT.h"
#include"BALL.h"
using namespace std;


void main()
{
	bool KP = 0;//KEY PRESSED? It changes to 1 when player presses the key. This is used to indicate when player is Ready (once ready he presses the key)
	float X = 10.0;//Defines X-cordinate.(Helps in giving Gaps in Bricks)
	float Y = 10.0;//Defines Y-cordinate.(Helps in making serveral lines of Bricks)
	bool game_start = false;
	/*	GLOBAL VARIBALES	*/
	Game_Functions Function;
	Brick *BL1 = new Brick[13];

	for (int i = 0; i < Function.get_First_line_bricks(); i++)
	{
		BL1[i] = Brick(X, Y);
		X = X + 60.0;
	}

	Brick *BL2 = new Brick[12];
	X = 50.0; Y = 45.0;
	for (int i = 0; i < Function.get_Second_line_bricks(); i++)
	{
		BL2[i] = Brick(X, Y);
		X = X + 60.0;
	}


	X = 10.0; Y = 80.0;
	Brick *BL3 = new Brick[13];

	for (int i = 0; i < Function.get_Third_line_bricks(); i++)
	{
		BL3[i] = Brick(X, Y);
		X = X + 60.0;
	}

	BAT BAT;
	BALL BALL;
	sf::RenderWindow GameWindow;
	GameWindow.create(sf::VideoMode(800, 600), "GAME");

	sf::RectangleShape menu_rectangle;
	menu_rectangle.setSize(sf::Vector2f(400, 80));
	menu_rectangle.setFillColor(sf::Color::Red);
	menu_rectangle.setOutlineColor(sf::Color::Yellow);
	menu_rectangle.setOutlineThickness(5);
	menu_rectangle.setPosition(sf::Vector2f(230, 280));

	


	sf::Font font;  //to add font
	if (!font.loadFromFile("arial.ttf"))
	{
	//handle error
	}


		sf::Text text;  //to add text
	text.setFont(font);  //to set font of text
	text.setString("PRESS ENTER TO START...");
	text.setStyle(sf::Text::Italic);
	text.setPosition(sf::Vector2f(250, 300));
	text.setCharacterSize(29);


	sf::Texture texture;
	if (!texture.loadFromFile("background.jpg"))
	{
		cout << "Error loading background\n";
	}

	sf::Music music;  //to add music
	if (!music.openFromFile("Music.ogg"))  //condition if music is not loaded properly
	{
		cout << "Error loading music" << endl;
	}

	music.play();  //to play the music

	music.setVolume(100);  //to set the volume of the music*/

	sf::Sprite sprite(texture);
	sprite.setTexture(texture); //setting texture to sprite



	while (GameWindow.isOpen())
	{
		sf::Event event;
		while (GameWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				GameWindow.close();
			}
		}
		if (game_start == true)
		{
			GameWindow.clear();
			GameWindow.draw(sprite);
			//		GameWindow.draw(text);

			for (int i = 0; i < Function.get_First_line_bricks(); i++)
			{
				GameWindow.draw(BL1[i].displayBrick());
			}
			for (int j = 0; j < Function.get_Second_line_bricks(); j++)
			{
				GameWindow.draw(BL2[j].displayBrick());
			}
			for (int k = 0; k < Function.get_Third_line_bricks(); k++)
			{
				GameWindow.draw(BL3[k].displayBrick());
			}
			GameWindow.draw(BAT.displayBAT());
			GameWindow.draw(BALL.displayBALL());
			GameWindow.display();


			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Left)
				{
					if (BAT.get_Xco() >= 3)//To limit BAT movement to within screen
					{
						BAT.bat_move_left();
					}
				}
				else if (event.key.code == sf::Keyboard::Right)
				{
					if (BAT.get_Xco() <= 800 - 83)//To limit BAT movement to within screen
					{
						BAT.bat_move_right();
					}
				}
				KP = 1;
			}

			if (KP == 1)
			{
				if (Function.get_Ypositive() == 1)//BALL moves UP
				{
					Function.ball_moving_up(BALL, BL1, BL2, BL3, GameWindow);
				}//end of if BALL is moving UP

				else if (Function.get_Ypositive() == 0)//BALL moves down when it reaches the TOP or collides with bricks
				{
					Function.ball_moving_down(BALL, BL1, BL2, BL3, GameWindow, BAT);
				}//end of else if that executes ONLY when BALL is coming Down
			}//end of if. It is only included so that the Ball starts moving only after the player has pressed a key (to indicate he is ready)
		}
		else
		{
			
			GameWindow.draw(menu_rectangle);
			GameWindow.draw(text);
			GameWindow.display();
			GameWindow.clear();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				game_start = true;
			}
		}
		}//end of while Window is Open
}//end main