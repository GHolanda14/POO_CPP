#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct Cliente{
	public:
		string nome;
		string fone;
	
	Cliente(string nome = "Xuxa",string fone = "4002-8922"){
		this->nome = nome;
		this->fone = fone;
	}

	string toString(){
		stringstream ss;
		ss<<this->nome<<":"<<this->fone;
		return ss.str();
	}
};

struct Sala{
	vector<Cliente*> cadeiras;

    Sala(int qtd = 0):
        cadeiras(qtd,nullptr)
	{
	}

	~Sala(){
    	for(Cliente * cli : cadeiras)
        	delete(cli);
	}

    bool reservar(Cliente * cliente, int ind){
    	int qnt = cadeiras.size();

    	if((ind < 0) || (ind >= qnt)){
    		cout<<"fail: essa cadeira nao existe"<<endl;
    		return false;
    	}
    	if(cadeiras[ind] != nullptr){
    		cout<<"fail: essa cadeira ja esta ocupada"<<endl;
    		return false;
    	}
    	for(int i = 0; i < qnt;i++){
    		if(cadeiras[i] != nullptr && (cadeiras[i]->nome == cliente->nome)){
    			cout<<"fail: voce ja esta no cinema"<<endl;
    			return false;
    		}
    	}
    	cadeiras[ind] = cliente;
    	return true;
    }

    bool cancelar(string nome){
    	int qnt = cadeiras.size();

    	for(int i = 0; i < qnt; i++){
    		if(cadeiras[i]->nome == nome){
    			cadeiras[i] = nullptr;
    			return true;
    		}
    	}
    	cout<<"fail: voce nao esta no cinema"<<endl;
    	return false;
    }

    string toString(){
        stringstream ss;
        ss << "[";
        for(Cliente * cliente : cadeiras)
			if(cliente == nullptr)
				ss<<"-";
			else
            	ss << cliente->toString() << " ";
        ss << "]";
        return ss.str();
    }

};

int main(){
	Sala sala;
	string op;

	while(true){
		cin>>op;

		if(op == "help"){
			cout<<"show init reservar cancelar"<<endl;
		}
		else if(op == "show"){
			cout<<sala.toString()<<endl;
		}
		else if(op == "init"){
			int qnt;
			cin>>qnt;

			sala = Sala(qnt);
			cout<<"sala criada com "<<qnt<<" cadeiras"<<endl;;
		}
		else if(op == "reservar"){
			string nome,fone;
			int ind;
			cin>>nome>>fone>>ind;
			if(sala.reservar(new Cliente(nome,fone),ind))
				cout<<"done"<<endl;
		}
		else if(op == "cancelar"){
			string nome;
			cin>>nome;
			if(sala.cancelar(nome))
				cout<<"done"<<endl;
		}
	}

	return 0;
}
