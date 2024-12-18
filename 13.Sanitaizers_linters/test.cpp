// Copyright 2024 MISIS
#include <iostream>

int main() {
    int* ptr = new int;
    *ptr = 10;
    delete ptr;
    return 0;
}
