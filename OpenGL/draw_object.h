#pragma once
#ifndef DRAW_OBJECT_H
#define DRAW_OBJECT_H

class Draw
{
	int x_vector_angle = 0;
	int y_vector_angle = 0;
	int z_vector_angle = 30;
	int rotate = 0;
	int size = 600;
	float translate_x = 0;
	float translate_y = 0;
	float translate_z = 0;
public:
	void load_texture();
	void move();
	void rotate_figure();
	void draw_coordinate_XYZ();
//	void cube();
	void cylinder();
	void set_position_object(int a, int b, int c) { translate_x = a; translate_y = b; translate_z = c; }
};








#endif // !1

