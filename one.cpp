//one - counting calories

//input.txt

//output: # of the elve who is carrying the most calories and the # of calories

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void countingCalories(){
    string calories;
    int calsum;
    int max = 0, elve = 0, pos = 0;

    ifstream MyReadFile("input.txt");

    while(getline (MyReadFile, calories)){
        if(calories == ""){
            if(calsum > max){
                max = calsum;
                elve = pos;
            }
            ++pos;
            calsum = 0;
        }
        else{
            calsum += stoi(calories);
        }
    }

    cout << max << " " << elve << endl;
}

void countingCaloriesBackUp(){
    string calories;
    int calsum, maxsum;
    int max1 = 0, max2 = 0, max3 = 0;

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
                else{
                    max3 = calsum;
                }
            }
            calsum = 0;
        }
        else{
            calsum += stoi(calories);
        }
    }

    maxsum = max1 + max2 + max3;

    cout << maxsum << endl;
}

int main(){
    countingCaloriesBackUp();
}

//g++ -std=c++17 -Wall -pedantic -O3 one.cpp -o one