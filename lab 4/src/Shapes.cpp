#include <Shapes.hpp>
#include <iostream>

namespace ds 
{
	Circle::Circle(float x, float y, float r)
	{
		SetUp(x, y, r);
	}
	void Circle::SetUp(float x, float y, float r)
	{
		d_x = x;
		d_y = y;
		d_r = r;
		d_shape.setRadius(d_r);
		d_shape.setPosition(d_x, d_y);
		d_shape.setFillColor(sf::Color::Green);
	}
	sf::CircleShape Circle::Get()
	{
		return d_shape;
	}

	Triagle::Triagle(float x, float y, float r, int point)
	{
		SetUp(x, y, r, point);
	}
	void Triagle::SetUp(float x, float y, float r, int point)
	{
		d_x = x;
		d_y = y;
		d_r = r;
		d_point = point;
		d_shape.setRadius(r);
		d_shape.setPointCount(d_point);

		d_shape.setPosition(d_x, d_y);
		d_shape.setFillColor(sf::Color::Yellow);
	}
	sf::CircleShape Triagle::Get()
	{
		return d_shape;
	}
	Rectangle::Rectangle(float x, float y, float a, int b)
	{
		SetUp(x, y, a, b);
	}
	void Rectangle::SetUp(float x, float y, float a, float b)
	{
		d_x = x;
		d_y = y;
		d_a = a;
		d_b = b;
		d_shape.setSize(sf::Vector2f(a, b));
		d_shape.setPosition(d_x, d_y);
		d_shape.setFillColor(sf::Color::Blue);
	}
	void Rectangle::ChangeColortoWhite()
	{
		d_shape.setFillColor(sf::Color::White);
	}
	sf::RectangleShape Rectangle::Get()
	{
		return d_shape;
	}
}