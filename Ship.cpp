//
// Created by Thu Nhan Truong on 6/8/24.
//

#include "Ship.h"
Ship::Ship()
{
    setSize(0);
    setLetter('~');
}
Ship::Ship(int size, char letter)
{
    setSize(size);
    setLetter(letter);
}

Ship::Ship(ShipEnum ship, Orientation orientation)
{
    _orientation = orientation;
    switch(ship)
    {
        case DESTROYER:
            setSize(2);
            setLetter('D');
            break;
        case JEFF:
            setSize(3);
            setLetter('J');
            break;
        case SUBMARINE:
            setSize(3);
            setLetter('S');
            break;
        case BATTLESHIP:
            setSize(4);
            setLetter('B');
            break;
        case CARRIER:
            setSize(5);
            setLetter('C');
            break;
        default:
            setSize(0);
            setLetter('~');
    }
}
int Ship::getSize() const
{
    return _size;
}

char Ship::getLetter() const
{
    return _letter;
}

void Ship::setSize(int size)
{
    _size = size;
}

void Ship::setLetter(char letter)
{
    _letter = letter;
}
Orientation Ship::getOrientation() const
{
    return _orientation;
}

void Ship::setOrientation(Orientation orientation)
{
    _orientation = orientation;
}