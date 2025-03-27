#include "BattleshipPlayer.h"
BattleshipPlayer::BattleshipPlayer()
{
    init();
}
void BattleshipPlayer::draw(sf::RenderWindow& window)
{
    GraphicBoard graphicBoard;
    graphicBoard.draw(window, board);
}
void BattleshipPlayer::draw(sf::RenderTarget& window,
                            sf::RenderStates states) const
{
    window.draw(graphicBoard);
    drawShips(window);
}
void BattleshipPlayer::update()
{
    graphicBoard.update(board);
}

void BattleshipPlayer::eventHandler(sf::RenderWindow& window, sf::Event event)
{
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);
    for(int i=0; i<board.getRowSize(); i++)
    {
        for(int j=0; j<board.getColSize(); j++)
        {
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)
               && graphicBoard.getSquare(i, j).getGlobalBounds().contains(mpos))
            {
                board.getShip(i, j).setLetter('k');
            }
            else if(board.getShip(i, j).getLetter() < 'a' ||
                    board.getShip(i, j).getLetter() > 'e')
                board.getShip(i, j).setLetter('~');
            if(sf::Event::MouseButtonReleased == event.type)
                if(board.getShip(i, j).getLetter() == 'k')
                {
                    board.getShip(i, j).setLetter('a'+ selectedRow);
                    isDragging = false;
                }
        }
    }

    shipEventHandler(window, event);
}

void BattleshipPlayer::shipEventHandler(sf::RenderWindow& window, sf::Event event) {
    //take the coordinate of the mouse (mouse position)
    sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window);

    //check if the left mousr button is pressed ?
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
    {
        for (int i = 0; i < _ships.size(); i++) {
            for (int j = 0; j < _ships[i].size(); j++) {
                //check if the mouse position is at any ship
                if (_ships[i][j].getGlobalBounds().contains(mpos)) {
                    selectedRow = i;
                    selectedShipIndex = j;
                    isDragging = true;

                    //calculate the distance between mouse position and the ship
                    //and remain the distance between the mouse and the ship
                    offset = mpos - _ships[i][j].getPosition();

                    for (int k = 0; k < _ships[i].size(); k++) {
                        // save the offset of the square of the same ship
                        relativeOffsets.push_back(_ships[i][k].getPosition() - _ships[i][0].getPosition());
                    }
                    break;
                }
            }
        }
    }

    if (event.type == sf::Event::MouseMoved && isDragging)
    {
        //calculate the new ship position
        sf::Vector2f basePos = mpos - offset;

        // j: num square of each ship
        for (int j = 0; j < _ships[selectedRow].size(); j++) {
            //set a new position for the ship
            _ships[selectedRow][j].setPosition(basePos + relativeOffsets[j]);
        }
    }
    if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && isDragging)
    {
        isDragging = false;



        sf::Vector2f firstSquarePosition = _ships[selectedRow][0].getPosition();
        int rowIndex = static_cast<int>(firstSquarePosition.y / boardCellSize);
        int colIndex = static_cast<int>(firstSquarePosition.x / boardCellSize);


        // check boundaries
        if (rowIndex >= 0 && rowIndex < board.getRowSize() &&
            colIndex >= 0 && colIndex + _shipSizes[selectedRow] - 1 < board.getColSize())
        {

            char shipLetter = 'a' + selectedRow;
            for (int i = 0; i < _shipSizes[selectedRow]; i++) {
                board.getShip(rowIndex, colIndex + i).setLetter(shipLetter);
                graphicBoard.getSquare(rowIndex, colIndex + i).setFillColor(getSquareColorFromShipLetter(shipLetter));
            }
        }
        // Đặt lại vị trí của các con tàu về vị trí ban đầu
        sf::Vector2f startPosition = {700.f, 50.f};
        sf::Vector2f position = startPosition;
        for (int i = 0; i < _ships.size(); i++)
        {
            position.x = startPosition.x;
            for (int j = 0; j < _ships[i].size(); j++)
            {
                _ships[i][j].setPosition(position);
                position.x += _ships[i][j].getGlobalBounds().width + 10.f;
            }
            position.y += 100.f;
        }

        selectedRow = -1;
        relativeOffsets.clear();
    }
}


void BattleshipPlayer::init()
{
    _shipSizes = {2, 3, 3, 4, 5};
    _shipColors = {sf::Color::Red, sf::Color::Green,
                   sf::Color::Yellow, sf::Color::Cyan,
                   sf::Color::Magenta};

    sf::Vector2f startPosition = {700.f, 50.f};
    sf::Vector2f position;
    boardPosition = {0.f, 0.f};
    position = startPosition;
    for(int i=0; i<_shipSizes.size(); i++)
    {
        position.x = startPosition.x;
        _ships.push_back(std::vector<sf::RectangleShape>(_shipSizes.size()));
        for(int j=0; j<_shipSizes[i]; j++)
        {
            sf::RectangleShape r({50.f, 50.f});
            r.setFillColor(_shipColors[i]);
            r.setPosition(position);
            _ships[i][j] = r;
            position.x += r.getGlobalBounds().width + 10.f;
        }
        position.y += 100.f;
    }
    boardCellSize = 50.f;
//    boardStartPosition = {0.f,0.f};
}

void BattleshipPlayer::drawShips(sf::RenderTarget& window) const
{
    for(int i=0; i<_shipSizes.size(); i++)
    {
        for(int j=0; j<_shipSizes[i]; j++)
        {
            window.draw(_ships[i][j]);
        }
    }
}
void BattleshipPlayer::dragShip(sf::Vector2f mpos, int row, int col)
{
    sf::Vector2f center;
    sf::FloatRect f = _ships[row][col].getGlobalBounds();
    center.x = f.width/2.f;
    center.y = f.height/2.f;
    _ships[row][col].setOrigin(center);
    _ships[row][col].setPosition(mpos);
}

sf::Color BattleshipPlayer::getSquareColorFromShipLetter(char shipLetter) {
    switch(shipLetter) {
        case 'a':
            return sf::Color::Red;
        case 'b':
            return sf::Color::Green;
        case 'c':
            return sf::Color::Yellow;
        case 'd':
            return sf::Color::Cyan;
        case 'e':
            return sf::Color::Magenta;
        default:
            return sf::Color::Blue; // Default color for unoccupied cells
    }
}
