#include <cstdlib> //Library used for srand function used in the program
#include <ctime> // Library used for seeding time function used in the program
#include <iostream> //Library used for basic C++ functions
using namespace std;

// function to get the computer move
char getComputerMove()
{
    int move;
    move = rand() % 3;

    // return the move based on the random number generated
    if (move == 0) {
        return 'p';
    }
    else if (move == 1) {
        return 's';
    }
    return 'r';
}

// Function to return the result of the game
int getResults(char playerMove, char computerMove)
{
    // condition for draw
    if (playerMove == computerMove) {
        return 0;
    }

    // condition for win and loss based on the rules of game
    //Scissor v/s Paper --> Scissor wins
    //Scissor v/s Rock --> Rock wins
    //Paper v/s Rock --> Paper wins
    //If same moves --> Draw
    // 1 --> Player winds ; -1 --> Computer wins; 0 --> Draw
    if (playerMove == 's' && computerMove == 'p') {
        return 1;
    }
    if (playerMove == 's' && computerMove == 'r') {
        return -1;
    }
    if (playerMove == 'p' && computerMove == 'r') {
        return 1;
    }
    if (playerMove == 'p' && computerMove == 's') {
        return -1;
    }
    if (playerMove == 'r' && computerMove == 'p') {
        return -1;
    }
    if (playerMove == 'r' && computerMove == 's') {
        return 1;
    }
    
    return 0;
}

// Function to show the moves by the user and computer
void showMove(char move){
    if(move == 'p'){
        cout<<"Paper"<<endl;
    }
    else if(move == 's'){
        cout<<"Scissor"<<endl;
    }
    else{
        cout<<"Rock"<<endl;
    }
}


// main function
int main()
{

    char playerMove; //Stores player move

    cout << "\n\n\n\t\t\tWelcome to Stone Paper Scissor Game\n";

    cout << "\n\t\tEnter r for ROCK, p for PAPER, and s for SCISSOR\n\t\t\t\t\t";

    // input from the user
    while(1) {
        cin >> playerMove;
        if (playerMove == 'p' || playerMove == 'r' || playerMove == 's') {
            break;
        }
        else {
            cout << "\t\t\tInvalid Player Move!!! Please Try Again." << endl;
        }
    }
    
    // computer move
    srand(time(NULL)); //generates a completely random number (number of seconds since january 1970)
    char computerMove = getComputerMove();

    int result = getResults(playerMove, computerMove);

    // priting the result
    if (result == 0) {
        cout << "\n\t\t\tGame Draw!\n";
    }
    else if (result == 1) {
        cout << "\n\t\t\tCongratulations! Player won the "
                "game!\n";
    }
    else {
        cout << "\n\t\t\tOh! Computer won the game!\n";
    }

    // showing both the moves
    cout << "\t\t\tYour Move: "; 
    showMove(playerMove);
    cout << "\t\t\tComputer's Move: ";
    showMove(computerMove);

    return 0;
}