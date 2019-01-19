#pragma once
#ifndef PARAMETERS_H
#define PARAMETERS_H
#include <string>

class Parameters
{
	float color_one;
	float color_two;
	float color_three;
	int rotate_cube_angle;
	int x_vector_angle;
	int y_vector_angle;
	int z_vector_angle;
public:
	void load_texture(std::string);
	void set_vector_of_angle(int a, int b, int c) { x_vector_angle = a; x_vector_angle = b; x_vector_angle = c; };
	
};





#endif
