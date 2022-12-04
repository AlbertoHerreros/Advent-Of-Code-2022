#include <iostream>
#include <fstream>
#include <set>
#include <unordered_map>
using namespace std;

int main(int argc, char** argv) {

    std::string fileName = "day3_input.txt";
    std::ifstream file(fileName.c_str() );
    std::string line;
    //Map every char with numeric value
    std::unordered_map<char, int> charValues;
    int value = 1;
    // a=1...z=26
    for( char c = 'a'; c != '{'; c++ )
        charValues[c] = value++;
    // A=27...Z=52
    for( char c = 'A'; c != '['; c++ )
        charValues[c] = value++;
    
    //Chars which appears in every half of the line
    std::set<char> charsI;
    std::set<char> charsJ;
    int i, j;
    long score = 0;
    
    //Read the entire input
    while( getline( file,line ) ){
        
        int i = 0;
        int j = line.length()/2;
        repeatedChar = false;

        while( i < line.length()/2 && j < line.length() ){
            
            charsI.insert(line[i++]);
            charsJ.insert(line[j++]);

        } 
        for( auto& it: charsI ){
            for( auto& it2: charsJ )
                if( it == it2 )
                    score += charValues[it];
        }
        charsI.clear();
        charsJ.clear();
    }
    cout << score;
    
    return 0;
}

