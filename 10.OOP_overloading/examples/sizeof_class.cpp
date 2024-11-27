#include <iostream>

class A {
    int a;        // 4 байта
    char c;       // 1 байт
    double b;     // 8 байт
};

class B
{
    //поля
    char m_c; // 1
    int m_n; // 4
    bool m_b; // 1
    double m_d; // 8

    void print(){
        std::cout << this->m_b;
    }
    
};

// Здесь выделится меньше памяти
class C
{
    //поля
    double m_d;
    int m_n;
    char m_c;
    bool m_b;
    
};


int main(){
    std::cout << sizeof(A) << "\n";
    std::cout << sizeof(B) << "\n";
    std::cout << sizeof(C) << "\n";

}