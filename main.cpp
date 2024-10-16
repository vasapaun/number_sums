#include "Board.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

#define BOARD_DIMENSION (10)
#define OFFSET_PERCENT (10)

void handleEvent (sf::Event* event, sf::Window* window);
sf::Vector2u calculateBoardSize (sf::Vector2u windowSize, unsigned offsetPercent);


int main(int argc, char** argv)
{
    // Load font and check for error
    sf::Font font;
    if(!font.loadFromFile("../resources/HackNerdFont-Regular.ttf"))  exit(1);

    sf::RenderWindow mainWindow(sf::VideoMode::getDesktopMode(), "SumS", sf::Style::Fullscreen);

    sf::Vector2u mainWindowSize = mainWindow.getSize();
    sf::Vector2u boardSize = calculateBoardSize(mainWindowSize, OFFSET_PERCENT);
    sf::Vector2u drawOffset = sf::Vector2u((mainWindowSize.x - boardSize.x) / 2, (mainWindowSize.y - boardSize.y) / 2);

    Board gameBoard = Board(boardSize.x, BOARD_DIMENSION, &font);

    sf::Text text;

    // select the font
    text.setFont(font); // font is a sf::Font

    // set the string to display
    text.setString("Hello world");

    // set the character size
    text.setCharacterSize(24); // in pixels, not points!

    // set the color
    text.setFillColor(sf::Color::Red);

    // set the text style
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);

    text.setPosition(sf::Vector2f(100.f ,100.f));

    while (mainWindow.isOpen())
    {
        sf::Event event;
        while (mainWindow.pollEvent(event))
        {
            handleEvent(&event, &mainWindow);
        }

        mainWindow.clear(sf::Color(20, 20, 20));

        mainWindow.draw(text);
        gameBoard.draw(&mainWindow, sf::Vector2f(drawOffset));

        mainWindow.display();
    }

    return 0;
}

void handleEvent(sf::Event* event, sf::Window* window)
{
    if (event->type == sf::Event::Closed || (event->type == sf::Event::KeyPressed && event->key.code == sf::Keyboard::Q))
        window->close();
}

sf::Vector2u calculateBoardSize (sf::Vector2u windowSize, unsigned offsetPercent)
{
    sf::Vector2u retVector;

    if(windowSize.x < windowSize.y)
    {
        retVector.x = windowSize.x * (100 - 2 * offsetPercent) / 100;
        retVector.y = retVector.x;
    }

    else {
        retVector.y = windowSize.y * (100 - 2 * offsetPercent) / 100;
        retVector.x = retVector.y;
    }

    return retVector;
}
