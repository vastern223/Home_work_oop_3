#pragma once
#include<iostream>
using namespace std;
class Triangle {
private:
	float height;
	float width;
	static  int count_Triangle;
	static  float count_area;
public:

	Triangle();

	Triangle(float size);

	Triangle(float _height, float _width);

	void Print()const;

	float GetArea();

	float GetPerimeter();

	float Getheight();

	float Getwidth();

	void Set_height(float _height);

	void Setwidth(float _width);

	static int Show_count_Triangle();

	static float Show_Area();


};