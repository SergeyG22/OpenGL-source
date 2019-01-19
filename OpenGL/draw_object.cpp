#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GLU.h>
#include <string>
#include "draw_object.h"

#define GL_CLAMP_TO_EDGE 0x812F

void Draw::draw_coordinate_XYZ()
{
	glLineWidth(10);
	glBegin(GL_LINES);
	glColor3f(1.0, 1.0, 0.0);
	glVertex2f(0, 0);
	glVertex2f(0, 600);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(1, 0, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(600, 0, 0);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(0, 1, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 600, 0);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 1);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 600);
	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor3f(1, 0, 1);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, -600);
	glEnd();
}

void Draw::draw_line_of_rotate(bool set = false)
{
	if (set) {
		glLineWidth(10);
		glColor3f(0, 0, 1);
		glBegin(GL_LINES);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(x_vector_angle, y_vector_angle, z_vector_angle);
		glEnd();
	}
}

void Draw::draw_cube()
{

	glEnable(GL_CULL_FACE);
	glEnable(GL_TEXTURE_2D);

	glCullFace(GL_BACK);

	glRotatef(rotate_cube_angle, x_vector_angle, y_vector_angle, z_vector_angle);
	glTranslatef(translate_x, translate_y, translate_z);

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(50, -50, 50);
	glTexCoord2f(0.0, -1.0);
	glVertex3f(50, 50, 50);
	glTexCoord2f(-1.0, -1.0);
	glVertex3f(-50, 50, 50);
	glTexCoord2f(-1.0, 0.0);
	glVertex3f(-50, -50, 50);
	glEnd();


	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(50, -50, -50);
	glTexCoord2f(-1.0, 0.0);
	glVertex3f(50, 50, -50);
	glTexCoord2f(-1.0, -1.0);
	glVertex3f(50, 50, 50);
	glTexCoord2f(0.0, -1.0);
	glVertex3f(50, -50, 50);
	glEnd();


	
	glBegin(GL_POLYGON);//
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-50, -50, 50);
	glTexCoord2f(-1.0, 0.0);
	glVertex3f(-50, 50, 50);
	glTexCoord2f(-1.0, -1.0);
	glVertex3f(-50, 50, -50);
	glTexCoord2f(-1.0, 0.0);
	glVertex3f(-50, -50, -50);
	glEnd();
	
	

	

	





	

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(50, 50, 50);
	glTexCoord2f(-1.0, 0.0);
	glVertex3f(50, 50, -50);
	glTexCoord2f(-1.0, -1.0);
	glVertex3f(-50, 50, -50);
	glTexCoord2f(0.0, -1.0);
	glVertex3f(-50, 50, 50);
	glEnd();
	

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(50, -50, -50);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-50, -50, -50);
	glTexCoord2f(-1.0, 0.0);
	glVertex3f(-50, 50, -50);
	glTexCoord2f(-1.0, -1.0);
	glVertex3f(50, 50, -50);
	glTexCoord2f(0.0, -1.0);
	glEnd();
	

	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(50, -50, 50);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-50, -50, 50);
	glTexCoord2f(-1.0, 0.0);
	glVertex3f(-50, -50, -50);
	glTexCoord2f(-1.0, -1.0);
	glVertex3f(50, -50, -50);
	glTexCoord2f(0.0, -1.0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	

}

void Draw::draw_color_cube()
{

	glEnable(GL_BLEND);
	glBlendFunc(GL_ONE, GL_ONE);
	glBegin(GL_POLYGON);
	glColor4f(color_one, color_two, color_three, 0.0);
	glVertex3f(55, -55, 55);
	glVertex3f(55, 55, 55);
	glVertex3f(-55, 55, 55);
	glVertex3f(-55, -55, 55);
	glEnd();


	glBegin(GL_POLYGON);
	glColor4f(color_one, color_two, color_three, 0.0);
	glVertex3f(55, -55, -55);
	glVertex3f(55, 55, -55);
	glVertex3f(55, 55, 55);
	glVertex3f(55, -55, 55);
	glEnd();



	glBegin(GL_POLYGON);
	glColor4f(color_one, color_two, color_three, 0.0);
	glVertex3f(-55, -55, 55);
	glVertex3f(-55, 55, 55);
	glVertex3f(-55, 55, -55);
	glVertex3f(-55, -55, -55);
	glEnd();


	glBegin(GL_POLYGON);
	glColor4f(color_one, color_two, color_three, 0.0);
	glVertex3f(55, 55, 55);
	glVertex3f(55, 55, -55);
	glVertex3f(-55, 55, -55);
	glVertex3f(-55, 55, 55);
	glEnd();


	glBegin(GL_POLYGON);
	glColor4f(color_one, color_two, color_three, 0.0);
	glVertex3f(55, -55, -55);
	glVertex3f(-55, -55, -55);
	glVertex3f(-55, 55, -55);
	glVertex3f(55, 55, -55);
	glEnd();

	glBegin(GL_POLYGON);
	glColor4f(color_one, color_two, color_three, 0.0);
	glVertex3f(55, -55, 55);
	glVertex3f(-55, -55, 55);
	glVertex3f(-55, -55, -55);
	glVertex3f(55, -55, -55);
	glEnd();

	glDisable(GL_BLEND);
}

void Draw::move_xy()
{

	 if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		translate_y += 10;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		translate_y -= 10;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		translate_x += 10;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		translate_x -= 10;
	}

}

void Draw::rotate_object()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		rotate_cube_angle += 5;
	}
	else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		rotate_cube_angle -= 5;
	}


}


