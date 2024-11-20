#include <iostream>

int main(){
    // int value;
    // int* ptr;

    // std::cout << value << " " << ptr << "\n";

    int value = 4;
    int* ptr = &value;
    std::cout << value << " " << ptr << "\n";
    std::cout << &value << " " << &ptr << "\n";
    std::cout << sizeof(value) << " " << sizeof(ptr) << "\n";

    // int* p1, p2;
    int* p1;
    int* p2;
    std::cout << sizeof(p1) << " " << sizeof(p2) << "\n";

    // value = 4, ptr = адрес, value = 4
    std::cout << value << " " << ptr << " " << *ptr << "\n";

    int& refValue = value;
    p1 = &value;
    p2 = &refValue;
    std::cout << value << " " << refValue << "\n";
    std::cout << &value << " " << &refValue << "\n";
    std::cout << p1 << " " << p2 << "\n";
    std::cout << *p1 << " " << *p2 << "\n";

    *p2 = 50;
    std::cout << "Change to 50\n";
    std::cout << value << " " << refValue << "\n";
    std::cout << &value << " " << &refValue << "\n";
    std::cout << p1 << " " << p2 << "\n";
    std::cout << *p1 << " " << *p2 << "\n";

    int*& refPtr2 = p2;
    std::cout << (p2 == refPtr2) << "\n";

    *refPtr2 = 80;
    std::cout << "Change to 80\n";
    std::cout << value << " " << refValue << "\n";
    std::cout << &value << " " << &refValue << "\n";
    std::cout << p1 << " " << p2 << "\n";
    std::cout << *p1 << " " << *p2 << "\n";

    int value2 = 13;
    const int* p3 = &value;
    // *p3 = 10; // read-only ERROR
    // value = 10; // read-write OK
    p3 = &value2;

    int* const p4 = &value;
    // p4 = &value2; // read-only ERROR
    *p4 = 87;

    // const pointer to const value
    const int* const cPtr = &value;
    // cPtr = &value2; // read-only ERROR
    // *cPtr = 98; // read-only ERROR

    int value3 = 812;
    int* ptrValue3 = &value3;
    std::cout << ptrValue3 << " " << *ptrValue3 << "\n";
    ptrValue3++;
    std::cout << ptrValue3 << " " << *ptrValue3 << "\n";



    


    
    
}