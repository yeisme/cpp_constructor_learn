/**
 * @file main.cpp
 * @author yeisme (yefun2004@gmail.com)
 * @brief C++ 构造函数案例
 * @version 0.1
 * @date 2025-04-07
 *
 * @copyright Copyright (c) 2025
 *
 */
#include <initializer_list>
#include <iostream>
#include <string>

using std::cout;
using std::endl;

class Person
{
  public:
    // 1. 默认构造函数
    Person() : _name("momo"), _age(0)
    {
    }

    // 2. 带参数的构造函数
    Person(std::string name, int age) : _name(name), _age(age)
    {
    }

    // 3. 拷贝构造函数
    Person(const Person &p) : _name(p._name), _age(p._age)
    {
    }

    // 4. 移动构造函数 (移交所有权)
    Person(Person &&p) noexcept : _name(std::move(p._name)), _age(p._age)
    {
        p._age = 0;
    }

    // 5. 委托构造函数
    Person(const std::string &name) : Person(name, 0)
    {
    }

    // 6. 显式转换构造函数
    explicit Person(int age) : Person("momo", age)
    {
    }

  private:
    std::string _name;
    int _age;

    friend std::ostream &operator<<(std::ostream &os, const Person &p)
    {
        os << "name: " << p._name << ", age: " << p._age;
        return os;
    }
};

class Student : public Person
{
  public:
    // 7. 初始化列表构造函数 (允许传入多个字符串，但是不允许传入其他类型的参数)
    Student(std::initializer_list<std::string> list) : Person(*list.begin(), 0)
    {
    }
};

int main()
{
    auto p1 = Person{};
    cout << p1 << endl;
    auto p2 = Person{"username", 18};
    cout << p2 << endl;
    auto p3 = Person{p2};
    cout << p3 << endl;
    auto p4 = Person{std::move(p2)}; // 移动构造函数
    cout << "p4: " << p4 << "\t" << "p2: " << p2 << endl;
    auto p5 = Person{"username"};
    cout << p5 << endl;
    auto p6 = Person{18}; // 显式转换构造函数"
    cout << p6 << endl;

    auto p7 = Student{"student1", "student2", "student3"};
    cout << p7 << endl;

    return 0;
}

/* 
name: momo, age: 0
name: username, age: 18
name: username, age: 18
p4: name: username, age: 18     p2: name: , age: 0
name: username, age: 0
name: momo, age: 18
name: student1, age: 0
 */
 