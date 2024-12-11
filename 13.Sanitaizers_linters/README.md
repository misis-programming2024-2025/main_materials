# Санитайзеры и линтеры

## Sanitizing

Санитайзеры (Sanitizers) - это инструменты для статического или динамического анализа программного обеспечения, которые помогают обнаруживать и предотвращать различные виды ошибок в коде, такие как переполнение буфера, утечки памяти, неопределенное поведение и другие. 

[Санитайзеры компилятора clang](https://skkv-itmo.gitbook.io/ct-c-cpp-course/code-analysis/sanitizer)

```bash
clang++ -fsanitize=memory -fno-omit-frame-pointer -g test.cpp -o main -lstdc++
```

```bash
-fsanitize=memory # в этом параметре перечисляются санитайзеры
-fsanitize=address # AddressSanitizer – детектор ошибок при работе с адресацией (выход за границы выделенной области памяти, стека, двойное высвобождение памяти и другое)
-fsanitize=memory # MemorySanitizer – детектор чтения из неинициализированной области памяти
-fsanitize=undefined # UndefinedBehaviorSanitizer – детектор специфических ошибок, чаще всего регламентированных в стандарте как Undefined Behavior
-fsanitize=leak # LeakSanitizer – детектор утечки (не освобождаемой) памяти.
-fsanitize=thread # ThreadSanitizer – детектор ошибок при взаимодействиями между потоками (data race)
```

Утечки памяти - то, за чем очень важно следить  !!!
* [Microsoft: 70 percent of all security bugs are memory safety issues ](https://www.zdnet.com/article/microsoft-70-percent-of-all-security-bugs-are-memory-safety-issues/)
* [Chrome: 70% of all security bugs are memory safety issues ](https://www.zdnet.com/article/chrome-70-of-all-security-bugs-are-memory-safety-issues/)


Проблемы с памятью:

1. **Переполнение буфера (Buffer Overflow)**: Нарушение целостности данных, когда данные записываются за пределы выделенной области памяти, что может привести к перезаписи других данных или даже выполнению вредоносного кода.


```cpp
#include <iostream>
#include <cstring>

int main() {
    char buffer[5];
    strcpy(buffer, "Hello, World!"); // переполнение буфера
    std::cout << buffer << std::endl;
}
```

2. **Отказ страницы (Page Fault)**: Ошибка, возникающая при попытке доступа к физической памяти, которая не загружена в оперативную память, часто вызванная неправильным обращением к адресам памяти.

```cpp
#include <iostream>

int main() {
    int* ptr = nullptr;
    std::cout << *ptr << std::endl; // доступ к нулевому указателю
    return 0;
}
```


3.  **Использование после освобождения (Use-After-Free)**: Ситуация, когда программа обращается к памяти, которая уже была освобождена, что может привести к ошибкам или некорректному поведению.

```cpp
#include <iostream>

int main() {
    int* ptr = new int;
    delete ptr;
    *ptr = 10; // использование освобожденной памяти
    return 0;
}
```

4. **Двойное освобождение (Double Free)**: Ошибка, возникающая при повторном освобождении уже освобожденной памяти, что может привести к нарушению структуры управления памятью и аварийному завершению программы.

```cpp
#include <iostream>

int main() {
    int* ptr = new int;
    delete ptr;
    delete ptr; // повторное освобождение памяти
    return 0;
}
```
5. **Утечка памяти**

```cpp
#include <iostream>

int main() {
    int* ptr = new int; // Выделение памяти
    return 0; // Утечка памяти, так как не было освобождения выделенной памяти
}

```

6. **Гонка за данными (Race Condition)** - Несогласованность взаимодействия нескольких потоков, что приводит к непредсказуемому поведению программы и возможно к сбоям или утечкам данных.

```cpp
#include <iostream>
#include <thread>

int counter = 0;

void increment() {
    for (int i = 0; i < 1000000; ++i) {
        counter++;
    }
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);
    t1.join();
    t2.join();
    std::cout << "Counter: " << counter << std::endl;
    return 0;
}
```

## Linting

**Линтеры** - это инструменты статического анализа кода, которые проверяют исходный код на соответствие определенным стандартам кодирования, правилам форматирования и лучшим практикам программирования. Они помогают обнаруживать потенциальные проблемы, ошибки и уязвимости на ранних этапах разработки.


[Clang-tidy](https://clang.llvm.org/extra/clang-tidy/)
[Cpplint (Google Style Guide)](https://github.com/cpplint/cpplint)

### Cpplint как использовать

* Установка
```bash
$ pip install cpplint
```

* Анализ .cpp кода. Здесь files это .cpp
```bash
$ cpplint [OPTIONS] files
```

Можно езе сразу скрипт `cpplint.py` скачать, и запустить с аналогичными параметрами - путь до файла .cpp и опции
```bash
python cpplint.py test.cpp 
```


## <a id="oop3"></a>[Google style guide](https://google.github.io/styleguide/cppguide.html)

Например, рекомендации по пробелам горизонтальным
```cpp
int i = 0;  // Two spaces before end-of-line comments.

void f(bool b) {  // Open braces should always have a space before them.
  ...
int i = 0;  // Semicolons usually have no space before them.
// Spaces inside braces for braced-init-list are optional.  If you use them,
// put them on both sides!
int x[] = { 0 };
int x[] = {0};

// Spaces around the colon in inheritance and initializer lists.
class Foo : public Bar {
 public:
  // For inline function implementations, put spaces between the braces
  // and the implementation itself.
  Foo(int b) : Bar(), baz_(b) {}  // No spaces inside empty braces.
  void Reset() { baz_ = 0; }  // Spaces separating braces from implementation.
  ...
```
Некоторые разделы styleguide:
* https://google.github.io/styleguide/cppguide.html#General_Naming_Rules
* https://google.github.io/styleguide/cppguide.html#Implementation_Comment_Donts

Each line of text in your code should be at most 80 characters long.
