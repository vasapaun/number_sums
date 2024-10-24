#ifndef SQUARE_HPP
#define SQUARE_HPP

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <string>

class Square
{
    private:
        sf::Text text;
        sf::RectangleShape shape;
        unsigned value;
        bool real;

    public:

        // Constructor

        Square(sf::Font*,
               sf::RectangleShape newShape = sf::RectangleShape(),
               unsigned newValue = 8,
               bool newReal = false);

        // Getters and setters

        sf::Text getText () const { return text; }
        void setText (sf::Text newText) { text = newText; }

        sf::RectangleShape getShape () const { return shape; }
        void setShape (sf::RectangleShape newShape) { shape = newShape; }

        unsigned getValue () const { return value; }
        void setValue (unsigned newValue) { value = newValue; }

        bool isReal () { return real; }
        void setIsReal (bool newIsReal) { real = newIsReal; }

        sf::Vector2f getPosition () const { return shape.getPosition(); }
        void setPosition (sf::Vector2f newPosition)
        { 
            shape.setPosition(newPosition);
            text.setPosition(newPosition);
        }

        sf::Color getFillColor () const { return shape.getFillColor(); }
        void setFillColor (sf::Color newFillColor) { shape.setFillColor(newFillColor); }

        sf::Color getOutlineColor () const { return shape.getOutlineColor(); }
        void setOutlineColor (sf::Color newOutlineColor) { shape.setOutlineColor(newOutlineColor); }

        float getOutlineThickness () const { return shape.getOutlineThickness(); }
        void setOutlineThickness (float newOutlineThickness) { shape.setOutlineThickness(newOutlineThickness); }

        sf::Vector2f getSize() const { return shape.getSize(); }
        void setSize (float newSize) { shape.setSize(sf::Vector2f(newSize, newSize)); }


        // Other methods

        std::string toString ();

        void draw (sf::RenderWindow*);
        void drawWithOffset (sf::RenderWindow*, sf::Vector2f);

        void move (sf::Vector2f);

        sf::Vector2f getCenter();
};

#endif
