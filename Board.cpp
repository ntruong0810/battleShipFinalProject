//
// Created by Thu Nhan Truong on 6/8/24.
//

#include "Board.h"
void Board::print()
{
    std::cout << "  ";
    for(int i=1; i<=10; i++)
        std::cout << std::setw(3) << i;
    std::cout << std::endl;

    for(int i=0; i<rowSize; i++)
    {
        std::cout << static_cast<char>('A' + i) << " ";
        for(int j=0; j<colSize; j++)
        {

            std::cout << std::setw(3) << board[i][j].getLetter();
        }
        std::cout << std::endl;
    }
}

void Board::place(int row, int col, Ship ship)
{
    if(ship.getOrientation() == HORIZONTAL)
        placeHorizontal(row, col, ship);
    else
        placeVertical(row, col, ship);
}

void Board::placeHorizontal(int row, int col, Ship ship)
{
    int j = col;
    for(int i=0; i<ship.getSize(); i++)
    {
        board[row][j++] = ship;
    }
}
void Board::placeVertical(int row, int col, Ship ship)
{
    int j = row;
    for(int i=0; i<ship.getSize(); i++)
    {
        board[j++][col] = ship;
    }
}

Ship &Board::getShip(int rowIndex, int colIndex)
{
    return board[rowIndex][colIndex];
}

int Board::getRowSize() const
{
    return rowSize;
}

int Board::getColSize() const
{
    return colSize;
}