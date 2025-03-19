#include <iostream>

// Базовый класс
class BaseClass {
    private:
        int privateInt;
    
    public:
        BaseClass() : privateInt(0) {}
    
        void setPrivateInt(int value) {
            privateInt = value;
        }
        int getPrivateInt() {
            return privateInt;
        }
    };
    
    // Производный класс
    class DerivedClass : public BaseClass {
    public:
        void modifyPrivateInt() {
            // напрямую не изменить значение приватного поля
            setPrivateInt(42);
        }
    };
    
    int main() {
        DerivedClass derivedObj;
        
        std::cout << "Before: " << derivedObj.getPrivateInt() << std::endl;
        // std::cout << derivedObj.privateInt; // Ошибка компиляции
    
        derivedObj.modifyPrivateInt();
        
        std::cout << "After: " << derivedObj.getPrivateInt() << std::endl;
        
        
        derivedObj.setPrivateInt(57);
        // derivedObj.privateInt = 8;

        std::cout << "After: " << derivedObj.getPrivateInt() << std::endl;
        return 0;
    }