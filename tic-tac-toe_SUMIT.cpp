#include <bits/stdc++.h>
using namespace std;

void print_board(char arr[3][3]){
    for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        cout<<arr[i][j]<<" ";
    }  
    cout<<endl; 
}
}


bool check_move(int row,int column,char arr[3][3]){
    if(arr[row][column]!='|'){
       return false;
    }
    return true;
}

void X_move(char arr[3][3],int row,int column){
    arr[row][column]='X';
    print_board(arr);
}

void O_move(char arr[3][3],int row,int column){
    arr[row][column]='O';
    print_board(arr);
}

bool h_win(char arr[3][3]){
    int count_X=0;
    int count_O=0;
    int row=0;
    while(row<3){
        for(int j=0;j<3;j++){
            if(arr[row][j]=='X'){
                count_X++;
            }else if(arr[row][j]=='O'){
                count_O++;
            }
        }
        if(count_O==3 || count_X==3){
            return true;
        }
        count_X=0;
        count_O=0;
        row++;
    }

    return false;
}

bool v_win(char arr[3][3]){
    int count_X=0;
    int count_O=0;
    int col=0;
    while(col<3){
        for(int j=0;j<3;j++){
            if(arr[j][col]=='X'){
                count_X++;
            }else if(arr[j][col]=='O'){
                count_O++;
            }
        }
        if(count_O==3 || count_X==3){
            return true;
        }
        count_O=0;
        count_X=0;
        col++;
    }

    return false;
}

bool diag_win(char arr[3][3]){
    int count_O=0;
    int count_X=0;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i==j){
                if(arr[i][j]=='X'){
                    count_X++;
                }else if(arr[i][j]=='O'){
                    count_O++;
                }
            }

        }
    }
    if(count_O==3 || count_X==3){
        return true;
    }
count_O=0;
count_X=0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(i+j==2){
                if(arr[i][j]=='X'){
                    count_X++;
                }else if(arr[i][j]=='O'){
                    count_O++;
                }
            }
        }
    }
    if(count_O==3 || count_X==3){
        return true;
    }

    
    return false;


}



int main()
{

while(true){

//creating the 3x3 tic tac toe board
char arr[3][3];
for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
        arr[i][j]='|';
    }
}

cout<<"INITIAL BOARD :"<<endl;
print_board(arr);

int x=9;



//running the game uptil 9 valid moves
while(x){

int p1=1;      //EACH PLAYER CAN DO ONE MOVE EACH TIME
int p2=1;

//player 1 chance
while(p1){ 
             cout<<"PLAYER 1 , ENTER YOUR MOVE: X OR O "<<endl;
             char s;
             cin>>s;
             int row;
             int column;
             cin>>row>>column;
    if(check_move(row,column,arr)){
        if(s=='X'){
          X_move(arr,row,column);
          x--;
          p1--;
        }
        else if(s=='O'){
        O_move(arr,row,column);
        x--;
        p1--;
        }
    }
    else{
        cout<<"POSITION IS ALREADY OCCUPIED  RE-ENTER A NEW POSITION:";
    }

//checks if any of the winning condition is satisfied upto current moves
   if(h_win(arr) || v_win(arr) || diag_win(arr)){
       cout<<"PLAYER 1 HAS WON"<<endl;
       break;                           //GETS OUT OF WHILE LOOP OF MOVES OF PLAYER 1 IF WON
    }


}
if(h_win(arr) || v_win(arr) || diag_win(arr)){  //CHECK AGAIN IF TRUE IT MEANS PLAYER HAS ALREADY WON GET OUT OF OUTER WHILE LOOP GAME ENDS
    break;
}

//breaks the game as 9th move is encountered by player 1 , after which the game ends in a draw or win 
if(x==0){
    break;
}


//player 2 chance
while(p2){
    cout<<"PLAYER 2 , ENTER YOUR MOVE: X OR O "<<endl;
    char t;
    cin>>t;
    int row2;
    int column2;
    cin>>row2>>column2;
if(check_move(row2,column2,arr)){
    if(t=='X'){
        X_move(arr,row2,column2);
        x--;
        p2--;
    }
    else if(t=='O'){
        O_move(arr,row2,column2);
        x--;
        p2--;
    }
}
else{
     cout<<"POSITION IS ALREADY OCCUPIED  RE-ENTER A NEW POSITION:"<<endl; 
}

//check if any of the winning condition is satisfied upto current moves
if(h_win(arr) || v_win(arr) || diag_win(arr)){  //IF ANYONE SATISFIED GET OUT OF MOVES WHILE LOOP
    cout<<"PLAYER 2 HAS WON"<<endl;
    break;  
    
  }

//END OF WHILE LOOP FOR MOVES OF PLAYER 2
}

//CHECK AGAIN IF ONE IS TRUE THAT MEANS ANY ONE PLAYER HAS ALREADY ONE GET OUT OF OUTER WHILE LOOP GAME ENDS
if(h_win(arr) || v_win(arr) || diag_win(arr)){
    break;
}
//end of the outer while loop which is after 9 moves resulting in a draw or win for one player
}

if(!(h_win(arr) || v_win(arr) || diag_win(arr))){
   cout<<"ITS A DRAW"<<endl;
}


char query;
cout<<"TYPE Y TO PLAY AGAIN OR N TO EXIT THE GAME:"<<endl;
cin>>query;
if(query=='Y'){
    continue;
}
else if(query=='N'){
    break;
}


}

}


///////             FINALLYY WE MADE IT
/////               CONGRATULATIONS SUMIT! KEEP UP THE HARD WORK!!!!