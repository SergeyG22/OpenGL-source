#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <Windows.h>
#include <iostream>
#include <gl/GLU.h>
#include "keyboard_mouse.h"
#include "draw_object.h"





#pragma comment(lib,"glu32.lib")

POINT mousexy;




int main()
{

	sf::RenderWindow window(sf::VideoMode(1600, 1200), "gaming machine", sf::Style::None);
	ShowCursor(FALSE);
	glClearColor(0.3, 1.0, 1.0, 1.0);
	Control control_mouse_display;
	CilynderA object1;
	CilynderB object2;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
				window.close();
			switch (event.type)
			{
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Q)
					window.close();
				break;
			}

		}

			GetCursorPos(&mousexy);
			HCURSOR oldCursor = SetCursor(NULL);
			control_mouse_display.angleX += (320 - mousexy.x) / 3;
			control_mouse_display.angleY += (240 - mousexy.y) / 3;
			if (control_mouse_display.angleY < -89.0) { control_mouse_display.angleY = -89.0; }
			if (control_mouse_display.angleY > 89.0) { control_mouse_display.angleY = 89.0; }
			SetCursorPos(320, 240);

			control_mouse_display.vision_on_display();
			control_mouse_display.buttons();
			//=============

			object2.load_texture();
			object2.cylinder();
		
			//===========

			object1.load_texture();
			object1.cylinder();

			//===========


			object1.rotate_figure();
	//		object1.draw_coordinate_XYZ();
			
		    window.display();
	
	}
	
	return 0;
}







	



























