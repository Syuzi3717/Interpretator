#include <iostream>
#include <vector>
#include <string>


double operation_m_double(std::vector <std::string>& vec){

    double operand=0;
    double operand1=0;
    double operand2=0;
    
    for(int w=2; w<vec.size(); ++w){
        if(vec[w]=="*"){
            for(int q=0; q<vars.size(); ++q){ 
                if(vec[w-1]==vars[q].name){
                    operand1=*(static_cast<double*>(vars[q].value));
                }
                if(vec[w+1]==vars[q].name){
                    operand2=*(static_cast<double*>(vars[q].value));
                }
            }
            bool b1=true;
            std::string _mstr=vec[w-1];
            for(int h=0; h<_mstr.size(); ++h){
                if (! ((_mstr[h]>='0' && _mstr[h]<='9') || _mstr[h]=='.') ){
                    b1=false;
                }
            }
            bool b2=true;
            std::string _msti=vec[w+1];
            for(int h=0; h<_msti.size(); ++h){
                if (! ((_msti[h]>='0' && _msti[h]<='9') || _msti[h]=='.') ){
                    b2=false;
                }
            }
            if(b1==true){ 
                operand1=std::stod(vec[w-1]);
            }
            if(b2==true){ 
               operand2=std::stod(vec[w+1]);
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
                    operand1=*(static_cast<double*>(vars[q].value));
                }
                if(vec[w+1]==vars[q].name){
                    operand2=*(static_cast<double*>(vars[q].value));
                }
            }
            bool b1=true;
            std::string _mstr=vec[w-1];
            for(int h=0; h<_mstr.size(); ++h){
                if (! ((_mstr[h]>='0' && _mstr[h]<='9') || _mstr[h]=='.')){
                    b1=false;

                }
            }
            bool b2=true;
            std::string _msti=vec[w+1];
            for(int h=0; h<_msti.size(); ++h){
                if (! ((_msti[h]>='0' && _msti[h]<='9') || _mstr[h]=='.') ){
                    b2=false;

                }
            }
            if(b1==true){ 
                operand1=std::stod(vec[w-1]);
            }
            if(b2==true){ 
               operand2=std::stod(vec[w+1]);
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
    double returning;
    int gf=0;
    for(; gf<vars.size(); ++gf){
        if(vec[2]==vars[gf].name){
            returning=*(static_cast<double*>(vars[gf].value));
        }
    }
    bool b23=true;
    std::string _mygf=vec[2];
    for(int yo=0; yo<_mygf.size(); ++yo){
        if(!((_mygf[yo]>='0' && _mygf[yo]<='9')|| _mygf[yo]=='.')){
            b23=false;
        }
    }
    if(b23==true){
        returning=std::stod(vec[2]);
    }
    for(int w=2; w<vec.size(); ++w){ 
        if(vec[w]=="+"){
            for(int q=0; q<vars.size(); ++q){ 
                if(vec[w+1]==vars[q].name){
                    operand2=*(static_cast<double*>(vars[q].value));
                }
            }
            bool b2=true;
            std::string _msti=vec[w+1];
            for(int h=0; h<_msti.size(); ++h){
                std::to_string(operand2);
                if (! ((_msti[h]>='0' && _msti[h]<='9') || _msti[h]=='.') ){
                    b2=false;

                }
            }
            if(b2==true){ 
               operand2=std::stod(vec[w+1]);
            }
            returning+=operand2;
        }
        else if(vec[w]=="-"){
            for(int q=0; q<vars.size(); ++q){ 
                if(vec[w+1]==vars[q].name){
                    operand2=*(static_cast<double*>(vars[q].value));
                }
            }
            bool b2=true;
            std::string _msti=vec[w+1];
            for(int h=0; h<_msti.size(); ++h){
                if (! ((_msti[h]>='0' && _msti[h]<='9') || _msti[h]=='.')){
                    b2=false;

                }
            }
            if(b2==true){ 
               operand2=std::stod(vec[w+1]);
            }
            returning-=operand2;
        }
    }
    
    return returning;
}
double ev_double(std::vector <std::string>& vec){
    double op1=0;
    double op2;
    for(int l=0; l<vars.size(); ++l){
        if(vec[0]==vars[l].name){
            op1=*(static_cast<double*>(vars[l].value));
        }
        if(vec[2]==vars[l].name){
            op2=*(static_cast<double*>(vars[l].value));
        }
    }
    bool b2=true;
    std::string _msti=vec[2];
    for(int h=0; h<_msti.size(); ++h){
        if (! ((_msti[h]>='0' && _msti[h]<='9') || _msti[h]=='.') ){
            b2=false;

        }
    }
    if(b2==true){ 
        op2=std::stod(vec[2]);
    }
    if(vec[1]=="+="){
        op1+=op2;
    }
    else if(vec[1]=="-="){
        op1-=op2;
    }
    else if(vec[1]=="*="){
        op1*=op2;
    }
    else if(vec[1]=="/="){
       op1/=op2;
    }
   return op1;

}