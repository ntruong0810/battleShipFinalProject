#include <iostream>
#include "Board.h"
#include "Ship.h"
#include "GraphicBoard.h"
#include "BattleshipPlayer.h"
int main()
{
    sf::RenderWindow window({1080, 720, 32}, "Battleship");
    window.setFramerateLimit(60);
    BattleshipPlayer player1;

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
            player1.eventHandler(window, event);
        }
        /////// PLACE CODE FOR PLACE SHIPS OM THE BOARD IN THE CONSOLE
        player1.update();

        window.clear();
        window.draw(player1);
        window.display();
    }
    return 0;
}