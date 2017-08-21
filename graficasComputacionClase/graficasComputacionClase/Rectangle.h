#pragma once

class Rectangle{
	public:
		Rectangle();
		Rectangle(float w, float h);
		float getWidth();
		void setWidth(float w);
		float getHeight();
		void setHeight(float h);
		float getArea();
		float getPerimeter();
	private:
		float _width;
		float _height;
};