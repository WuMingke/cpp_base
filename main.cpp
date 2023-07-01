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
private:
    int name;
    int *m_Height;
};

int main() {
    Student s{};
    s.id = 1;
    cout << "result:" << s.id << endl;
    return 0;
}


