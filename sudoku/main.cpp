#include <iostream>
using std::cout;

int startupClues = 0;
int boardData[81];
int startupSelectedTile;
int startupGivenValue;

void boardStartup(){

    

    std::cin >> startupSelectedTile;
    if (startupSelectedTile > 0 && startupSelectedTile < 82){
        cout << "\nYou have selected tile number " << startupSelectedTile << ".\nNow input the value of the tile.\n ";
        std::cin >> startupGivenValue;


        if (startupGivenValue > 0 && startupGivenValue <= 9){
            boardData[startupSelectedTile - 1] = startupGivenValue;
            cout << "\nTile number " << startupSelectedTile << " has been set to " << startupGivenValue;
            startupClues++;
            cout << "\nNow select another tile.";
            boardStartup();
        }
        else{
            cout << "\nYou probably gave an illegal value. And I'm tired of coding this fucking loop so go and input something good and nice.\n";
        }
                
        
        }
    else if (startupSelectedTile == 0 && startupClues < 17){//if user tries to quit board setup without enough information.
        cout << "Minimum clues needed to solve sudoku is 17. But you only provided " << startupClues << ". Please provide more clues.\n";
        boardStartup();
    }
    else if (startupClues == 81){//if the board is already solved
        cout << "My brother in christ, this sudoku is fucking solved already.";
    } 
    else if (startupSelectedTile == 0 && startupClues >= 17){//all good.
        cout << "\nThe board has been constructed successfully and can be solved properly.";
    }
    else{//if idk whatever the fuck happens
        cout << "\nBro for the love of god and wellbeing of your loved ones, input something valid.";
        boardStartup();
    }
    
    
    }

int main(){
    for (int i = 1; i <= 80; i++){
        boardData[i] = 0;
    }
    cout << "Welcome to Sudoku Solver 69! \nLet's set up the board.\nFirst you need to specify a tile, number 1 is bottom left, 81 is top right. \nWhen you're done, input 0.\n";
    boardStartup();

    cout << "if this message is shown, board has been constructed and program continues.\nNow the program will output the board.\n";
    for (int i = 0; i <= 80; i++){
        cout << boardData[i] << std::endl;
    }


}