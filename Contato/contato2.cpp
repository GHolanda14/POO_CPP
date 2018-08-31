#include <iostream>
#include <vector>
#include <sstream>

struct Fone{
    string id;
    string fone;
    Fone(string id = "", string fone=""){
        this->id = id;
        this->fone = fone;
    }

};

struct Contato{
    string id;
    Contato(string id = "Ze mane"){
        id(id);
    }
    string toString(){
        stringstream ss;
        ss<<id<<":";

        for(auto fone : fones){
            ss<<fone.toString();
        }

        return ss.str();
    }
};

struct Controller{
    Contato cont;

    string shell(string line){
        stringstream in(line);
        stringstream out;

        string op;

    }

    void exec(){
        string line;
        while(true){
            getline(cin,line);
            if(line == "end"){
                break;
            }
            cout<< " " << shel(line) <<endl;
        }
    }
};

int main(){
    Controller controller;
    controller.exec();
    return 0;
}