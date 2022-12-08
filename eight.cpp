//seven - directories

//seveninput.txt

//output: size of all directories with size at most 1000000

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

bool visible(string& wald, int& r, int& c, int& rows, int& columns){
    bool sichtbar;
    //links
    int biggestbaum = wald[r * columns] -47;
    //cout << "init " << biggestbaum << endl;
    for(int i = 0; i < c; ++i){
        //cout << "test " << wald[r * columns + i] -47 << endl;
        if(wald[r * columns + i] -47 > biggestbaum){
            biggestbaum = wald[r * columns + i] -47;
        }
    }
    //cout << biggestbaum << endl;
    if(wald[r * columns + c] -47 <= biggestbaum) sichtbar = false;
    else {
        //cout << r <<" " << c << " " << wald[r * columns + c] << " sichtbar von links" << endl;
        return true;
    };
    //rechts
    biggestbaum = wald[r * columns + columns -1] -47;
    //cout << "init " << biggestbaum << endl;
    for(int i = columns -1; i > c; --i){
        if(wald[r * columns + i] -47 > biggestbaum){
            biggestbaum = wald[r * columns + i] -47;
        }
    }
    //cout << biggestbaum << endl;
    if(wald[r * columns + c]-47 <= biggestbaum) sichtbar = false;
    else {
        //cout << r <<" " << c << " " << wald[r * columns + c] << " sichtbar von rechts" << endl;
        return true;
    };
    //oben
    biggestbaum = wald[c]-47;
    //cout << "init " << biggestbaum << endl;
    for(int i = 0; i < r; ++i){
        if(wald[i * columns + c]-47 > biggestbaum){
            biggestbaum = wald[i * columns + c]-47;
        }
    }
    //cout << biggestbaum << endl;
    if(wald[r * columns + c]-47 <= biggestbaum) sichtbar = false;
    else {
        //cout << r <<" " << c << " " << wald[r * columns + c] << " sichtbar von oben" << endl;
        return true;
    };
    //unten
    biggestbaum = wald[(rows-1) * columns + c]-47;
    //cout << "init " << biggestbaum << endl;
    for(int i = rows-1; i > r; --i){
        if(wald[i * columns + c]-47 > biggestbaum){
            biggestbaum = wald[i * columns + c]-47;
        }
    }
    //cout << biggestbaum << endl;
    if(wald[r * columns + c] -47<= biggestbaum) sichtbar = false;
    else {
        //cout << r <<" " << c << " " << wald[r * columns + c] << " sichtbar von unten" << endl;
        return true;
    };

    return sichtbar;
}

int score(string& wald, int& r, int& c, int& rows, int& columns){
    int score1 = 1, score2 = 1, score3 = 1, score4 = 1;
    //links
    int i = c-1;
    while(wald[r * columns + i] -47 < wald[r * columns + c] -47 && i > 0){
        --i;
        ++score1;
    }
    //rechts
    i = c+1;
    while(wald[r * columns + i] -47 < wald[r * columns + c] -47 && i < columns-1){
        ++i;
        ++score2;
    }
    //oben
    i = r-1;
    while(wald[i * columns + c] -47 < wald[r * columns + c] -47 && i > 0){
        --i;
        ++score3;
    }
    //unten
    i = r+1;
    while(wald[i * columns + c] -47 < wald[r * columns + c] -47 && i < rows-1){
        ++i;
        ++score4;
    }

    cout << r << " " << c << " score: " << score1 << " " << score2 << " " << score3 << " " << score4 << endl;

    return score1 * score2 * score3 * score4;
}

void eight(){
    string line;
    int columns;
    string wald;
    int sichtbar;
    int rows = 0;

    ifstream MyReadFile("eightinput.txt");
    while(getline (MyReadFile, line)){
        columns = line.size();
        wald += line;
        ++rows;
    }

    // wald = "3037325512653323354935390";
    // columns = 5;
    // rows = 5;

    //r * columns + c

    sichtbar = 2 * rows + 2 * (columns-2);

    cout << sichtbar << endl; // stimmt

    for(int c = 1; c < columns-1; ++c){
        for(int r = 1; r < rows-1; ++r){
            if(visible(wald,r,c,rows,columns)) ++sichtbar;
        }
    }

    cout << sichtbar << endl;
}

void scenicscore(){
    string line;
    string wald;
    int columns;
    int rows = 0;
    int bestscore = 0;
    
    ifstream MyReadFile("eightinput.txt");
    while(getline (MyReadFile, line)){
        columns = line.size();
        wald += line;
        ++rows;
    }

    // wald = "3037325512653323354935390";
    // columns = 5;
    // rows = 5;

    for(int c = 1; c < columns-1; ++c){
        for(int r = 1; r < rows-1; ++r){
            if(score(wald,r,c,rows,columns) > bestscore) bestscore = score(wald,r,c,rows,columns);
        }
    }

    cout << bestscore << endl;
}



int main(){
    scenicscore();
}

//9996,7729 too high