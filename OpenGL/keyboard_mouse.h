#pragma once
#ifndef KEYBOARD_MOUSE_H
#define KEYBOARD_MOUSE_H





class Control
{
	int rotate_cube_angle = 0;
	float translate_x = 0;
	float translate_y = 0;
	float translate_z = 0;
    const double PI = 3.141592653;
	int x = 150;
	int y = 150;
	int z = 150;	
	int wight = 1600;
	int heigh = 1200;
	const float height = 0;
public:
	float angleX;
	float angleY;
	void buttons();
	void vision_on_display();
};






#endif // !1

