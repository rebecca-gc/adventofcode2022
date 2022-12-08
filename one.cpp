//one - calorie counting
//g++ -std=c++17 -Wall -pedantic -O3 one.cpp -o one

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void part1(){
    string calories;
    int calsum, max = 0;

    ifstream MyReadFile("oneinput.txt");

    while(getline (MyReadFile, calories)){
        if(calories == ""){
            if(calsum > max) max = calsum;
            calsum = 0;
        }
        else calsum += stoi(calories);
    }

    cout << max << endl;
}

void part2(){
    string calories;
    int calsum, max1 = 0, max2 = 0, max3 = 0;

    ifstream MyReadFile("input.txt");

    while(getline (MyReadFile, calories)){
        if(calories == ""){
            if(calsum > max3){
                if(calsum > max2){
                    if(calsum > max1){
                        max3 = max2;
                        max2 = max1;
                        max1 = calsum;
                    }
                    else{
                        max3 = max2;
                        max2 = calsum;
                    }
                }
                else max3 = calsum;
            }
            calsum = 0;
        }
        else calsum += stoi(calories);
    }

    cout << max1 + max2 + max3 << endl;
}

int main(){
    part1();
    part2();
}
