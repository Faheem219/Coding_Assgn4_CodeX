#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'},
                    {'4', '5', '6'},
                    {'7', '8', '9'}};
char cur_player;

void ShowBoard(){
    cout<<"--------\n";
    for(int i=0; i<3; i++){
        for(int j=0;j<3;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"--------\n";
}

void PlayerSwitch(){
    cur_player = (cur_player == 'X') ? 'O' : 'X';
}

bool WinCheck(){
    //For rows and columns:
    for(int i=0; i<3; i++){
        if((board[i][0]==board[i][1] && board[i][1]==board[i][2]) ||
        (board[0][i]==board[1][i] && board[1][i]==board[2][i])){
            return true;
        }
    }

    //For diagonals:
    if((board[0][0]==board[1][1] && board[1][1]==board[2][2]) ||
    (board[0][2]==board[1][1] && board[1][1]==board[2][0])){
        return true;
    }
    return false;
}

bool TieCheck(){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]!='X' && board[i][j]!='O'){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int choice;
    char mark;

    do{
        srand(time(0));
        cur_player=(rand()%2==0)?'X':'O';
        ShowBoard();
        cout<<"The turn is of player: "<<cur_player<<"\nSelect your move (1-9):";
        cin>>choice;

        if(choice<1||choice>9||board[(choice-1)/3][(choice-1)%3]=='X'||board[(choice-1)/3][(choice-1)%3]=='O'){
            cout<<"Incorrect move, try again.\n";
            continue;
        }

        mark=cur_player;
        board[(choice-1)/3][(choice-1)%3]=mark;

        if(WinCheck()){
            ShowBoard();
            cout<<"Congratulations Player "<<cur_player<<" you win!\n";
            break;
        }
        else if(TieCheck()){
            ShowBoard();
            cout<<"Its a tie!\n";
            break;
        }
        PlayerSwitch();
    }while(true);
    return 0;
}