#include <iostream>

// С-строки типа char [] хранят последнй элемент \0 
// который указывает на конец строки
int main()
{
    char str[] = "Hello";
    std::cout << str << " \n";

    for (auto el : str)
    {
        std::cout << el << " ";
    }
    std::cout << "\n";

    for (int i = 0; i < sizeof(str); i++)
    {
        if (str[i] == '\0')
        {
            std::cout << "\\0" << " ";
            // std::cout << str[i] << " ";
        }
        else
        {
            std::cout << str[i] << " ";
        }
    }
}