//
// Created by Thu Nhan Truong on 6/8/24.
//

#ifndef FINAL_BATTLESHIPPLAYER_H
#define FINAL_BATTLESHIPPLAYER_H
#include "Board.h"
#include <SFML/Graphics.hpp>
#include "GraphicBoard.h"
class BattleshipPlayer : public sf::Drawable
{
private:
    Board board;

    GraphicBoard graphicBoard;
    std::vector<int> _shipSizes;
    std::vector<sf::Color> _shipColors;
    std::vector<std::vector<sf::RectangleShape>> _ships;

    sf::Vector2f offset;
    sf::Vector2f boardPosition;
    // save the difference in offset àter each turn
    std::vector<sf::Vector2f> relativeOffsets;
    sf::Vector2f boardStartPosition;
    int selectedRow = -1;
    sf::Color getSquareColorFromShipLetter(char shipLetter);
    float boardCellSize = 50.f;
    int selectedShipIndex = -1;
    bool isDragging = false;

    void init();
    void drawShips(sf::RenderTarget& window) const;
    void shipEventHandler(sf::RenderWindow& window, sf::Event event);
    void dragShip(sf::Vector2f mpos, int row, int col);
//    void rotateShip(int shipIndex);

public:
    BattleshipPlayer();
    void draw(sf::RenderWindow& window);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
    void update();
    void eventHandler(sf::RenderWindow& window, sf::Event);

};

#endif //FINAL_BATTLESHIPPLAYER_H
