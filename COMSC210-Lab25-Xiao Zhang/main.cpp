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

void read(string name);
void sorting();
void insert();
void del();

int main() {
    cout<<"Operation\t"<<"Vector\t"<<"List\t"<<"Set"<<endl;
    string name = "codes.txt";
    
    
    

    return 0;
}

void read(string name){
    ifstream file(name);
    string temp;
    auto start_ve = high_resolution_clock::now();

    while(file >> temp){
        ve.push_back(temp);
    }

    auto end_ve = high_resolution_clock::now();
    auto duration_ve = duration_cast<milliseconds>(end_ve - start_ve);
    
    auto start_li = high_resolution_clock::now();

    while(file >> temp){
        li.push_back(temp);
    }

    auto end_li = high_resolution_clock::now();
    auto duration_li = duration_cast<milliseconds>(end_li - start_li);
    
    auto start_se = high_resolution_clock::now();

    while(file >> temp){
        se.insert(temp);
    }

    auto end_se = high_resolution_clock::now();
    auto duration_se = duration_cast<milliseconds>(end_se - start_se);
    
    cout<<"Read\t"<<duration_ve<<"\t"<<duration_li<<"\t"<<duration_se<<endl;
}

void sorting(){
    auto start_ve = high_resolution_clock::now();

    sort(ve.begin(),ve.end());

    auto end_ve = high_resolution_clock::now();
    auto duration_ve = duration_cast<milliseconds>(end_ve - start_ve);
    
    auto start_li = high_resolution_clock::now();

    sort(li.begin(),li.end());

    auto end_li = high_resolution_clock::now();
    auto duration_li = duration_cast<milliseconds>(end_li - start_li);
    
    int duration_se = -1;
    
    cout<<"Sort\t"<<duration_ve<<"\t"<<duration_li<<"\t"<<duration_se<<endl;
}

void insert(){
    string code = "TESTCODE";
    auto start_ve = high_resolution_clock::now();

    long middle = ve.size()/2;
    ve.insert(ve.begin()+middle, code);

    auto end_ve = high_resolution_clock::now();
    auto duration_ve = duration_cast<milliseconds>(end_ve - start_ve);
    
    auto start_li = high_resolution_clock::now();

    auto it = li.begin();
    advance(it, li.size()/2);
    li.insert(it,code);

    auto end_li = high_resolution_clock::now();
    auto duration_li = duration_cast<milliseconds>(end_li - start_li);
    
    auto start_se = high_resolution_clock::now();

    se.insert(code);

    auto end_se = high_resolution_clock::now();
    auto duration_se = duration_cast<milliseconds>(end_se - start_se);
    
    cout<<"Insert\t"<<duration_ve<<"\t"<<duration_li<<"\t"<<duration_se<<endl;
}

void del(){
    auto start_ve = high_resolution_clock::now();

    long middle = ve.size()/2;
    ve.erase(ve.begin()+middle);

    auto end_ve = high_resolution_clock::now();
    auto duration_ve = duration_cast<milliseconds>(end_ve - start_ve);
    
    auto start_li = high_resolution_clock::now();

    auto it = li.begin();
    advance(it, li.size()/2);
    li.erase(it);

    auto end_li = high_resolution_clock::now();
    auto duration_li = duration_cast<milliseconds>(end_li - start_li);
    
    auto start_se = high_resolution_clock::now();

    auto it_se = se.begin();
    advance(it_se, se.size()/2);
    se.erase(it_se);

    auto end_se = high_resolution_clock::now();
    auto duration_se = duration_cast<milliseconds>(end_se - start_se);
    
    cout<<"Erase\t"<<duration_ve<<"\t"<<duration_li<<"\t"<<duration_se<<endl;
}
