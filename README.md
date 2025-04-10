# CSE 332 Lab Base
Repository for submitting lab work

Note: We will read this file as raw text rather than markdown.

Name:
Mingzhi Cai <c.mingzhi@wustl.edu>
Boka Qin <bokaqin@wustl.edu>
Lab #: 04

Document your lab work here according to the lab specification

Create a new file named TicTacToe.h and TicTacToe.cpp, copy and paste the code in the game.h and game.cpp before
Move the code about TicTacToe into the new file, game.h and game.cpp only using for GameBase


Implementation Details
GameBase Class
The GameBase class contains:

Protected member variables for board dimensions and state
Pure virtual methods that derived classes must implement:
done() - Check if the game is won
draw() - Check if the game is a draw
turn() - Execute a player's turn
print() - Display the game board
The base class implements:

play() - Main game loop logic
prompt() - Get user input for moves
setPiece() - Place a piece on the board
Static checkArgs() method to handle command-line arguments


# Make, Warning and Error
We guys do a great job!

```bash
(base) ubuntu@arm-oracle:~/Documents/lab4-0xffff_lab_4/build$ cmake ..
-- The C compiler identification is GNU 11.4.0
-- The CXX compiler identification is GNU 11.4.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: /home/ubuntu/Documents/lab4-0xffff_lab_4/build
```
```bash
(base) ubuntu@arm-oracle:~/Documents/lab4-0xffff_lab_4/build$ make
[ 16%] Building CXX object src/CMakeFiles/lab_x.dir/Main.cpp.o
[ 33%] Building CXX object src/CMakeFiles/lab_x.dir/header.cpp.o
[ 50%] Building CXX object src/CMakeFiles/lab_x.dir/TicTacToe.cpp.o
[ 66%] Building CXX object src/CMakeFiles/lab_x.dir/game.cpp.o
/home/ubuntu/Documents/lab4-0xffff_lab_4/src/game.cpp: In static member function ‘static GameBase* GameBase::checkArgs(int, char**)’:
/home/ubuntu/Documents/lab4-0xffff_lab_4/src/game.cpp:26:1: warning: control reaches end of non-void function [-Wreturn-type]
   26 | }
      | ^
[ 83%] Building CXX object src/CMakeFiles/lab_x.dir/Gomoku.cpp.o
[100%] Linking CXX executable lab_x
[100%] Built target lab_x
```


# Games
TicTacToe Class
The TicTacToe class implements:

3x3 game board with "X" and "O" pieces
Win condition: 3 pieces in a row, column, or diagonal
Custom print method for the 3x3 board

## test for the lab_x

Command Line Tests
lab_x TicTacToe
Result: Successfully launched TicTacToe game

lab_x Gomoku
Result: Successfully launched Gomoku game

TicTacToe Testing:

```bash
(base) ubuntu@arm-oracle:~/Documents/lab4-0xffff_lab_4/build/src$ ./lab_x  TicTacToe
4          
3          
2          
1          
0          
  0 1 2 3 4 

Player X's turn.
Enter 'quit' or coordinates (x, y) between 1 ~ 3: 
```

Move as active:
```bash
Enter 'quit' or coordinates (x, y) between 1 ~ 3: 2,1
4          
3     O X  
2   X O    
1   X O    
0          
  0 1 2 3 4 


Player O: 2, 2; 2, 3; 2, 1
Player O wins!
```

Move as invilid:
```bash
(base) ubuntu@arm-oracle:~/Documents/lab4-0xffff_lab_4/build/src$ ./lab_x  TicTacToe
4          
3          
2          
1          
0          
  0 1 2 3 4 

Player X's turn.
Enter 'quit' or coordinates (x, y) between 1 ~ 3: 0,0
Coordinates must be between 1 and 3, please try again.
```

GomokuGame Class
The GomokuGame class implements:

19x19 game board with "B" (black) and "W" (white) pieces
Win condition: 5 stones in a row, column, or diagonal
Custom print method with appropriate board labeling

Gomoku Testing:
```bash
(base) ubuntu@arm-oracle:~/Documents/lab4-0xffff_lab_4/build/src$ ./lab_x Gomoku
 19                                      
 18                                      
 17                                      
 16                                      
 15                                      
 14                                      
 13                                      
 12                                      
 11                                      
 10                                      
  9                                      
  8                                      
  7                                      
  6                                      
  5                                      
  4                                      
  3                                      
  2                                      
  1                                      
    1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19

Player B's turn.
Enter 'quit' or coordinates(x, y) between 1 ~ 19: 
```
Move as invalid:
```bash
Enter 'quit' or coordinates(x, y) between 1 ~ 19: 1,3
 19                                      
 18                                      
 17                                      
 16                                      
 15                                      
 14                                      
 13                                      
 12                                      
 11                                      
 10                                      
  9                                      
  8                                      
  7                                      
  6                                      
  5                                      
  4                                      
  3 W                                    
  2 B                                    
  1 B W                                  
    1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19


Player W: 2,1; 1,3
Player B's turn.
Enter 'quit' or coordinates(x, y) between 1 ~ 19: 1,2,
Invalid Action: the square is already occupied, please try again.
```
