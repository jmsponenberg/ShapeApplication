#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include "Point.h"

class Triangle : public Shape {
public:
	Triangle();
	void CalcPerimeter();
	bool ValidateShape();
	void setPointValues(int index, float x, float y);
	void setPerimeter(float p);
	float getPerimeter();

private:
	Point m_Points[3];
	float perimeter;
};

#endif
