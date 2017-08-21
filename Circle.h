#pragma once
#include <string>
class Circle{
	public:
		Circle();
		Circle(double r);
		Circle(double r, std::string c);
		double getRadius();
		double getArea();
		std::string  getCircle();
		void setRadius(double r);
		void setColor(std::string c);
		std::string getColor();
	private:	
		double _radius;
		std::string _color;

};