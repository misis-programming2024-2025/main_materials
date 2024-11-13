#include <iostream>
#include <string>

class Person {
public:
    // Конструктор
    Person(const std::string& name, int age) : name(name), age(age) {}

    // Метод для отображения информации о человеке
    void displayInfo() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }

private:
    std::string name; // Член данных
    int age;          // Член данных
};

struct OurDataType {
    int number = 10;

    int addNumber(int new_value){
        return this->number += new_value;
    }
};

class OurDataTypeClass {
  private:
    int number = 10;

  public:

    //конструктор
    OurDataTypeClass(int value){
        this->number = value;
    }

    // OurDataTypeClass(int value)
    //     : number(value)
    // {}

    // конструктор копирования + список инициализации
    OurDataTypeClass(const OurDataTypeClass& other)
        : number(other.number)
    {}
    
    int addNumber(int new_value){
        return this->number += new_value;
    }

    //геттер
    int getNumber(){
        return this->number;
    }

    //сеттер
    void setNumber(int new_value){
        this->number = new_value;
    }
};

int main() {
    Person person("Alice", 30);
    person.displayInfo(); // Вывод: Name: Alice, Age: 30
    // std::string new_name = person.name;

    OurDataType data_type;
    std::cout << data_type.number << std::endl;
    std::cout << data_type.addNumber(20) << std::endl;

    OurDataTypeClass data_type_cl(45);
    std::cout << data_type_cl.getNumber() << std::endl;
    // std::cout << data_type_cl.number << std::endl;
    std::cout << data_type_cl.addNumber(20) << std::endl;
    std::cout << data_type_cl.getNumber() << std::endl;
}