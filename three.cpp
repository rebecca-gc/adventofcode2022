//three - packing rucksacks

//input.txt

//output: priority sum of false packed items

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void priorities(){
    string rucksack;
    int prioritysum = 0;

    ifstream MyReadFile("input.txt");

    while(getline (MyReadFile, rucksack)){
        vector<char> items1 (53, 0);
        vector<char> items2 (53, 0);
        for(unsigned i = 0; i < (rucksack.size() / 2); ++i){
            if(islower(rucksack[i])){
                items1[int(rucksack[i]) - 96] += 1;
            }
            else{
                items1[int(rucksack[i]) - 38] += 1;
            }
        }
        for(unsigned i = rucksack.size() / 2; i < rucksack.size(); ++i){
            if(islower(rucksack[i])){
                items2[int(rucksack[i]) - 96] += 1;
            }
            else{
                items2[int(rucksack[i]) - 38] += 1;
            }
        }
        for(unsigned i = 0; i < items1.size(); ++i){
            if(items1[i] != 0 && items2[i] != 0){
                prioritysum += i;
            }
        }
    }

    cout << prioritysum << endl;
}

void groups(){
    string rucksack;
    int prioritysum = 0;
    vector<char> items1 (53, 0);
    vector<char> items2 (53, 0);
    vector<char> items3 (53, 0);
    int elvenum = 1;

    ifstream MyReadFile("input.txt");

    while(getline (MyReadFile, rucksack)){
        if(elvenum % 3 == 1){
            for(unsigned i = 0; i < rucksack.size(); ++i){
                if(islower(rucksack[i])){
                    items1[int(rucksack[i]) - 96] += 1;
                }
                else{
                    items1[int(rucksack[i]) - 38] += 1;
                }
            }
        }
        if(elvenum % 3 == 2){
            for(unsigned i = 0; i < rucksack.size(); ++i){
                if(islower(rucksack[i])){
                    items2[int(rucksack[i]) - 96] += 1;
                }
                else{
                    items2[int(rucksack[i]) - 38] += 1;
                }
            }
        }
        if(elvenum % 3 == 0){
            for(unsigned i = 0; i < rucksack.size(); ++i){
                if(islower(rucksack[i])){
                    items3[int(rucksack[i]) - 96] += 1;
                }
                else{
                    items3[int(rucksack[i]) - 38] += 1;
                }
            }
            for(unsigned i = 0; i < items1.size(); ++i){
                if(items1[i] != 0 && items2[i] != 0 && items3[i] != 0){
                    prioritysum += i;
                    cout << i << endl;
                }
            }
            for(unsigned i = 0; i < items1.size(); ++i){
                items1[i] = 0;
                items2[i] = 0;
                items3[i] = 0;
            }
        }
        
        ++elvenum;
    }

    cout << prioritysum << " " << elvenum << endl;
}

int main(){
    groups();
}