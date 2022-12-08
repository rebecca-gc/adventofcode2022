//six - communication device

//sixinput.txt

//output: # of chars processed before a marker

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void markerpos(){
    string sms;    
    ifstream MyReadFile("sixinput.txt");
    char a, b, c, d;
    int pos = 4;
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

bool alleUnterschiedlich(vector<char>& currentmarker){
    for(unsigned i = 0; i < currentmarker.size(); ++i){
        for(unsigned j = 0; j < currentmarker.size(); ++j){
            if(i == j);
            else{
                if(currentmarker[i] == currentmarker[j]){
                    return false;
                }
            }
        }
    }
    return true;
}

void markerpos14(){
    string sms;    
    ifstream MyReadFile("sixinput.txt");
    vector<char> currentmarker (14);
    int pos = 14;
    while(getline (MyReadFile, sms)){
        for(unsigned i = 0; i < 14; ++i){
            currentmarker[i] = sms[i];
        }

        while(!alleUnterschiedlich(currentmarker)){
            for(unsigned i = 0; i < currentmarker.size()-1; ++i){
                currentmarker[i] = currentmarker[i+1];
            }
            currentmarker[13] = sms[pos];
            ++pos;
        }
    }

    cout << pos << endl;
}

int main(){
    markerpos14();
}