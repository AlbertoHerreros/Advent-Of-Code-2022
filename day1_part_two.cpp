/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Alberto Herreros Magaña
 *
 * Created on 3 de diciembre de 2022, 22:13
 */

#include <iostream>
#include <fstream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    std::string fileName = "day1_input.txt";
    std::ifstream file(fileName.c_str() );
    std::string line;
    
    
    int n;
    std::string str;
    long total = 0;
    long max = 0;
    long max2 = 0;
    long max3 = 0;
    //Read the entire input
    while( getline( file,line ) ){
        
        if( line != "" )
            total += stoi(line);
        else{
            
            if( total > max ){
                max3 = max2;
                max2 = max;
                max = total;
            } else if( total > max2 ){  
                max3 = max2;
                max2 = total;   
            } else if( total > max3 )
                 max3 = total;
        total = 0;    
        }  
    }
    
    if( total > max ){
        max3 = max2;
        max2 = max;
        max = total;
    } else if( total > max2 ){  
        max3 = max2;
        max2 = total;   
    } else if( total > max3 )
        max3 = total;
    
    std::cout << max + max2 + max3;
    
    return 0;
}

