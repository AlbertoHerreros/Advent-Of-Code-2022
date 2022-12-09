#include <iostream>
#include <fstream>

bool fullyContains( int firstMin, int firstMax, int secondMin, int secondMax){
    return( firstMin >= secondMin && firstMax <= secondMax );
}

int main(int argc, char** argv) {

    std::string fileName = "day4_input.txt";
    std::ifstream file(fileName.c_str() );
    std::string line;
    int cut;
    
    std::string first, second;
    int firstMin, firstMax, secondMin, secondMax;
    int score = 0;
    
    //Read the entire input
    while( getline( file,line ) ){
        
        cut = line.find(',');
        first = line.substr(0,cut);
        line.erase(0,cut+1);
        second = line;
        
        cut = first.find('-');
        firstMin = stoi(first.substr(0,cut));
        first.erase(0,cut+1);
        firstMax = stoi(first);
        
        cut = second.find('-');
        secondMin = stoi(second.substr(0,cut));
        second.erase(0,cut+1);
        secondMax = stoi(second);
        
        if(fullyContains(firstMin, firstMax, secondMin, secondMax))
            score++;
        else if (fullyContains(secondMin, secondMax, firstMin, firstMax))
            score++;

    }
    std::cout << score;
    return 0;
}



