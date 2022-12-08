//two - rock paper scissors
//g++ -std=c++17 -Wall -pedantic -O3 two.cpp -o two

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void part1(){
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
            else{//scissor
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
            else{//scissor
                score += 9;
            }
        }
        else{//scissor
            if(play[2] == 'X'){//rock
                score += 7;
            }
            else if(play[2] == 'Y'){//paper
                score += 2;
            }
            else{//scissor
                score += 6;
            }
        }
    }

    cout << score << endl;
}

void part2(){
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
            else{//win: paper
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
            else{//win: scissor
                score += 9;
            }
        }
        else{//scissor
            if(play[2] == 'X'){//lose: paper
                score += 2;
            }
            else if(play[2] == 'Y'){//draw: scissor
                score += 6;
            }
            else{//win: rock
                score += 7;
            }
        }
    }

    cout << score << endl;
}

int main(){
    part1();
    part2();
}
