#include <iostream>
#include <string>

using namespace std;

class Pessoa{
    public:
        int idade;
        Pessoa(){
            idade = 19;
        }
         toString(){

        }
};

int main(){
    Pessoa p[3];
    p[0].idade = 18;
    
    p[1].idade = 13;

    p[2].idade = 12;

    for(int i = 0; i < 3;i++){
        p[i].toString(p[i]);
    }
    return 0;
}