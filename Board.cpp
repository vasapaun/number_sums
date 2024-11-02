#include "Board.hpp"

Board::Board(std::size_t drawSize, std::size_t squareCount, sf::Font* font)
{

    // Calculate size of board squares (in pixels)
    std::size_t squareSize = drawSize / squareCount;

    board.resize(squareCount);

    for(int i = 0; i < squareCount; i++)
    {
        for(int j = 0; j < squareCount; j++)
        {
            sf::RectangleShape newShape(sf::Vector2f(squareSize, squareSize));
            newShape.setPosition(sf::Vector2f(j * squareSize, i * squareSize));

            Square newSquare{font, newShape};

            board[i].push_back(newSquare);
        }
    }

    cursor = Cursor(board[0][0]);

}

void Board::draw(sf::RenderWindow* window, sf::Vector2f offset)
{
    
    for(auto row : board)
    {
        for(auto sq : row)
        {
            if (sq == cursor.getSelected())
            {
            }
            sq.drawWithOffset(window, offset);
        }
    }
}
