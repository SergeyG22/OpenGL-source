#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GLU.h>
#include <string>
#include "draw_object.h"

#define GL_CLAMP_TO_EDGE 0x812F
#define PI 3.141592753

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

void Draw::draw_line_of_rotate()
{
	
		glLineWidth(10);
		glColor3f(0, 0, 1);
		glBegin(GL_LINES);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(x_vector_angle, y_vector_angle, z_vector_angle);
		glEnd();
	
}

void Draw::draw_cylinder()
{
	glEnable(GL_CULL_FACE);
	glEnable(GL_TEXTURE_2D);
	//============= !!!!!!!!!!!!!!!!

	glRotatef(rotate_cube_angle, x_vector_angle, y_vector_angle, z_vector_angle);
	glTranslatef(translate_x, translate_y, translate_z);

	//============== !!!!!!!!!!!!!!!!
	glCullFace(GL_BACK);
		GLfloat x = 0.0;
		GLfloat y = 0.0;
		GLfloat angle = 0.0;
		GLfloat angle_stepsize = 0.01;
		double radius = 30;

		glBegin(GL_QUAD_STRIP);
		angle = 0.0;
		while (angle < 2 * PI) {
			x = radius * cos(angle);
			y = radius * sin(angle);
			const float tc = (angle / (float)(2 * PI));
			glTexCoord2f(tc, 0.0);
			glVertex3f(x, y, 60.0);
			glTexCoord2f(tc, 1.0);
			glVertex3f(x, y, 0.0);
			angle = angle + angle_stepsize;
		}
		glVertex3f(radius, 0.0, 60.0);
		glVertex3f(radius, 0.0, 0.0);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		
		glBegin(GL_POLYGON);
		angle = 0.0;
		while (angle < 2 * PI) {
			x = radius * cos(angle);
			y = radius * sin(angle);
			glVertex3f(x, y, 60.0);
			angle = angle + angle_stepsize;
		}
		
		glVertex3f(radius, 0.0, 60.0);
		glEnd();
		
		glBegin(GL_POLYGON);
		angle = 0.0;
		while (angle < 2 * PI) {
			x = radius * cos(angle);
			y = radius * sin(angle);
			glVertex3f(x, y, -30.0);
			angle = angle + angle_stepsize;
		}

		glVertex3f(radius, 0.0, -30.0);
		glEnd();

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
/*
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
}*/






void Draw::move_xy()
{

	 if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		translate_y += 10;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		translate_y -= 10;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		translate_x += 10;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		translate_x -= 10;
	}

}

void Draw::rotate_cube()
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


