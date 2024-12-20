#include "Square.hpp"

#include <format>

Square::Square() 
{
    text = sf::Text();
    shape = sf::RectangleShape();
    value = 0;
    real = false;
}

Square::Square(sf::Font* font, sf::RectangleShape newShape, unsigned newValue, bool newReal)
    : shape(newShape), value(newValue), real(newReal)
{
    shape.setFillColor(sf::Color(50, 50, 50));
    shape.setOutlineColor(sf::Color::White);
    shape.setOutlineThickness(3.f);

    text.setString(std::to_string(value));
    text.setFillColor(sf::Color::White);
    text.setFont(*font);
    text.setCharacterSize(getSize().x / 2); // Magic, works fine

    // Position text to center of square
    sf::FloatRect textBounds = text.getLocalBounds();
    const sf::FloatRect bounds(text.getLocalBounds());
    const sf::Vector2f box(getSize());
    text.setOrigin((bounds.width - box.x) / 2 + bounds.left, (bounds.height - box.y) / 2 + bounds.top);
    text.setPosition(getCenter());
}

bool Square::operator==(const Square& other) const {
    return (getPosition() == other.getPosition());
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

sf::Vector2f Square::getCenter()
{
    return getPosition() + getSize() / 2.0f;
}
