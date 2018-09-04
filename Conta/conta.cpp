#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

struct Operacao{
    int indice;
    string descricao;
    float valor;
    float saldo;

    Operacao(int indice = 0,string descricao="",float valor=0,float saldo=0){
        this->indice = indice;
        this->descricao = descricao;
        this->valor = valor;
        this->saldo = saldo;
    }
    string toString(){
        stringstream ss;
        ss<<indice<<":"<<descricao<<":"<<valor<<":"<<saldo;
        return ss.str();
    }
};

struct Conta{
    vector<Operacao> extrato;
    int nextId;
    int numero;
    float saldo;

    string toString(){
        stringstream ss;

        ss<<"conta:"<<numero<<" saldo:"<<saldo;

        return ss.str();
    }

    Conta(int num = 0, float saldo = 0,int nextId = 0){
        numero = num;
        this->saldo = saldo;
        this->nextId = nextId;
    }

    bool creditar(string label, float valor){
        if(label == "sacar"){
            if(valor > 0){
                if(saldo>=valor){
                    saldo-=valor;
                }else{
                    cout<<"failure: saldo insufisciente"<<endl;
                    return false;
                }
            }else{
                cout<<"failure: valor invalido"<<endl;
                return false;
            }
            return true;
        }
        else if(label == "tarifa"){
            if(valor > 0){
                saldo-=valor;
            }else{
                cout<<"failure: valor invalido"<<endl;
                return false;
            }
            return true;
        }
        return false;
    }

    bool debitar(string label, float valor){
        if(label == "depositar"){
            if(valor > 0){
                saldo+=valor;
            }else{
                cout<<"failure: valor invalido"<<endl;
                return false;
            }
        }
        else if(label == "extornar"){
            int tam = (int)extrato.size();

            if(valor > tam){
                cout<<"failure: indice "<<valor<<" invalido"<<endl;
                return false;
            }
            for(int i = 0;i < tam;i++){
                if(i == valor && extrato[i].descricao == "tarifa"){
                    saldo = saldo + extrato[i].valor*-1;
                    cout<<"success: indice "<<i<<" extornado"<<endl;
                    pushOperation(label,extrato[i].valor*-1,saldo);
                    return true;
                }
                else if(i == valor){
                    cout<<"failure: indice "<<valor<<" nao e tarifa"<<endl;;
                    return false;
                }
            }
        }
        return false;
    }

    void pushOperation(string label, float valor, float saldo){
        if(label == "init"){
            extrato.push_back(Operacao(nextId,"abertura",valor,saldo));
        }
        else if(label == "depositar"){
            extrato.push_back(Operacao(nextId,"deposito",valor,saldo));
        }
        else if(label == "sacar"){
            extrato.push_back(Operacao(nextId,"saque",valor*-1,saldo));
        }
        else if(label == "tarifa"){
            extrato.push_back(Operacao(nextId,"tarifa",valor*-1,saldo));
        }
        else if(label == "extornar"){
            extrato.push_back(Operacao(nextId,"extorno",valor,saldo));
        }
        nextId++;
    }

    vector<Operacao> getExtratoN(int valor){
        vector<Operacao> op;
        int tam = (int)extrato.size();
        for(int i = 0;valor >0;i++){
            if(i+valor == tam){
                op.push_back(extrato[i]);
                valor--;
            }
        }
        return op;
    }
};

int main(){
    Conta conta;
    string txt,op;
    float valor;
    while(true){
        getline(cin,txt);
        stringstream ss(txt);
        getline(ss,op,' ');
        cout<<op<<endl;
        ss>>valor;

        if(op == "end"){
            break;
        }
        if(op == "help"){
            cout<<"init show deposito tarifa saque extrato"<<endl;
        }
        else if(op == "show"){
            cout<<conta.toString()<<endl;
        }
        else if(op == "init"){
            conta = Conta(valor);
            conta.pushOperation(op,0,0);
            cout<<"success"<<endl;
        }
        else if(op == "depositar"){
            if(conta.debitar(op,valor)){
                conta.pushOperation(op,valor,conta.saldo);
                cout<<"success"<<endl;
            }
        }
        else if(op == "sacar"){
            if(conta.creditar(op,valor)){
                conta.pushOperation(op,valor,conta.saldo);
                cout<<"success"<<endl;
            }
        }
        else if(op == "tarifa"){
            if(conta.creditar(op,valor)){
                conta.pushOperation(op,valor,conta.saldo);
                cout<<"success"<<endl;
            }
        }
        else if(op == "extrato"){
            for(Operacao ext : conta.extrato)
                cout<<ext.toString()<<endl;
        }
        else if(op == "extratoN"){
            vector<Operacao> p = conta.getExtratoN(valor);
            for(Operacao ext : p)
                cout<<ext.toString()<<endl;
        }
        else if(op == "extornar"){
            conta.debitar(op,valor);
            while(ss>>valor){
                conta.debitar(op,valor);
            }
        }
        /*else if(op == "extornar"){
            if(conta.debitar(op,valor)) conta.pushOperation(op,conta.extrato[valor].valor*-1,conta.saldo);
            while(ss>>valor){
                if(conta.debitar(op,valor)) conta.pushOperation(op,conta.extrato[valor].valor*-1,conta.saldo);
            }
        }*/
    }

}