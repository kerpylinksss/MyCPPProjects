#include <iostream>
#include <string>

using namespace std;

class Critter {
    public:
        Critter(int hunger = 0, int boredom = 0);
        void Talk();
        void Eat(int food = 4);
        void Play(int fun = 4);
    private:
        int mHunger;
        int mBoredom;
        int GetMood() const;
        void PassTime(int time = 1);
};

Critter::Critter(int hunger, int boredom):
    mHunger(hunger),
    mBoredom(boredom)
    {}

inline int Critter::GetMood() const{
    return(mHunger + mBoredom);
}

void Critter::PassTime(int time){
    mHunger += time;
    mBoredom += time;
}

void Critter::Talk(){
    cout << "Hello, I feel ";
    int mood = GetMood();
    if (mood > 15) {
        cout << "mad.\n";
    }
    else if(mood > 10){
        cout << "frustrated.\n";
    }
    else if(mood > 5) {
        cout << "happy.\n";
    }
    else{
        cout << "ok.\n";
    }
    PassTime();
}

void Critter::Eat(int food){
    cout << "Brrruupp!\n";
    mHunger -= food;
    if (mHunger < 0){
        mHunger = 0;
    }
    PassTime();
}

void Critter::Play(int fun){
    cout << "Whee!\n";
    mBoredom -= fun;
    if(mBoredom < 0){
        mBoredom = 0;
    }
    PassTime();
}

int main(){
    Critter crit;
    crit.Talk();
    int choice;
    do{
        cout << "\nCritter caretaker\n\n";
        cout << "0 - quit\n";
        cout << "1 - listen to your critter\n";
        cout << "2 - feed your critter\n";
        cout << "3 - play with your critter\n\n";
        cout << "Choice: ";
        cin >> choice;
        switch(choice){
            case 0:
                cout << "Good bye!\n";
                break;
            case 1:
                crit.Talk();
                break;
            case 2:
                crit.Eat();
                break;
            case 3:
                crit.Play();
                break;
            default:
                cout << "\nSorry, but it's not a valid choice!\n\n";
        }  
    }while(choice != 0);
    

    return 0;
}