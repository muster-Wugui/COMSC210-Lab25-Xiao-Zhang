//
//  main.cpp
//  COMSC210-Lab25-Xiao Zhang
//
//  Created by Xiao Zhang on 10/26/24.
//

#include <iostream>
#include <chrono>
#include <fstream>
#include <list>
#include <set>
#include <vector>
using namespace std;
using namespace std::chrono;

const int MAX_SZ = 20000;

vector<string> ve;
list<string> li;
set<string> se;

int main() {
    ifstream file("codes.txt");
    
    
    string temp;
    auto start = high_resolution_clock::now();

    while(file >> temp){
        ve.push_back(temp);
    }

    auto end = high_resolution_clock::now();
    auto duration_ve = duration_cast<milliseconds>(end - start);
    
    
    

    return 0;
}

