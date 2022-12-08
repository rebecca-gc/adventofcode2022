//five - supply stacks
//g++ -std=c++17 -Wall -pedantic -O3 five.cpp -o five

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void part1(){
    string moves;
    bool moving = false;
    int amount, from, to;
    vector<string> cargo (9);

    ifstream MyReadFile("fiveinput.txt");

    while(getline (MyReadFile, moves)){
        if(moves[1] == '1'|| moves == "") moving = true;
        else if(!moving){
            int j = 0;
            for(unsigned i = 1; i <= 33; i+=4){
                if(moves[i] != ' ') cargo[j] += moves[i];
                ++j;
            }
        }
        else{
            if(moves[6] == ' '){
                amount = (moves[5]-48);
                from = (moves[12]-48) -1;
                to = (moves[17]-48) -1;
            }
            else{
                amount = (moves[5]-48)*10 + (moves[6]-48);
                from = (moves[13]-48) -1;
                to = (moves[18]-48) -1;
            }
            for(int i = 0; i < amount; ++i){
                cargo[to] = cargo[from][0] + cargo[to];
                cargo[from] = cargo[from].substr(1, cargo[from].size()-1);
            }
        }
    }

    for(unsigned i = 0; i < cargo.size(); ++i){
        cout << cargo[i][0];
    }
    cout << endl;
}

void part2(){
    string moves;
    bool moving = false;
    int amount, from, to;
    vector<string> cargo (9);

    ifstream MyReadFile("fiveinput.txt");

    while(getline (MyReadFile, moves)){
        if(moves[1] == '1'|| moves == "") moving = true;
        else if(!moving){
            int j = 0;
            for(unsigned i = 1; i <= 33; i+=4){
                if(moves[i] != ' ') cargo[j] += moves[i];
                ++j;
            }
        }
        else{
            if(moves[6] == ' '){
                amount = (moves[5]-48);
                from = (moves[12]-48) -1;
                to = (moves[17]-48) -1;
            }
            else{
                amount = (moves[5]-48)*10 + (moves[6]-48);
                from = (moves[13]-48) -1;
                to = (moves[18]-48) -1;
            }
            cargo[to] = cargo[from].substr(0,amount) + cargo[to];
            cargo[from] = cargo[from].substr(amount, cargo[from].size()-1);
        }
    }

    for(unsigned i = 0; i < cargo.size(); ++i){
        cout << cargo[i][0];
    }
    cout << endl;
}

int main(){
    part1();
    part2();
}
