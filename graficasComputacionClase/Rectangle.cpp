#include "Rectangle.h"

Rectangle::Rectangle(){
	_width = 1.0f;
	_height = 1.0f;
}
Rectangle::Rectangle(float w, float h){
	_width = w;
	_height = h;
}
float Rectangle::getWidth(){
	return _width;
}
float Rectangle::getHeight(){
	return _height;
}
void Rectangle::setWidth(float w){
	_width = w;
}
void Rectangle::setHeight(float h){
	_height = h;
}
float Rectangle::getArea(){
	return _width*_height;
}
float Rectangle::getPerimeter(){
	return (2*_height)+(2*_width);
}