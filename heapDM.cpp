#include <iostream>
#include <string>

using namespace std;

class Critter{
    public:
        Critter(const string& name = "", int age = 0);
        ~Critter();
        Critter(const Critter& c);
        Critter& Critter::operator=(const Critter& c);

        void Greet() const;
    private:
        string* m_pName;
        int mAge;
};

Critter::Critter(const string& name, int age){
    cout << "Constructor called\n";
    m_pName = new string(name);
    mAge = age;

}
    
Critter::~Critter(){
    cout << "Destructor called.\n";
    delete m_pName;
}
Critter::Critter(const Critter& c){
    cout << "Copy Constructor called\n";
    m_pName = new string(*(c.m_pName));
    mAge = c.mAge;
}

