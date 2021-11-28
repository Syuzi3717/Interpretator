#include <iostream>
#include <vector>
#include <string>

std::string operation_m_string(std::vector <std::string>& vec){
    std::string op1;
    std::string op2;
    bool v=true;
    for(int l=0; l<vars.size(); ++l){
        if(vec[2]==vars[l].name){
            op1=*(static_cast<std::string*>(vars[l].value));
            v=false;
        }
    }
    if(v){
        op1=vec[2];
    }
    for(int w=2; w<vec.size();++w){
        bool h=true;
        if(vec[w]=="+"){
            for(int q=0; q<vars.size(); ++q){
                if(vec[w+1]==vars[q].name){
                    op2=*(static_cast<std::string*>(vars[q].value));
                    h=false;
                }
            }
            if(h){
                op2=vec[w+1];
            }
            op1=op1+" " +op2;
        }
    }
    return op1; 
}
std::string ev_string(std::vector <std::string>& vec){
    std::string op1;
    std::string op2;
    bool w=true;
    for(int l=0; l<vars.size(); ++l){
        if(vec[0]==vars[l].name){
            op1=*(static_cast<std::string*>(vars[l].value));
        }
        if(vec[2]==vars[l].name){
            op2=*(static_cast<std::string*>(vars[l].value));
            w=false;
        }
    }
    if(w){
        op2=vec[2];
    }
    if(vec[1]=="+="){
        op1=op1+op2;
    }
    else{
        std::cout<<"ERROR, undefined action with cigols!!!!!"<<std::endl;
        exit(-1);
    }
    return op1;
}