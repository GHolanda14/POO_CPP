#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct Passageiro{
    string id;
    int idade;

    Passageiro(string id, int idade){
        this->id = id;
        this->idade = idade;
    }

    string toString(){
        stringstream ss;
        ss<<id<<":"<<idade;
        return ss.str();
    }

};

struct Topic{
    vector<Passageiro*> cadeiras;
    int qtd;
    int prioridade;

    Topic(int qtd = 0, int prioridade = 0):
        cadeiras(qtd,nullptr)
    {
        this->prioridade = prioridade;
    }

    string toString(){
        stringstream ss;
        int p = 0;
        ss<<"[";
        for(Passageiro * passa : cadeiras){
            if(passa == nullptr){
                if(p < prioridade)
                    ss<<"@ ";
                else
                    ss<<"# ";
            }
            else{
                if(p < prioridade)
                    ss<<"@"<<passa->toString()<<" ";
                else
                    ss<<"#"<<passa->toString()<<" ";
            }
            p++;
        }
        ss<<"]";
        return ss.str();
    }

    bool embarcar(Passageiro * passageiro){
        for(Passageiro * cadeira : cadeiras){
            if(cadeira != nullptr){
                if(passageiro->id = cadeira->id){
                    cout<<"fail: "<<cadeira->id<<" ja esta no trem"<<endl;
                    return false;
                }
            }
        }
        
        int tam = cadeiras.size();

        if((passageiro->idade) < 60){
            bool sem_normal = false;
            for(int i = prioridade; ;i++){
                if(cadeiras[i] == nullptr){
                    cadeiras[i] = passageiro;
                    return true;
                }
                if(i+1 == tam){
                    i = -1;
                    sem_normal = true;
                }
                if(i+1 == prioridade && sem_normal){
                    break;
                }
            }
        }
        else{
            for(int i = 0; i < tam;i++){
                if(cadeiras[i]==nullptr){
                    cadeiras[i] = passageiro;
                    return true;
                }
            }
        }
        cout<<"fail: Topic lotada"<<endl;
        return false;
    }

    bool desembarcar(string id){
        for(int i = 0; i < (int) cadeiras.size();i++){
            if(id == cadeiras[i]->id){
                cadeiras[i] = nullptr;
                return true;
            }
        }
        cout<<id<<" nao esta no trem"<<endl;
        return false;
    }
};

int main(){
    Topic topic;
    string op;

    while(true){
        cin>>op;
        cout<<op<<endl;
        if(op == "fim"){
            break;
        }
        if(op == "show"){
            cout<<topic.toString()<<endl;
        }
        else if(op == "new"){
            int qnt;
            int prioridad;
            cin>>qnt>>prioridad;

            topic = Topic(qnt,prioridad);
            cout<<"done"<<endl;
        }
        else if(op == "in"){
            string id;
            int idade;

            cin>>id>>idade;
            if(topic.embarcar(new Passageiro(id,idade))){
                cout<<"done"<<endl;
            }
        }
        else if(op == "out"){
            string id;

            cin>>id;
            if(topic.desembarcar(id)){
                cout<<"done"<<endl;
            }
        }
    }

    return 0;
}