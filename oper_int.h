#include <iostream>
#include <vector>
#include <string>


int operation_m_int(std::vector <std::string>& vec){
    int operand=0;
    int operand1=0;
    int operand2=0;
    
    for(int w=0; w<vec.size(); ++w){
        if(vec[w]=="*"){
            for(int q=0; q<vars.size(); ++q){ 
                if(vec[w-1]==vars[q].name){
                    operand1=*(static_cast<int*>(vars[q].value));
                }
                if(vec[w+1]==vars[q].name){
                    operand2=*(static_cast<int*>(vars[q].value));
                }
            }
            bool b1=true;
            std::string _mstr=vec[w-1];
            for(int h=0; h<_mstr.size(); ++h){
                if (! (_mstr[h]>='0' && _mstr[h]<='9') ){
                    b1=false;
                }
            }
            bool b2=true;
            std::string _msti=vec[w+1];
            for(int h=0; h<_msti.size(); ++h){
                if (! (_msti[h]>='0' && _msti[h]<='9') ){
                    b2=false;
                }
            }
            if(b1==true){ 
                operand1=std::stoi(vec[w-1]);
            }
            if(b2==true){ 
               operand2=std::stoi(vec[w+1]);
            }
            
            operand=operand1*operand2;
            vec.insert(vec.begin()+w, std::to_string(operand));
            ++w;
            vec.erase(vec.begin()+w);
            vec.erase(vec.begin()+w);
            vec.erase(vec.begin()+w-2);
            w=2;
            
        }
  
        else if(vec[w]=="/"){
            for(int q=0; q<vars.size(); ++q){ 
                if(vec[w-1]==vars[q].name){
                    operand1=*(static_cast<int*>(vars[q].value));
                }
                if(vec[w+1]==vars[q].name){
                    operand2=*(static_cast<int*>(vars[q].value));
                }
            }
            bool b1=true;
            std::string _mstr=vec[w-1];
            for(int h=0; h<_mstr.size(); ++h){
                if (! (_mstr[h]>='0' && _mstr[h]<='9') ){
                    b1=false;

                }
            }
            bool b2=true;
            std::string _msti=vec[w+1];
            for(int h=0; h<_msti.size(); ++h){
                if (! (_msti[h]>='0' && _msti[h]<='9') ){
                    b2=false;

                }
            }
            if(b1==true){ 
                operand1=std::stoi(vec[w-1]);
            }
            if(b2==true){ 
               operand2=std::stoi(vec[w+1]);
            }
          
            operand=operand1/operand2;
            vec.insert(vec.begin()+w, std::to_string(operand));
            ++w;
            vec.erase(vec.begin()+w);
            vec.erase(vec.begin()+w);
            vec.erase(vec.begin()+w-2);
            w=2;
            
        }
    }
    int returning=0;
    
    for(int gf=0; gf<vars.size(); ++gf){
        if(vec[2]==vars[gf].name){
            returning=*(static_cast<int*>(vars[gf].value));
        }
    }
    bool b23=true;
    std::string _mygf=vec[2];
    for(int yo=0; yo<_mygf.size(); ++yo){
        if(!(_mygf[yo]>='0' && _mygf[yo]<='9')){
            b23=false;
        }
    }
    if(b23==true){
        returning=std::stoi(vec[2]);
    }
    for(int w=2; w<vec.size(); ++w){ 
        if(vec[w]=="+"){
            for(int q=0; q<vars.size(); ++q){ 
                if(vec[w+1]==vars[q].name){
                    operand2=*(static_cast<int*>(vars[q].value));
                }
            }
            
            bool b2=true;
            std::string _msti=vec[w+1];
            for(int h=0; h<_msti.size(); ++h){
                if (! (_msti[h]>='0' && _msti[h]<='9') ){
                    b2=false;

                }
            }
            if(b2==true){ 
               operand2=std::stoi(vec[w+1]);
            }
            returning+=operand2;
        }
        else if(vec[w]=="-"){
            for(int q=0; q<vars.size(); ++q){ 
                if(vec[w+1]==vars[q].name){
                    operand2=*(static_cast<int*>(vars[q].value));
                }
            }
            bool b2=true;
            std::string _msti=vec[w+1];
            for(int h=0; h<_msti.size(); ++h){
                if (! (_msti[h]>='0' && _msti[h]<='9') ){
                    b2=false;

                }
            }
            if(b2==true){ 
               operand2=std::stoi(vec[w+1]);
            }
            returning-=operand2;
        }
    }
    return returning;
}
int ev_int(std::vector <std::string>& vec){
    int op1;
    int op2;
    for(int l=0; l<vars.size(); ++l){
        if(vec[0]==vars[l].name){
            op1=*(static_cast<int*>(vars[l].value));
        }
        if(vec[2]==vars[l].name){
            op2=*(static_cast<int*>(vars[l].value));
        }
    }
    bool b2=true;
    std::string _msti=vec[2];
    for(int h=0; h<_msti.size(); ++h){
        if (! (_msti[h]>='0' && _msti[h]<='9') ){
            b2=false;

        }
    }
    if(b2==true){ 
        op2=std::stoi(vec[2]);
    }
    if(vec[1]=="+="){
       op1=op1+op2;
    }
    else if(vec[1]=="-="){
       op1=op1-op2;
    }
    else if(vec[1]=="*="){
       op1=op1*op2;
    }
    else if(vec[1]=="/="){
       op1=op1/op2;
    }
    return op1;

}