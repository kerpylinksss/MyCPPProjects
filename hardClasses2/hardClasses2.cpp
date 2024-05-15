#include <iostream>
#include <string>


using namespace std;


class Critter{
    friend void Peek(const Critter& aCritter);
    friend ostream& operator << (ostream& os, const Critter& aCritter); 
    public:
        Critter(const string& name = "");
    private:
        string mName;
};

Critter::Critter(const string& name):
    mName(name)
    {}





void Peek(const Critter& aCritter);
    
ostream& operator << (ostream& os, const Critter& aCritter);

int main(){
    Critter crit("Poohie");

    cout << "Calling Peek() to access the crit's private data member, mName:\n";

    Peek(crit);
    cout << "\nSending crit object to cout with the << operator: \n";
    cout << crit;
    return 0;
}

void Peek(const Critter& aCritter){
    cout << aCritter.mName << endl;
}

ostream& operator << (ostream& os, const Critter& aCritter){

    os << "Critter object - ";
    os << "mName: " << aCritter.mName;
    return os;

}
