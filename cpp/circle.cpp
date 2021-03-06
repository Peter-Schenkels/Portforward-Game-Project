#include "drawables.hpp"

// circle.cpp
// Daniel van Eijk-Bos Bulkowski - Peter Schenkels - Rick van Mourik - Noah Titarsole, 31-Jan-2020, Version 3.4
// Contains all functions for the circle subclass

// Constructor
Circle::Circle(sf::Vector2f location, float radius, std::string color) :
	Drawable(location, radius, "CIRCLE", color),
	radius(radius)
{
	// Sets the size, position and color of the circle to the given variables
	// COLORS EVERYWHERE NEED TO BE REPLACE BY TEXTURES - XXX DONIOL
	shape.setRadius(radius);
	shape.setPosition(location);
	if (color == "red") {
		shape.setFillColor({ 255, 0, 0 });
	}
	else if (color == "green") {
		shape.setFillColor({ 0, 255, 0 });
	}
	else if (color == "blue") {
		shape.setFillColor({ 0, 0, 255 });
	}
}


// Function that draws the circle
void Circle::drawable_draw(sf::RenderWindow& window) {
	window.draw(shape);
}

// Returns color
std::string Circle::drawable_get_visual() {
	return color;
}

// Update the circle
void Circle::drawable_update() {
	shape.setPosition(location);
	hitbox = sf::FloatRect( location.x, location.y, drawable_get_size().x, drawable_get_size().y );
}