# Какие бывают тесты для вашего кода? Как писать unit-тесты

## Напоминалка про .gitignore
### Работа с .gitignore
Ясно, что мы хотим хранить только исходный код и ничего другого в репозитории. А что может быть еще? Как минимум, скомпилированные классы и/или файлы, которые создают среды разработки.

Чтобы гит их игнорировал, есть специальный файл, который нужно создать. Делаем это: создаем файл в корне проекта с названием .gitignore, и в этом файле каждая строка будет шаблоном для игнорирования.  

Взято отсюда: [тык посмотреть подробнее](https://javarush.com/groups/posts/2683-nachalo-rabotih-s-git-podrobnihy-gayd-dlja-novichkov)

### Что не пушим на гит:
Папку build не нужно отправлять в репозиторий, если она содержит бинарные файлы. Это антипаттерн, так как бинарные файлы собираются под конкретную архитектуру, и их можно собрать самостоятельно или взять из последнего релиза. 1

Система контроля версий предназначена для того, чтобы хранить историю файлов, а не оперировать ими. 

Иногда может понадобится запушить build, например, собранный код фронтенда - так можно сайт разместить на Github Pages


## 1. Что такое тестирование?

**Тестирование** — это процесс проверки работоспособности программы с целью выявления ошибок и убедиться, что программный продукт соответствует требованиям. Основная задача тестирования — обнаружение дефектов в коде на ранних этапах разработки и предотвращение появления багов в продакшн-среде.

### Виды ошибок, которые можно выявить при тестировании:
- Логические ошибки (некорректные вычисления)
- Ошибки в обработке исключений
- Проблемы с производительностью
- Уязвимости безопасности
- Ошибки интеграции между компонентами

## 2. Зачем нужно тестирование?

- **Обеспечение качества кода**: Автоматические тесты помогают избежать регрессий и ошибок в системе.
- **Ускорение разработки**: Быстрая проверка работоспособности кода снижает затраты на ручное тестирование.
- **Поддержка и рефакторинг**: Наличие тестов делает рефакторинг кода безопаснее, поскольку тесты контролируют, что все работает корректно.
- **Документация**: Тесты могут служить документацией для других разработчиков, показывая, как должен работать код.

## 3. Виды тестирования

### 3.1 Unit-тестирование (Модульное тестирование)
Тестирование отдельных функций или методов в изоляции от остальной системы. Каждая функция проверяется на корректность работы при различных вводных данных.

- **Зачем**: Проверяет, что каждый отдельный модуль работает правильно.
- **Пример**: Тестирование функции, которая складывает два числа.

```c++
#include <cassert>

int add(int a, int b) {
    return a + b;
}

void test_add() {
    assert(add(2, 3) == 5);
    assert(add(-1, 1) == 0);
    assert(add(0, 0) == 0);
}

int main() {
    test_add();
}
```

### 3.2 Интеграционное тестирование
Тестирование взаимодействия нескольких компонентов системы вместе. Проверяется, как модули работают в связке друг с другом.

- **Зачем**: Убедиться, что модули корректно взаимодействуют и совместно выполняют задачи.
- **Пример**: Тестирование модуля аутентификации, который использует функцию авторизации и базу данных.

```c++
#include <iostream>

class Database {
public:
    bool Connect() { return true; }
};

class User {
public:
    User(Database& db) : db_(db) {}
    bool Login() { return db_.Connect(); }
private:
    Database& db_;
};

void TestUserLogin() {
    Database db;
    User user(db);
    if (!user.Login()) {
        std::cout << "TestUserLogin failed: Login() returned false" << std::endl;
    } else {
        std::cout << "TestUserLogin passed" << std::endl;
    }
}

int main() {
    TestUserLogin();
}

```

### 3.3 Функциональное тестирование
Тестирование функциональности системы на соответствие требованиям. Проверяется, выполняются ли все необходимые функции в соответствии с ожиданиями пользователя.

- **Зачем**: Убедиться, что система работает в соответствии с требованиями.
- **Пример**: Проверка формы логина, которая должна либо допустить пользователя, либо вывести ошибку.

```c++
#include <cassert>
#include <string>

std::string authenticate(const std::string& username, const std::string& password) {
    if (username == "user" && password == "pass") {
        return "Login success";
    }
    return "Login failed";
}

void test_authenticate() {
    assert(authenticate("user", "pass") == "Login success");
    assert(authenticate("user", "wrongpass") == "Login failed");
}

int main() {
    test_authenticate();
}
```

### 3.4 Тестирование производительности (Performance Testing)
Измерение скорости и потребления ресурсов программы при высоких нагрузках.

- **Зачем**: Оценка того, как система справляется с нагрузками и ресурсоемкими задачами.
- **Пример**: Замер времени выполнения сортировки большого массива.

### 3.5 Тестирование безопасности
Проверка программы на наличие уязвимостей, которые могут быть использованы злоумышленниками.

- **Зачем**: Защита системы от потенциальных атак и эксплойтов.
- **Пример**: Проверка того, как система обрабатывает SQL-инъекции или другие атаки.

### 3.6 Регрессионное тестирование
Тестирование уже существующего функционала после внесения изменений в код, чтобы убедиться, что новый код не привел к появлению новых багов.

- **Зачем**: Убедиться, что исправления и новые фичи не поломали старые.
- **Пример**: Тестирование функции, которая ранее работала корректно, после добавления нового кода.

## 4. Best Practices в тестировании

### 4.1 Пишите тесты вместе с кодом
Писать тесты нужно параллельно с разработкой, а не откладывать на потом. Это поможет вам быстрее находить ошибки и убедиться, что новый код не нарушил старую функциональность.

### 4.2 Используйте автоматическое тестирование
Запуск тестов вручную может быть долгим и трудоемким процессом. Автоматические тесты позволяют быстро прогонять все проверки при каждом изменении кода.

### 4.3 Пишите тесты для граничных случаев
Граничные случаи (например, ноль, максимальные и минимальные значения) часто становятся причиной ошибок, поэтому важно проверять их.

### 4.4 Модульные тесты должны быть изолированы
Каждый модульный тест должен быть независимым и проверять лишь одну функцию или метод. Это позволяет легко находить источник проблемы, если тест не прошел.

### 4.5 Поддерживайте тесты актуальными
Тесты должны меняться вместе с кодом. Если функционал изменился, необходимо обновить и тесты, иначе они станут бесполезными.

### 4.6 Не полагайтесь на тесты как на единственный источник истины
Автоматические тесты — это важно, но они не могут поймать все возможные баги. Также важно проводить ручное тестирование, особенно в сложных сценариях взаимодействия пользователя с системой.

### 4.7 Регулярно выполняйте регрессионное тестирование
После каждого изменения в коде проверяйте, что всё, что ранее работало, продолжает работать правильно.


# Unit-тесты с использованием doctest 

```c++
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <stdexcept>
#include <vector>

// Пример функции для тестирования
int add(int a, int b) {
    return a + b;
}

std::vector<int> make_vector(int size) {
    if (size < 0) {
        throw std::invalid_argument("Size cannot be negative");
    }
    return std::vector<int>(size, 0);
}

// Тестовые кейсы
TEST_CASE("Basic functionality of add()") {
    CHECK(add(2, 3) == 5);
    CHECK(add(-1, 1) == 0);
    CHECK(add(0, 0) == 0);
}

TEST_CASE("Exception handling in make_vector()") {
    CHECK_THROWS_AS(make_vector(-1), std::invalid_argument); // Проверка на исключение
}

// Тестирование с подкейсами
TEST_CASE("Vectors with make_vector()") {
    SUBCASE("Empty vector") {
        std::vector<int> v = make_vector(0);
        CHECK(v.empty());
    }
    
    SUBCASE("Non-empty vector") {
        std::vector<int> v = make_vector(3);
        CHECK(v.size() == 3);
        CHECK(v[0] == 0);
    }
}

// Тестирование через циклы
TEST_CASE("Parameterized testing") {
    for (int i : {1, 2, 3}) {
        CHECK(add(i, i) == 2 * i);  // Проверка для разных значений
    }
}
```

# Домашнее задание

Написать класс рациональные числа с unit-тестами используя doctest
* Структура директорий аналогична косплексным, только тестовый файл - с использованием доктест
* Написать реализацию всех методов и всё протестировать

```c++
#ifndef RATIONAL_RATIONAL_HPP_20231113
#define RATIONAL_RATIONAL_HPP_20231113

#include <cstdint>
#include <iosfwd>

class Rational {
 public:
    Rational() = default;
    Rational(const Rational&) = default;
    explicit Rational(const std::int64_t num) noexcept : num_(num) { }
    Rational(const std::int64_t num, const std::int64_t den);
    ~Rational() = default;
    Rational& operator=(const Rational&) = default;

    std::int64_t num() const noexcept;
    std::int64_t den() const noexcept;

    bool operator==(const Rational& rhs) const noexcept;
    bool operator!=(const Rational& rhs) const noexcept;
    bool operator<(const Rational& rhs) const noexcept;
    bool operator<=(const Rational& rhs) const noexcept;
    bool operator>(const Rational& rhs) const noexcept;
    bool operator>=(const Rational& rhs) const noexcept;

    Rational operator-() const noexcept;

    Rational& operator+=(const Rational& rhs) noexcept;
    Rational& operator-=(const Rational& rhs) noexcept;
    Rational& operator*=(const Rational& rhs) noexcept;
    Rational& operator/=(const Rational& rhs);

    Rational& operator+=(const int64_t rhs) noexcept;
    Rational& operator-=(const int64_t rhs) noexcept;
    Rational& operator*=(const int64_t rhs) noexcept;
    Rational& operator/=(const int64_t rhs);

    //! \brief Форматированный вывод в поток ostrm рационального числа в виде num/den.
    //!
    //! \param[in,out] ostrm - поток
    //! \retval поток
    std::ostream& WriteTo(std::ostream& ostrm) const noexcept;

    //! \brief Форматированный ввод из потока istrm комплексного числа в виде num/den.
    //!
    //! \param[in,out] istrm - поток
    //! \retval
    std::istream& ReadFrom(std::istream& istrm) noexcept;

 private:
    std::int64_t num_ = 0;
    std::int64_t den_ = 1;
};

 Rational operator+(const Rational& lhs, const Rational& rhs) noexcept;
 Rational operator-(const Rational& lhs, const Rational& rhs) noexcept;
 Rational operator*(const Rational& lhs, const Rational& rhs) noexcept;
 Rational operator/(const Rational& lhs, const Rational& rhs);

 Rational operator+(const Rational& lhs, const int64_t rhs) noexcept;
 Rational operator-(const Rational& lhs, const int64_t rhs) noexcept;
 Rational operator*(const Rational& lhs, const int64_t rhs) noexcept;
 Rational operator/(const Rational& lhs, const int64_t rhs);

 Rational operator+(const int64_t lhs, const Rational& rhs) noexcept;
 Rational operator-(const int64_t lhs, const Rational& rhs) noexcept;
 Rational operator*(const int64_t lhs, const Rational& rhs) noexcept;
 Rational operator/(const int64_t lhs, const Rational& rhs);

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) noexcept;

std::istream& operator>>(std::istream& istrm, Rational& rhs) noexcept;

#endif
```