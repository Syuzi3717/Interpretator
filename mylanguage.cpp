#include <iostream>
#include <string>
#include <fstream>
#include <vector>

struct variable{
    std::string name;
    std::string type;
    void* value;
};

std::vector<variable> vars;
#include "operations.h"

int main(){
    std::string path;
    std::ifstream fin ; 
    std::cin >> path;
    fin.open(path);
    if (fin.is_open()){
        translate(fin);

    }
    else{
        std::cout << "ERROR" << std::endl;
    }

}