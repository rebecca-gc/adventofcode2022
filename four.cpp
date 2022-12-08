//four - camp cleanup
//g++ -std=c++17 -Wall -pedantic -O3 four.cpp -o four

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

void part1(){
    string sections;
    int overlaps = 0;
    
    ifstream MyReadFile("fourinput.txt");

    while(getline (MyReadFile, sections)){
        bool dvorbei = false, bvorbei = false, cvorbei = false;
        int minuscounter = 0, stelle = 0;
        int a, b, c, d;
        //this whole for-loop is just for initialising a,b,c and d. i'm sure there is a better way...
        for(unsigned i = sections.size() - 1; i > 0; --i){
            if(sections[i] == '-' && minuscounter == 1){
                bvorbei = true;
                stelle = 0;
            }
            else if(sections[i] == '-'){
                dvorbei = true;
                ++minuscounter;
                stelle = 0;
            }
            else if(sections[i] == ','){
                cvorbei = true;
                stelle = 0;
            }
            else{
                if(!dvorbei){
                    d += (sections[i]-48) * pow(10,stelle);
                    ++stelle;
                }
                else if(!cvorbei){
                    c += (sections[i]-48) * pow(10,stelle);
                    ++stelle;
                }
                else if(!bvorbei){
                    b += (sections[i]-48) * pow(10,stelle);
                    ++stelle;
                }
                else{
                    a += (sections[i]-48) * pow(10,stelle);
                    ++stelle;
                }
            }
        }
        a += (sections[0]-48) * pow(10,stelle);
        if((a <= c && b >= d) || (a >= c && b <= d)) ++overlaps;
    }

    cout << overlaps << endl;
}

void part2(){
    string sections;
    int overlaps = 0;
    
    ifstream MyReadFile("fourinput.txt");

    while(getline (MyReadFile, sections)){
        bool dvorbei = false, bvorbei = false, cvorbei = false;
        int minuscounter = 0, stelle = 0;
        int a, b, c, d;
        for(unsigned i = sections.size() - 1; i > 0; --i){
            if(sections[i] == '-' && minuscounter == 1){
                bvorbei = true;
                stelle = 0;
            }
            else if(sections[i] == '-'){
                dvorbei = true;
                ++minuscounter;
                stelle = 0;
            }
            else if(sections[i] == ','){
                cvorbei = true;
                stelle = 0;
            }
            else{
                if(!dvorbei){
                    d += (sections[i]-48) * pow(10,stelle);
                    ++stelle;
                }
                else if(!cvorbei){
                    c += (sections[i]-48) * pow(10,stelle);
                    ++stelle;
                }
                else if(!bvorbei){
                    b += (sections[i]-48) * pow(10,stelle);
                    ++stelle;
                }
                else{
                    a += (sections[i]-48) * pow(10,stelle);
                    ++stelle;
                }
            }
        }
        a += (sections[0]-48) * pow(10,stelle);
        if((a <= c && b >= d) || (a >= c && b <= d) || (a <= c && b >= c) || (a <= d && b >= d) || (c <= a && d >= a) || (c <= b && d >= b)) ++overlaps;
    }

    cout << overlaps << endl;
}

int main(){
    part1();
    part2();
}
