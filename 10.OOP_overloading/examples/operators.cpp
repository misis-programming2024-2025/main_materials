#include <iostream>

class MyClass{
  public:
    MyClass() = default;

    MyClass(int a){
        this->a = a;
    }

    MyClass operator+(MyClass& other){
        std::cout << "Calling operator +\n";
        MyClass my_class = MyClass();
        my_class.a = this->a + other.a;
        return my_class;
    }

    MyClass operator+(int value){
        std::cout << "Calling operator + with int value\n";
        MyClass my_class = MyClass();
        my_class.a = this->a + value;
        return my_class;
    }

    int a{ 10 };
};

MyClass operator-(MyClass& lhs, MyClass& rhs) {
    std::cout << "Calling operator - from outside\n";
    MyClass my_class = MyClass();
    my_class.a = lhs.a - rhs.a;
    return my_class;
}

int main(){
    MyClass m_1 = MyClass(10);
    MyClass m_2 = MyClass(12);
    MyClass res = m_1.operator+(m_2);
    std::cout << res.a << "\n";

    MyClass res_2 = m_1 + m_2;
    std::cout << res_2.a << "\n";

    MyClass res_3 = m_1 - m_2;
    std::cout << res_3.a << "\n";
    
    int a = 10;
    MyClass res_4 = m_1 + a;
    std::cout << res_4.a << "\n";

}