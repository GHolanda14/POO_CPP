#include <iostream>
#include <sstream>

using namespace std;

struct Carro{
	public:
		float tanque;
		int qnt_pessoas,max_pess = 2, max_l = 10;
		float km;

		Carro(float tanque = 0, int qnt_pessoas = 0, float km = 0){
			this->tanque = tanque;
			this->qnt_pessoas = qnt_pessoas;
			this->km = km;
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
			if(tanque+qnt > max_l){
				tanque = max_l;
			}else{
				tanque += qnt;
			}
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
	Carro c;

	while(true){
		cin>>op;

		if(op == "help"){
			puts("in,out,show,drive,fuel");
		}
		else if(op == "show"){
			cout<<c.toString()<<endl;;
		}
		else if(op == "in"){
			if(c.embarcar()){
				cout<<"done"<<endl;
			}
		}
		else if(op == "out"){
			if(c.desembarcar()){
				cout<<"done"<<endl;
			}
		}
		else if(op == "fuel"){
			int qnt;
			cin>>qnt;
			c.fuel(qnt);
		}
		else if(op == "drive"){
			int qnt;
			cin>>qnt;
			if(c.drive(qnt)){
				cout<<"done"<<endl;
			}
		}
		else{
			break;
		}
	}

	return 0;
}