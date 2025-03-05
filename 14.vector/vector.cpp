#include <initializer_list>
#include <cstdint>
#include <algorithm>
#include <iostream>

class DynamicArray {
    public:
        DynamicArray(int64_t size = 0, int value = 0);

        // {1, 2, 3, 4, 5}
        DynamicArray(const std::initializer_list<int>& list);

        DynamicArray(const DynamicArray& other);
        ~DynamicArray();

        // геттеры
        int64_t Size() const;
        int64_t Capacity() const;
        bool empty() const; 

        void push_back(int value); 
        void pop_back(); 
        void clear(); 
        void erase(int64_t index);
        // 1, 2, 3 -> 1, 2, 3, 0 ,0,
        // [1, 2, 3, 4,] 5, 6 -> 1, 2, 3, 4, 0, 0
        void resize(int64_t new_size); 
        // 1, 2, 3 -> value, value, value, value, 
        void assign(int64_t new_size, int value); 
        // 1, 2, 3,  -> 1, value, 2, 3, 
        void insert(int64_t index, const int value); 

        void swap(DynamicArray& other); 

        int* begin();
        int* end();

        int& at(int64_t i) const; 
        int& operator[](int64_t i) const; 

        DynamicArray& operator=(const DynamicArray& rhs); 

        // size == и все элементы, не capacity
        bool operator==(const DynamicArray& rhs) const;
        bool operator!=(const DynamicArray& rhs) const;
    private:
        int64_t size = 0;
        int64_t capacity = 0;
        int* data = nullptr;
}; 


int main(){
    int size = 10;
    int capacity = 10;
    int* data = new int[20];
    // data[0] = 10;
    for (int i = 0; i < 20; i++){
        data[i] = 15;
    }
    int* other = new int[10];
    for (int i = 0; i < 10; i++){
        other[i] = 89;
    }
    // other[8] = 6;
    // std::copy(other, other + capacity, data);
    int* temp = other;
    other = data;
    data = temp;
    for (int i = 0; i < 20; i++){
        std::cout << data[i] << " ";
    }
    std::cout << "\n";
    for (int i = 0; i < 20; i++){
        std::cout << other[i] << " ";
    }
    // std::cout << "\n";
    // for (int i = 0; i < 20; i++){
    //     std::cout << temp[i] << " ";
    // }
    std::cout << "\n";
    int* new_data = new int[5];
    std::cout << new_data[10];
    std::cout << "\n";
    std::cout << &temp << " " << &new_data;
    std::cout << "\n";
    int* el = new int[2];
    el[1] = 10;
    int* new_data_2 = new int[4];
    new_data_2[0] = 16;
    std::cout << el[2];
    std::cout << "\n";
    std::cout << &el << " " << &new_data_2;



}