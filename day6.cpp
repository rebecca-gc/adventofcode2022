//six - tuning trouble
//g++ -std=c++17 -Wall -pedantic -O3 day6.cpp -o six

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void part1(){
    string sms;    
    char a, b, c, d;
    int pos = 4;

    ifstream MyReadFile("input6.txt");

    while(getline (MyReadFile, sms)){
        a = sms[0];
        b = sms[1];
        c = sms[2];
        d = sms[3];
        while(!(a!=b && a!=c && a!=d && b!=c && b!=c && b!=d && c!=d)){
            a = b;
            b = c;
            c = d;
            d = sms[pos];
            ++pos;
        }
    }

    cout << pos << endl;
}

bool alldifferent(vector<char>& currentmarker){
    for(unsigned i = 0; i < currentmarker.size(); ++i) for(unsigned j = 0; j < currentmarker.size(); ++j) if(i != j) if(currentmarker[i] == currentmarker[j]) return false;
    return true;
}

void part2(){
    string sms;    
    vector<char> currentmarker (14);
    int pos = 14;

    ifstream MyReadFile("input6.txt");

    while(getline (MyReadFile, sms)){
        for(unsigned i = 0; i < 14; ++i){
            currentmarker[i] = sms[i];
        }
        while(!alldifferent(currentmarker)){
            for(unsigned i = 0; i < currentmarker.size()-1; ++i) currentmarker[i] = currentmarker[i+1];
            currentmarker[13] = sms[pos];
            ++pos;
        }
    }

    cout << pos << endl;
}

int main(){
    part1();
    part2();
}