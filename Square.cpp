#include "Square.hpp"

#include <format>

Square::Square(sf::RectangleShape newShape, unsigned newValue, bool newReal)
    : shape(newShape), value(newValue), real(newReal) { }

std::string Square::toString()
{
    return std::format("Position: {}, {}\nSize: {}, {}\n", getPosition().x, getPosition().y, getSize().x, getSize().y);
}

void Square::draw(sf::RenderWindow* window)
{
    window->draw(shape);
}

void Square::drawWithOffset(sf::RenderWindow* window, sf::Vector2f offset)
{
    move(offset);
    draw(window);
    move(-offset);
}

void Square::move(sf::Vector2f offset)
{
    setPosition(getPosition() + offset);
}
