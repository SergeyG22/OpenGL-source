#pragma once
#ifndef DRAW_OBJECT_H
#define DRAW_OBJECT_H

class Draw
{
	int x_vector_angle = 0;
	int y_vector_angle = 0;
	int z_vector_angle = 30;
	float color_one=1.0;
	float color_two=0.0;
	float color_three=0.0;
	int rotate_cube_angle = 0;
	int translate_x=0;
	int translate_y=0;
	int translate_z=0;
	int size = 600;


public:
	void move_xy();
	void rotate_cube();
	void draw_coordinate_XYZ();
	void draw_line_of_rotate();
	void draw_cube();
	void draw_cylinder();
//	void draw_color_cube();
	void set_color_cube(float a, float b, float c) { color_one = a; color_two = b; color_three = c; };
	void set_cube_angle(int a) { rotate_cube_angle = a; }
	void set_position_object(int a, int b, int c) { translate_x = a; translate_y = b; translate_z = c; }
};








#endif // !1

