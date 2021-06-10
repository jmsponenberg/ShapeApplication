#include "Triangle.h"
#include <math.h>

Triangle::Triangle()
{
	perimeter = 0.0f;
}

//method to calculate perimeter of the triangle
void Triangle::CalcPerimeter()
{
	float perimeter = 0.0f;
	float tempX = 0.0f;
	float tempY = 0.0f;

	//distance formula to get distance of each side between points
	//A side
	tempX = m_Points[1].m_x - m_Points[0].m_x;
	tempY = m_Points[1].m_y - m_Points[0].m_y;
	double A = sqrt(pow((double)tempX, 2) + pow(tempY, 2));

	//B side
	tempX = m_Points[2].m_x - m_Points[1].m_x;
	tempY = m_Points[2].m_y - m_Points[1].m_y;
	double B = sqrt(pow((double)tempX, 2) + pow(tempY, 2));

	//C side
	tempX = m_Points[0].m_x - m_Points[2].m_x;
	tempY = m_Points[0].m_y - m_Points[2].m_y;
	double C = sqrt(pow((double)tempX, 2) + pow(tempY, 2));

	perimeter = (float)(A + B + C);

	setPerimeter(perimeter);
}

//calculate the area of triangle to verify that the points provided yield a triangle
bool Triangle::ValidateShape()
{
	float area = 0.0f;

	area = (m_Points[0].m_x * (m_Points[1].m_y - m_Points[2].m_y))
		 + (m_Points[1].m_x * (m_Points[2].m_y - m_Points[0].m_y))
		 + (m_Points[2].m_x * (m_Points[0].m_y - m_Points[1].m_y));

	if (area == 0.0f) {
		return false;
	}
	else {
		return true;
	}
}

//set the value of each point in the Point array
void Triangle::setPointValues(int index, float x, float y)
{
	m_Points[index].m_x = x;
	m_Points[index].m_y = y;
}

//set perimeter
void Triangle::setPerimeter(float p)
{
	perimeter = p;
}

//returns perimeter value
float Triangle::getPerimeter()
{
	return perimeter;
}
