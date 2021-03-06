// Player_Hitbox.cpp
// Daniel van Eijk-Bos Bulkowski - Peter Schenkels - Rick van Mourik - Noah Titarsole, 31-Jan-2020, Version 3.4
// Contains all functions for the Player_Hitbox class


#include "player_hitbox.hpp"


// Constructor
Player_Hitbox::Player_Hitbox(sf::Vector2f position, sf::Vector2f size) :
    position(position),
    size(size),
    left(sf::Vector2f{ 0, size.y / 2 }),
    right{ sf::Vector2f{0, size.y / 2} },
    top({ size.x - size.x / 2, 0 }),
    bottom({ size.x - size.x / 2, 0 }),
    core({ size.x / 4, size.y / 4 }),
    touch({ size.x - size.x / 8, size.y }),
    box(size)
{
    Player_Hitbox_update(position);

    left.setOutlineThickness(1.f);
    right.setOutlineThickness(1.f);
    top.setOutlineThickness(1.f);
    bottom.setOutlineThickness(1.f);
    core.setOutlineThickness(1.f);
}

// Update the hitbox
void Player_Hitbox::Player_Hitbox_update(sf::Vector2f new_position) {
    position = new_position;
    left.setPosition({ position.x, position.y + size.y / 4 });
    right.setPosition({ position.x + 1 + size.x, position.y + size.y / 4 });
    top.setPosition({ position.x + size.x / 4, position.y});
    bottom.setPosition({ position.x + size.x / 4, position.y + size.y });
    core.setPosition({ position.x + size.x / 3, position.y + size.y / 3 });
    touch.setPosition({ position.x + size.x / 8, position.y });
    box.setPosition(position);
}

// Draw the hitbox
void Player_Hitbox::Player_Hitbox_draw(sf::RenderWindow& window) {
    window.draw(left);
    window.draw(right);
    window.draw(top);
    window.draw(bottom);
    window.draw(core);
}

// Check whether this certain part of the hitbox collides with an object
bool Player_Hitbox::Player_Hitbox_left_side_intersect(sf::FloatRect collider) {
    return left.getGlobalBounds().intersects(collider);
}

bool Player_Hitbox::Player_Hitbox_right_side_intersect(sf::FloatRect collider) {
    return right.getGlobalBounds().intersects(collider);
}

bool Player_Hitbox::Player_Hitbox_top_side_intersect(sf::FloatRect collider) {
    return top.getGlobalBounds().intersects(collider);
}

bool Player_Hitbox::Player_Hitbox_bottom_side_intersect(sf::FloatRect collider) {
    return bottom.getGlobalBounds().intersects(collider);
}

bool Player_Hitbox::Player_Hitbox_core_intersect(sf::FloatRect collider) {
    return core.getGlobalBounds().intersects(collider);
}

bool Player_Hitbox::Player_Hitbox_touch_intersect(sf::FloatRect collider) {
    return touch.getGlobalBounds().intersects(collider);
}

// Return the hitbox outerbounds
sf::FloatRect Player_Hitbox::Player_Hitbox_get_outerbounds() {
    return box.getGlobalBounds();
}