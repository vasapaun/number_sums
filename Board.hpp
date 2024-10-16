#ifndef BOARD_HPP 
#define BOARD_HPP

#include <vector>
#include "Square.hpp"

class Board {
    private:
        std::vector<std::vector<Square>> board;

    public:
        Board (std::size_t drawSize, std::size_t squareCount);
        
        void draw (sf::RenderWindow* window, sf::Vector2f offset);
};

#endif
