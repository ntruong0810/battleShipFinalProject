//
// Created by Thu Nhan Truong on 6/8/24.
//

#ifndef FINAL_BOARD_H
#define FINAL_BOARD_H

#include <iostream>
#include <iomanip>

#include "Ship.h"
class Board
{

public:

    void print();

    void place(int row, int col, Ship ship);
    Ship &getShip(int rowIndex, int colIndex);
    int getRowSize() const;
    int getColSize() const;
private:
    static const int rowSize = 10;
    static const int colSize = 10;
    void placeHorizontal(int row, int col, Ship ship);
    void placeVertical(int row, int col, Ship ship);
    Ship board[rowSize][colSize];

};

#endif //FINAL_BOARD_H
