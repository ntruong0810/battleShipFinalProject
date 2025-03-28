# Battleship Game (SFML + C++)

A Battleship game implemented in C++ using the SFML graphics library. This project is part of the CS2 final assignment and features a graphical board where players can place ships and engage in naval battles.
Future updates will include backend networking to connect two computers for real-time gameplay.

## Requirements

## Features
- **Graphical Interface**: Uses SFML to render the game board and ships.
- **Player Interaction**: Allows users to place ships and attack enemy positions.
- **Turn-Based Gameplay**: Each player takes turns attacking the opponent's board.
- **Game Logic**: Implements core Battleship mechanics, including hit detection and sinking ships.
- **Multiplayer Setup (Planned)**: Currently, players must play on separate computers and manually track their moves. Future updates will include backend networking to connect two computers for real-time gameplay.

## Requirements
To run this project, you need:
- **C++ Compiler** (G++/Clang/MSVC)
- **SFML 2.5+** (Simple and Fast Multimedia Library)
- **CMake** (Optional but recommended for building)

## Installation & Setup

### 1. Clone the Repository
```bash
git clone https://github.com/your-username/battleship-sfml.git
cd battleship-sfml
```

### 2. Install SFML
- Windows: Use vcpkg
  ```bash
  vcpkg install sfml
  ```
- macOS: Use Homebrew
  ```bash
  brew install sfml
  ```
- Linux: Install via package manager
  ```bash
  sudo apt-get install libsfml-dev
  ```

### 3. Compile and Run
```bash
g++ -std=c++11 main.cpp GraphicBoard.cpp Ship.cpp BattleshipPlayer.cpp Board.cpp -o battleship -lsfml-graphics -lsfml-window -lsfml-system
./battleship
```

## How to Play
- **Start the Game**: Launch the program to see the game board.
- **Place Ships**: Players set up their ships on the fixed board.
- **Take Turns**: Each player selects a position to attack.
- **Multiplayer Mode**: Currently, each player must play on their own laptop and manually check if they hit the opponent's ships. Future updates will add networked multiplayer functionality.
- **Win Condition**: The game ends when all of an opponent’s ships are destroyed.

## File Structure
```
├── main.cpp              # Main entry point of the game
├── GraphicBoard.cpp      # Handles rendering using SFML
├── GraphicBoard.h        # Header file for GraphicBoard
├── Ship.cpp              # Defines ship attributes and functions
├── Ship.h                
├── BattleshipPlayer.cpp  # Manages player interactions and turns
├── BattleshipPlayer.h    # Header file for BattleshipPlayer
├── Board.cpp             # Handles board logic
├── Board.h               # Header file for Board
└── README.md             # Project documentation
```

## Future Improvements
- Implement backend networking to connect two computers
- AI opponent for single-player mode
- Sound effects for better immersion
- Additional UI enhancements

## Demo


https://github.com/user-attachments/assets/773c0d17-490a-48ba-9df9-e5922d62b0e9


## License
This project is open-source under the MIT License.
