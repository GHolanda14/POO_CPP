#include <iostream>
#include <sstream>
//#include "pet.hpp"

using namespace std;

class Pet{
    public:
        bool isAlive(){
            return status;
        }
        int getEnergy(){
            return energy;
        }
        int getHungry(){
            return hungry;
        }
        int getClean(){
            return clean;
        }
        int getMaxEnergy(){
            return max_energy;
        }
        int getMaxHungry(){
            return max_hungry;
        }
        int getMaxClean(){
            return max_clean;
        }
        int getDiamonds(){
            return diamonds;
        }
        int getAge(){
            return age;
        }
        void setAlive(bool status){
            this->status = status;
        }
        void setEnergy(int energy){
            this->energy = energy;
        }
        void setHungry(int hungry){
            this->hungry = hungry;
        }
        void setClean(int clean){
            this->clean = clean;
        }
        void setMaxEnergy(int max_energy){
            this->max_energy = max_energy;
        }
        void setMaxHungry(int max_hungry){
            this->max_hungry = max_hungry;
        }
        void setMaxClean(int max_clean){
            this->max_clean = max_clean;
        }
        void setDiamonds(int diamonds){
            this->diamonds = diamonds;
        }
        void setAge(int age){
            this->age = age;
        }
        Pet(int max_energy=0, int max_hungry=0, int max_clean=0){
            setEnergy(max_energy);
            setHungry(max_hungry);
            setClean(max_clean);
            setMaxEnergy(max_energy);
            setMaxHungry(max_hungry);
            setMaxClean(max_clean);
            setDiamonds(0);
            setAge(0);
            setAlive(true);
        }

        string toString(){
            stringstream ss;
            ss<<"E:"<<getEnergy()<<"/"<<getMaxEnergy()<<", ";
            ss<<"H:"<<getHungry()<<"/"<<getMaxHungry()<<", ";
            ss<<"C:"<<getClean()<<"/"<<getMaxClean()<<", ";
            ss<<"D:"<<getDiamonds()<<", A:"<<getAge();

            return ss.str();
        }
        //Com retorno
        /*
        bool analyse(){
            if(getHungry() <= 0){
                setHungry(0);
                cout<<"failure: pet morreu de fome"<<endl;
                setAlive(false);
                return false;
            }
            else if(getClean() <= 0){
                setClean(0);
                cout<<"failure: pet morreu de sujeira"<<endl;
                setAlive(false);
                return false;
            }
            else if(getEnergy() <= 0){
                setEnergy(0);
                cout<<"failure: pet morreu de fraqueza"<<endl;
                setAlive(false);
                return false;
            }
            return true;
        }
        
        bool play(){
            setEnergy(getEnergy()-2);
            setHungry(getHungry()-1);
            setClean(getClean()-3);
            setAge(getAge()+1);
            setDiamonds(getDiamonds()+1);

            if(analyse())return true;
            return false;
        }

        bool eat(){
            setEnergy(getEnergy()-1);
            setClean(getClean()-2);
            setAge(getAge()+1);
            getHungry()+4 > getMaxHungry() ? setHungry(getMaxHungry()) : setHungry(getHungry()+4);
            if(analyse())return true;
            return false;
        }
        bool sleep(){
            if(getEnergy() <= getMaxEnergy()-5){
                setHungry(getHungry()-1);
                setAge(getAge()+(getMaxEnergy()-getEnergy()));
                setEnergy(getMaxEnergy());
                if(analyse())return true;
                return false;
            }
            cout<<"failure: nao esta com sono"<<endl;
            return false;
        }
        bool cleaner(){            
            setHungry(getHungry()-1);
            setEnergy(getEnergy()-3);
            setClean(getMaxClean());
            setAge(getAge()+2);
            if(analyse())return true;
            return false;
        }
        bool revival(){
            setAlive(true);
            setClean(getMaxClean());
            setHungry(getMaxHungry());
            setEnergy(getMaxEnergy());
            return true;
        }
        //*/
        //Sem retorno
        
        void analyse(){
            if(getHungry() <= 0){
                setHungry(0);
                cout<<"failure: pet morreu de fome"<<endl;
                setAlive(false);
            }
            else if(getClean() <= 0){
                setClean(0);
                cout<<"failure: pet morreu de sujeira"<<endl;
                setAlive(false);
            }
            else if(getEnergy() <= 0){
                setEnergy(0);
                cout<<"failure: pet morreu de fraqueza"<<endl;
                setAlive(false);
            }            
        }
        void play(){
            setEnergy(getEnergy()-2);
            setHungry(getHungry()-1);
            setClean(getClean()-3);
            setAge(getAge()+1);
            setDiamonds(getDiamonds()+1);
            analyse();
        }

        void eat(){
            setEnergy(getEnergy()-1);
            setClean(getClean()-2);
            setAge(getAge()+1);
            getHungry()+4 > getMaxHungry() ? setHungry(getMaxHungry()) : setHungry(getHungry()+4);
            analyse();
        }
        void sleep(){
            if(getEnergy() <= getMaxEnergy()-5){
                setHungry(getHungry()-1);
                setAge(getAge()+(getMaxEnergy()-getEnergy()));
                setEnergy(getMaxEnergy());
                analyse();
            }else{
                cout<<"failure: nao esta com sono"<<endl;
            }
        }
        void cleaner(){            
            setHungry(getHungry()-1);
            setEnergy(getEnergy()-3);
            setClean(getMaxClean());
            setAge(getAge()+2);
            analyse();
        }
        void revival(){
            setAlive(true);
            setClean(getMaxClean());
            setHungry(getMaxHungry());
            setEnergy(getMaxEnergy());
        }
        //*/
        
    private:
        bool status;
        int hungry;
        int energy;
        int clean;
        int max_hungry;
        int max_energy;
        int max_clean;
        int diamonds;
        int age;
};

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
        else if(op == "revival"){
            pet.revival();
        }
        else if(pet.isAlive()){
            if(op == "init"){
                int energy,hungry,clean;
                cin>>energy>>hungry>>clean;
                //cout<<energy<<" "<<hungry<<" "<<clean<<endl;
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