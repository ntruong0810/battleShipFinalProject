//
// Created by Thu Nhan Truong on 6/8/24.
//

#ifndef FINAL_GRAPHICBOARD_H
#define FINAL_GRAPHICBOARD_H
#include <SFML/Graphics.hpp>
#include "Board.h"

class GraphicBoard : public sf::Drawable
{
public:
    void draw(sf::RenderWindow& window, Board& board);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
    void update(Board& board);
    sf::RectangleShape& getSquare(int row, int col);

private:
    sf::RectangleShape getSquare(Ship ship, sf::Vector2f point);

    sf::RectangleShape _board[10][10];

};
#endif //FINAL_GRAPHICBOARD_H
