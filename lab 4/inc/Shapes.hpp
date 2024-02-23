#pragma once
#include <SFML/Graphics.hpp>

namespace ds
{
	class Circle {
		float d_x;
		float d_y;
		float d_r;
		sf::CircleShape d_shape;
	public:
		Circle() = default;
		Circle(float x, float y, float r);
		
		void SetUp(float x, float y, float r);
		
		sf::CircleShape Get();
		
	};
	class Triagle {
		float d_x;
		float d_y;
		float d_r;
		int d_point;
		sf::CircleShape d_shape;
	public:
		Triagle() = default;
		Triagle(float x, float y, float r, int point);
		
		void SetUp(float x, float y, float r, int point);
		
		sf::CircleShape Get();
		
	}; 
	class Rectangle {
		float d_x;
		float d_y;
		float d_a;
		float d_b;

		sf::RectangleShape d_shape;
	public:
		Rectangle() = default;
		Rectangle(float x, float y, float a, int b);
		
		void SetUp(float x, float y, float a, float b);
		
		void ChangeColortoWhite();
		
		sf::RectangleShape Get();
		
	};

}