//two - rock paper scissor

//input.txt

//output: score following the strategy guide

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//A X rock 1
//B Y paper 2
//C Z Scissor 3
//0 loss, 3 draw, 6 win

void countScore(){
    int score = 0;
    string play;

    ifstream MyReadFile("input.txt");

    while(getline (MyReadFile, play)){
        if(play[0] == 'A'){//rock
            if(play[2] == 'X'){//rock
                score += 4;
            }
            else if(play[2] == 'Y'){//paper
                score += 8;
            }
            else if(play[2] == 'Z'){//scissor
                score += 3;
            }
        }
        else if(play[0] == 'B'){//paper
            if(play[2] == 'X'){//rock
                score += 1;
            }
            else if(play[2] == 'Y'){//paper
                score += 5;
            }
            else if(play[2] == 'Z'){//scissor
                score += 9;
            }
        }
        else if(play[0] == 'C'){//scissor
            if(play[2] == 'X'){//rock
                score += 7;
            }
            else if(play[2] == 'Y'){//paper
                score += 2;
            }
            else if(play[2] == 'Z'){//scissor
                score += 6;
            }
        }
    }

    cout << score << endl;
}
//A X rock 1
//B Y paper 2
//C Z Scissor 3
//0 loss, 3 draw, 6 win
void countScore2(){
    int score = 0;
    string play;

    ifstream MyReadFile("input.txt");

    while(getline (MyReadFile, play)){
        if(play[0] == 'A'){//rock
            if(play[2] == 'X'){//lose: scissor
                score += 3;
            }
            else if(play[2] == 'Y'){//draw: rock
                score += 4;
            }
            else if(play[2] == 'Z'){//win: paper
                score += 8;
            }
        }
        else if(play[0] == 'B'){//paper
            if(play[2] == 'X'){//lose: rock
                score += 1;
            }
            else if(play[2] == 'Y'){//draw:paper
                score += 5;
            }
            else if(play[2] == 'Z'){//win: scissor
                score += 9;
            }
        }
        else if(play[0] == 'C'){//scissor
            if(play[2] == 'X'){//lose: paper
                score += 2;
            }
            else if(play[2] == 'Y'){//draw: scissor
                score += 6;
            }
            else if(play[2] == 'Z'){//win: rock
                score += 7;
            }
        }
    }

    cout << score << endl;
}

int main(){
    countScore2();
}