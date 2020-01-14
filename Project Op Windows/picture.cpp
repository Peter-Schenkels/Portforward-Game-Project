#include "drawables.hpp"

// picture.cpp
// Daniel van Eijk-Bos Bulkowski, 02-Dec-19, Version 1

// Contains all functions for the picture subclass

// Constructor that stores the given location and link to the texture
picture::picture(sf::Vector2f location, sf::Vector2f size, std::string link) :
	drawable(location, size, "PICTURE", "none"),
	size(size),
	link(link)
{
	// Loads the texture from the given link, sets the texture for the sprite and sets the sprites position
	texture.loadFromFile(link);
	sprite.setTexture(texture);
	sprite.setPosition(location);

	sf::Vector2f current_factor = sprite.getScale();
	sf::Vector2f new_factor(current_factor.x * (size.x / texture.getSize().x),
		current_factor.y * (size.y / texture.getSize().y));

	sprite.setScale(new_factor);
}

// Constructor that uses a drawable pointer
picture::picture(drawable* input) :
	drawable(input->drawable_get_location(), sf::Vector2f(input->drawable_get_hitbox().width,
		input->drawable_get_hitbox().height), "PICTURE", input->drawable_get_visual()),
	size(sf::Vector2f(input->drawable_get_hitbox().width, input->drawable_get_hitbox().height)),
	link(input->drawable_get_visual())
{
	// Loads the texture from the given link, sets the texture for the sprite and sets the sprites position
	texture.loadFromFile(link);
	sprite.setTexture(texture);
	sprite.setPosition(location);

	sf::Vector2f current_factor = sprite.getScale();
	sf::Vector2f new_factor(current_factor.x * (size.x / texture.getSize().x),
		current_factor.y * (size.y / texture.getSize().y));

	sprite.setScale(new_factor);
}


// Draws the picture
void picture::drawable_draw(sf::RenderWindow& window) {
	window.draw(sprite);
}

// Returns the link that the picture uses as texture
std::string picture::drawable_get_visual() {
	return link;
}

// Update the picture
void picture::drawable_update() {
	sprite.setPosition(location);
}