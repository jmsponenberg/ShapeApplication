// ShapeApplication.cpp
// Author: Jeff Sponenberg
// This application is used to satisfy the assignment:
// "Create a console application to calculate the perimeter of a triangle given 3 user supplied coordinates"

#include <iostream>
#include "Triangle.h"

float getXLoc(int index);
float getYLoc(int index);

int main()
{
    Triangle* triangle = new Triangle();
    float tempX = 0.0f;
    float tempY = 0.0f;

    std::cout << "This application finds the perimeter of a triangle with user supplied values" << std::endl;

    //loop for getting valid input for all 3 points of a triangle
    for (int index = 0; index < 3; index++) {
        tempX = getXLoc(index);
        tempY = getYLoc(index);
        triangle->setPointValues(index, tempX, tempY);
    }

    //ensure the points form a triangle in order to calculate a perimeter
    if (triangle->ValidateShape()) {
        triangle->CalcPerimeter();
        std::cout << "The 3 points entered formed a triangle with a perimeter of " << triangle->getPerimeter() << "." << std::endl;
    }
    else {
        std::cout << "The 3 points entered did not form a triangle" << std::endl;
    }

    //added this so the program can be give the user control over when to exit
    do {
        std::cin.ignore();
        std::cout << "Press the Enter key to Exit ShapeApplication...";
    } while (std::cin.get() != '\n');
}

//method to ensure the entry is valid data for X
float getXLoc(int index) {
    float tempX = 0.0f;

    while (true) {
        std::cout << "Enter X-value for point " << index + 1 << "." << std::endl;
        std::cin >> tempX;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n'); //chose a large buffer to prevent multiple cout's of the next line
            std::cout << "Invalid entry for X value, please enter a valid value for X" << std::endl;
            
        }
        else {
            break;
        }
    }
    return tempX;
}

//method to ensure the entry is valid data for Y
float getYLoc(int index) {
    float tempY = 0.0f;

    while (true) {
        std::cout << "Enter Y-value for point " << index + 1 << "." << std::endl;
        std::cin >> tempY;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n'); //chose a large buffer to prevent multiple cout's of the next line
            std::cout << "Invalid entry for Y value, please enter a valid value for Y" << std::endl;

        }
        else {
            break;
        }
    }
    return tempY;
}
