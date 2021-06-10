#ifndef SHAPE_H
#define SHAPE_H

class Shape {
public:
	virtual void CalcPerimeter() = 0; //pure virtual function
	virtual bool ValidateShape() = 0; //input for shapes can be invalid from the user so create method to validate the shape
};

#endif