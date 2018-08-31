#include <iostream>
#include <sstream>
#include <vector>
#include <cstring>

using namespace std;

struct Fone{
    string label;
    string numero;

    Fone(string label="",string numero=""){
        this->label = label;
        this->numero = numero;
    }
    string toString(){
        stringstream ss;
        ss<<label<<":"<<numero;
        return ss.str();
    }
};

struct Contato{
    string nome;
    vector<Fone> fones;

    Contato(string nome = "vazio"){
        this->nome = nome;
    }

    string toString(){
        stringstream ss;
        
        ss<<nome<<"=>";
        for(int i = 0; i < (int) fones.size();i++){
            ss<<"["<<i<<":"<<fones[i].toString()<<"]";
        }
        return ss.str();
    }

    bool addFone(Fone fone){
        fones.push_back(fone);
        return true;
    }

    bool rmFone(int n){
        for(int i = 0; i< (int) fones.size();i++){
            if(i == n){
                fones.erase(fones.begin()+i);
                return true;
            }
        }
        cout<<"failure: indice nao encontrado"<<endl;
        return false;
    }
};

int main(){
    Contato contato;
    string op;
    string txt;

    while(true){
        getline(cin,txt);
        stringstream ss(txt);

        getline(ss,op,' ');
        if(op == "help"){
            cout<<"nome show add rm update"<<endl;
        }
        else if(op == "show"){
            cout<<contato.toString()<<endl;
        }
        else if(op == "nome"){
            string nome;
            ss>>nome;

            contato = Contato(nome);
            cout<<"success"<<endl;
        }
        else if(op == "add"){
            string numero, label;
            ss>>label>>numero;

            if(contato.addFone(Fone(label,numero))) cout<<"success"<<endl;
        }
        else if(op == "rm"){
            int n;
            ss>>n;

            if(contato.rmFone(n))cout<<"success"<<endl;
        }
        else if(op == "update"){
            string label,numero;
            contato.fones.clear();
            string txt;
            while(ss>>txt){
                getline(ss,txt,' ');
                stringstream a(txt);
                getline(a,label,':');
                ss>>numero;

                contato.addFone(Fone(label,numero));
            }
        }
    }

    return 0;
}