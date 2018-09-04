#include <iostream>
#include <sstream>
#include <vector>

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
    bool validate(string num){
        string valido = "0123456789().";
        int i;
        for(char n : num){            
            for(i = 0; i < (int) valido.size();i++){
                if(n == valido[i]){
                    break;
                }
            }
            if(i == (int)valido.size()){
                return false;
            }
        }
        return true;
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
        if(fone.validate(fone.numero)){
            fones.push_back(fone);
            return true;
        }
        return false;
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
    
    bool upFone(string t){
        stringstream ss(t);
        string label,numero;
        fones.clear();
        string txt;
        Fone fone;
        while(ss>>txt){ 
            stringstream a(txt);
            getline(a,label,':');
            getline(a,numero,' ');
            if(fone.validate(numero)){
                addFone(Fone(label,numero));
            }
        }
        return true;
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
        cout<<op<<endl;
        if(op == "end"){
            break;
        }
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
            else cout<<"failure: fone invalido"<<endl;
        }
        else if(op == "rm"){
            int n;
            ss>>n;
            if(contato.rmFone(n))cout<<"success"<<endl;
        }
        else if(op == "update"){
            string nome;
            ss>>nome;
            contato = Contato(nome);
            
            string txt;
            getline(ss,txt);
            if(contato.upFone(txt))cout<<"success"<<endl;
        }
    }

    return 0;
}