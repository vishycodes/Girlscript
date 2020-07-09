/* **************************************************************************************************************************
Welcome to my TIC TAC TOE game in C++
The game operates as follows:
1. Player One gets asked whether they want to play with "X's" or "O's"
2. Player Two then automatically get assigned the other variable.
3. Player One and Two then take turns to fill in their variables in specific slots
4. Once a player reaches three X's or O's in a row / column or diagonally the game ends and a player is declared the winner
5. If no player wins after 9 moves we end the game.
******************************************************************************************************************************* */

#include <iostream>
#include <stdlib.h>

using namespace std;

char board_elements[3][3] = {{'1','2','3'}, {'4','5','6'} , {'7','8','9'}};

char marker_tracker; /* Variable to keep track of where the marker has been placed */
int player_checker;  /* Variable to alternate between players */
void game_board() /* Function to draw out the TIC TAC TOE board */
{
    cout<< " " << board_elements[0][0] << " | " << board_elements[0][1] << " | " << board_elements[0][2] << endl;
    cout<<"----------"<<endl;
    cout<< " " << board_elements[1][0] << " | " << board_elements[1][1] << " | " << board_elements[1][2] << endl;
    cout<<"----------"<<endl;
    cout<< " " << board_elements[2][0] << " | " << board_elements[2][1] << " | " << board_elements[2][2] << endl;


}

bool slot_marker(int marker) /*Function to marker the slot(from 1-9) where the user has inputted */
{
    /* if statements to give us particular row and column number */
    int row_number;
    int col_number;
    if(marker % 3 ==0)
    {
        row_number = (marker/3) - 1;
    }
    else
    {
        row_number = marker/3;
    }

    if(marker %3 ==0)
    {
        col_number = 2;
    }
    else
    {
        col_number = (marker%3)- 1;
    }

    if(board_elements[row_number][col_number] != 'X' && board_elements[row_number][col_number] != 'O')
    {
        board_elements[row_number][col_number] = marker_tracker ;
        return true;
    }
    else
    {
        return false;
    }






}


int check_winner() /* Function to checker which player won */
{
   int i;
   for(i=0;i<3;i++)
   {
       /*First for-loop checks the rows for a winner */
       if((board_elements[i][0] == board_elements[i][1]) && (board_elements[i][1] == board_elements[i][2]))
       {
           return player_checker;
       }

       /*Second for-loop checks the columns for a winner */
       if((board_elements[0][i] == board_elements[1][i]) && (board_elements[1][i] == board_elements[2][i]))
       {
           return player_checker;
       }




   }

   /* Checks Diagonals to see if we have a winner */

   if( board_elements[0][0] == board_elements[1][1] &&  board_elements[1][1] == board_elements[2][2])
       {
           return player_checker ;
       }
       else if((board_elements[0][2] == board_elements[1][1]) && (board_elements[1][1] == board_elements[2][0]))
       {
           return player_checker ;
       }

      return 0;
}

void swap_markers() /*Function to swap between X's and O's */
{
    if(marker_tracker == 'X')
    {
        marker_tracker = 'O';
    }
    else
    {
        marker_tracker = 'X';
    }
}

void swap_players() /* Function to swap between Player 1 and Player Two */
{
    if(player_checker == 1)
    {
        player_checker = 2;
    }
    else
    {
        player_checker = 1;
    }

}

void game_play() /* Function to Play the Game - then call inside the main function */
{
    /* Allows player 1 to choose whether they want an 'X' or a 'O' */
    cout << "Player 1 , Choose whether you want an 'X' or 'O':" <<endl;
    char player1_marker;
    cin >> player1_marker;

    player_checker = 1;
    marker_tracker = player1_marker;


    game_board();
    int game_winner;

    int i;
    for(i = 0 ; i < 9 ; i++)
    {
        cout << "Player " << player_checker << " its your turn, Please enter a slot: ";
        /* User input to enter specific slot */
        int slot;
        cin >> slot;

        if(slot < 1 || slot > 9) /* Print Error Message if number entered is not between 1 and 9 */
        {
            cout <<"Player " <<player_checker << " -- Please Enter a slot within 1-9"<<endl;
            i--; /* To not skip player;s turn if they enter an occupied slot */
            continue;
        }
        if(!slot_marker(slot))
        {
            cout << "Invalid Slot -- Try Again"<<endl;
            i--;
            continue;
        }
        game_board();

        game_winner = check_winner();

        if(game_winner == 1)
        {
            cout << "Player One is the Winner! Congragulations!"<<endl;
            break;
        }
        else if(game_winner == 2)
        {
            cout << "Player Two is the Winner! Congragulations!"<<endl;
            break;
        }

        swap_players();
        swap_markers();



    }

    if(game_winner == 0) /* If game does not end after 9 moves then the game is a tie */
    {
        cout << "We have a tie!, You two can sure play!";
    }

}
int main()
{
    game_play();
}
