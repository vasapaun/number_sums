#ifndef CURSOR_HPP
#define CURSOR_HPP

#include "Square.hpp"

class Cursor {
    private:
        Square selected;

    public:
        Cursor();
        Cursor(Square);

        Square getSelected() { return selected; }
        void select(Square newSelection) { selected = newSelection; }
};

#endif
