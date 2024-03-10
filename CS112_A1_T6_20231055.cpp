/*
Program: Two squares game: This game is played on a board of 4 x 4 squares. Two players take turns;
    each of them takes turn to place a rectangle (that covers two squares) on the board,
    covering any 2 squares. Only one rectangle can be on a square. A square cannot be covered
    twice. The last player who can place a card on the board is the winner.
Author: Ruth Gad Labeb Gerges
ID: 20231055
Version: 1.0
Date: 28/2/2024
 */

#include <bits/stdc++.h> // library that contains all other libraries
using namespace std; 

bool check_digit (string choice); // prototype of function that check if the input is a number
bool check_list (string choice, int numbers[][4]); // prototype of function that check if the input in the board
bool check_rectangle (string choice1, string choice2, int numbers[][4]); // prototype of function that check the two numbers are beside each other
bool check_winner (int numbers[][4]); // prototype of function to check the winner
void print_board (int numbers[][4]); // prototype of function that print the board

int main(){
    string player1_choice1, player1_choice2, player2_choice1, player2_choice2; // declare variables
    int numbers[][4] = { // set the numbers of the board
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    cout << "Welcome to Two squares game" << endl; // print welcome message
    for (int i = 0; i < 4; i++){  // print the board
        for (int j = 0; j < 4; j++){ 
            cout << "|" << setw(4) << setfill('_') << numbers[i][j];
        }     
        cout << "|" << endl; 
    }

    while (true){ // start the game
        // player 1's turn
        cout << "Player 1: Place your first square "<< endl; 
        cin >> player1_choice1; // take first square as input from player 1
        // check if the first input is valid
        while (check_digit(player1_choice1) == false || check_list(player1_choice1,numbers) == false || stoi(player1_choice1) == 0){ 
            cout << "Player 1: Please enter a valid number for your first choice " << endl;
            cin >> player1_choice1;
        }
        cout <<"Player 1: Place your second square "<< endl;
        cin >> player1_choice2; // take second square as input from player 1
        // check if the second input is valid
        while (check_digit(player1_choice2) == false || check_list(player1_choice2,numbers) == false || stoi(player1_choice2) == 0){ 
            cout << "Player 1: Please enter a valid number for your second choice " << endl;
            cin >> player1_choice2;
        }
        // check if two numbers beside each other
        // if two numbers not beside each other, take another two inputs and check that numbers are valid or not
        while (check_rectangle(player1_choice1, player1_choice2,numbers) == false){
            cout << "Player 1: Please place rectangle that covers two available squares " << endl;
            cout << "Player 1: Place your first square "<< endl;
            cin >> player1_choice1;
            while (check_digit(player1_choice1) == false || check_list(player1_choice1,numbers) == false || stoi(player1_choice1) == 0){ 
                cout << "Player 1: Please enter a valid number for your first choice " << endl;
                cin >> player1_choice1;
            }
            cout << "Player 1: Place your second square " << endl;
            cin >> player1_choice2;
            while (check_digit(player1_choice2) == false || check_list(player1_choice2,numbers) == false || stoi(player1_choice2) == 0){ 
                cout << "Player 1: Please enter a valid number for your second choice " << endl;
                cin >> player1_choice2;
            }
        }
        // loop start from the beginning of the board to the end and set the choices of player1 to 0
        for (int i = 0; i < 4; i++){ 
            for (int j = 0; j < 4; j++){ 
                if(numbers[i][j] == stoi(player1_choice1)){
                    numbers[i][j] = 0;
                }
                else if(numbers[i][j] == stoi(player1_choice2)){
                    numbers[i][j] = 0;
                }
            }     
        }
        // check if player 1 wins, print the final board and end game
        if(check_winner(numbers)){
            cout << "Player 1: "<< player1_choice1<< ", " << player1_choice2 << endl;
            print_board(numbers);
            cout << "Player 1 is winner" << endl;
            break;
        }
        // if the player 1 doesn't win, print the board and continue the game
        else{
            cout << "Player 1: " << player1_choice1 << ", " << player1_choice2 << endl;
            print_board(numbers);
        }
        // player 2's turn
        cout << "Player 2: Place your first square " << endl;
        cin >> player2_choice1; // take first square as input from player 2
        // check if the first input is valid
        while (check_digit(player2_choice1) == false || check_list(player2_choice1,numbers) == false || stoi(player2_choice1) == 0){ 
            cout << "Player 2: Please enter a valid number for your first choice ";
            cin >> player2_choice1;
        }
        cout << "Player 2: Place your second square " << endl;
        cin >> player2_choice2; // take second square as input from player 2
        // check if the second input is valid
        while (check_digit(player2_choice2) == false || check_list(player2_choice2,numbers) == false || stoi(player2_choice2) == 0){ 
            cout << "Player2: Please enter a valid number for your second choice ";
            cin >> player2_choice2;
        }
        // check if two numbers beside each other
        // if two numbers not beside each other, take another two inputs and check that numbers are valid or not
        while (check_rectangle(player2_choice1, player2_choice2, numbers) == false){
            cout << "Player 2: Please place a rectangle that covers two available squares " << endl;
            cout << "Player 2: Place your first square " << endl;
            cin >> player2_choice1;
            while (check_digit(player2_choice1) == false || check_list(player2_choice1,numbers) == false || stoi(player2_choice1)==0){ 
                cout << "Player 2: Please enter a valid number for your first choice "<<endl;
                cin >> player2_choice1;
            }
            cout << "Player 2: Place your second square " << endl;
            cin >> player2_choice2;
            while (check_digit(player2_choice2) == false || check_list(player2_choice2,numbers) == false || stoi(player2_choice2) == 0){ 
                cout << "Player2: Please enter a valid number for your second choice " << endl;
                cin >> player2_choice2;
            }
        }
        // loop start from the beginning of the board to the end and set the choices of player2 to 0
        for (int i = 0; i < 4; i++){ 
            for (int j = 0; j < 4; j++){ 
                if(numbers[i][j] == stoi(player2_choice1)){
                    numbers[i][j] = 0;
                }
                else if(numbers[i][j] == stoi(player2_choice2)){
                    numbers[i][j] = 0;
                }
            }     
        }
        // check if player 2 wins, print the final board and end game
        if(check_winner(numbers)){
            cout << "Player 2: " << player2_choice1 << ", " << player2_choice2 << endl;
            print_board(numbers);
            cout << "Player 2 is winner" << endl;
            break;
        }
        // if the player 2 doesn't win, print the board and continue the game
        else{
            cout << "Player 2: " << player2_choice1 << ", " << player2_choice2 << endl;
            print_board(numbers);
        }
    }
    return 0;
}
bool check_digit(string choice){ // function that take the choice of the player to check if it is a number
    for(int i = 0; i < choice.length(); i++){ // loop start from the beginning of the input to the end
        if (isdigit(choice[i]) == false){
            return false;  // return false if it isn't a number
        }
    }
    return true; // return true if it is a number
}
bool check_list(string choice, int numbers[][4]){  // function that take the choice of the player and the board to check if the choice in the board or not
    for(int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            if(numbers[i][j] == stoi(choice)){
                return true; // return true if it find the choice in the board
            }
        }
    }
    return false; // return false if the number not in the board
}
bool check_rectangle(string choice1, string choice2, int numbers[][4]){ // function that take first choice and second choice and the board
    for(int i = 0; i < 4; i++){                                         // to check if ther are beside each other
        for (int j = 0; j < 4; j++){
            if(j == 0 && numbers[i][j] == stoi(choice1) && stoi(choice2) == stoi(choice1)-1){ // if the first choice in the first column 
                return false;                                                           // the player can't take the previous square as second choice 
            }
            else if(j == 3 && numbers[i][j] == stoi(choice1) && stoi(choice2) == stoi(choice1)+1){ // if the first choice in the last column
                return false;                                                                // the player can't take the next square as second choice
            }
            else if((numbers[i][j] == stoi(choice1) && numbers[i][j+1] == stoi(choice2)) || (numbers[i][j] == stoi(choice1) && numbers[i+1][j] == stoi(choice2)) 
            || (numbers[i][j] == stoi(choice1) && numbers[i][j-1] == stoi(choice2)) || (numbers[i][j] == stoi(choice1) && numbers[i-1][j] == stoi(choice2))){

                return true;
            }
        }
    }
    return false;
}
bool check_winner(int numbers[][4]){ // function that take the board to check if the player win
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (numbers[i][j] != 0) {
                if ((j < 3 && numbers[i][j+1] != 0) || (i < 3 && numbers[i+1][j] != 0)){ // if there two squares beside each other return false to continue the game
                    return false; 
                }
            }
        }
    }
    return true; // return true if the player covers last two squares beside each other
}

void print_board(int numbers[][4]){ // function that take the board and print it
    for (int i = 0; i < 4; i++){ 
        for (int j = 0; j < 4; j++){ 
            if(numbers[i][j] == 0){ // if the number = 0 that mean that the player choose that number and print "X" instead
                cout << "|" << setw(4) << setfill('_') << "X"; 
            }
            else{
                cout << "|" << setw(4) << setfill('_') << numbers[i][j];
            }
        }     
        cout << "|" << endl; 
    }
}