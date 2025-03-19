#include <iostream>

class IBase {
    public:
        virtual void foo() = 0;
        virtual ~IBase() {
            std::cout << "Base destructor\n";
        }
    };
    
    
class Derived : public IBase {
    public:
        ~Derived() {
            std::cout << "Derived destructor\n";
        }
        void foo(){
            std::cout << "Derived func\n";
        }
    };
    
int main() {
    IBase *basePtr = new Derived; 
    delete basePtr; 
}