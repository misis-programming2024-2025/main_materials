# Еще раз о комплексных числах и структуре, сборке репозитория

## Ошибки и неточности в выполнении домашнего задания:

1. Структура проекта 

2. Загрузка на гит ненужных файлом/директорих (в том числе отсутствие gitignore)

3. Использование float вместо double

4. Класс написан, но не протестирован (нет int main(){})

5. (*) Отсутствует единый стиль оформления кода 

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
