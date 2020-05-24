#include"Triangle.h"

int Triangle::count_Triangle = 0;
float Triangle::count_area = 0;

Triangle::Triangle()
{
	height = 0;
	width = 0;
	++count_Triangle;
}

Triangle::Triangle(float size)
{
	if (size > 0)
	{
		height = size;
		width = size;
		++count_Triangle;
	}

}

Triangle::Triangle(float _height, float _width)
{
	if (_height > 0 && _width > 0)
	{
		height = _height;
		width = _width;
		++count_Triangle;
	}

}

void Triangle::Print()const
{
	cout << "height :" << height << endl;
	cout << "width :" << width << endl;
}

float Triangle::GetArea()
{
	float area = 0;
	area = 0.5 * height * width;
	count_area += area;
	return area;
}

float Triangle::GetPerimeter()
{
	float perimeter = 0;
	float side = 0;
	side = pow(height, 2) + pow(width / 2, 2);
	side = sqrt(side);
	perimeter = side + side + width;
	return  perimeter;
}

inline float Triangle::Getheight()
{
	return height;
}

inline float Triangle::Getwidth()
{
	return width;
}

void Triangle::Set_height(float _height)
{
	if (_height > 0)
		height = _height;
}

void Triangle::Setwidth(float _width)
{
	if (_width > 0)
		width = _width;
}

int Triangle::Show_count_Triangle()
{
	return count_Triangle;
}

float Triangle::Show_Area()
{
	return count_area;
}

