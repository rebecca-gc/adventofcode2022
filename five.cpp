//five - stacking cargo

//fiveinput.txt

//output: label of the upper crates at the end of stacking

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void stacks(){
    string moves;
    bool moving = false;
    bool print = true;
    bool firstmove = true;
    ifstream MyReadFile("fiveinput.txt");

    vector<string> cargo (9);

    while(getline (MyReadFile, moves)){
        if(moves[1] == '1'|| moves == ""){
            moving = true;
        }
        else if(!moving){
            int j = 0;
            for(unsigned i = 1; i <= 33; i+=4){
                if(moves[i] != ' '){
                    cargo[j] += moves[i];
                    //cout << cargo[j] << " ";
                }
                ++j;
            }
        }
        else{
            if(print){
                print = false;
                for(unsigned i = 0; i < cargo.size(); ++i){
                    cout << cargo[i] << endl;
                }
                for(unsigned i = 0; i < cargo.size(); ++i){
                    cout << cargo[i][0];
                }
                cout << endl;
            }
            int amount;
            int from;
            int to;
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
            //cout << amount << from << to << endl;
            for(int i = 0; i < amount; ++i){
                cargo[to] = cargo[from][0] + cargo[to];
                cargo[from] = cargo[from].substr(1, cargo[from].size()-1);
            }

            if(firstmove){
                firstmove = false;
                cout << "erster move:" << endl;
                for(unsigned i = 0; i < cargo.size(); ++i){
                    cout << cargo[i] << endl;
                }
            }

        }
    }

    for(unsigned i = 0; i < cargo.size(); ++i){
        cout << cargo[i][0];
    }
    cout << endl;
}

void stacks9001(){
    string moves;
    bool moving = false;
    bool print = true;
    bool firstmove = true;
    ifstream MyReadFile("fiveinput.txt");

    vector<string> cargo (9);

    while(getline (MyReadFile, moves)){
        if(moves[1] == '1'|| moves == ""){
            moving = true;
        }
        else if(!moving){
            int j = 0;
            for(unsigned i = 1; i <= 33; i+=4){
                if(moves[i] != ' '){
                    cargo[j] += moves[i];
                    //cout << cargo[j] << " ";
                }
                ++j;
            }
        }
        else{
            if(print){
                print = false;
                for(unsigned i = 0; i < cargo.size(); ++i){
                    cout << cargo[i] << endl;
                }
                for(unsigned i = 0; i < cargo.size(); ++i){
                    cout << cargo[i][0];
                }
                cout << endl;
            }
            int amount;
            int from;
            int to;
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
            //cout << amount << from << to << endl;
            
            string tmp = cargo[from].substr(0,amount);
            cargo[to] = tmp + cargo[to];
            if(amount-1 <= cargo[from].size()-1) cargo[from] = cargo[from].substr(amount, cargo[from].size()-1);
            


            if(firstmove){
                firstmove = false;
                cout << "erster move:" << endl;
                for(unsigned i = 0; i < cargo.size(); ++i){
                    cout << cargo[i] << endl;
                }
            }

        }
    }

    for(unsigned i = 0; i < cargo.size(); ++i){
        cout << cargo[i][0];
    }
    cout << endl;
}

int main(){
    stacks9001();
}