//nine - rope bridge
//g++ -std=c++17 -Wall -pedantic -O3 day9.cpp -o nine

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <vector>

using namespace std;

bool stop = false;

pair<int,int> movetail(int r_head, int c_head, int r_tail, int c_tail){
    if(abs(r_head - r_tail) > 1 || abs(c_head - c_tail) > 1){
        if(r_head - r_tail == -2){
            if(c_head - c_tail == 2) return {-1,1};
            else if(c_head - c_tail == 1) return {-1,1};
            else if(c_head - c_tail == 0) return {-1,0};
            else if(c_head - c_tail == -1) return {-1,-1};
            else if(c_head - c_tail == -2) return {-1,-1};
            else{
                cout << "error1" << endl;
                stop = true;
                return {0,0};
            }
        }
        else if(r_head - r_tail == 2){
            if(c_head - c_tail == 2) return {1,1};
            else if(c_head - c_tail == 1) return {1,1};
            else if(c_head - c_tail == 0) return {1,0};
            else if(c_head - c_tail == -1) return {1,-1};
            else if(c_head - c_tail == -2) return {1,-1};
            else{
                cout << "error2" << endl;
                stop = true;
                return {0,0};
            }
        }
        else if(c_head - c_tail == 2){
            if(r_head - r_tail == 2) return {1,1};
            else if(r_head - r_tail == 1) return {1,1};
            else if(r_head - r_tail == 0) return {0,1};
            else if(r_head - r_tail == -1) return {-1,1};
            else if(r_head - r_tail == -2) return {-1,1};
            else{
                cout << "error3" << endl;
                stop = true;
                return {0,0};
            }
        }
        else if(c_head - c_tail == -2){
            if(r_head - r_tail == 2) return {1,-1};
            else if(r_head - r_tail == 1) return {1,-1};
            else if(r_head - r_tail == 0) return {0,-1};
            else if(r_head - r_tail == -1) return {-1,-1};
            else if(r_head - r_tail == -2) return {-1,-1};
            else{
                cout << "error4" << endl;
                stop = true;
                return {0,0};
            }
        }
        else{
            cout << "error9" << endl;
            stop = true;
            return {0,0};
        }
    }
    else return {0,0};
}

void part1(){
    string move;
    int amount;
    int r_head = 0, c_head = 0, r_tail = 0, c_tail = 0;
    vector<pair<int,int>> posvis;
    posvis.push_back({r_tail,c_tail});

    ifstream MyReadFile("input9.txt");

    while(getline (MyReadFile, move)){
        if(move.size() == 4){
            amount = (move[2]-48) *10 + move[3]-48;
        }
        else amount = move[2]-48;
        //cout << "amount " << amount << endl;
        for(int i = 0; i < amount; ++i){
            if(move[0] == 'U') ++r_head;
            else if(move[0] == 'D') --r_head;
            else if(move[0] == 'L') --c_head;
            else if(move[0] == 'R') ++c_head;
            int tmpr = movetail(r_head,c_head,r_tail,c_tail).first;
            int tmpc = movetail(r_head,c_head,r_tail,c_tail).second;
            r_tail += tmpr;
            c_tail += tmpc;
            posvis.push_back({r_tail,c_tail});
        }
    }

    vector<pair<int,int>> alreadyvisited;
    bool add = true;

    for(unsigned i = 0; i < posvis.size(); i++){
        for(unsigned j = 0; j < alreadyvisited.size(); j++){
            if(posvis[i] == alreadyvisited[j]){
                add = false;
                break;
            }
        }
        if(add) alreadyvisited.push_back(posvis[i]);
        else add = true;
    }

    cout << alreadyvisited.size() << endl;
}

void part2(){
   string move;
    int amount;
    int r_head = 0, c_head = 0, r_tail = 0, c_tail = 0, r1 = 0, c1 = 0, r2 = 0, c2 = 0, r3 = 0, c3 = 0, r4 = 0, c4 = 0, r5 = 0, c5 = 0, r6 = 0, c6 = 0, r7 = 0, c7 = 0, r8 = 0, c8 = 0;
    int tmpr, tmpc;
    vector<pair<int,int>> posvis;
    posvis.push_back({r_tail,c_tail});

    ifstream MyReadFile("input9.txt");

    while(getline (MyReadFile, move)){
        if(move.size() == 4){
            amount = (move[2]-48) *10 + move[3]-48;
        }
        else amount = move[2]-48;
        for(int i = 0; i < amount; ++i){
            if(move[0] == 'U') ++r_head;
            else if(move[0] == 'D') --r_head;
            else if(move[0] == 'L') --c_head;
            else if(move[0] == 'R') ++c_head;

            tmpr = movetail(r_head,c_head,r1,c1).first;
            tmpc = movetail(r_head,c_head,r1,c1).second;
            r1 += tmpr;
            c1 += tmpc;

            tmpr = movetail(r1,c1,r2,c2).first;
            tmpc = movetail(r1,c1,r2,c2).second;
            r2 += tmpr;
            c2 += tmpc;

            tmpr = movetail(r2,c2,r3,c3).first;
            tmpc = movetail(r2,c2,r3,c3).second;
            r3 += tmpr;
            c3 += tmpc;

            tmpr = movetail(r3,c3,r4,c4).first;
            tmpc = movetail(r3,c3,r4,c4).second;
            r4 += tmpr;
            c4 += tmpc;

            tmpr = movetail(r4,c4,r5,c5).first;
            tmpc = movetail(r4,c4,r5,c5).second;
            r5 += tmpr;
            c5 += tmpc;

            tmpr = movetail(r5,c5,r6,c6).first;
            tmpc = movetail(r5,c5,r6,c6).second;
            r6 += tmpr;
            c6 += tmpc;
            
            tmpr = movetail(r6,c6,r7,c7).first;
            tmpc = movetail(r6,c6,r7,c7).second;
            r7 += tmpr;
            c7 += tmpc;

            tmpr = movetail(r7,c7,r8,c8).first;
            tmpc = movetail(r7,c7,r8,c8).second;
            r8 += tmpr;
            c8 += tmpc;

            tmpr = movetail(r8,c8,r_tail,c_tail).first;
            tmpc = movetail(r8,c8,r_tail,c_tail).second;
            r_tail += tmpr;
            c_tail += tmpc;

            posvis.push_back({r_tail,c_tail});
            
            if(stop){
                cout << r_head << " " << c_head << endl;
                cout << r1 << " " << c1 << endl;
                cout << r2 << " " << c2 << endl;
                cout << r3 << " " << c3 << endl;
                cout << r4 << " " << c4 << endl;
                cout << r5 << " " << c5 << endl;
                cout << r6 << " " << c6 << endl;
                cout << r7 << " " << c7 << endl;
                cout << r8<< " " << c8 << endl;
                cout << r_tail << " " << c_tail << endl;
                throw invalid_argument("error ocurred");
            }
        }
    }

    vector<pair<int,int>> alreadyvisited;
    bool add = true;

    for(unsigned i = 0; i < posvis.size(); i++){
        for(unsigned j = 0; j < alreadyvisited.size(); j++){
            if(posvis[i] == alreadyvisited[j]){
                add = false;
                break;
            }
        }
        if(add) alreadyvisited.push_back(posvis[i]);
        else add = true;
    }

    cout << alreadyvisited.size() << endl;
}

int main(){
    part1();
    part2();
}