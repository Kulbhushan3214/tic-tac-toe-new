#include <iostream>
#include <vector>

using namespace std;

void displayBoard(const vector<char>& board){
    cout<<"----"<<endl;
    for(int i=0; i<9; i=i+3){
        cout<<"|"<< board[i] <<" | "<<board[i+1] <<" | "<<board[i+2]<<" | "<<endl;
        cout<<"----"<<endl;
    }
}

bool checkWin(const vector<char>& board, char player){
    for(int i=0; i<9; i=i+3){
        if(board[i] == player && board[i+1] == player && board[i+2]== player){
            return true;
        }
    }


    for (int i=0; i<3; i++){
        if(board[i]==player && board[i+3] == player && board[i+6] == player){
            return true;
        }
    }

    if(board[0] == player && board[4] == player && board[8] == player){
        return true;
    }
    if(board[2] == player && board[4] == player && board[6] == player){
        return true;
    }

    return false;
}

int main(){
    vector<char> board(9, ' ');
    char currentPlayer = 'X';
    int moves = 0;

    while (true){
        displayBoard(board);
        cout<<"Player "<<currentPlayer << "'s turn. Enetr position from 1 to 9: ";

        int position;
        cin>>position;

        if(position <1 || position >9 || board[position - 1] != ' '){
            cout<< " Inavalid Move. Try again."<<endl;
            continue;
        }

        board[position - 1] = currentPlayer;
        moves++;

        if(checkWin(board, currentPlayer)){
            displayBoard(board);
            cout<<"Player "<<currentPlayer<< " wins!" << endl;
            break;
        }
        if (moves == 9){
            displayBoard(board);
            cout<<"It's a tie"<<endl;
            break;
        }

        if(currentPlayer =='X'){
            currentPlayer = '0';
        }else{
            currentPlayer = 'X';
        }
    }
    return 0;
}