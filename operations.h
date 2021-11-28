#include <iostream>
#include <vector>
#include <string>
#include "oper_double.h"
#include "oper_int.h"
#include "oper_string.h"

void decleration(std::vector<std::string>&);
void output_m(std::vector<std::string>&);
void operation_m(std::vector<std::string>&);
bool cast_to_bool(std::vector<std::string>&);
void holl_m(std::vector<std::vector<std::string> >&);
void translate (std::ifstream& fin ){
    while (!fin.eof()){
        std::string line;
        getline(fin, line);
        std::vector<std::string> tokens; 
        std::string tmp;
        for (int i = 0; i <= line.length(); ++i){
            if (line[i] != ' ' && line[i] != '\0'){
                tmp += line[i];
            }
            else{
                tokens.push_back(tmp);
                tmp = "";
            }
        }
        if (tokens[0] == "vita" || tokens[0] == "viti" || tokens[0] == "enil" || tokens[0] == "cigol"){
            decleration(tokens);
        }
        else if (tokens[0] == "bass" ){
            std::vector <std::string> payman ;
            payman.push_back(tokens[1]);
            payman.push_back(tokens[2]);
            payman.push_back(tokens[3]);
            payman.push_back(tokens[4]);
            bool pay=cast_to_bool(payman);
            
            std::vector<std::string> nor;
            if(pay){
                getline(fin, line);
                std::string ptmp;
                for (int pi = 0; pi <= line.length(); ++pi){
                    if (line[pi] != ' ' && line[pi] != '\0'){
                        ptmp += line[pi];;
                    }
                    else{
                        nor.push_back(ptmp);
                        ptmp = "";
                    }
                }
                while(nor[0]!="}"){
                    if (nor[0] == "vita" || nor[0] == "viti" || nor[0] == "enil" || nor[0] == "cigol"){
                       decleration(nor);
                    }
                    else if (nor[0] == "dobby"){
                        output_m(nor);
                    }
                    else{
                        for (int j = 0 ; j < vars.size(); j++){
                            if (nor[0] == vars[j].name ){
                                operation_m(nor);
                                break;
                            }
                        }
                    }    
                    getline(fin, line);
                    std::string ptmp;
                    nor.clear();
                    for (int pi = 0; pi <= line.length(); ++pi){
                        if (line[pi] != ' ' && line[pi] != '\0'){
                            ptmp += line[pi];
                        }
                        else{
                           nor.push_back(ptmp);
                           ptmp = "";
                        }
                    }
                }
            }
            else{
                std::string line;
                getline(fin, line);
                std::string ptmp;
                for (int pi = 0; pi <= line.length(); ++pi){
                    if (line[pi] != ' ' && line[pi] != '\0'){
                        ptmp += line[pi];
                    }
                    else{
                        nor.push_back(ptmp);
                       ptmp = "";
                    }
                } 

                while(nor[0]!="}"){
                    nor.clear();
                    //std::string line;
                    getline(fin, line);
                    for (int xi = 0; xi <= line.length(); ++xi){
                        if (line[xi] != ' ' && line[xi] != '\0'){
                           ptmp += line[xi];
                        }
                        else{
                           nor.push_back(ptmp);
                           ptmp = "";
                        }
                    } 
                }
            }
            
        }
        else if (tokens[0] == "holl"){ 
            std::vector<std::string> paymam;
            paymam.push_back(tokens[1]);
            paymam.push_back(tokens[2]);
            paymam.push_back(tokens[3]);
            bool paym=cast_to_bool(paymam);
            std::vector<std::vector<std::string> > text;
            std::string stre="";
            std::string stre2="";
            int ai=0;
            std::vector<std::string> tmp;
            while(stre2!="}"){
                getline(fin, line);
                for (int pi = 0; pi <= line.length(); ++pi){
                    if (line[pi] != ' ' && line[pi] != '\0'){
                        stre += line[pi];
                    }
                    else{
                        stre2=stre; 
                        if(stre=="}"){
                            break;
                        } 
                        tmp.push_back(stre);                       
                        stre = "";
                    }
                }  
                if(stre!="}"){ 
                text.push_back(tmp);
                tmp.clear();}
            }
            while (paym){
                holl_m(text);
                paym=cast_to_bool(paymam);
            }


        }
        else if (tokens[0] == "dobby"){
            output_m(tokens);
        }
        else{
           for (int j = 0 ; j < vars.size(); j++){
               if (tokens[0] == vars[j].name ){
                    operation_m(tokens);
                    break;
                }
            }
        }
    }
}
void decleration (std::vector <std::string>& vec){ 
    variable v1;
    void* ptr;
    for(int bh=0; bh<vars.size(); ++bh){
        if(vec[1]==vars[bh].name){
            std::cout<<"UNDEFINED ACTION! variable double decleration"<<std::endl;
            exit(-1);
        }
    }
    for (int i = 0; i < vec.size(); ++i){
        v1.type = vec[0];
        v1.name = vec[1];
        if (vec[2] == "="){
           if (vec[0] == "vita"){
               ptr = static_cast <void*> (new int);
               *(static_cast<int*>(ptr))=std::stoi(vec[3]);
            }
            else  if (vec[0] == "viti"){
               ptr= static_cast <void*> (new double);
               *(static_cast<double*>(ptr)) = std::stod(vec[3]);
            }
            else  if (vec[0] == "enil"){
               ptr = static_cast <void*> (new std::string);
               *(static_cast<std::string*>(ptr)) = vec[3];
            }
            else if (vec[0] == "cigol"){ 
               ptr = static_cast <void*> (new bool);
               if (vec[3] == "false" || vec[3] == "0"){
                  *(static_cast<bool*>(ptr)) = false;
                }
                else{
                   *(static_cast<bool*>(ptr)) = true;
                }
            }
        }
    }
    v1.value=ptr;
    vars.push_back(v1);
}
void operation_m(std::vector <std::string>& vec){
    if(vec[1]=="="){ 
        for(int j=0; j<vars.size(); ++j){
            if(vec[0]==vars[j].name){
                if(vars[j].type=="vita"){
                    if(vec.size()==4){
                        for(int k=0; k<vars.size(); ++k){
                            if(vec[2]==vars[k].name){
                                vars[j].value=vars[k].value;
                                return;
                            }
                        }
                        vars[j].value=static_cast<void*>(new int);
                        *(static_cast<int*>(vars[j].value))=std::stoi(vec[2]);
                        return;
                    }
                    else {
                        int countint=operation_m_int(vec);
                        vars[j].value=static_cast<void*>(new int);
                        *(static_cast<int*>(vars[j].value))=countint;
                        return;
                    }
                }
                else if(vars[j].type=="viti"){
                    if(vec.size()==4){
                        for(int k=0; k<vars.size(); ++k){
                            if(vec[2]==vars[k].name){
                                vars[j].value=vars[k].value;
                                return;
                            }
                        }
                        vars[j].value=static_cast<void*>(new double);
                        *(static_cast<double*>(vars[j].value))=std::stod(vec[2]);
                        return;
                    }
                    else {
                        double countdoub=operation_m_double(vec);
                        vars[j].value=static_cast<void*>(new double);
                        *(static_cast<double*>(vars[j].value))=countdoub;
                        return;
                    }
                }
                else if(vars[j].type=="enil"){
                    if(vec.size()==4){
                        for(int k=0; k<vars.size(); ++k){
                            if(vec[2]==vars[k].name){
                                vars[j].value=vars[k].value;
                                return;
                            }
                        }
                        vars[j].value=static_cast<void*>(new std::string);
                        *(static_cast<std::string*>(vars[j].value))=vec[2];
                        return;
                    }
                    else {
                        std::string coustr=operation_m_string(vec);
                        vars[j].value=static_cast<void*>(new std::string);
                        *(static_cast<std::string*>(vars[j].value))=coustr;
                        return;
                    }

                }
                else if(vars[j].type=="cigol"){
                    if(vec.size()==4){
                        for(int k=0; k<vars.size(); ++k){
                            if(vec[2]==vars[k].name){
                                vars[j].value=vars[k].value;
                                return;
                            }
                        }
                        vars[j].value=static_cast<void*>(new bool);
                        std::vector<std::string> booling;
                        for(int bo=2; bo<vec.size(); ++bo){
                            booling.push_back(vec[bo]);
                        }
                        *(static_cast<bool*>(vars[j].value))=cast_to_bool(booling);
                        return;
                    }    
                }

            }
        }
    }
    if(vec[1]=="+=" || vec[1]=="-=" || vec[1]=="*=" || vec[1]=="/="){
        for(int j=0; j<vars.size(); ++j){
            if(vec[0]==vars[j].name){
                if(vars[j].type=="vita"){
                    *(static_cast<int*>(vars[j].value))=ev_int(vec);
                    return;
                }
                else if(vars[j].type=="viti"){
                    *(static_cast<double*>(vars[j].value))=ev_double(vec);
                    return;
                }
                else if(vars[j].type=="enil"){
                    *(static_cast<std::string*>(vars[j].value))=ev_string(vec);
                    return; 
                }

            }
        }
        std::cout<<"ERROR, undefined action with literal"<<std::endl;
        exit(-1);
    }
    else if(vec[1]=="<" || vec[1]==">" || vec[1]=="==" || vec[1]=="!=" || vec[1]=="<=" || vec[1]==">="){
        std::cout<<cast_to_bool(vec);
        return;
    }
    
    return;
}
bool cast_to_bool(std::vector <std::string>& vec){
    double a;
    double b;
    int m=0;
    int a1;
    int b1;
    std::string strval1;
    std::string strval2;
    std::string name1;
    std::string name2;
    bool bval1;
    bool bval2;
    for(int t4=0; t4<vars.size(); ++t4){
        bool t6=false;
        if(vec[0]==vars[t4].name && vars[t4].type=="enil"){
            strval1=*((std::string*)vars[t4].value);
            t6=true;
            for(int t5=0; t5<vars.size(); ++t5){
                if(vec[2]==vars[t5].name){
                   strval2=*((std::string*)vars[t5].value);
                   t6=false;
                }
            }
            if(t6){
                strval2=vec[2];
            }
            if(vec[1]=="=="){
                return (strval1 == strval2);
            }
            if(vec[1]=="!="){
                return (strval1 != strval2);
            }
            return true;
        }
    }
    for(int t4=0; t4<vars.size(); ++t4){
        bool t6=false;
        if(vec[0]==vars[t4].name && vars[t4].type=="cigol"){
            bval1=*((bool*)vars[t4].value);
            t6=true;
            for(int t5=0; t5<vars.size(); ++t5){
                if(vec[2]==vars[t5].name){
                   bval2=*((bool*)vars[t5].value);
                   t6=false;
                }
            }
            if(t6){
                bval2=((vec[2]=="true" || vec[2]=="1")?true:false);
            }
            if(vec[1]=="=="){
                return (bval1 == bval2);
            }
            if(vec[1]=="!="){
                return (bval1 != bval2);
            }
            return true;
        }
    }
    for( ; m<vars.size(); ++m){
        if(vec[0]==vars[m].name){
            if(vars[m].type=="vita"){
               a1=*(static_cast<int*>(vars[m].value));
               a=(double)a1;
               name1="vita";
            }
            else if(vars[m].type=="viti"){
                a=*(static_cast<double*>(vars[m].value));
                name1="viti";
            }
        }
        if(vec[2]==vars[m].name){
            if(vars[m].type=="vita"){
               b1=*(static_cast<int*>(vars[m].value));
               b=(double)b1;
               name2="vita";
            }
            else if(vars[m].type=="viti"){
                b=*(static_cast<double*>(vars[m].value));
                name2="viti";
            }
        }
    }
    bool b3=true;
    std::string _mstr=vec[0];
    for(int h=0; h<_mstr.size(); ++h){
        if (! ((_mstr[h]>='0' && _mstr[h]<='9') || _mstr[h]=='.') ){
            b3=false;
        }
    }
    bool b2=true;
    std::string _msti=vec[2];
    for(int h=0; h<_msti.size(); ++h){
        if (! ((_msti[h]>='0' && _msti[h]<='9') || _msti[h]=='.') ){
            b2=false;
        }
    }
    if(b3==true){ 
        if(name1=="vita"){
            a1=std::stoi(vec[0]);
            a=(double)a1;
        }
        else a=std::stod(vec[0]);
    }
    if(b2==true){ 
        if(name2=="vita"){
            b1=std::stoi(vec[2]);
            b=(double)b1;
        }
        else b=std::stod(vec[2]);
    }
    if(vec[1]=="=="){
        return (a==b);
    }
    if(vec[1]=="!="){
        return (a!=b);
    }
    if(vec[1]==">"){
        return (a>b);
    }
    if(vec[1]=="<"){
        return (a<b);
    }
    if(vec[1]==">="){
        return (a>=b);
    }
    if(vec[1]=="<="){
        return (a<=b);
    }
    exit(-1);
}
void holl_m(std::vector<std::vector<std::string> >& vec){
    for(int mk=0; mk<vec.size(); ++mk){
        if (vec[mk][0] == "vita" || vec[mk][0] == "viti" || vec[mk][0] == "enil" || vec[mk][0] == "cigol"){
            decleration(vec[mk]);
        }
        else if (vec[mk][0] == "dobby"){
            output_m(vec[mk]);
        }
        else{
           for (int j = 0 ; j < vars.size(); j++){
               if (vec[mk][0] == vars[j].name ){
                    operation_m(vec[mk]);
                    break;
                }
            }
        }
    }
    return;
}
void output_m(std::vector<std::string>& vec) {
    for (int i = 1; i < vec.size(); ++i) {
        if (vec[i] == ";") {
            std::cout<<std::endl;
            break;
        }
        if (vec[i] == "^") {
            ++i;
        }
        bool b5=true;
        for (int j = 0; j < vars.size(); ++j) {
            if (vec[i] == vars[j].name) {
                if (vars[j].type == "vita") {
                    int tp=*(static_cast<int*>(vars[j].value));
                    std::cout <<tp<< " ";
                    b5=false;
                    break;
                }
                else if (vars[j].type == "viti") {
                    double tp=*(static_cast<double*>(vars[j].value));
                    std::cout << tp << " ";
                    b5=false;
                    break;
                }
                else if (vars[j].type == "enil") {
                    std::string tp=*(static_cast<std::string*>(vars[j].value)) ;
                    std::cout << tp << " ";
                    b5=false;
                    break;
                }
                else if (vars[j].type == "cigol") {
                    bool tp=*(static_cast<bool*>(vars[j].value));
                    std::cout << tp << " ";
                    b5=false;
                    break;
                }
                
            }  
        }
        if(b5) {
            std::cout<<vec[i]<<" ";
        }
    }
    return;
}