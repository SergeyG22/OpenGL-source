#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GLU.h>
#include <string>
#include "draw_object.h"

#define GL_CLAMP_TO_EDGE 0x812F
#define PI 3.141592753

void CilynderA::draw_coordinate_XYZ() // Отрисовывает координаты
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


void CilynderA::cylinder() // Отрисовывает цилиндр
{
	
	glColor4f(1.0, 1.0, 1.0, 0.9);
	glEnable(GL_CULL_FACE);
	glEnable(GL_TEXTURE_2D);
	glRotatef(rotate, x_vector_angle, y_vector_angle, z_vector_angle);
	glTranslatef(translate_x, translate_y, translate_z);

	
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
			glColor3f(1.0, 0.0, 1.0);
			glVertex3f(x, y, 60.0);
			
			angle = angle + angle_stepsize;
		}		
		glVertex3f(radius, 0.0, 60.0);
		glEnd();
		
		glCullFace(GL_FRONT);
		glBegin(GL_POLYGON);		
		angle = 0.0;
		while (angle < 2 * PI) {
			x = radius * cos(angle);
			y = radius * sin(angle);
			glColor3f(1.0, 0.0, 1.0);
			glVertex3f(x, y, 0.0);
			angle = angle + angle_stepsize;
		}
		glVertex3f(radius, 0.0, 0.0);
		glEnd();

}



void CilynderA::move() // движение в трехмерном пространстве
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

void CilynderA::rotate_figure() // вращение фигуры
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		rotate += 5;
	}
	else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
	{
		rotate -= 5;
	}
}

void CilynderA::load_texture()
{
	sf::Image data_img;
	data_img.loadFromFile("texture1.png");
	GLuint textureID;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 128, 128, 0, GL_RGBA, GL_UNSIGNED_BYTE, data_img.getPixelsPtr());
}

void CilynderB::load_texture()
{
	sf::Image data_img;
	data_img.loadFromFile("texture2.png");
	GLuint textureID;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, 128, 128, 0, GL_RGBA, GL_UNSIGNED_BYTE, data_img.getPixelsPtr());
}


