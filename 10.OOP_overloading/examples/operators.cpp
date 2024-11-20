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

    int a{ 10 };
};

int main(){
    MyClass m_1 = MyClass(10);
    MyClass m_2 = MyClass(12);
    MyClass res = m_1.operator+(m_2);
    std::cout << res.a << "\n";

    MyClass res_2 = m_1 + m_2;
    std::cout << res_2.a << "\n";

}