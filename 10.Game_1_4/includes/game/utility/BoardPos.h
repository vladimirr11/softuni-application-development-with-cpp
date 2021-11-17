#ifndef BOARDPOS_H
#define BOARDPOS_H

// C system includes

// C++ system includes
#include <cstdint>

// Third-party includes

// Own includes

// Forward declarations

struct BoardPosition {
    BoardPosition() = default;
    
    BoardPosition(int32_t inputRow, int32_t inputCol) :
        boardRow(inputRow), boardCol(inputCol) {}

    int32_t boardRow {};
    int32_t boardCol {};
};

#endif // !BOARDPOS_H
