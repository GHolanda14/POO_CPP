#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

struct Vagao{
	int qnt_max_pass;
	bool existe;
	Vagao(int qnt_max_pass=0,bool existe=true){
		this->qnt_max_pass = qnt_max_pass;
		this->existe = existe;
	}
	
	string toString(){
		stringstream ss;

		if(!existe){
			ss<<"-";
		}
		else{
		}

		return ss.str();
	}
};

struct Trem{
	int qnt_max_vagao;
	vector<Vagao> vagao;

	Trem(int qnt_max_vagao=0){
		this->qnt_max_vagao = qnt_max_vagao;
	}

	string toString(){
		stringstream ss;
		ss<<"[";
		for(Vagao v : vagao){
			ss<<v.toString();
		}
		ss<<"]";
		
		return ss.str();	
	}

	bool addVagao(int qnt){
		int qtd = vagao.size();

		if(qtd < qnt_max_vagao){
			for(int i; i < qnt;i++){
				vagao.push_back(Vagao(qnt,false));
			}
		}
		return true;
	}
};

int main(){
	vector<Trem> trem;
	int j = 0,qnt;
	string op;

	while(true){
		cin>>op;
		if(op == "show"){
			for(Trem t : trem){
				cout<<t.toString();
			}
			cout<<endl;
		}
		else if(op == "init"){
			cin>>qnt;
			j = 0;
			for(int i = 0; i < qnt;i++){
				trem.push_back(Trem(qnt));
			}
			cout<<"done"<<endl;
		}
		else if(op == "nwvag"){
			int qtd;
			cin>>qtd;

			if(j == trem.size()){
				cout<<"fail: limite de vagoes atingido"<<endl;
			}
			else{
				if(trem[j].addVagao(qtd)){
					cout<<"done"<<endl;
					j++;
				}
			}
		}
	}

	return 0;
}