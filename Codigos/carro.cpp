#include <iostream>
#include <sstream>

using namespace std;

struct Carro{
	public:
		float tanque;
		int qnt_pessoas,max_pess, max_l;
		float km;

		Carro(float tanque = 0, int qnt_pessoas = 0, float km = 0,int max_l = 10,int max_pess = 2){
			this->tanque = tanque;
			this->qnt_pessoas = qnt_pessoas;
			this->km = km;
			this->max_l = max_l;
			this->max_pess = max_pess;
		}
		
		string toString(){
			stringstream ss;

			ss<<"pass: "<<qnt_pessoas<<", gas: "<<tanque<<", km: "<<km;

			return ss.str();
		}

		bool embarcar(){
			if(qnt_pessoas < max_pess){
				qnt_pessoas++;
				return true;
			}
			cout<<"fail: limite de pessoas atingido"<<endl;
			return false;
		}

		bool desembarcar(){
			if(qnt_pessoas>0){
				qnt_pessoas--;
				return true;
			}
			cout<<"fail: carro vazio"<<endl;
			return false;
		}

		void fuel(int qnt){
			tanque += max_l;
			tanque = (tanque > max_l) ? max_l : tanque
			cout<<"done"<<endl;
		}

		bool drive(int qnt){
			if(qnt_pessoas > 0){
				if(tanque - (qnt/10) >= 0){
					tanque -= qnt/10;
					km += qnt;
					return true;
				}
				else{
					cout<<"fail: gasolina insuficiente"<<endl;
					return false;
				}
			}
			cout<<"fail: nao ha ninguem no carro"<<endl;
			return false;
		}
};


int main(){
	string op;
	Carro carro;

	while(true){
		cin>>op;

		if(op == "help"){
			puts("in,out,show,drive,fuel");
		}
		else if(op == "show"){
			cout<<carro.toString()<<endl;;
		}
		else if(op == "in"){
			if(carro.embarcar()){
				cout<<"done"<<endl;
			}
		}
		else if(op == "out"){
			if(carro.desembarcar()){
				cout<<"done"<<endl;
			}
		}
		else if(op == "fuel"){
			int km;
			cin>>km;
			carro.fuel(km);
		}
		else if(op == "drive"){
			int km;
			cin>>km;
			if(carro.drive(km)){
				cout<<"done"<<endl;
			}
		}
		else{
			break;
		}
	}
	return 0;
}