#include "Board.hpp"

Board::Board(std::size_t drawSize, std::size_t squareCount)
{
    // Calculate size of board squares (in pixels)
    std::size_t squareSize = drawSize / squareCount;

    board.resize(squareCount);

    for(int i = 0; i < squareCount; i++)
    {
        for(int j = 0; j < squareCount; j++)
        {
            Square newSquare{};

            newSquare.setValue(1);
            newSquare.setIsReal(true);

            newSquare.setPosition(sf::Vector2f(j * squareSize, i * squareSize));
            newSquare.setSize(squareSize);

            newSquare.setFillColor(sf::Color(40, 40, 40));
            newSquare.setOutlineColor(sf::Color::White);
            newSquare.setOutlineThickness(5.f);

            board[i].push_back(newSquare);
        }
    }
}

void Board::draw(sf::RenderWindow* window, sf::Vector2f offset)
{
    for(auto row : board)
    {
        for(auto sq : row)
        {
            sq.drawWithOffset(window, offset);
        }
    }
}
