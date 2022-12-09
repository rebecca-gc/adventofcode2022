//eight - treetop tree house
//g++ -std=c++17 -Wall -pedantic -O3 day8.cpp -o eight

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

bool visible(string& wood, int& r, int& c, int& rows, int& columns){
    //left
    int tallesttree = wood[r * columns];
    for(int i = 0; i < c; ++i) if(wood[r * columns + i] > tallesttree) tallesttree = wood[r * columns + i];
    if(wood[r * columns + c] > tallesttree) return true;
    //right
    tallesttree = wood[r * columns + columns -1];
    for(int i = columns -1; i > c; --i) if(wood[r * columns + i] > tallesttree) tallesttree = wood[r * columns + i];
    if(wood[r * columns + c] > tallesttree) return true;
    //over
    tallesttree = wood[c];
    for(int i = 0; i < r; ++i) if(wood[i * columns + c] > tallesttree) tallesttree = wood[i * columns + c];
    if(wood[r * columns + c] > tallesttree) return true;
    //under
    tallesttree = wood[(rows -1) * columns + c];
    for(int i = rows -1; i > r; --i) if(wood[i * columns + c] > tallesttree) tallesttree = wood[i * columns + c];
    if(wood[r * columns + c] > tallesttree) return true;

    return false;
}

int score(string& wood, int& r, int& c, int& rows, int& columns){
    int score1 = 1, score2 = 1, score3 = 1, score4 = 1;
    //left
    int i = c-1;
    while(wood[r * columns + i] < wood[r * columns + c] && i > 0){
        --i;
        ++score1;
    }
    //right
    i = c+1;
    while(wood[r * columns + i] < wood[r * columns + c] && i < columns -1){
        ++i;
        ++score2;
    }
    //over
    i = r-1;
    while(wood[i * columns + c] < wood[r * columns + c] && i > 0){
        --i;
        ++score3;
    }
    //under
    i = r+1;
    while(wood[i * columns + c] < wood[r * columns + c] && i < rows -1){
        ++i;
        ++score4;
    }

    return score1 * score2 * score3 * score4;
}

void part1(){
    string line, wood;
    int columns, rows = 0;

    ifstream MyReadFile("input8.txt");

    while(getline (MyReadFile, line)){
        columns = line.size();
        wood += line;
        ++rows;
    }

    int vis = 2 * rows + 2 * (columns -2);
    for(int c = 1; c < columns -1; ++c) for(int r = 1; r < rows -1; ++r) if(visible(wood,r,c,rows,columns)) ++vis;

    cout << vis << endl;
}

void part2(){
    string line, wood;
    int columns, rows = 0, bestscore = 0;
    
    ifstream MyReadFile("input8.txt");

    while(getline (MyReadFile, line)){
        columns = line.size();
        wood += line;
        ++rows;
    }

    for(int c = 1; c < columns -1; ++c) for(int r = 1; r < rows -1; ++r) if(score(wood,r,c,rows,columns) > bestscore) bestscore = score(wood,r,c,rows,columns);

    cout << bestscore << endl;
}

int main(){
    part1();
    part2();
}
