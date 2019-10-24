#include "keyboard_mouse.h"
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GLU.h>
#include <Windows.h>

 void Control::buttons()
{
	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			x -= (float)sin(angleX / 180 * PI) * 5;
			z -= (float)cos(angleX / 180 * PI) * 5;
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			x += (float)sin(angleX / 180 * PI) * 5;
			z += (float)cos(angleX / 180 * PI) * 5;
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			x += (float)sin((angleX - 90) / 180 * PI) * 5;
			z += (float)cos((angleX - 90) / 180 * PI) * 5;
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			x += (float)sin((angleX + 90) / 180 * PI) * 5;
			z += (float)cos((angleX + 90) / 180 * PI) * 5;

		}


}



void Control::vision_on_display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65, float(wight / heigh), 1, 1600);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(x, y + height, z, x - sin(angleX / 180 * PI), y + height + (tan(angleY / 180 * PI)), z - cos(angleX / 180 * PI), 0, 1, 0);
}