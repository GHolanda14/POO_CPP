#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

/*
1-Iniciar topique solicitando a lotação maxima
 e a qd de cadeiras preferenciais.
2-SHOW 
    colocar @ nas cadeiras preferenciais
    coloque = na frente das cadeiras normais
3-IN
    informar id e idade
        se idoso (){
            se houver cadeiras prefenrenciais 
                {
                    colocar na primeira cadeira preferencial
                }
            se nao 
                coloque na primeira cadeira normal    
        }else{
            se houver cadeiras normais{
                colocar na primeira
            }
            se nao{
                coloque na primeira preferencial
            }
        }
4- remover passageiros por id

*/
struct Passageiro{
    string nome;
    int idade;

    Passageiro(string nome, int idade){
        this->nome=nome;
        this->idade=idade;
    }
    string toString(){
        stringstream ss;
        ss<<this->nome<<" : "<<this->idade;
        return ss.str();
    }

};
struct Topiq{
    vector<Passageiro*> cadeiras;

    Topiq(int qtd = 0):
        cadeiras(qtd,nullptr)
    {

    }

    ~Topiq(){
        for(Passageiro* passageiro : cadeiras)
            delete(passageiro);
    }

    bool in(Passageiro* passageiro,int lot, int pref){  
        if(passageiro->idade > 60){
            for(int i=0;i<pref;i++){
                if(cadeiras[i]==nullptr){
                    cadeiras[i]=passageiro;
                    return true;
                }
            }
            for(int j=pref;j<lot;j++){
                if((cadeiras[j])==nullptr){
                    cadeiras[j]=passageiro;
                    return true;
                }
            }      
                             
        }    
        else if(passageiro->idade < 60){
            for(int i=pref;i<lot;i++){
                if(cadeiras[i]==nullptr){
                    cadeiras[i]=passageiro;
                    return true;
                }                
            }
             for(int j=0;j<pref;j++){
                if((cadeiras[j])==nullptr){
                    cadeiras[j] ß                                                      =passageiro;
                    return true;
                }
            } 
        }
        cout<<"Topique esta cheia" << endl;
        return false;
    }
    bool out(Passageiro* passageiro,int lot,string name){
        for(int i=0;i<lot;i++){
            if((cadeiras[i]!=nullptr)&&(passageiro->nome==cadeiras[i]->nome)){
                cadeiras[i]=nullptr;
                return true;
            }                
        } 
        cout<<"A pessoa nao esta na topique"<<endl;
    }

    string toString(){
        stringstream ss;
        ss<<"[";

        for(Passageiro* passageiro : cadeiras)
            if(passageiro == nullptr)
                ss<<"-";
            else
                ss<<passageiro->toString()<<" ";
        ss<<"]";
        return ss.str();        
    }    
};

int main(){
    Topiq topiq;
    string op;
    int lot;
    int pref;

    cout<<"Digite a lotação e a qtd de cadeiras preferenciais : " <<endl;
    cin>>lot>>pref;

    while(true){
        cout<<"Digite uma das opções : \n";
        cout<<"\t show \n \t in \n \t out \n \t end \n ";
        cin>>op;

        if(op == "end")
            break;
        if(op == "show"){
            cout << topiq.toString() << endl;
        }else if(op == "in"){
            string nome;
            int idade;
            cout<<"Digite o nome e a idade : " <<endl;
            cin >> nome >> idade;
            if(topiq.in(new Passageiro(nome,idade),lot,pref))
                cout << "done" << endl;
        }else if(op == "out"){
            string nome;
            cout <<"Digite o nome da pessoa que deseja retirar: " <<endl;
            cin>>nome;
           /* if(topiq.out(Passageiro(nome,0),lot,pref)){
                cout<<"done"<<endl;
            }*/    
        }

    }
   
} 
