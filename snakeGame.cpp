#include<iostream>
#include<conio.h>
#include<cstdlib>
#include <bits/stdc++.h>
using namespace std;

int BOARD[22][22] = {0};
int SNAKE_X=10, SNAKE_Y=10;
int FOOD_X=15, FOOD_Y=15;
int SCORE=0, SCORE_FACTOR=1;
char MOVEMENT='s';
string NAME;
queue<pair<int, int>> Q;

void getNameAndInstruction(){
    system("cls");
    cout << "NOTE ---->>>> Press s to forward, a to backward, w to upward, z to downward " << endl;
    cout << "Enter your name : ";
    cin >> NAME;
}

void increaseLength(){
    if((SCORE_FACTOR==1)&&(SNAKE_X==0 || SNAKE_X==21 || SNAKE_Y==0 || SNAKE_Y==21)){
        if(SNAKE_X==0) SNAKE_X=20;
        if(SNAKE_X==21) SNAKE_X=1;
        if(SNAKE_Y==0) SNAKE_Y=20;
        if(SNAKE_Y==21) SNAKE_Y=1;
    }
    BOARD[SNAKE_Y][SNAKE_X] = 1;
    
    Q.push(pair<int, int>(SNAKE_Y, SNAKE_X));
    // BOARD[Q.front().second][Q.front().first]=0;
    if(!Q.empty() && !(SNAKE_X==FOOD_X && SNAKE_Y==FOOD_Y)){
        BOARD[Q.front().first][Q.front().second]=0;
        // cout << "hello " << Q.size() << " " << Q.front().second << " " << Q.front().first<<endl;
        Q.pop();
    }
}

void showResult(){
    cout << "<<<<<<<<<<<<<<GAME OVER>>>>>>>>>>>>>>>"<< endl;
    cout << "Dear " << NAME <<  ", Your score -> " << SCORE;
    exit(1);
}

void randomFoodGenerator(){
    FOOD_X = (rand() % 21);
    if(FOOD_X == 0) FOOD_X=1;
    FOOD_Y = (rand() % 21);
    if(FOOD_Y == 0) FOOD_Y=1;
}


void printBoard(){
    if(BOARD[SNAKE_Y][SNAKE_X] == 1){
        showResult();
    } else{
        increaseLength();
    }
    if(FOOD_X==SNAKE_X && FOOD_Y==SNAKE_Y){
        randomFoodGenerator();
        SCORE+=SCORE_FACTOR;
    }
    
    
    for(int i=0; i<22; i++){
        for(int j=0; j<22; j++){
            if(i==0 || j==0 || i==21 || j==21){
                cout << " * ";
            }else{
                if(SNAKE_X==j && SNAKE_Y==i){
                    cout << " O ";
                }else if(FOOD_X==j && FOOD_Y==i){
                    cout << " # ";
                }else if(BOARD[i][j]==1){
                    cout << " o ";
                }else{
                    cout << "   ";
                }
            }
        }
        cout << endl ;
    }
    // cout << SCORE_FACTOR;
}

void applyBoundaryValidation(){
    for(int i=0; i<22; i++){
        BOARD[i][0] = 1;
        BOARD[0][i] = 1;
        BOARD[i][21] = 1;
        BOARD[21][i] = 1;
    }
}

void getInput(){
    if(kbhit()){
        char ch = _getch();
        if(ch == 'w' || ch == 'a' || ch == 's' || ch == 'z'){
            if((MOVEMENT == 'w' && ch != 'z')
             || (MOVEMENT == 's' && ch != 'a')
              || (MOVEMENT == 'z' && ch != 'w')
               || (MOVEMENT == 'a' && ch != 's')){
                    MOVEMENT = ch;
               }
        }
    }
    cout << "Your score: " << SCORE << endl;
    switch (MOVEMENT)
    {
    case 'w':
        SNAKE_Y--;
        break;
    case 's':
        SNAKE_X++;
        break;
    case 'z':
        SNAKE_Y++;
        break;
    case 'a':
        SNAKE_X--;
        break;
    default:
        break;
    }
}

void level1(){
    while(SCORE<2){
        system("cls");
        getInput();
        printBoard();
        // cin >> MOVEMENT;
        _sleep(1000-SCORE);
    }
    cout << "Entering Level 2";
    _sleep(2000);
}

void level2(){
    SCORE_FACTOR=10;
    applyBoundaryValidation();
    while(SCORE<20){
        system("cls");
        getInput();
        printBoard();
        // cin >> MOVEMENT;
        _sleep(1000-SCORE);
    }
    cout << "Entering Level 3";
    _sleep(2000);
}

void level3(){
    SCORE_FACTOR=20;
    while(1){
        system("cls");
        getInput();
        printBoard();
        // cin >> MOVEMENT;
        _sleep(1000-SCORE);
    }
}

int main(){
    getNameAndInstruction();
    Q.push(pair<int, int>(SNAKE_Y, SNAKE_X));
    level1();
    level2();
    level3();
}