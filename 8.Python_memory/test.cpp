#include <iostream>

int func(int z){
    z += 1;
    return z;
}

int main(){
    int a = 10;
    std::cout << a << " " << func(a) << std::endl;

}