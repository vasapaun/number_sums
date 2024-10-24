#ifndef BOARD_HPP 
#define BOARD_HPP

#include <vector>
#include "Square.hpp"
#include "Cursor.hpp"

class Board {
    private:
        std::vector<std::vector<Square>> board;
        sf::Font font;
        Cursor cursor;

    public:
        Board (std::size_t drawSize, std::size_t squareCount, sf::Font* font);

        void draw (sf::RenderWindow* window, sf::Vector2f offset);
};

#endif
