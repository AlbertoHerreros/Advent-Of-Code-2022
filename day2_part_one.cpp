#include <iostream>
#include <fstream>
#include <unordered_map>
using namespace std;

int main(int argc, char** argv) {

    std::string fileName = "day2_input.txt";
    std::ifstream file(fileName.c_str() );
    std::string line;
    
    unordered_map<std::string, int> moves;
    unordered_map<std::string, int>::iterator it;
    //AX rock 1, BY paper 2, CZ scissors 3
    //win 6 points, draw 3, lose 0
    moves["A X"] = 3 + 1;
    moves["A Y"] = 6 + 2;
    moves["A Z"] = 0 + 3;
    moves["B X"] = 0 + 1;
    moves["B Y"] = 3 + 2;
    moves["B Z"] = 6 + 3;
    moves["C X"] = 6 + 1;
    moves["C Y"] = 0 + 2;
    moves["C Z"] = 3 + 3;     
    
    long score = 0;
    
    //Read the entire input
    while( getline( file,line ) ){
        
        it = moves.find(line);
        if( it != moves.end() )
            score += it->second;
        
    }
    cout << score;
    
    return 0;
}

