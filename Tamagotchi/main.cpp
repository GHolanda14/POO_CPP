#include "pet.hpp"
#include <iostream>

int main(){
    Pet pet;
    string op;
    
    while(true){
        cin>>op;
        cout<<op<<endl;
        if(op == "end")break;
        if(op == "show"){
            cout<<pet.toString()<<endl;
        }
        else if(pet.isAlive()){
            if(op == "init"){
                int energy,hungry,clean;
                cin>>energy>>hungry>>clean;
                pet = Pet(energy,hungry,clean);
            }
            else if(op == "play"){
                pet.play();
            }
            else if(op == "eat"){
                pet.eat();
            }
            else if(op == "sleep"){
                pet.sleep();
            }
            else if(op == "clean"){
                pet.cleaner();
            }
        }else{
            cout<<"failure: pet esta morto"<<endl;
        }
    }
    return 0;
}