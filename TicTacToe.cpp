#include <iostream>
#include <ctime>
#include <cstdlib>

//Function declarations
void drawBoard(char *spaces); //accepts a pointer to an array named spaces
// which we do because now we dont make a copy of the entire array, but now we only really pass in the first element
void playerMove(char *spaces, char player);
void computerMove(char *spaces, char computer);
bool checkWinner(char *spaces, char player, char computer);
bool checkTie(char *spaces);

int main(){
    char spaces[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
    char player = 'X';
    char computer = 'O';
    bool running = true;

    drawBoard(spaces);
    

    while(running){
        playerMove(spaces, player);
        drawBoard(spaces);
        
        if(checkWinner(spaces,player,computer)){
            //std::cout << "Congrats, you win!";
            running = false;
            break;
        } else if(checkTie(spaces)){
            running = false;
            break;
        }
        std::cout << "Computer moving...\n" ;
        
        computerMove(spaces, computer);
        drawBoard(spaces);

        if(checkWinner(spaces,player,computer)){
            //std::cout << "Congrats, you win!";
            running = false;
            break;
        }
    }
    

}

void drawBoard(char *spaces){
    //Draws the board
    std::cout << "\n " << spaces[0] << " | " << spaces[1] << " | " << spaces[2] << '\n';
    std::cout << "-----------\n";
    std::cout << " " << spaces[3] << " | " << spaces[4] << " | " << spaces[5] << '\n';
    std::cout << "-----------\n";
    std::cout << " " << spaces[6] << " | " << spaces[7] << " | " << spaces[8] << '\n' << '\n';
}



void playerMove(char *spaces, char player){
    int number; 
    do{
        std::cout << "Enter a spot to place a marker (1-9): ";
        std::cin >> number;
        number--;
        if(spaces[number] == ' '){
            spaces[number] = player;
        }
    }while(!(number >= 0 && number <= 8));

}

void computerMove(char *spaces, char computer){
    srand(time(NULL));
    while(true){
        int num = rand() % 9; //Generate rand number between 0-8
        if(spaces[num] == ' '){
            spaces[num] = computer;
            break;
        }

    }
    
}

bool checkWinner(char *spaces, char player, char computer){
    // Check horizontal wins
    if (spaces[0] == spaces[1] && spaces[1] == spaces[2] && spaces[0] != ' '){
        if (spaces[0] == player) {
            std::cout << "YOU WIN!\n";
        } else if (spaces[0] == computer) {
            std::cout << "YOU LOSE!\n";
        }
        return true; // A winner is found
    }
    if (spaces[3] == spaces[4] && spaces[4] == spaces[5] && spaces[3] != ' ') {
        if (spaces[3] == player) {
            std::cout << "YOU WIN!\n";
        } else if (spaces[3] == computer) {
            std::cout << "YOU LOSE!\n";
        }
        return true; // A winner is found
    }
    if (spaces[6] == spaces[7] && spaces[7] == spaces[8] && spaces[6] != ' ') {
        if (spaces[6] == player) {
            std::cout << "YOU WIN!\n";
        } else if (spaces[6] == computer) {
            std::cout << "YOU LOSE!\n";
        }
        return true; // A winner is found
    }

    // Check vertical wins
    if (spaces[0] == spaces[3] && spaces[3] == spaces[6] && spaces[0] != ' ') {
        if (spaces[0] == player) {
            std::cout << "YOU WIN!\n";
        } else if (spaces[0] == computer) {
            std::cout << "YOU LOSE!\n";
        }
        return true; // A winner is found
    }
    if (spaces[1] == spaces[4] && spaces[4] == spaces[7] && spaces[1] != ' ') {
        if (spaces[1] == player) {
            std::cout << "YOU WIN!\n";
        } else if (spaces[1] == computer) {
            std::cout << "YOU LOSE!\n";
        }
        return true; // A winner is found
    }
    if (spaces[2] == spaces[5] && spaces[5] == spaces[8] && spaces[2] != ' ') {
        if (spaces[2] == player) {
            std::cout << "YOU WIN!\n";
        } else if (spaces[2] == computer) {
            std::cout << "YOU LOSE!\n";
        }
        return true; // A winner is found
    }

    // Check diagonal wins
    if (spaces[0] == spaces[4] && spaces[4] == spaces[8] && spaces[0] != ' ') {
        if (spaces[0] == player) {
            std::cout << "YOU WIN!\n";
        } else if (spaces[0] == computer) {
            std::cout << "YOU LOSE!\n";
        }
        return true; // A winner is found
    }
    if (spaces[2] == spaces[4] && spaces[4] == spaces[6] && spaces[2] != ' ') {
        if (spaces[2] == player) {
            std::cout << "YOU WIN!\n";
        } else if (spaces[2] == computer) {
            std::cout << "YOU LOSE!\n";
        }
        return true; // A winner is found
    }

    // No winner found
    return false;
}

bool checkTie(char *spaces){
    for(int i = 0; i < 9; i ++){
        if(spaces[i] == ' '){
            return false;
        }
    }
    std::cout << "It was a tie\n";
    return true;
}