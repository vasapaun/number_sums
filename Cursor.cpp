#include "Cursor.hpp"


Cursor::Cursor() {  selected = Square{};    }

Cursor::Cursor(Square newSquare) : selected(newSquare) {}
