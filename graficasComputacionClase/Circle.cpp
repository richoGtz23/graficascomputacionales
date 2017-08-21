#include "Circle.h"
#include <string>
Circle::Circle(){
	_radius = 1.0;
	_color = "red";
}
Circle::Circle(double r){
	_radius = r;
	_color = "red";
}
Circle::Circle(double r,std::string c){
	_radius = r;
	_color = c;
}
double Circle::getRadius(){
	return _radius;
}
double Circle::getArea(){
	return _radius*_radius*3.14159;
}
std::string Circle::getColor(){
	return _color;
}
void Circle::setRadius(double r){
	_radius = r;
}
void Circle::setColor(std::string c){
	_color = c;
}