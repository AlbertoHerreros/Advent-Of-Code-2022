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
    //A rock 1, B paper 2, C scissors 3
    //win 6 points, draw 3, lose 0
    //X lose, Y draw, Z lose
    moves["A X"] = 0 + 3;
    moves["A Y"] = 3 + 1;
    moves["A Z"] = 6 + 2;
    moves["B X"] = 0 + 1;
    moves["B Y"] = 3 + 2;
    moves["B Z"] = 6 + 3;
    moves["C X"] = 0 + 2;
    moves["C Y"] = 3 + 3;
    moves["C Z"] = 6 + 1;     
    
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

