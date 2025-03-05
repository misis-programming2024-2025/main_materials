#include <iostream>
#include <chrono>
#include <utility>
#include <string>

class DynamicArr {
    std::string* data;
    size_t size;

public:
    DynamicArr(size_t s) : size(s), data(new std::string[s]) {
        for (size_t i = 0; i < size; ++i) {
            data[i] = std::string(1000000, 'a'); 
        }
    }

    ~DynamicArr() {
        delete[] data;
    }

    DynamicArr(const DynamicArr& other) : size(other.size), data(new std::string[other.size]) {
        std::cout << "Copying array of " << size << " elements.\n";
        for (size_t i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    DynamicArr(DynamicArr&& other) noexcept : size(other.size), data(other.data) {
        other.data = nullptr;
        std::cout << "Moving array of " << size << " elements.\n";
    }
};


DynamicArr createArray() {
    DynamicArr arr(10000); 
    return arr; 
}

int main() {
    
    auto start = std::chrono::high_resolution_clock::now();
    // copy
    // DynamicArr arr = createArray(); 
    // DynamicArr arr1(arr); 
    auto end = std::chrono::high_resolution_clock::now();
    auto copy_duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Time taken for copy: " << copy_duration << " ms\n";


    start = std::chrono::high_resolution_clock::now();
    // move
    DynamicArr arr_0 = createArray(); 
    DynamicArr arr2(std::move(arr_0));
    end = std::chrono::high_resolution_clock::now();
    auto move_duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Time taken for move: " << move_duration << " ms\n";
}
