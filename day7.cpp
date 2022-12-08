//seven - directories

//seveninput.txt

//output: size of all directories with size at most 1000000

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

void dirsize(){
    string command, commands;

    ifstream MyReadFile("input7.txt");
    while(getline (MyReadFile, command)){
        commands += command;
    }

    int allsizes = 0, currentdir = 0, pos = 0;
    int print = 0;

    while(pos < commands.size()){
        if(commands[pos] == '$'){
            if(commands[pos+2] == 'l' && commands[pos+3] == 's'){
                pos += 4;
            }
            else{ //c
                if(commands[pos+5] == '.'){ //cd ..
                    pos += 7;
                }
                //cd x
                pos += 5;
            }
        }
        else if(commands[pos] == 'd'){
            pos += 4;
        }
        else{
            int stelle = 0;
            currentdir = 0;
            for(unsigned i = pos; i < commands.size(); ++i){
                if(commands[i] -48 >= 0 && commands[i] -48 <= 9){
                    ++stelle;
                }
                else{
                    //if(print) cout << "broke at " << pos << endl;
                    break;
                }
            }
            if(stelle != 0){
                currentdir = stoi(commands.substr(pos,stelle));

                // if(print < 5){
                //     cout << pos << " " << currentdir << endl;
                //     ++print;
                // }
                
                if(currentdir <= 100000) allsizes += currentdir;

                pos += stelle;

            }
            else ++pos;
        }
        //cout << pos << endl;
    }

    //cout << commands.size() << endl;
    cout << allsizes << endl;
}

void recurse(int pos, string commands){
    int currentdir = 0, allsizes = 0, tmp = 0;
    int insidedir = 0;
    while(pos < commands.size()){
        if(commands[pos] == '$'){
            if(commands[pos+2] == 'l'){
                pos += 4;
                //hier jetzt berechnen
            }
            else{ //c
                if(commands[pos+5] == '.'){ //cd ..
                    pos += 7;
                    if(currentdir <= 100000) allsizes += currentdir;
                    --insidedir;
                }
                //cd x
                ++insidedir;
                pos += 5;
            }
        }
    }
}

int berechnung(int& pos, string& commands){
    int stelle = 0;
    int currentdir = 0;
    while(commands[pos] != '$'){
        for(unsigned i = pos; i < commands.size(); ++i){
            if(commands[i] -48 >= 0 && commands[i] -48 <= 9){
                ++stelle;
            }
            else{
                //if(print) cout << "broke at " << pos << endl;
                break;
            }
        }
        if(stelle != 0){
            currentdir += stoi(commands.substr(pos,stelle));

            // if(print < 5){
            //     cout << pos << " " << currentdir << endl;
            //     ++print;
            // }

            pos += stelle;
        }
    }
}

void bennisidee(){
    string command;
    vector<vector<int>> knoten;
    int pos = 0;
    int tiefe = 0;

    ifstream MyReadFile("input7.txt");
    while(getline (MyReadFile, command)){
        if(command[0] == '$' && command[2] == 'c' && command[5] != '.'){
            knoten[pos][0] = tiefe;
        }
    }
}

int main(){
    dirsize();
}

//3889922 too high