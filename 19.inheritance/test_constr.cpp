#include <iostream>


class BaseClass {
    public:
        BaseClass() {
            std::cout << "BaseClass constructor\n";
        }
    
        ~BaseClass() {
            std::cout << "BaseClass destructor\n";
        }
    };
    
    
    class DerivedClass : public BaseClass {
    public:
        DerivedClass() {
            std::cout << "DerivedClass constructor\n";
        }
    
        ~DerivedClass() {
            std::cout << "DerivedClass destructor\n";
        }
    };
    
    int main() {
        {
            DerivedClass derivedObj;
        }
    }

