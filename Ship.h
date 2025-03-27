//
// Created by Thu Nhan Truong on 6/8/24.
//

#ifndef FINAL_SHIP_H
#define FINAL_SHIP_H
#include <cassert>
enum ShipEnum{
    DESTROYER, JEFF, SUBMARINE, BATTLESHIP, CARRIER, EMPTY
};
enum Orientation
{
    HORIZONTAL, VERTICAL
};

class Ship
{
private:
    int _size;
    char _letter;
    Orientation _orientation;
public:
    ///Constructors
    ///default
    Ship();
    ///overloaded constructor
    Ship(int size, char letter);

    ///Constructor that will take an enum and
    /// automatically assign the size and letter;
    Ship(ShipEnum ship, Orientation orientation = HORIZONTAL);
    ///Accessors and Mutators (Getters and Setters)
    int getSize() const;
    char getLetter() const;
    Orientation getOrientation() const;

    void setSize(int size);
    void setLetter(char letter);
    void setOrientation(Orientation orientation);
};

#endif //FINAL_SHIP_H
