#include "Square.hpp"

#include <format>

Square::Square(sf::Font* font, sf::RectangleShape newShape, unsigned newValue, bool newReal)
    : shape(newShape), value(newValue), real(newReal)
{
    shape.setFillColor(sf::Color(40, 40, 40));
    shape.setOutlineColor(sf::Color::White);
    shape.setOutlineThickness(5.f);

    text.setString(std::to_string(value));
    text.setPosition(getPosition());
    text.setFillColor(sf::Color::Red);
    text.setFont(*font);
    text.setCharacterSize(24);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
}

std::string Square::toString()
{
    return std::format("Position: {}, {}\nSize: {}x{}\n", getPosition().x, getPosition().y, getSize().x, getSize().y);
}

void Square::draw(sf::RenderWindow* window)
{
    window->draw(shape);
    window->draw(text);
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
