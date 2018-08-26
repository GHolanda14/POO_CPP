#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct Telefone{
	string id;
	int numero;

	Telefone(string id,int numero){
		this->id = id;
		this->numero = numero;
	}

	string toString(){
		stringstream ss;
		
		ss<<"["<<id<<":"<<numero<<"]";

		return ss.str();
	}
};

struct Contato{
	public:
		string nome;
		vector<Telefone> telefones;

		Contato(string nome){
			this->nome = nome;
		}

		string toString(){
			stringstream ss;
			int qnt = telefones.size();
			
			for(int i = 0; i < qnt;i++){
				ss<<telefones[i].toString();
			}
			ss<<endl;
			return ss.str();
		}

		bool verifica(int ind,vector<Contato> contato,Telefone telefone){
			for(Telefone t : contato[ind].telefones){
				if(t.id == telefone.id){
					cout<<"fail: fone "<<t.id<<" ja existe para "<<contato[ind].nome<<endl;
					return false;
				}
			}
			return true;	
		}

		Contato addFone(int ind,vector<Contato> contato,Telefone telefone){
			if(contato[ind].verifica(ind,contato,telefone)){
				contato[ind].telefones.push_back(telefone);
			}
			return contato[ind];
		}

		Contato rmFone(int ind,vector<Contato> contato,string id){
			int qnt = contato[ind].telefones.size();
			bool existe = false;
			for(int i = 0;i < qnt; i++){
				if(contato[ind].telefones[i].id == id){
					existe = true;
					contato[ind].telefones.erase(contato[ind].telefones.begin() +i);
					cout<<"done"<<endl;
				}
			}
			
			if(!existe){
				cout<<"fail: fone "<<id<<"nao existe"<<endl;
			}
			
			return contato[ind];
		}
};

bool existe(string nome,vector<Contato> contato){
	for(int i = 0; i < (int) contato.size();i++){
		if(contato[i].nome == nome){
			return true;
		}
	}
	return false;
}

vector<string> split(string str, char delimiter = ' ')
{
    vector<string> ret;

    int start = 0;

    for(int i = 0; i < str.length(); ++i) {
        if(str[i] == delimiter) {
            ret.push_back(str.substr(start, i-start));
            start = i+1;
        }
    }

    ret.push_back(str.substr(start, start - str.length()));

    return ret;
}

int main(){
	vector<Contato> contatos;
	string txt,nome,op,id;
	int numero;

	while(true){
		getline(cin,txt);

		stringstream ss(txt);

		getline(ss,op,' ');
		if(op == "update"){
			ss>>nome;
			vector<string> v = split(ss.str(),' ');
			for(int i = 2; i < v.size();i++){
				stringstream s(v[i]);
				getline(s,id,':');
				s>>numero;	
			}

		}else{
			nome = "";
			numero = 0;
			id = "";
			ss>>nome>>id>>numero;

			if(op == "help"){
				cout<<"show init addFone rmFone update"<<endl;
			}

			else if(op == "show"){
				int qnt = contatos.size();
				
				for(int i = 0; i < qnt;i++){
					if(nome != ""){
						if(existe(nome,contatos)){
							if(nome == contatos[i].nome){
								cout<<contatos[i].toString();
								break;
							}
						}
						else{
							cout<<"fail: contato nao encontrado"<<endl;
						}
					}
					else{
						cout<<contatos[i].nome<<" ";
						cout<<contatos[i].toString();
					}
				}
			}
			
			else if(op == "init"){
				int qnt = contatos.size();
				if(!existe(nome,contatos)){
					contatos.push_back(Contato(nome));
					cout<<"done"<<endl;
				}
				else{
					cout<<"fail: usuario ja agendado"<<endl;
				}
			}

			else if(op == "addFone"){
				if(existe(nome,contatos)){
					for(int i = 0; i < (int) contatos.size();i++){
						if(nome == contatos[i].nome){
							if(id != "" && numero != 0){
								if(contatos[i].verifica(i,contatos,(Telefone(id,numero)))){
									contatos[i] = contatos[i].addFone(i,contatos,(Telefone(id,numero)));
									cout<<"done"<<endl;
								}
							}else{
								cout<<"fail: informacoes incompletas"<<endl;
							}
						}
					}
				}else{
					cout<<"fail: contato nao encontrado"<<endl;
				}
			}

			else if(op == "rmFone"){			
				if(existe(nome,contatos)){
					for(int i = 0; i < (int) contatos.size();i++){
						if(nome == contatos[i].nome){
							if(id != ""){
								contatos[i] = contatos[i].rmFone(i,contatos,id);						
							}
							else{
								cout<<"fail: faltam informacoes"<<endl;
							}
						}
					}
				}
				else{
					cout<<"fail: contato nao encontrado"<<endl;
				}
			}
		}
	}

	return 0;
}