#pragma once
#ifndef DRAW_OBJECT_H
#define DRAW_OBJECT_H

class CilynderA
{
	int x_vector_angle;
	int y_vector_angle;
	int z_vector_angle;
	int rotate;
	float translate_x;
	float translate_y;
	float translate_z;
public:
	CilynderA() :translate_x(0), translate_y(0), translate_z(0),rotate(0) 
	{
		x_vector_angle = 0;
		y_vector_angle = 0;
		z_vector_angle = 30;
	};
    void load_texture();
	void move();
	void rotate_figure();
	void draw_coordinate_XYZ();
	void cylinder();
};

class CilynderB
{
public:
	void load_texture();

};








#endif // !1

