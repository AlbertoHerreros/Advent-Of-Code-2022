#include <iostream>
#include <fstream>
#include <vector>
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
    std::vector<set<char>> vCharsets;
    for( int i = 0; i < 3; i++ )
        vCharsets.push_back(set<char>());
    int n=0;//1,2,3
    bool repeatedChar;
    long score = 0;
    
    //Read the entire input
    while( getline( file,line ) ){
        
        for( int i = 0; i < line.length(); i++ )
            vCharsets[n].insert(line[i]);
        n++;
        
        if( n == 3){
            for( auto& it: vCharsets[0] )
                for( auto& it2: vCharsets[1] )
                    for( auto& it3: vCharsets[2] )
                        if( it == it2 && it2 == it3 )
                           score += charValues[it];
           
            for( int i = 0; i < 3; i++ )
                vCharsets[i].clear();
            n=0;
        }

    }
    cout << score;
    
    return 0;
}

