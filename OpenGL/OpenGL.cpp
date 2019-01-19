#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <Windows.h>
#include <iostream>
#include <gl/GLU.h>
#include "keyboard_mouse.h"
#include "draw_object.h"
#include "parameters.h"




#pragma comment(lib,"glu32.lib")

POINT mousexy;




int main()
{

	sf::RenderWindow window(sf::VideoMode(1600,1200), "Rotate_cube", sf::Style::None);
	ShowCursor(FALSE);
	glClearColor(0.3, 1.0, 1.0, 1.0);
	Control control_mouse_display;
	Draw object[10];
	
	Parameters set;

	Object cube_two;
	int x = 0;
	



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
			object[0].draw_coordinate_XYZ();
			set.load_texture("fox.png");//"grass.png","fox.png"

			object[1].set_position_object(50, 50, 0);		
			object[1].draw_cube();

			


				for (int i = 2, x = 100; i < 10; i++)
				{
					object[i].set_position_object(0, x, 0);
					object[i].draw_cube();
				}

				for (int i = 2, x = 100; i < 10; i++)
				{
					object[i].set_position_object(x, 0, 0);
					object[i].draw_cube();
				}

				for (int i = 2, x = 100; i < 10; i++)
				{
					object[i].set_position_object(0, 0, -x);
					object[i].draw_cube();
				}
			
				for (int i = 2, x = 100; i < 10; i++)
				{
					object[i].set_position_object(0, 0, x);
					object[i].draw_cube();
				}
		/*	set.load_texture("grass.png");
			cube_two.set_position_object(100, 100,0);
			cube_two.draw_cube();
			cube_two.draw_color_cube();
			cube_two.set_color_cube(0, 1, 0);			
			*/


		window.display();
	
	}
	
	return 0;
}







	



























