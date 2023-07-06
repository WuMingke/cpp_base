#include <iostream>
#include "swap.h" // 双引号代表自定义的头文件

using namespace std;

//int main() {
//    cout << "Hello, World!" << endl;
//    int a = 10;
//    int b = 20;
//    swap(a, b);
//    return 0;
//}

//int main() {
//
//    int a = 10;
//
//    int *p;
//    p = &a;
//
//    *p = 200;
//    int b = *p;
//    cout << "b = " << b << endl;
//    cout << "a = " << a << endl;
//
//    cout << "指针大小：" << sizeof(int *) << endl;
//
//    int *n = NULL;
//
////    *n = 100;
//
//    int c = 10;
//
//    cout << "c = " << c << endl;
//
//
//    return 0;
//}


//int main() {
//    int arr[3] = {1, 2, 3};
//    cout << "0-" << arr[0] << endl;
//
//    int *p = arr;// arr就是数组的首地址
//    p++; // 让指针往后移动4字节
//    cout << "1-" << *p << endl;
//
//
//    return 0;
//}

int *func() {
    // p存放在栈区，new开辟的内存在栈区，new返回的是该数据类型的指针
    int *p = new int(10);
    return p;
}

//int main() {
//    int *p = func();
//    cout << "result:" << *p << endl;
//    delete p; // 释放内存空间
//    p = NULL; // 防止野指针
//
//    return 0;
//}

class Student {
public:
    int id;

    Student() {

    };

    Student(const Student &s) { // 拷贝构造函数
        id = s.id;
        name = s.name; // 浅拷贝
        // 如果不利用深拷贝在堆区创建新内存，会导致浅拷贝带来的重复释放堆区的问题
        m_Height = new int(*s.m_Height); // 深拷贝
    }

    ~Student() { // 析构函数
        if (m_Height != NULL) {
            delete m_Height;
            m_Height = NULL;
        }
    };

    virtual void fun1() {

    }

private:
    int name;
    int *m_Height;
};

class XIAOMING : private Student { // 私有继承
public:
    void fun1() override {

    }
};

//int main() {
//    Student s{};
//    s.id = 1;
//    cout << "result:" << s.id << endl;
//    return 0;
//}


class Animal {
public:
    virtual void speak() { // 虚函数
        cout << "Animal speak" << endl;
    }
//    auto i = 0;
};

class Cat : public Animal {
public:
    void speak() override {
        cout << "Cat speak" << endl;
    }
};

void doSpeak(Animal &animal) { // 这一行，父类的指针或者引用指向子类对象的时候：Animal &animal = cat;
    animal.speak();
}

//int main() { // 多态
//
//    Cat cat;
//    doSpeak(cat);
//    return 0;
//}


template<typename T>
void mySwap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
}

template<>
void mySwap(Student &s1, Student &s2) { // 模版重载
    s1.id = s2.id;
}

//int main() {
//    int a = 10;
//    int b = 20;
////    mySwap<int>(a, b); // 显示指定类型
//    mySwap(a, b); // 自动类型推导
//    cout << "a=" << a << ",b=" << b << endl;
//
//
//    Student s1;
//    s1.id = 1;
//    Student s2;
//    s2.id = 2;
//    mySwap(s1, s2);
//    cout << "s1.id=" << s1.id << endl;
//    return 0;
//}


#include <vector>
#include <algorithm>

void myPrint(int p) {
    cout << "myPrint->item:" << p << endl;

}

void t1() {
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

//    auto itBegin = v.begin();
//    auto itEnd = v.end();
//    while (itBegin != itEnd) {
//        cout << *itBegin << endl;
//        itBegin++;
//    }

    for (const auto &item: v) {
        cout << item << endl;
    }


    for_each(v.begin(), v.end(), myPrint);

}


class MyAdd { // 仿函数
public:
    int operator()(int a, int b) {
        return a + b;
    }
};

void t2() {
    MyAdd m;
    int result = m(1, 2);

    cout << "result = " << result << endl;
}


void t3() {
    plus<int> p; // STL仿函数
    cout << "result = " << p(10, 20) << endl;
}


int main() {
//    t1();
//    t2();
    t3();
    return 0;
}
