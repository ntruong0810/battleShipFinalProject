//
// Created by Thu Nhan Truong on 6/8/24.
//

#include "GraphicBoard.h"
void GraphicBoard::draw(sf::RenderTarget& window, sf::RenderStates states) const
{
    for(int i=0; i<10; i++)
    {
        for(int j=0; j<10; j++)
        {
            window.draw(_board[i][j]);
        }
    }
}
void GraphicBoard::draw(sf::RenderWindow& window, Board& board)
{
    sf::Vector2f point;
    for(int i=0; i<board.getRowSize(); i++)
    {
        point.x = 0;
        sf::RectangleShape square;
        for(int j =0; j<board.getColSize(); j++)
        {
            square = getSquare(board.getShip(i, j), point);
            window.draw(square);
            point.x += square.getGlobalBounds().width + 10.f;
        }
        point.y += square.getGlobalBounds().height + 10.f;
    }
}

void GraphicBoard::update(Board& board)
{
    sf::Vector2f point;
    for(int i=0; i<board.getRowSize(); i++)
    {
        point.x = 0;
        sf::RectangleShape square;
        for(int j =0; j<board.getColSize(); j++)
        {
            square = getSquare(board.getShip(i, j), point);
            _board[i][j] = square;
            point.x += square.getGlobalBounds().width + 10.f;
        }
        point.y += square.getGlobalBounds().height + 10.f;
    }
}
sf::RectangleShape GraphicBoard::getSquare(Ship ship, sf::Vector2f point)
{
    sf::RectangleShape r({50.f, 50.f});
    switch(ship.getLetter())
    {
        case '~':
            r.setFillColor(sf::Color::Blue);
            break;
        case 'a':
            r.setFillColor(sf::Color::Red);
            break;
        case 'b':
            r.setFillColor(sf::Color::Green);
            break;
        case 'c':
            r.setFillColor(sf::Color::Yellow);
            break;
        case 'd':
            r.setFillColor(sf::Color::Cyan);
            break;
        case 'e':
            r.setFillColor(sf::Color::Magenta);
            break;

        default:
            r.setFillColor(sf::Color::White);
    }

    r.setPosition(point);
    return r;
}
sf::RectangleShape& GraphicBoard::getSquare(int row, int col)
{
    return _board[row][col];
}

