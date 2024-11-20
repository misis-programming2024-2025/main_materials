#include <iostream>

void func(int array[]){
    std::cout << "From func\n";
    std::cout << sizeof(array) << " " << sizeof(array) / 4 << "\n";

}

// Массив в стиле С не запоминает свой размер
int main(){
    int array[5]{1, 2, 3, 4, 5};
    std::cout << sizeof(array) << " " << sizeof(array) / 4 << "\n";
    func(array);
}