#include <memory>
#include <iostream>

void process(std::unique_ptr<int> ptr) {
    std::cout << &ptr << "\n";
}

int main() {
    std::unique_ptr<int> ptr(new int(42));
    std::cout << &ptr << "\n";
    process(std::move(ptr)); // Передача владения указателем

    return 0;
}
