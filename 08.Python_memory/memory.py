# Каждый раз новый объект

a = 0
print(hex(id(a)))
a += 1
print(hex(id(a)))
print()

# Ссылаются на единый кусочек памяти
x = 10
print(x)
print(id(x))

y = x
print(y)
print(id(y))
print(x)
print(id(x))

# Передача в функцию по ссылке
lst = [1, 2, 3]

def func(lst):
    lst += [1]

func(lst)
print(lst)

# Нужно явно копировать
from copy import copy, deepcopy

lst = [1, 2, 3]

def func(lst):
    lst = copy(lst)
    lst += [1]

func(lst)
print(lst)

# Строки - неизменяемы
str1 = "String 1"
str2 = str1
str1 = str1 + " something new"
print(str1)
print(str2)

# is vs ==

lst1 = [1, 2, 3]
lst2 = lst1
print(lst1 == lst2)
print(lst1 is lst2)

lst3 = lst1[:] #копирование
print(lst1 == lst3)
print(lst1 is lst3)

# matrix 
rows, cols = 3, 4
matrix = [[0] * cols] * rows
matrix[0][0] = 1
matrix[0][1] = 2

print(matrix)

# верная инициализация
matrix = [[0 for _ in range(cols)] for _ in range(rows)]
matrix[0][0] = 1
matrix[0][1] = 2

print(matrix)

# аннотации типов
a: int = 10
lst: list[str] = ["1", 2]
print(a)
print(lst)

# wrong type

def func_1(x: int):
    return x

func_1("smth")

my_dict = {
 "key": 1
}

print(my_dict["key"])

from dataclasses import dataclass

@dataclass
class MyDict:
    key: int

data_dict = MyDict(
    key=1
)
print(data_dict.key)